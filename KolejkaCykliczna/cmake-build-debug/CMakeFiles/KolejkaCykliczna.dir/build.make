# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Programy\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programy\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\C++\AiSD_I\KolejkaCykliczna

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\C++\AiSD_I\KolejkaCykliczna\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/KolejkaCykliczna.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/KolejkaCykliczna.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KolejkaCykliczna.dir/flags.make

CMakeFiles/KolejkaCykliczna.dir/main.cpp.obj: CMakeFiles/KolejkaCykliczna.dir/flags.make
CMakeFiles/KolejkaCykliczna.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\C++\AiSD_I\KolejkaCykliczna\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KolejkaCykliczna.dir/main.cpp.obj"
	D:\Programy\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\KolejkaCykliczna.dir\main.cpp.obj -c E:\C++\AiSD_I\KolejkaCykliczna\main.cpp

CMakeFiles/KolejkaCykliczna.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KolejkaCykliczna.dir/main.cpp.i"
	D:\Programy\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\C++\AiSD_I\KolejkaCykliczna\main.cpp > CMakeFiles\KolejkaCykliczna.dir\main.cpp.i

CMakeFiles/KolejkaCykliczna.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KolejkaCykliczna.dir/main.cpp.s"
	D:\Programy\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\C++\AiSD_I\KolejkaCykliczna\main.cpp -o CMakeFiles\KolejkaCykliczna.dir\main.cpp.s

# Object files for target KolejkaCykliczna
KolejkaCykliczna_OBJECTS = \
"CMakeFiles/KolejkaCykliczna.dir/main.cpp.obj"

# External object files for target KolejkaCykliczna
KolejkaCykliczna_EXTERNAL_OBJECTS =

KolejkaCykliczna.exe: CMakeFiles/KolejkaCykliczna.dir/main.cpp.obj
KolejkaCykliczna.exe: CMakeFiles/KolejkaCykliczna.dir/build.make
KolejkaCykliczna.exe: CMakeFiles/KolejkaCykliczna.dir/linklibs.rsp
KolejkaCykliczna.exe: CMakeFiles/KolejkaCykliczna.dir/objects1.rsp
KolejkaCykliczna.exe: CMakeFiles/KolejkaCykliczna.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\C++\AiSD_I\KolejkaCykliczna\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable KolejkaCykliczna.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\KolejkaCykliczna.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KolejkaCykliczna.dir/build: KolejkaCykliczna.exe
.PHONY : CMakeFiles/KolejkaCykliczna.dir/build

CMakeFiles/KolejkaCykliczna.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\KolejkaCykliczna.dir\cmake_clean.cmake
.PHONY : CMakeFiles/KolejkaCykliczna.dir/clean

CMakeFiles/KolejkaCykliczna.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\C++\AiSD_I\KolejkaCykliczna E:\C++\AiSD_I\KolejkaCykliczna E:\C++\AiSD_I\KolejkaCykliczna\cmake-build-debug E:\C++\AiSD_I\KolejkaCykliczna\cmake-build-debug E:\C++\AiSD_I\KolejkaCykliczna\cmake-build-debug\CMakeFiles\KolejkaCykliczna.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KolejkaCykliczna.dir/depend
