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
CMAKE_SOURCE_DIR = /home/llw/Project/Face_cmake/Face_Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/llw/Project/Face_cmake/Face_Server/bin

# Include any dependencies generated for this target.
include src/CMakeFiles/Face_Server.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Face_Server.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Face_Server.dir/flags.make

src/CMakeFiles/Face_Server.dir/server_basic.cpp.o: src/CMakeFiles/Face_Server.dir/flags.make
src/CMakeFiles/Face_Server.dir/server_basic.cpp.o: ../src/server_basic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llw/Project/Face_cmake/Face_Server/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Face_Server.dir/server_basic.cpp.o"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Face_Server.dir/server_basic.cpp.o -c /home/llw/Project/Face_cmake/Face_Server/src/server_basic.cpp

src/CMakeFiles/Face_Server.dir/server_basic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Face_Server.dir/server_basic.cpp.i"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llw/Project/Face_cmake/Face_Server/src/server_basic.cpp > CMakeFiles/Face_Server.dir/server_basic.cpp.i

src/CMakeFiles/Face_Server.dir/server_basic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Face_Server.dir/server_basic.cpp.s"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llw/Project/Face_cmake/Face_Server/src/server_basic.cpp -o CMakeFiles/Face_Server.dir/server_basic.cpp.s

src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.requires:

.PHONY : src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.requires

src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.provides: src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Face_Server.dir/build.make src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.provides.build
.PHONY : src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.provides

src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.provides.build: src/CMakeFiles/Face_Server.dir/server_basic.cpp.o


src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o: src/CMakeFiles/Face_Server.dir/flags.make
src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o: ../src/facerecognize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llw/Project/Face_cmake/Face_Server/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Face_Server.dir/facerecognize.cpp.o -c /home/llw/Project/Face_cmake/Face_Server/src/facerecognize.cpp

src/CMakeFiles/Face_Server.dir/facerecognize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Face_Server.dir/facerecognize.cpp.i"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llw/Project/Face_cmake/Face_Server/src/facerecognize.cpp > CMakeFiles/Face_Server.dir/facerecognize.cpp.i

src/CMakeFiles/Face_Server.dir/facerecognize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Face_Server.dir/facerecognize.cpp.s"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llw/Project/Face_cmake/Face_Server/src/facerecognize.cpp -o CMakeFiles/Face_Server.dir/facerecognize.cpp.s

src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.requires:

.PHONY : src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.requires

src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.provides: src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Face_Server.dir/build.make src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.provides.build
.PHONY : src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.provides

src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.provides.build: src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o


src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o: src/CMakeFiles/Face_Server.dir/flags.make
src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o: ../src/ExtractFeature.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llw/Project/Face_cmake/Face_Server/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o -c /home/llw/Project/Face_cmake/Face_Server/src/ExtractFeature.cpp

src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Face_Server.dir/ExtractFeature.cpp.i"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llw/Project/Face_cmake/Face_Server/src/ExtractFeature.cpp > CMakeFiles/Face_Server.dir/ExtractFeature.cpp.i

src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Face_Server.dir/ExtractFeature.cpp.s"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llw/Project/Face_cmake/Face_Server/src/ExtractFeature.cpp -o CMakeFiles/Face_Server.dir/ExtractFeature.cpp.s

src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.requires:

.PHONY : src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.requires

src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.provides: src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Face_Server.dir/build.make src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.provides.build
.PHONY : src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.provides

src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.provides.build: src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o


src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o: src/CMakeFiles/Face_Server.dir/flags.make
src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o: ../src/wcdCFacerecognize.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/llw/Project/Face_cmake/Face_Server/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o -c /home/llw/Project/Face_cmake/Face_Server/src/wcdCFacerecognize.cpp

src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.i"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/llw/Project/Face_cmake/Face_Server/src/wcdCFacerecognize.cpp > CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.i

src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.s"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/llw/Project/Face_cmake/Face_Server/src/wcdCFacerecognize.cpp -o CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.s

src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.requires:

.PHONY : src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.requires

