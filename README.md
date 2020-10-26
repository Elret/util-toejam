#ToeJam! v.0.8.2

Toejam was created to ease the process of creating projects for c++ by initializing a build folder, auto building a makefile, and creating new .cpp and .h files.

Example usage:

toejam create bob

This command would create a .toejam folder containing a build directory, and some project files for keeping track of libraries and the project name.  Also, it would create a src directory and build two files within it: bob.cpp and bob.h.  Finally it would create a Makefile.

Example Usage:

toejam add_lib -Wall

This command would add the -Wall flag to the makefile.

Example usage:

toejam build

This command would parse the files in the src directory and build a Makefile containing any .cpp and .h files.
Note: It will only parse the parent directory. As of right now it will not parse child directories.

Change Log:

0.8.3

-Fixed bug that would crash program if ran without arguments.

-Cleaned up some of the code base.

-Added recursive directory scanning
