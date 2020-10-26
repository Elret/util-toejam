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

void Makefile::build_makefile() {
    std::string *line = new std::string;
    std::string project_name;
    std::ifstream project_file;
    project_file.open(".toejam/project");
    getline(project_file, *line);
    project_name = *line;
    
    project_file.close();

    std::ifstream libs_file;
    libs_file.open(".toejam/libs");
    Linked_List ll_libs;
    while (getline(libs_file, *line)) {
        ll_libs.add_to_list(*line);
    }
    ll_libs.reset_list();
    libs_file.close();
    
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

    while (ll_libs.read_from_list(line)) {
        write_file << *line << " ";
    }
    
    write_file << std::endl;
    write_file << "DEPS = ";
    h_list->reset_list();
    while (h_list->read_from_list(line)) {
        write_file << "$(SRC)" << *line << " ";
    }
    write_file << std::endl << std::endl;
    cpp_list->reset_list();
    write_file << project_name << ":";
    while (cpp_list->read_from_list(line)) {
    write_file << " $(BUILD)" << *line <<".o";
    }
    write_file << std::endl;
    write_file << return_main_compile_str(project_name) << std::endl << std::endl;
    cpp_list->reset_list();
    while (cpp_list->read_from_list(line)) {
        write_file << return_o_compile_str(*line) << std::endl << std::endl;
    }
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