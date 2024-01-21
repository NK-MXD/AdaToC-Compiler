WORKSPACE ?= $(shell pwd)
SRC_PATH ?= $(WORKSPACE)/src
INC_PATH ?= $(WORKSPACE)/include
BUILD_PATH ?= $(WORKSPACE)/build

EXAMPLE_PATH ?= $(WORKSPACE)/example
TEST_PATH ?= $(WORKSPACE)/PhaseOne_Case

OBJ_PATH ?= $(BUILD_PATH)/obj
BINARY ?= $(BUILD_PATH)/Ada2Compiler

INC = $(addprefix -I, $(INC_PATH))
SRC = $(shell find $(SRC_PATH)  -name "*.cpp")

CFLAGS = -O3 -g -Wall -std=c++17 $(INC)

FLEX ?= $(SRC_PATH)/lexer.l
LEXER ?= $(addsuffix .cpp, $(basename $(FLEX)))
# BISON ?= $(SRC_PATH)/parser.y
# PARSER ?= $(addsuffix .cpp, $(basename $(BISON)))

SRC += $(LEXER)
# SRC += $(PARSER)

OBJ = $(SRC:$(SRC_PATH)/%.cpp=$(OBJ_PATH)/%.o)
# PARSERH ?= $(INC_PATH)/$(addsuffix .h, $(notdir $(basename $(PARSER))))

EXAMPLECASE = $(shell find $(EXAMPLE_PATH) -name "*.adb")
TESTCASE = $(shell find $(TEST_PATH) -name "*.adb" | xargs -i basename {})
TESTCASE_NUM = $(words $(TESTCASE))

OUTPUT_TOKEN = $(addsuffix .toks, $(basename $(TESTCASE)))
OUTPUT_AST = $(addsuffix .ast, $(basename $(TESTCASE)))
OUTPUT_ADB1 = $(shell find $(TEST_PATH) -name "b__*.adb")
OUTPUT_ADB2 = $(filter %.toks %.log %.ads %.ali %.o %.stderr %.stdout %.bexch %.bin, $(wildcard $(TEST_PATH)/*))

OUTPUT_EXAMPLE1 = $(shell find $(EXAMPLE_PATH)/src -name "b__*.adb")
OUTPUT_EXAMPLE2 = $(filter %.ads %.ali %.o %.stderr %.stdout %.bexch %.bin, $(wildcard $(EXAMPLE_PATH)/src/*))

.phony:all app example run clean-run test_lex

all:app

$(LEXER):$(FLEX)
	@flex -o $@ $<

# $(PARSER):$(BISON)
	# @bison -o $@ $< --warnings=error=all --defines=$(PARSERH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.cpp 
	@mkdir -p $(OBJ_PATH)
	@clang++ $(CFLAGS) -c -o $@ $<

$(BINARY):$(OBJ)
	@clang++ -O3 -g -o $@ $^

app:$(LEXER) $(BINARY)

.ONESHELL:
testadb:app
	@success=0
	@cd $(TEST_PATH)
	@for file in $(sort $(TESTCASE))
	do
		FILE=$${file##*/}
		BIN=$${file%.*}.bin
		LOG=$${file%.*}.log
		@gprbuild -p $${FILE} -o $${BIN} > $${LOG} 2>&1
		if [ $$? != 0 ]; then
			echo "\033[1;31mFAIL:\033[0m $${FILE}\t\033[1;31mGPRBuild Error\033[0m"
		else
			./$${BIN}
			RETURN_VALUE=$$?
			if [ $$? != 0 ]; then
				echo "\033[1;31mFAIL:\033[0m $${FILE}\t\033[1;31mADBRun Error\033[0m"
			else
				success=$$((success + 1))
				echo "\033[1;32mPASS:\033[0m $${FILE}"
			fi
		fi
	done
	echo "\033[1;33mTotal: $(TESTCASE_NUM)\t\033[1;32mAccept: $${success}\t\033[1;31mFail: $$(($(TESTCASE_NUM) - $${success}))\033[0m"
	[ $(TESTCASE_NUM) = $${success} ] && echo "\033[5;32mAll Accepted. Congratulations!\033[0m"
	:

.ONESHELL:
test-all:app
	@success=0
	@cd $(TEST_PATH)
	@for file in $(sort $(TESTCASE))
	do
		FILE=$${file##*/}
		TOKS=$${file%.*}.toks
		LOG=$${file%.*}.log
		$(BINARY) $${file} -t -o $${TOKS}
		if [ $$? != 0 ]; then
			echo "\033[1;31mFAIL:\033[0m $${FILE}\t\033[1;31mCompiler Error\033[0m"
		else
			# ./$${BIN}
			# RETURN_VALUE=$$?
			# if [ $$? != 0 ]; then
			# 	echo "\033[1;31mFAIL:\033[0m $${FILE}\t\033[1;31mADBRun Error\033[0m"
			# else
			success=$$((success + 1))
			echo "\033[1;32mPASS:\033[0m $${FILE}"
			# fi
		fi
	done
	echo "\033[1;33mTotal: $(TESTCASE_NUM)\t\033[1;32mAccept: $${success}\t\033[1;31mFail: $$(($(TESTCASE_NUM) - $${success}))\033[0m"
	[ $(TESTCASE_NUM) = $${success} ] && echo "\033[5;32mAll Accepted. Congratulations!\033[0m"
	:

test_lex:app
	$(BINARY) $(EXAMPLE_PATH)/src/example.adb -t

run:
	@gprbuild -p $(EXAMPLE_PATH)/default.gpr -Xver=opt
	@$(EXAMPLE_PATH)/obj/opt/example

clean:
	@rm -rf $(BUILD_PATH) $(LEXER)

clean-test:
	@rm -rf $(OUTPUT_EXAMPLE1) $(OUTPUT_EXAMPLE2)

clean-all:clean clean-test
	@rm -rf $(EXAMPLE_PATH)/obj/ $(EXAMPLE_PATH)/obj/* $(OUTPUT_ADB1) $(OUTPUT_ADB2)

