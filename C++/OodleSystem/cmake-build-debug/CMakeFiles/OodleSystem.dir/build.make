# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/worlder/Documents/Language/C++/OodleSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OodleSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OodleSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OodleSystem.dir/flags.make

CMakeFiles/OodleSystem.dir/main.cpp.o: CMakeFiles/OodleSystem.dir/flags.make
CMakeFiles/OodleSystem.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OodleSystem.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OodleSystem.dir/main.cpp.o -c /Users/worlder/Documents/Language/C++/OodleSystem/main.cpp

CMakeFiles/OodleSystem.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OodleSystem.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/worlder/Documents/Language/C++/OodleSystem/main.cpp > CMakeFiles/OodleSystem.dir/main.cpp.i

CMakeFiles/OodleSystem.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OodleSystem.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/worlder/Documents/Language/C++/OodleSystem/main.cpp -o CMakeFiles/OodleSystem.dir/main.cpp.s

CMakeFiles/OodleSystem.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OodleSystem.dir/main.cpp.o.requires

CMakeFiles/OodleSystem.dir/main.cpp.o.provides: CMakeFiles/OodleSystem.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OodleSystem.dir/build.make CMakeFiles/OodleSystem.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OodleSystem.dir/main.cpp.o.provides

CMakeFiles/OodleSystem.dir/main.cpp.o.provides.build: CMakeFiles/OodleSystem.dir/main.cpp.o


# Object files for target OodleSystem
OodleSystem_OBJECTS = \
"CMakeFiles/OodleSystem.dir/main.cpp.o"

# External object files for target OodleSystem
OodleSystem_EXTERNAL_OBJECTS =

OodleSystem: CMakeFiles/OodleSystem.dir/main.cpp.o
OodleSystem: CMakeFiles/OodleSystem.dir/build.make
OodleSystem: CMakeFiles/OodleSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OodleSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OodleSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OodleSystem.dir/build: OodleSystem

.PHONY : CMakeFiles/OodleSystem.dir/build

CMakeFiles/OodleSystem.dir/requires: CMakeFiles/OodleSystem.dir/main.cpp.o.requires

.PHONY : CMakeFiles/OodleSystem.dir/requires

CMakeFiles/OodleSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OodleSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OodleSystem.dir/clean

CMakeFiles/OodleSystem.dir/depend:
	cd /Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/worlder/Documents/Language/C++/OodleSystem /Users/worlder/Documents/Language/C++/OodleSystem /Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug /Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug /Users/worlder/Documents/Language/C++/OodleSystem/cmake-build-debug/CMakeFiles/OodleSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OodleSystem.dir/depend

