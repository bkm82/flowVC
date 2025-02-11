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
.PHONY: all

PATHS = src/
PATHT = test/
PATHB = build/release/
PATHD = build/release/dependencies/
PATHO = build/release/out/

BUILD_PATHS = $(PATHB) $(PATHD) $(PATHO)

SRCT = $(wildcard $(PATHT)*.c)

COMPILE=gcc -c
LINK=gcc
DEPEND=gcc -MM -MG -MF
LFLAG= -lm

# Set build mode
ifeq ($(mode),debug)
   CFLAGS = -g -Wall -O0 -I. -I$(PATHS) -DDEBUG_LEVEL=1
else
   mode = release
   CFLAGS = -Wall -O3 -I. -I$(PATHS)
endif



all: info project

info:
ifneq ($(mode),release)
ifneq ($(mode),debug)
	@echo "Invalid build mode." 
	@echo "Please use 'make mode=release' or 'make mode=debug'"
	@exit 1
endif
endif
	@echo "Building in "$(mode)" mode..."

# Define the output filename
OUTPUT_NAME = flowVC

# List of source files for your project
SRCS = $(wildcard $(PATHS)*.c)

# List of object files for your project
OBJS = $(patsubst $(PATHS)%.c,$(PATHO)%.o,$(SRCS))

# Target for building your project
project: $(BUILD_PATHS) $(OBJS)
	$(LINK) -o $(PATHB)$(OUTPUT_NAME).$(TARGET_EXTENSION) $(OBJS) $(LFLAG)

# Dependency rule for object files
$(PATHO)%.o: $(PATHS)%.c
	$(COMPILE) $(CFLAGS) $< -o $@


$(PATHB):
	$(MKDIR) $(PATHB)

$(PATHD):
	$(MKDIR) $(PATHD)

$(PATHO):
	$(MKDIR) $(PATHO)

clean:
	$(CLEANUP) $(PATHO)*.o
	$(CLEANUP) $(PATHB)*.$(TARGET_EXTENSION)

.PRECIOUS: $(PATHD)%.d
.PRECIOUS: $(PATHO)%.o





