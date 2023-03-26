# Intro to CMake

March 25, 2023

Internal course for introducing CMake. 

The course material will be updated and hosted as a public repo on GitHub at https://github.com/jharoian-mchp/IntroToCMake

## Prerequisites

Install the following programs and packages.  Any MPLAB X supported platform can be used.  Platform diversity is encouraged for the course.

### Programs to install

- MPLAB X v6.05
  - https://www.microchip.com/mplabx
  - Update CMSIS to v5.8.0 from Packs under Tools menu
- XC32 v4.21
  - https://www.microchip.com/xc32
- Visual Studio Code
  - https://code.visualstudio.com/
  - Extensions:
    - C/C++ by Microsoft (not C/C++ Extension Pack - keep it simple)
    - CMake Tools by Microsoft
- CMake v3.19 or newer
  - https://cmake.org/install/
- Ninja v1.11.1 or newer
  - https://ninja-build.org/
  - For Windows users, place ninja.exe in C:\Users\C14029\\.local\bin - may need to create and add to path
- Git v2.40.0 or newer
  - https://git-scm.com/downloads

### Testing install

Launch a terminal program for your platform and execute the following commands to test each of the above programs.

```
C:\Users\C14029>xc32-gcc --version
pic32m-gcc.exe (Microchip XC32 Compiler v4.21) 8.3.1 Build date: Dec  5 2022
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

C:\Users\C14029>cmake --version
cmake version 3.25.3

CMake suite maintained and supported by Kitware (kitware.com/cmake).

C:\Users\C14029>ninja --version
1.11.1.git.kitware.jobserver-1

C:\Users\C14029>git --version
git version 2.40.0.windows.1
```

### Hardware Required

The course uses the [SAME54 Xplained Pro Evaluation Kit.](https://www.microchip.com/en-us/development-tool/ATSAME54-XPRO)  The board features the ATSAME54P20A and contains an USB connected embedded debugger which will be used in the course.

## References

- [Professional CMake 14th Edition](https://crascit.com/professional-cmake/)

