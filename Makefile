SRC_PATH ?= src
INC_PATH ?= include
BUILD_PATH ?= build

EXAMPLE_PATH ?= example/
TEST_PATH ?= PhaseOne_Case/

OBJ_PATH ?= $(BUILD_PATH)/obj
BINARY ?= $(BUILD_PATH)/Ada2Compiler

INC = $(addprefix -I, $(INC_PATH))
SRC = $(shell find $(SRC_PATH)  -name "*.cpp")

CFLAGS = -O3 -g -Wall -std=c++17 $(INC)

FLEX ?= $(SRC_PATH)/lexer.l
LEXER ?= $(addsuffix .cpp, $(basename $(FLEX)))
BISON ?= $(SRC_PATH)/parser.y
PARSER ?= $(addsuffix .cpp, $(basename $(BISON)))

SRC += $(LEXER)
SRC += $(PARSER)

OBJ = $(SRC:$(SRC_PATH)/%.cpp=$(OBJ_PATH)/%.o)
PARSERH ?= $(INC_PATH)/$(addsuffix .h, $(notdir $(basename $(PARSER))))

TESTCASE = $(shell find $(TEST_PATH) -name "*.adb")
TESTCASE_NUM = $(words $(TESTCASE))

OUTPUT_TOKEN = $(addsuffix .toks, $(basename $(TESTCASE)))
OUTPUT_AST = $(addsuffix .ast, $(basename $(TESTCASE)))

.phony:all app example run clean-run

all:app

$(LEXER):$(FLEX)
	@flex -o $@ $<

$(PARSER):$(BISON)
	@bison -o $@ $< --warnings=error=all --defines=$(PARSERH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.cpp 
	@mkdir -p $(OBJ_PATH)
	@clang++ $(CFLAGS) -c -o $@ $<

$(BINARY):$(OBJ)
	@clang++ -O3 -g -o $@ $^

app:$(LEXER) $(PARSER) $(BINARY)

run:
	@gprbuild -p -P $(EXAMPLE_PATH)/default.gpr -Xver=opt

clean-run:
	@rm -rf $(EXAMPLE_PATH)/obj/ $(EXAMPLE_PATH)/obj/*



