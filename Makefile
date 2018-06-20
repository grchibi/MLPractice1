CXX ?= g++

TARGET_EXEC ?= ql

BUILD_DIR ?= ./build
SRC_DIR ?= ./src

REL_DIR ?= bin/release
DBG_DIR ?= bin/debug

SRCS := $(shell find $(SRC_DIR) -name *.cpp)
OBJS := $(addprefix $(BUILD_DIR)/, $(notdir $(SRCS:.cpp=.o)))
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

LIBS=

-include $(DEPS)

MKDIR_P ?= mkdir -p
RM ?= rm

CPPFLAGS ?= $(INC_FLAGS) -c -MMD -MP -std=c++1y

# c++ source
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	-mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) -o $@ $<

# link
.PHONY: build
build: $(OBJS) $(LIBS)
	-mkdir -p $(OUTPUT_DIR)
	$(CXX) $(LDFLAGS) -o $(OUTPUT) $(OBJS) $(LIBS)

.PHONY: all
all: clean release

.PHONY: clean
clean:
	$(RM) $(BUILD_DIR)/*
	$(RM) $(DBG_DIR)/$(TARGET_EXEC)
	$(RM) $(REL_DIR)/$(TARGET_EXEC)

.PHONY: debug
debug: OUTPUT_DIR = $(DBG_DIR)
debug: OUTPUT = $(DBG_DIR)/$(TARGET_EXEC)
debug: CPPFLAGS += -g3 -O0 -Wall -W
debug: build

.PHONY: release
release: OUTPUT_DIR = $(REL_DIR)
release: OUTPUT = $(REL_DIR)/$(TARGET_EXEC)
release: CPPFLAGS += -Wall -W
release: build
