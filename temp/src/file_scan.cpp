#include "file_scan.h"

File_Scan::File_Scan(Linked_List *h_link, Linked_List *cpp_link) {
h_list = h_link;
cpp_list = cpp_link;
}

void File_Scan::search() {

    boost::filesystem::path p("src");
    if(boost::filesystem::exists(p)) {
        std::string file_name;
    if (boost::filesystem::exists("src") && boost::filesystem::is_directory("src")) {
        boost::filesystem::recursive_directory_iterator iter("src");
        boost::filesystem::recursive_directory_iterator end;
        while (iter != end) {
            if (match_file_extension(iter->path().string()) == 1) {
                cpp_list->add_to_list(iter->path().string());
            }
            else if (match_file_extension(iter->path().string()) == 2) {
                h_list->add_to_list(iter->path().string());
            }
            iter++;
        }
    }
    }
}

int File_Scan::match_file_extension(std::string file_name) {
    boost::filesystem::path pathObj(file_name);
    if (pathObj.has_extension()) {
        if (pathObj.extension().string() == ".cpp") {
            return 1;
        }
        else if(pathObj.extension().string()==".h") {
            return 2;
        }
    }
    return 0;
}

