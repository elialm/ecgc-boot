##########################

NAME=template

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

AS_FLAGS= -iinclude
LD_FLAGS= -n $(BUILD_DIR)/$(NAME).sym -m $(BUILD_DIR)/$(NAME).map
FX_FLAGS= -v -p 0 -C

RM=rm

TARGET=$(NAME).gbc

.PHONY: all clean

all: $(BUILD_DIR) $(OBJ_DIR) $(BUILD_DIR)/$(TARGET)
	$(FX) $(FX_FLAGS) $(BUILD_DIR)/$(TARGET)

$(OBJ_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	$(LD) $(LD_FLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.z80
	$(AS) $(AS_FLAGS) $< -o $@

clean:
	$(RM) -f $(BUILD_DIR)/* $(OBJ_DIR)/*.o

test: $(BUILD_DIR)/$(TARGET)
	@for file in "$(TEST_FILES)"; do \
		echo "Running tests in $$file..."; \
		evunit -c $$file -d dump -n $(BUILD_DIR)/$(NAME).sym $(BUILD_DIR)/$(TARGET); \
		echo; \
	done