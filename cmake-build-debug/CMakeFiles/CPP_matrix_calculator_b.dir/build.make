# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CPP_matrix_calculator_b.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPP_matrix_calculator_b.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPP_matrix_calculator_b.dir/flags.make

CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.o: CMakeFiles/CPP_matrix_calculator_b.dir/flags.make
CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.o: ../sources/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.o -c /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/sources/main.cpp

CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/sources/main.cpp > CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.i

CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/sources/main.cpp -o CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.s

CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.o: CMakeFiles/CPP_matrix_calculator_b.dir/flags.make
CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.o: ../sources/Matrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.o -c /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/sources/Matrix.cpp

CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/sources/Matrix.cpp > CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.i

CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/sources/Matrix.cpp -o CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.s

# Object files for target CPP_matrix_calculator_b
CPP_matrix_calculator_b_OBJECTS = \
"CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.o" \
"CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.o"

# External object files for target CPP_matrix_calculator_b
CPP_matrix_calculator_b_EXTERNAL_OBJECTS =

CPP_matrix_calculator_b: CMakeFiles/CPP_matrix_calculator_b.dir/sources/main.cpp.o
CPP_matrix_calculator_b: CMakeFiles/CPP_matrix_calculator_b.dir/sources/Matrix.cpp.o
CPP_matrix_calculator_b: CMakeFiles/CPP_matrix_calculator_b.dir/build.make
CPP_matrix_calculator_b: CMakeFiles/CPP_matrix_calculator_b.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CPP_matrix_calculator_b"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPP_matrix_calculator_b.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPP_matrix_calculator_b.dir/build: CPP_matrix_calculator_b

.PHONY : CMakeFiles/CPP_matrix_calculator_b.dir/build

CMakeFiles/CPP_matrix_calculator_b.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPP_matrix_calculator_b.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPP_matrix_calculator_b.dir/clean

CMakeFiles/CPP_matrix_calculator_b.dir/depend:
	cd /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug /mnt/c/Users/barak/Documents/GitHub/CPP_matrix-calculator-b/cmake-build-debug/CMakeFiles/CPP_matrix_calculator_b.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPP_matrix_calculator_b.dir/depend

