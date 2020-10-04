#include "toejam.h"

int main(int argc, char *argv[]) {
    Args args;
    if (!args.parse_args(argc, argv))
    {
        std::cout << "Failed to parse args." << std::endl;
    }
    

}