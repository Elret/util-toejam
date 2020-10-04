#include "create.h"


Create::Create(std::string passed_name) {
    project_name = passed_name;
}

bool Create::create_project() {
    boost::filesystem::create_directory("src");
    std::ofstream file;
    std::string filename = "src/";
    filename.append(project_name);
    filename.append(".cpp");
    file.open(filename, std::ios::out | std::ios::app);
    file << output_cpp();
    return true;
}

std::string Create::output_cpp() {
    std::string string_to_return = "#include \"";
    string_to_return.append(project_name);
    string_to_return.append("\"");
    return string_to_return;

}