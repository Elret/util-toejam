#ifndef ARGS_H
#define ARGS_H

#include <string>
#include <iostream>

class Args {
    private:
    bool parse_command(char *argv[]);
    bool parse_name(char *argv[]);
    std::string project_name = "empty";


    public:
    bool create;
    bool add;
    bool add_lib;
    bool help;
    bool build;

    bool parse_args(int argc, char *argv[]);
    std::string return_project_name();
};


#endif