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
    Makefile makefile;
    makefile.create_makefile(project_name);
}

void Create::init_project() {
    boost::filesystem::create_directory(".toejam");
    boost::filesystem::create_directory(".toejam/build"); 
    boost::filesystem::create_directory(".toejam/log");
    //todo: create logging eventually.

}

void Create::create_project() {
    boost::filesystem::create_directory("src");
    boost::filesystem::create_directory("bin");
    create_cpp_file();
    create_h_file();
    init_project();
    add_lib();
    create_makefile();
    create_project_file();
    
}

void Create::build() {
    Makefile makefile;
    makefile.build_makefile();
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
    Makefile makefile;
    makefile.build_makefile();
}

void Create::add_cflag() {
    std::ofstream file;
    file.open(".toejam/cflag", std::ios::app);
    file << project_name << " ";
    file.close();
    Makefile makefile;
    makefile.build_makefile();
}

void Create::add_lib() {
    std::ofstream file;
    file.open(".toejam/libs", std::ios::app);
    file << project_name << " ";
    file.close();
    Makefile makefile;
    makefile.build_makefile();
}

void Create::create_project_file() {
    std::ofstream file;
    file.open(".toejam/project");
    file << project_name;
    file.close();
}