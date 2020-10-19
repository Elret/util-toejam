#include "args.h"

bool Args::parse_args(int argc, char *argv[]) {
    std::string is_help;
    is_help = argv[1];
    if (is_help == "help" || is_help == "build") {
        if (!parse_command(argv)) {
        return false;
        }
        return true;
    }
    else if (argc > 3 || argc < 3) {
        std::cout << "Invalid number of args" << std::endl;
        return false;
    } 
    if (!parse_command(argv)) {
        return false;
    }
    if (!parse_name(argv)) {
        return false;
    }
    
    return true;
}

bool Args::parse_command(char *argv[]) {
    std::string parse_command_name = argv[1];

    if (parse_command_name == "create") {
        create = true;
    } else if (parse_command_name =="add") {
        add = true;
    } else if (parse_command_name =="add_lib") {
        add_lib = true;
    } else if (parse_command_name =="help") {
        help = true;
    } else if (parse_command_name == "build") {
        build = true;
    } else {
        return false;
    }
    return true;
}

bool Args::parse_name(char *argv[]) {
    project_name = argv[2];
    return true;
}

std::string Args::return_project_name() {
    return project_name;
}