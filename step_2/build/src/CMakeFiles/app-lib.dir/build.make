# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zeyen/spack/opt/spack/linux-ubuntu20.04-skylake_avx512/gcc-9.4.0/cmake-3.26.3-btffk7zumt6qc5pzosjeyy2s5eqhki74/bin/cmake

# The command to remove a file.
RM = /home/zeyen/spack/opt/spack/linux-ubuntu20.04-skylake_avx512/gcc-9.4.0/cmake-3.26.3-btffk7zumt6qc5pzosjeyy2s5eqhki74/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zeyen/project/cppug-kl-0623/step_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zeyen/project/cppug-kl-0623/step_2/build

# Include any dependencies generated for this target.
include src/CMakeFiles/app-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/app-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/app-lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/app-lib.dir/flags.make

src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.o: src/CMakeFiles/app-lib.dir/flags.make
src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.o: /home/zeyen/project/cppug-kl-0623/step_2/src/ErrorHandler.cpp
src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.o: src/CMakeFiles/app-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeyen/project/cppug-kl-0623/step_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.o"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.o -MF CMakeFiles/app-lib.dir/ErrorHandler.cpp.o.d -o CMakeFiles/app-lib.dir/ErrorHandler.cpp.o -c /home/zeyen/project/cppug-kl-0623/step_2/src/ErrorHandler.cpp

src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app-lib.dir/ErrorHandler.cpp.i"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeyen/project/cppug-kl-0623/step_2/src/ErrorHandler.cpp > CMakeFiles/app-lib.dir/ErrorHandler.cpp.i

src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app-lib.dir/ErrorHandler.cpp.s"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeyen/project/cppug-kl-0623/step_2/src/ErrorHandler.cpp -o CMakeFiles/app-lib.dir/ErrorHandler.cpp.s

src/CMakeFiles/app-lib.dir/service/UserService.cpp.o: src/CMakeFiles/app-lib.dir/flags.make
src/CMakeFiles/app-lib.dir/service/UserService.cpp.o: /home/zeyen/project/cppug-kl-0623/step_2/src/service/UserService.cpp
src/CMakeFiles/app-lib.dir/service/UserService.cpp.o: src/CMakeFiles/app-lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zeyen/project/cppug-kl-0623/step_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/app-lib.dir/service/UserService.cpp.o"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/app-lib.dir/service/UserService.cpp.o -MF CMakeFiles/app-lib.dir/service/UserService.cpp.o.d -o CMakeFiles/app-lib.dir/service/UserService.cpp.o -c /home/zeyen/project/cppug-kl-0623/step_2/src/service/UserService.cpp

src/CMakeFiles/app-lib.dir/service/UserService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app-lib.dir/service/UserService.cpp.i"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zeyen/project/cppug-kl-0623/step_2/src/service/UserService.cpp > CMakeFiles/app-lib.dir/service/UserService.cpp.i

src/CMakeFiles/app-lib.dir/service/UserService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app-lib.dir/service/UserService.cpp.s"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zeyen/project/cppug-kl-0623/step_2/src/service/UserService.cpp -o CMakeFiles/app-lib.dir/service/UserService.cpp.s

# Object files for target app-lib
app__lib_OBJECTS = \
"CMakeFiles/app-lib.dir/ErrorHandler.cpp.o" \
"CMakeFiles/app-lib.dir/service/UserService.cpp.o"

# External object files for target app-lib
app__lib_EXTERNAL_OBJECTS =

src/libapp-lib.a: src/CMakeFiles/app-lib.dir/ErrorHandler.cpp.o
src/libapp-lib.a: src/CMakeFiles/app-lib.dir/service/UserService.cpp.o
src/libapp-lib.a: src/CMakeFiles/app-lib.dir/build.make
src/libapp-lib.a: src/CMakeFiles/app-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zeyen/project/cppug-kl-0623/step_2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libapp-lib.a"
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/app-lib.dir/cmake_clean_target.cmake
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/app-lib.dir/build: src/libapp-lib.a
.PHONY : src/CMakeFiles/app-lib.dir/build

src/CMakeFiles/app-lib.dir/clean:
	cd /home/zeyen/project/cppug-kl-0623/step_2/build/src && $(CMAKE_COMMAND) -P CMakeFiles/app-lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/app-lib.dir/clean

src/CMakeFiles/app-lib.dir/depend:
	cd /home/zeyen/project/cppug-kl-0623/step_2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zeyen/project/cppug-kl-0623/step_2 /home/zeyen/project/cppug-kl-0623/step_2/src /home/zeyen/project/cppug-kl-0623/step_2/build /home/zeyen/project/cppug-kl-0623/step_2/build/src /home/zeyen/project/cppug-kl-0623/step_2/build/src/CMakeFiles/app-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/app-lib.dir/depend

