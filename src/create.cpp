#include "create.h"

Create::Create(std::string from_project_name) {
project_name = from_project_name;
}

bool Create::create_project() {
  boost::filesystem::create_directory("src");
  boost::filesystem::create_directory("docs");
  boost::filesystem::create_directory("bin");
  create_cpp_file();
  create_h_file();  
  return true;
}

void Create::create_cpp_file() {
  std::ofstream ofile;
  std::string file_name_cpp = "src/";
  file_name_cpp.append(project_name);
  file_name_cpp.append(".cpp");
  ofile.open(file_name_cpp);
}

void Create::create_h_file() {
  std::string file_name_h = "src/";
  file_name_h.append(project_name);
  file_name_h.append(".h");
  std::ofstream ofile;
  ofile.open(file_name_h);
}

void Create::add_files_to_project() {
  create_cpp_file();
  create_h_file();
}

void Create::create_header_file() {
  create_h_file();
}