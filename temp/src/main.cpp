#include "main.h"

int main() {
    Linked_List *cpp_list = new Linked_List;
    Linked_List *h_list = new Linked_List;
    File_Scan fs(h_list, cpp_list);
    fs.search();
    cpp_list->reset_list();
    std::string *line = new std::string;
    while (cpp_list->read_from_list(line)) {
        std::cout << *line << std::endl;
    }
}