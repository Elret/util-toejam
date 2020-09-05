#include "toejam.h"

int main(int argc, char *argv[]) {
Args args;
args.set_false_variables();
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << std::endl;

    if (argv[i] == "create") {
      args.create = true;
      if (!args.check_for_i(i,argc))
      return 0; //todo: Add error logging.
      pass_name = argv[i+1];
    }
    if (argv[i] == "add") {
      args.add_file = true;
      if (!args.check_for_i(i,argc))
      return 0; //todo: Add error logging.
      pass_name = argv[i+1];
    }
    if (argv[i] == "header") {
      args.add_header = true;
      if (!args.check_for_i(i,argc))
      return 0; //todo: Add error logging.
      pass_name = argv[i+1];
    }
    if (argv[i] == "spec") {
      args.spec = true;
    }
    if (argv[i] == "author") {
      args.add_author = true;
    }
    if (argv[i] == "--global") {
      args.global = true;
    }
  }

  if (args.create) {
    Create create(pass_name);
    create.create_project();
  }
  else if (args.add_file) {
  Create create(pass_name);
  create.add_files_to_project();
  }
  else if (args.add_header) {
    Create create(pass_name);
    create.create_header_file();
  }
}
