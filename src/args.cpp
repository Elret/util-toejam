#include "args.h"

int Args::arg_limit() {
  //returns 0 if good syntax

  int arg_count=0;
  if (create)
  arg_count++;
  if (add_file)
  arg_count++;
  if(add_header)
  arg_count++;
  if (spec)
  arg_count++;
  if (add_author)
  arg_count++;
  if (global)
  arg_count++;
  
  if (arg_count == 1)
  return 0;
  else if (arg_count == 0)
  return 1;
  
  return 2;
}

bool Args::check_for_i(int i, int argc) {
  if (argc - i > 0) {
    return true;
  } else {
    return false;
  }
}

void Args::set_false_variables() {
  create = false;
  add_file = false;
  add_header = false;
  spec = false;
  add_author = false;
  global = false;

}