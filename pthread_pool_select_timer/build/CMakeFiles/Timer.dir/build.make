# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/sunyingchun/share/thread_timer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sunyingchun/share/thread_timer/build

# Include any dependencies generated for this target.
include CMakeFiles/Timer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Timer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Timer.dir/flags.make

CMakeFiles/Timer.dir/src/main.c.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunyingchun/share/thread_timer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Timer.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Timer.dir/src/main.c.o   -c /home/sunyingchun/share/thread_timer/src/main.c

CMakeFiles/Timer.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Timer.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunyingchun/share/thread_timer/src/main.c > CMakeFiles/Timer.dir/src/main.c.i

CMakeFiles/Timer.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Timer.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunyingchun/share/thread_timer/src/main.c -o CMakeFiles/Timer.dir/src/main.c.s

CMakeFiles/Timer.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/Timer.dir/src/main.c.o.requires

CMakeFiles/Timer.dir/src/main.c.o.provides: CMakeFiles/Timer.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/Timer.dir/src/main.c.o.provides

CMakeFiles/Timer.dir/src/main.c.o.provides.build: CMakeFiles/Timer.dir/src/main.c.o


CMakeFiles/Timer.dir/src/pthread_pool.c.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/src/pthread_pool.c.o: ../src/pthread_pool.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunyingchun/share/thread_timer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Timer.dir/src/pthread_pool.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Timer.dir/src/pthread_pool.c.o   -c /home/sunyingchun/share/thread_timer/src/pthread_pool.c

CMakeFiles/Timer.dir/src/pthread_pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Timer.dir/src/pthread_pool.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunyingchun/share/thread_timer/src/pthread_pool.c > CMakeFiles/Timer.dir/src/pthread_pool.c.i

CMakeFiles/Timer.dir/src/pthread_pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Timer.dir/src/pthread_pool.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunyingchun/share/thread_timer/src/pthread_pool.c -o CMakeFiles/Timer.dir/src/pthread_pool.c.s

CMakeFiles/Timer.dir/src/pthread_pool.c.o.requires:

.PHONY : CMakeFiles/Timer.dir/src/pthread_pool.c.o.requires

CMakeFiles/Timer.dir/src/pthread_pool.c.o.provides: CMakeFiles/Timer.dir/src/pthread_pool.c.o.requires
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/src/pthread_pool.c.o.provides.build
.PHONY : CMakeFiles/Timer.dir/src/pthread_pool.c.o.provides

CMakeFiles/Timer.dir/src/pthread_pool.c.o.provides.build: CMakeFiles/Timer.dir/src/pthread_pool.c.o


CMakeFiles/Timer.dir/src/timer_select.c.o: CMakeFiles/Timer.dir/flags.make
CMakeFiles/Timer.dir/src/timer_select.c.o: ../src/timer_select.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sunyingchun/share/thread_timer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Timer.dir/src/timer_select.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Timer.dir/src/timer_select.c.o   -c /home/sunyingchun/share/thread_timer/src/timer_select.c

CMakeFiles/Timer.dir/src/timer_select.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Timer.dir/src/timer_select.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/sunyingchun/share/thread_timer/src/timer_select.c > CMakeFiles/Timer.dir/src/timer_select.c.i

CMakeFiles/Timer.dir/src/timer_select.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Timer.dir/src/timer_select.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/sunyingchun/share/thread_timer/src/timer_select.c -o CMakeFiles/Timer.dir/src/timer_select.c.s

CMakeFiles/Timer.dir/src/timer_select.c.o.requires:

.PHONY : CMakeFiles/Timer.dir/src/timer_select.c.o.requires

CMakeFiles/Timer.dir/src/timer_select.c.o.provides: CMakeFiles/Timer.dir/src/timer_select.c.o.requires
	$(MAKE) -f CMakeFiles/Timer.dir/build.make CMakeFiles/Timer.dir/src/timer_select.c.o.provides.build
.PHONY : CMakeFiles/Timer.dir/src/timer_select.c.o.provides

CMakeFiles/Timer.dir/src/timer_select.c.o.provides.build: CMakeFiles/Timer.dir/src/timer_select.c.o


# Object files for target Timer
Timer_OBJECTS = \
"CMakeFiles/Timer.dir/src/main.c.o" \
"CMakeFiles/Timer.dir/src/pthread_pool.c.o" \
"CMakeFiles/Timer.dir/src/timer_select.c.o"

# External object files for target Timer
Timer_EXTERNAL_OBJECTS =

Timer: CMakeFiles/Timer.dir/src/main.c.o
Timer: CMakeFiles/Timer.dir/src/pthread_pool.c.o
Timer: CMakeFiles/Timer.dir/src/timer_select.c.o
Timer: CMakeFiles/Timer.dir/build.make
Timer: CMakeFiles/Timer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sunyingchun/share/thread_timer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Timer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Timer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Timer.dir/build: Timer

.PHONY : CMakeFiles/Timer.dir/build

CMakeFiles/Timer.dir/requires: CMakeFiles/Timer.dir/src/main.c.o.requires
CMakeFiles/Timer.dir/requires: CMakeFiles/Timer.dir/src/pthread_pool.c.o.requires
CMakeFiles/Timer.dir/requires: CMakeFiles/Timer.dir/src/timer_select.c.o.requires

.PHONY : CMakeFiles/Timer.dir/requires

CMakeFiles/Timer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Timer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Timer.dir/clean

CMakeFiles/Timer.dir/depend:
	cd /home/sunyingchun/share/thread_timer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sunyingchun/share/thread_timer /home/sunyingchun/share/thread_timer /home/sunyingchun/share/thread_timer/build /home/sunyingchun/share/thread_timer/build /home/sunyingchun/share/thread_timer/build/CMakeFiles/Timer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Timer.dir/depend

