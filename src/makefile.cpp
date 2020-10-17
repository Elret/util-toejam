#include "makefile.h"

void Makefile::create_project_file(std::string input_name) {
    std::ofstream file;
    file.open(".toejam/project");
    file << input_name;
    file.close();
}



void Makefile::create_makefile(std::string input_name) {
       create_project_file(input_name);
       build_makefile();
}

void Makefile::build_makefile() {
    std::string line;
    std::string project_name;
    std::ifstream project_file;
    project_file.open(".toejam/project");
    getline(project_file, project_name);
    project_file.close();
    std::ifstream libs_file;
    libs_file.open(".toejam/libs");
    Linked_List ll_libs;
    while (getline(libs_file, line)) {
        ll_libs.add_to_list(line);
    }
    ll_libs.reset_list();
    libs_file.close();
    
    std::ofstream write_file;
    write_file.open("Makefile");
    write_file << "CC = GCC" << std::endl;
    write_file << "LIBS = ";
    while (ll_libs.read_from_list(line)) {
        write_file << line << " ";
    }
    write_file << std::endl;
    write_file << project_name << ":";
    Linked_List ll_write_file_names;

    }

