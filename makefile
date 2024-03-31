# Generic makefile for flowVC
ifeq ($(OS),Windows_NT)
	ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
endif
TARGET_EXTENSION=exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=out
endif

.PHONY: clean
.PHONY: test
.PHONY: all

PATHU = unity/src/
PATHS = src/
PATHT = test/
PATHB = build/
PATHD = $(PATHB)depends/
PATHO = $(PATHB)objs/$(mode)/
PATHR = $(PATHB)results/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO) $(PATHR)

SRC = $(wildcard $(PATHS)*.c)
SRCT = $(wildcard $(PATHT)*.c)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF



LFLAGS = -lm
CC = gcc

ifeq ($(mode),debug)
	CFLAGS = -g -Wall -O0 -I. -I$(PATHU) -I$(PATHS) -DTEST
else
	mode = release
	CFLAGS = -Wall -O3 -I. -I$(PATHU) -I$(PATHS) -DTEST
endif

EXE = flowVC
all: info $(EXE)

# Tests results
# For all of the testsomething.c create a testsomething.txt


PASSED = `grep -s PASS $(PATHR)*.txt`
FAIL = `grep -s FAIL $(PATHR)*.txt`
IGNORE = `grep -s IGNORE $(PATHR)*.txt`

test: $(BUILD_PATHS) $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@echo "$(IGNORE)"
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@echo "$(FAIL)"
	@echo "-----------------------\nPASSED:\n-----------------------"
	@echo "$(PASSED)"
	@echo "\nDONE"

RESULTS = $(patsubst $(PATHT)Test%.c,$(PATHR)Test%.txt,$(SRCT))
# In the results
$(PATHR)%.txt: $(PATHB)%.$(TARGET_EXTENSION)
	-./$< > $@ 2>&1

# Create object files from the source path
$(PATHO)%.o: $(PATHS)%.c | $(PATHO)
	$(COMPILE) $(CFLAGS) $< -o $@

# Create object files from the test path
$(PATHO)%.o: $(PATHT)%.c | $(PATHO)
	$(COMPILE) $(CFLAGS) $< -o $@

# Create object files from the unity path
$(PATHO)%.o: $(PATHU)%.c $(PATHU)%.h | $(PATHO)
	$(COMPILE) $(CFLAGS) $< -o $@

# Create the test dependency file
$(PATHD)%.d: $(PATHT)%.c
	$(DEPEND) $@ $<

# Make directories if they do not exist
$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

$(PATHR):
	$(MKDIR) $(PATHR)

# Link object files to create the executable
$(EXE): $(PATHO)*.o
	$(LINK) -o $@ $^ $(LFLAGS)

clean:
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)
	$(CLEANUP) $(PATHR)*.txt
	$(CLEANUP) $(EXE)

.PRECIOUS: $(PATHB)Test%.$(TARGET_EXTENSION)
.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o
.PRECIOUS: $(PATHR)%.txt

info:
ifneq ($(mode),release)
ifneq ($(mode),debug)
	@echo "Invalid build mode." 
	@echo "Please use 'make mode=release' or 'make mode=debug'"
	@exit 1
endif
endif
	@echo "Building in "$(mode)" mode..."
