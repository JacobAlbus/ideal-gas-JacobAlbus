# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\ideal-gas-visualizer.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\ideal-gas-visualizer.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\ideal-gas-visualizer.dir\flags.make

CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.obj: CMakeFiles\ideal-gas-visualizer.dir\flags.make
CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.obj: ..\ideal_gas_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ideal-gas-visualizer.dir/ideal_gas_main.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.obj /FdCMakeFiles\ideal-gas-visualizer.dir\ /FS -c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\ideal_gas_main.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-visualizer.dir/ideal_gas_main.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\ideal_gas_main.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-visualizer.dir/ideal_gas_main.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.s /c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\ideal_gas_main.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.obj: CMakeFiles\ideal-gas-visualizer.dir\flags.make
CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.obj: ..\src\gui\ideal_gas_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ideal-gas-visualizer.dir/src/gui/ideal_gas_app.cc.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.obj /FdCMakeFiles\ideal-gas-visualizer.dir\ /FS -c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\gui\ideal_gas_app.cc
<<

CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-visualizer.dir/src/gui/ideal_gas_app.cc.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\gui\ideal_gas_app.cc
<<

CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-visualizer.dir/src/gui/ideal_gas_app.cc.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.s /c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\gui\ideal_gas_app.cc
<<

CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.obj: CMakeFiles\ideal-gas-visualizer.dir\flags.make
CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.obj: ..\src\gui\sketchpad.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ideal-gas-visualizer.dir/src/gui/sketchpad.cc.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.obj /FdCMakeFiles\ideal-gas-visualizer.dir\ /FS -c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\gui\sketchpad.cc
<<

CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-visualizer.dir/src/gui/sketchpad.cc.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\gui\sketchpad.cc
<<

CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-visualizer.dir/src/gui/sketchpad.cc.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.s /c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\gui\sketchpad.cc
<<

CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.obj: CMakeFiles\ideal-gas-visualizer.dir\flags.make
CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.obj: ..\src\engine\particle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ideal-gas-visualizer.dir/src/engine/particle.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.obj /FdCMakeFiles\ideal-gas-visualizer.dir\ /FS -c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\engine\particle.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-visualizer.dir/src/engine/particle.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\engine\particle.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-visualizer.dir/src/engine/particle.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.s /c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\engine\particle.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.obj: CMakeFiles\ideal-gas-visualizer.dir\flags.make
CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.obj: ..\src\engine\simulation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/ideal-gas-visualizer.dir/src/engine/simulation.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.obj /FdCMakeFiles\ideal-gas-visualizer.dir\ /FS -c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\engine\simulation.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ideal-gas-visualizer.dir/src/engine/simulation.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\engine\simulation.cpp
<<

CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ideal-gas-visualizer.dir/src/engine/simulation.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.s /c C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\src\engine\simulation.cpp
<<

# Object files for target ideal-gas-visualizer
ideal__gas__visualizer_OBJECTS = \
"CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.obj" \
"CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.obj" \
"CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.obj" \
"CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.obj" \
"CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.obj"

# External object files for target ideal-gas-visualizer
ideal__gas__visualizer_EXTERNAL_OBJECTS =

Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\ideal_gas_main.cpp.obj
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\src\gui\ideal_gas_app.cc.obj
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\src\gui\sketchpad.cc.obj
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\src\engine\particle.cpp.obj
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\src\engine\simulation.cpp.obj
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\build.make
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\lib\msw\x86\Debug\v140\cinder.lib
Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe: CMakeFiles\ideal-gas-visualizer.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\ideal-gas-visualizer.dir --rc=C:\PROGRA~2\WI3CF2~1\8.1\bin\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\8.1\bin\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\ideal-gas-visualizer.dir\objects1.rsp @<<
 /out:Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe /implib:ideal-gas-visualizer.lib /pdb:C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\Debug\ideal-gas-visualizer\ideal-gas-visualizer.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:windows /NODEFAULTLIB:LIBCMT /NODEFAULTLIB:LIBCPMT   -LIBPATH:C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\lib\msw\x86  C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\lib\msw\x86\Debug\v140\cinder.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\ideal-gas-visualizer.dir\build: Debug\ideal-gas-visualizer\ideal-gas-visualizer.exe

.PHONY : CMakeFiles\ideal-gas-visualizer.dir\build

CMakeFiles\ideal-gas-visualizer.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ideal-gas-visualizer.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ideal-gas-visualizer.dir\clean

CMakeFiles\ideal-gas-visualizer.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug C:\Users\asus\CLionProjects\cinder_0.9.2_vc2015\my-projects\ideal-gas-JacobAlbus\cmake-build-debug\CMakeFiles\ideal-gas-visualizer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\ideal-gas-visualizer.dir\depend

