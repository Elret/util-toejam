#include "create.h"


Create::Create(std::string passed_name) {
    project_name = passed_name;
}

void Create::create_cpp_file() {
    std::ofstream file;
    std::string filename = "src/";
    filename.append(project_name);
    filename.append(".cpp");
    file.open(filename, std::ios::out | std::ios::app);
    file << output_cpp();
    file.close();
}

void Create::create_h_file() {
    std::ofstream file;
    std::string filename = "src/";
    filename.append(project_name);
    filename.append(".h");
    file.open(filename, std::ios::out | std::ios::app);
    file.close();
}

void Create::create_makefile() {
    //todo: create makefile.
}

void Create::create_project() {
    boost::filesystem::create_directory("src");
    create_cpp_file();
    create_h_file();
}

std::string Create::output_cpp() {
    std::string string_to_return = "#include \"";
    string_to_return.append(project_name);
    string_to_return.append(".h\"");
    return string_to_return;
}

void Create::add_file() {
    create_cpp_file();
    create_h_file();
}

void add_lib() {
    //todo: add external library to makefile.
}