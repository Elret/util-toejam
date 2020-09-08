#include "usage.h"

void Usage::run_usage() {
std::cout << "Usage: \n"
"Command: toejam <command> <name> <option>\n"
"\n"
"Available commands:\n"
"\n"
"create <name> \t\t Creates a new project, including src directories, and a makefile. \n"
"add <name> \t\t Adds a new .cpp file and corresponsing .h file in the src directory \n"
"header <name> \t\t Creates a only a .h file in the src directory \n"
"spec \t\t Opens up an editor with a template to create .spec files\n"
"author \t\t Places an saved AUTHOR.md file into the doc directory. To edit global author file use: --global author\n"
"--global \t\t Used to save global configs.  See: toejam --global --help\n"
"--debug \t\t Writes to a .log file in the main project folder.\n"; 
}