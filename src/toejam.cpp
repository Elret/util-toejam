#include "toejam.h"

int main(int argc, char *argv[]) {
    Args args;
    if (!args.parse_args(argc, argv))
    {
        std::cout << "Failed to parse args." << std::endl;
    }
    
    Create create(args.return_project_name());
    if (args.create == true) {
        create.create_project();
    }
    else if (args.add == true) {
        create.add_file();
    }
    //else if (args.add_lib == true) {
    //    create.add_lib();
    //}
    else if (args.help == true) {
        //todo: create usage file.
    }

}