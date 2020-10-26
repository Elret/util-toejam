#include "makefile.h"

void Makefile::create_project_file(std::string input_name) {
    std::ofstream file;
    file.open(".toejam/project");
    file << input_name;
    file.close();
}

void Makefile::create_libs_file() {
    std::ofstream file;
    file.open(".toejam/libs");
    file << " ";
    file.close();
}


void Makefile::create_makefile(std::string input_name) {
       create_project_file(input_name);
       create_libs_file();
       build_makefile();
}

std::string Makefile::return_project_name() {
    std::ifstream file;
    file.open(".toejam/project");
    std::string line;
    getline(file, line);
    file.close();
    return line;
}

std::string Makefile::return_project_libs() {
    std::ifstream file;
    file.open(".toejam/libs");
    std::string line;
    std::string return_str;
    while(getline(file, line)) {
        return_str.append(line);
        return_str.append(" ");
    }
    file.close();
    return return_str;
}

void Makefile::build_makefile() {
    std::string *line = new std::string;
    Linked_List *cpp_list = new Linked_List;
    Linked_List *h_list = new Linked_List;
    File_Scan fs(h_list, cpp_list);
    fs.search();

    std::ofstream write_file;
    write_file.open("Makefile");
    write_file << "CC = g++" << std::endl;
    write_file << "SRC = src/" << std::endl;
    write_file << "BUILD = .toejam/build/" << std::endl;
    write_file << "LIBS = ";

    write_file << return_project_libs();
    
    write_file << std::endl;
    write_file << "DEPS = ";
    h_list->reset_list();
    while (h_list->read_from_list(line)) {
        write_file << "$(SRC)" << *line << " ";
    }
    write_file << std::endl << std::endl;
    cpp_list->reset_list();
    write_file <<  return_project_name() << ":";
    while (cpp_list->read_from_list(line)) {
    write_file << " $(BUILD)" << *line <<".o";
    }
    write_file << std::endl;
    write_file << return_main_compile_str(return_project_name()) << std::endl << std::endl;
    cpp_list->reset_list();
    while (cpp_list->read_from_list(line)) {
        write_file << return_o_compile_str(*line) << std::endl << std::endl;
    }
    write_file.close();
}



std::string Makefile::return_main_compile_str(std::string project_name) {
    std::string return_str;
    return_str = "\t$(CC) -o ";
    return_str.append(project_name);
    return_str.append(" $^");
    return_str.append(" $(LIBS)");
    return return_str;
}

std::string Makefile::return_o_compile_str(std::string o_name) {
    std::string return_str;
    return_str = "$(BUILD)";
    return_str.append(o_name);
    return_str.append(".o: $(SRC)");
    return_str.append(o_name);
    return_str.append(".cpp $(DEPS)\n");
    return_str.append("\t$(CC) -c $(SRC)");
    return_str.append(o_name);
    return_str.append(".cpp -o $@");
    return return_str;
}