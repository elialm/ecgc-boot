##########################

NAME=boot

##########################

SRC_DIR=src
OBJ_DIR=obj
BUILD_DIR=build

ASM_FILES=$(wildcard $(SRC_DIR)/*.z80)
OBJ_FILES=$(ASM_FILES:$(SRC_DIR)/%.z80=$(OBJ_DIR)/%.o)

AS=rgbasm
LD=rgblink
FX=rgbfix

AS_FLAGS= -iinclude
LD_FLAGS= -n $(BUILD_DIR)/$(NAME).sym -m $(BUILD_DIR)/$(NAME).map
FX_FLAGS= -v -p 0

RM=rm

TARGET=$(NAME).gb

.PHONY: all clean mem

all: $(BUILD_DIR) $(OBJ_DIR) $(BUILD_DIR)/$(TARGET)

mem: $(BUILD_DIR)/$(TARGET).mem

$(OBJ_DIR):
	mkdir -p $@

$(BUILD_DIR):
	mkdir -p $@

$(BUILD_DIR)/$(TARGET): $(OBJ_FILES)
	$(LD) $(LD_FLAGS) $^ -o $@
	$(FX) $(FX_FLAGS) $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET).mem: $(BUILD_DIR)/$(TARGET)
	./scripts/make_hex.sh $< $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.z80
	$(AS) $(AS_FLAGS) $< -o $@

clean:
	$(RM) -f $(BUILD_DIR)/* $(OBJ_DIR)/*.o
