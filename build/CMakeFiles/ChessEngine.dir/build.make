# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adam/Desktop/chess_engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adam/Desktop/chess_engine/build

# Include any dependencies generated for this target.
include CMakeFiles/ChessEngine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ChessEngine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ChessEngine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ChessEngine.dir/flags.make

CMakeFiles/ChessEngine.dir/main.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/main.cpp.o: ../main.cpp
CMakeFiles/ChessEngine.dir/main.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Desktop/chess_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ChessEngine.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/main.cpp.o -MF CMakeFiles/ChessEngine.dir/main.cpp.o.d -o CMakeFiles/ChessEngine.dir/main.cpp.o -c /home/adam/Desktop/chess_engine/main.cpp

CMakeFiles/ChessEngine.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Desktop/chess_engine/main.cpp > CMakeFiles/ChessEngine.dir/main.cpp.i

CMakeFiles/ChessEngine.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Desktop/chess_engine/main.cpp -o CMakeFiles/ChessEngine.dir/main.cpp.s

CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o: ../ChessEngine.cpp
CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Desktop/chess_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o -MF CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o.d -o CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o -c /home/adam/Desktop/chess_engine/ChessEngine.cpp

CMakeFiles/ChessEngine.dir/ChessEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/ChessEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Desktop/chess_engine/ChessEngine.cpp > CMakeFiles/ChessEngine.dir/ChessEngine.cpp.i

CMakeFiles/ChessEngine.dir/ChessEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/ChessEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Desktop/chess_engine/ChessEngine.cpp -o CMakeFiles/ChessEngine.dir/ChessEngine.cpp.s

CMakeFiles/ChessEngine.dir/Board.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/Board.cpp.o: ../Board.cpp
CMakeFiles/ChessEngine.dir/Board.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Desktop/chess_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ChessEngine.dir/Board.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/Board.cpp.o -MF CMakeFiles/ChessEngine.dir/Board.cpp.o.d -o CMakeFiles/ChessEngine.dir/Board.cpp.o -c /home/adam/Desktop/chess_engine/Board.cpp

CMakeFiles/ChessEngine.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Desktop/chess_engine/Board.cpp > CMakeFiles/ChessEngine.dir/Board.cpp.i

CMakeFiles/ChessEngine.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Desktop/chess_engine/Board.cpp -o CMakeFiles/ChessEngine.dir/Board.cpp.s

CMakeFiles/ChessEngine.dir/core.cpp.o: CMakeFiles/ChessEngine.dir/flags.make
CMakeFiles/ChessEngine.dir/core.cpp.o: ../core.cpp
CMakeFiles/ChessEngine.dir/core.cpp.o: CMakeFiles/ChessEngine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adam/Desktop/chess_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ChessEngine.dir/core.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/ChessEngine.dir/core.cpp.o -MF CMakeFiles/ChessEngine.dir/core.cpp.o.d -o CMakeFiles/ChessEngine.dir/core.cpp.o -c /home/adam/Desktop/chess_engine/core.cpp

CMakeFiles/ChessEngine.dir/core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ChessEngine.dir/core.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adam/Desktop/chess_engine/core.cpp > CMakeFiles/ChessEngine.dir/core.cpp.i

CMakeFiles/ChessEngine.dir/core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ChessEngine.dir/core.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adam/Desktop/chess_engine/core.cpp -o CMakeFiles/ChessEngine.dir/core.cpp.s

# Object files for target ChessEngine
ChessEngine_OBJECTS = \
"CMakeFiles/ChessEngine.dir/main.cpp.o" \
"CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o" \
"CMakeFiles/ChessEngine.dir/Board.cpp.o" \
"CMakeFiles/ChessEngine.dir/core.cpp.o"

# External object files for target ChessEngine
ChessEngine_EXTERNAL_OBJECTS =

ChessEngine: CMakeFiles/ChessEngine.dir/main.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/ChessEngine.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/Board.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/core.cpp.o
ChessEngine: CMakeFiles/ChessEngine.dir/build.make
ChessEngine: CMakeFiles/ChessEngine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adam/Desktop/chess_engine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ChessEngine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ChessEngine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ChessEngine.dir/build: ChessEngine
.PHONY : CMakeFiles/ChessEngine.dir/build

CMakeFiles/ChessEngine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ChessEngine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ChessEngine.dir/clean

CMakeFiles/ChessEngine.dir/depend:
	cd /home/adam/Desktop/chess_engine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adam/Desktop/chess_engine /home/adam/Desktop/chess_engine /home/adam/Desktop/chess_engine/build /home/adam/Desktop/chess_engine/build /home/adam/Desktop/chess_engine/build/CMakeFiles/ChessEngine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ChessEngine.dir/depend

