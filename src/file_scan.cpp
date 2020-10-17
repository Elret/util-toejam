#include "file_scan.h"

File_Scan::File_Scan(Linked_List &h_link, Linked_List &cpp_link) {
h_link = h_list;
cpp_link = cpp_list;
}

void File_Scan::search() {
    boost::filesystem::path p;
    if(boost::filesystem::exists(p)) {
        std::string file_name;
        for (boost::filesystem::directory_entry& x : boost::filesystem::directory_iterator(p)) {
            if (match_file_extension(x) == 0) {
                std::string pass_string = stream_it(x);
                cpp_list.add_to_list(pass_string);
            }
            else if (match_file_extension(x) == 1) {
                std::string pass_string = stream_it(x);
                h_list.add_to_list(pass_string);
            }
            else if (match_file_extension(x) == 2) {
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

std::string File_Scan::stream_it(boost::filesystem::directory_entry &x) {
    std::string return_string;
    std::stringstream ss;
    ss << x;
    ss >> return_string;
    return return_string;
}