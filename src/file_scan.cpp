#include "file_scan.h"

File_Scan::File_Scan(Linked_List *h_link, Linked_List *cpp_link) {
h_list = h_link;
cpp_list = cpp_link;
}

void File_Scan::search() {

    boost::filesystem::path p("src");
    if(boost::filesystem::exists(p)) {
        std::string file_name;
        for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator(p)) {
            if (match_file_extension(x) == 0) {

            }
            else if (match_file_extension(x) == 1) {
                boost::filesystem::path q(x);
                cpp_list->add_to_list(q.stem().string());
            }
            else if (match_file_extension(x) == 2) {
                boost::filesystem::path q(x);
                h_list->add_to_list(q.filename().string());
            }
            
        }
    }
}

int File_Scan::match_file_extension(boost::filesystem::directory_entry file_name) {
    boost::filesystem::path pathObj(file_name);
    if (pathObj.has_extension()) {
        if (pathObj.extension().string() == ".cpp") {
            return 1;
        }
        else if(pathObj.extension().string()==".h") {
            return 2;
        }
    }
    else {
        return 0;
    }
}

