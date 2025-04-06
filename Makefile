##########################

NAME=boot

##########################

SRC_DIR=src
OBJ_DIR=obj
BUILD_DIR=build
TEST_DIR=test

ASM_FILES=$(wildcard $(SRC_DIR)/*.z80)
OBJ_FILES=$(ASM_FILES:$(SRC_DIR)/%.z80=$(OBJ_DIR)/%.o)
TEST_FILES=$(wildcard $(TEST_DIR)/*.toml)

AS=rgbasm
LD=rgblink
FX=rgbfix

AS_FLAGS= -Iinclude
LD_FLAGS= -n $(BUILD_DIR)/$(NAME).sym -m $(BUILD_DIR)/$(NAME).map
FX_FLAGS= -v -p 0

RM=rm

TARGET=$(NAME).gb

.PHONY: all clean test hex

all: $(BUILD_DIR)/$(TARGET)

$(OBJ_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/$(TARGET): $(BUILD_DIR) $(OBJ_FILES)
	$(LD) $(LD_FLAGS) $(filter %.o,$^) -o $@
	$(FX) $(FX_FLAGS) $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.z80 $(OBJ_DIR)
	$(AS) $(AS_FLAGS) $< -o $@

clean:
	$(RM) -f $(BUILD_DIR)/* $(OBJ_DIR)/*.o

test: $(BUILD_DIR)/$(TARGET)
	@for file in "$(TEST_FILES)"; do \
		echo "Running tests in $$file..."; \
		evunit -c $$file -d dump -n $(BUILD_DIR)/$(NAME).sym $(BUILD_DIR)/$(TARGET); \
		echo; \
	done

$(BUILD_DIR)/$(NAME).mem: $(BUILD_DIR)/$(TARGET)
	@./scripts/make_hex.sh $< $@

hex: $(BUILD_DIR)/$(NAME).mem
