#ifndef ARGS_H
#define ARGS_H

#include <string>

class Args
{
  private:

  public:
  bool create;
  bool add_file;
  bool add_header;
  bool spec;
  bool add_author;
  bool global;
  bool debug;
  std::string str;
  int arg_limit();
  bool check_for_i(int, int);
  void set_false_variables();
};

#endif