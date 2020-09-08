#include "toejam.h"

int main(int argc, char *argv[]) {
Args args;
args.set_false_variables();
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << std::endl;
    std::string argument = argv[i];
    if (argument == "create") {
      args.create = true;
      if (!args.check_for_i(i,argc))
      return 0; //todo: Add error logging.
      pass_name = argv[i+1];
    }
    if (argument == "add") {
      args.add_file = true;
      if (!args.check_for_i(i,argc))
      return 0; //todo: Add error logging.
      pass_name = argv[i+1];
    }
   if (argument == "header") {
      args.add_header = true;
      if (!args.check_for_i(i,argc))
      return 0; //todo: Add error logging.
      pass_name = argv[i+1];
    }
   if (argument == "spec") {
      args.spec = true;
    }
   if (argument == "author") {
      args.add_author = true;
    }
   if (argument == "--global") {
      args.global = true;
    }
   if (argument == "--debug") {
      args.debug = true;
    }

  }

  std::cout<< pass_name << "\n";

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
  else {
     Usage usage;
     usage.run_usage();
    }
}
