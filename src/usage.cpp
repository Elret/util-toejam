#include "usage.h"

void Usage::show() {
    std::cout << "Usage:\n\n"
    "syntax:  toejam <command> <name>\n\n"
    "<Command>\n\n"
    "create:\t\t\tCreates a new project, including setting up directories and creating a makefile\n"
    "add:\t\t\tAdds a new .cpp and .h file to the src directory\n"
    "add_lib:\t\tAdds a library include in the makefile. IE: -lboost_filesystem\n"
    "build:\t\t\tRebuilds the makefile.\n\n"
    "Example:\t\t\"toejam create myProject\"\n";
}