src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.provides: src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/Face_Server.dir/build.make src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.provides.build
.PHONY : src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.provides

src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.provides.build: src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o


# Object files for target Face_Server
Face_Server_OBJECTS = \
"CMakeFiles/Face_Server.dir/server_basic.cpp.o" \
"CMakeFiles/Face_Server.dir/facerecognize.cpp.o" \
"CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o" \
"CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o"

# External object files for target Face_Server
Face_Server_EXTERNAL_OBJECTS =

src/bin/Face_Server: src/CMakeFiles/Face_Server.dir/server_basic.cpp.o
src/bin/Face_Server: src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o
src/bin/Face_Server: src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o
src/bin/Face_Server: src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o
src/bin/Face_Server: src/CMakeFiles/Face_Server.dir/build.make
src/bin/Face_Server: /home/llw/software/muduo-master/build/release-install/lib/libmuduo_net.a
src/bin/Face_Server: /home/llw/software/muduo-master/build/release-install/lib/libmuduo_base.a
src/bin/Face_Server: /usr/local/lib/libopencv_videostab.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_ts.a
src/bin/Face_Server: /usr/local/lib/libopencv_superres.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_stitching.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_contrib.so.2.4.10
src/bin/Face_Server: /home/llw/caffe/cbuild/lib/libcaffe.so.1.0.0
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libGLU.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libGL.so
src/bin/Face_Server: /usr/local/lib/libopencv_nonfree.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_ocl.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_gpu.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_photo.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_objdetect.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_legacy.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_video.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_ml.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_calib3d.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_features2d.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_flann.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_highgui.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_imgproc.so.2.4.10
src/bin/Face_Server: /usr/local/lib/libopencv_core.so.2.4.10
src/bin/Face_Server: /home/llw/caffe/cbuild/lib/libcaffeproto.a
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_system.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_thread.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libpthread.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libglog.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libgflags.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5_hl.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libsz.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libz.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libdl.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libm.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libpthread.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libglog.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libgflags.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5_hl.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/hdf5/serial/lib/libhdf5.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libsz.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libz.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libdl.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libm.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libprotobuf.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/liblmdb.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libleveldb.so
src/bin/Face_Server: /usr/lib/liblapack.so
src/bin/Face_Server: /usr/lib/libcblas.so
src/bin/Face_Server: /usr/lib/libatlas.so
src/bin/Face_Server: /usr/lib/x86_64-linux-gnu/libboost_python.so
src/bin/Face_Server: src/CMakeFiles/Face_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/llw/Project/Face_cmake/Face_Server/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bin/Face_Server"
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Face_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Face_Server.dir/build: src/bin/Face_Server

.PHONY : src/CMakeFiles/Face_Server.dir/build

src/CMakeFiles/Face_Server.dir/requires: src/CMakeFiles/Face_Server.dir/server_basic.cpp.o.requires
src/CMakeFiles/Face_Server.dir/requires: src/CMakeFiles/Face_Server.dir/facerecognize.cpp.o.requires
src/CMakeFiles/Face_Server.dir/requires: src/CMakeFiles/Face_Server.dir/ExtractFeature.cpp.o.requires
src/CMakeFiles/Face_Server.dir/requires: src/CMakeFiles/Face_Server.dir/wcdCFacerecognize.cpp.o.requires

.PHONY : src/CMakeFiles/Face_Server.dir/requires

src/CMakeFiles/Face_Server.dir/clean:
	cd /home/llw/Project/Face_cmake/Face_Server/bin/src && $(CMAKE_COMMAND) -P CMakeFiles/Face_Server.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Face_Server.dir/clean

src/CMakeFiles/Face_Server.dir/depend:
	cd /home/llw/Project/Face_cmake/Face_Server/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/llw/Project/Face_cmake/Face_Server /home/llw/Project/Face_cmake/Face_Server/src /home/llw/Project/Face_cmake/Face_Server/bin /home/llw/Project/Face_cmake/Face_Server/bin/src /home/llw/Project/Face_cmake/Face_Server/bin/src/CMakeFiles/Face_Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Face_Server.dir/depend

