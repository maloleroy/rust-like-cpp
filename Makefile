# Compilers and flags
CXX ?= clang++
CXXFLAGS := -std=c++23
RUSTC ?= rustc

# Find all top-level directories (e.g., common-types/, memory/, traits/)
DIRS := $(wildcard */)

# --- C++ Compilation ---
# Find all .cpp files in these directories
# Example: common-types/a.cpp, memory/b.cpp
ALL_CPP_SRCS := $(foreach DIR,$(DIRS),$(wildcard $(DIR)*.cpp))
# Define target executable names by appending _cpp to the original filename (without extension)
# Example: common-types/a.cpp -> common-types/a_cpp
ALL_CPP_TARGETS := $(patsubst %.cpp,%_cpp,$(ALL_CPP_SRCS))

# Generic rule to compile a .cpp file to its _cpp counterpart
# $< is the first prerequisite (the .cpp file, e.g., common-types/a.cpp)
# $@ is the target (the output file, e.g., common-types/a_cpp)
%_cpp: %.cpp
	@echo "$< -> $@"
	@$(CXX) $(CXXFLAGS) $< -o $@

# --- Rust Compilation ---
# Find all .rs files in these directories
ALL_RS_SRCS := $(foreach DIR,$(DIRS),$(wildcard $(DIR)*.rs))
# Define target executable names by appending _rs to the original filename (without extension)
# Example: common-types/a.rs -> common-types/a_rs
ALL_RS_TARGETS := $(patsubst %.rs,%_rs,$(ALL_RS_SRCS))

# Generic rule to compile a .rs file to its _rs counterpart
%_rs: %.rs
	@echo "$< -> $@"
	@$(RUSTC) $< -o $@

# Default target: build all found C++ and Rust targets
all: $(ALL_CPP_TARGETS) $(ALL_RS_TARGETS)

# Clean target: remove all compiled executables identified
clean:
	@echo "Cleaning compiled files..."
	@rm -f $(ALL_CPP_TARGETS) $(ALL_RS_TARGETS)
	@echo "Clean complete."

# Phony targets to ensure 'all' and 'clean' always run their recipes
# and are not confused with files named 'all' or 'clean'.
.PHONY: all clean