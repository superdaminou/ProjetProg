# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.0.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.0.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/damien/Documents/L2S2/ProjetProg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/damien/Documents/L2S2/ProjetProg/build

# Include any dependencies generated for this target.
include CMakeFiles/strategy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/strategy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strategy.dir/flags.make

CMakeFiles/strategy.dir/strategy/strategy.c.o: CMakeFiles/strategy.dir/flags.make
CMakeFiles/strategy.dir/strategy/strategy.c.o: ../strategy/strategy.c
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/damien/Documents/L2S2/ProjetProg/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/strategy.dir/strategy/strategy.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/strategy.dir/strategy/strategy.c.o   -c /Users/damien/Documents/L2S2/ProjetProg/strategy/strategy.c

CMakeFiles/strategy.dir/strategy/strategy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strategy.dir/strategy/strategy.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /Users/damien/Documents/L2S2/ProjetProg/strategy/strategy.c > CMakeFiles/strategy.dir/strategy/strategy.c.i

CMakeFiles/strategy.dir/strategy/strategy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strategy.dir/strategy/strategy.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /Users/damien/Documents/L2S2/ProjetProg/strategy/strategy.c -o CMakeFiles/strategy.dir/strategy/strategy.c.s

CMakeFiles/strategy.dir/strategy/strategy.c.o.requires:
.PHONY : CMakeFiles/strategy.dir/strategy/strategy.c.o.requires

CMakeFiles/strategy.dir/strategy/strategy.c.o.provides: CMakeFiles/strategy.dir/strategy/strategy.c.o.requires
	$(MAKE) -f CMakeFiles/strategy.dir/build.make CMakeFiles/strategy.dir/strategy/strategy.c.o.provides.build
.PHONY : CMakeFiles/strategy.dir/strategy/strategy.c.o.provides

CMakeFiles/strategy.dir/strategy/strategy.c.o.provides.build: CMakeFiles/strategy.dir/strategy/strategy.c.o

# Object files for target strategy
strategy_OBJECTS = \
"CMakeFiles/strategy.dir/strategy/strategy.c.o"

# External object files for target strategy
strategy_EXTERNAL_OBJECTS =

libstrategy.a: CMakeFiles/strategy.dir/strategy/strategy.c.o
libstrategy.a: CMakeFiles/strategy.dir/build.make
libstrategy.a: CMakeFiles/strategy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C static library libstrategy.a"
	$(CMAKE_COMMAND) -P CMakeFiles/strategy.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strategy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strategy.dir/build: libstrategy.a
.PHONY : CMakeFiles/strategy.dir/build

CMakeFiles/strategy.dir/requires: CMakeFiles/strategy.dir/strategy/strategy.c.o.requires
.PHONY : CMakeFiles/strategy.dir/requires

CMakeFiles/strategy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/strategy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/strategy.dir/clean

CMakeFiles/strategy.dir/depend:
	cd /Users/damien/Documents/L2S2/ProjetProg/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/damien/Documents/L2S2/ProjetProg /Users/damien/Documents/L2S2/ProjetProg /Users/damien/Documents/L2S2/ProjetProg/build /Users/damien/Documents/L2S2/ProjetProg/build /Users/damien/Documents/L2S2/ProjetProg/build/CMakeFiles/strategy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/strategy.dir/depend

