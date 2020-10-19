#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class Linked_List {
private:
class Node {
public:
std::string line;
Node *next;
~Node();
};
Node *start;
Node *current;


public:
Linked_List();
~Linked_List();
void add_to_list(std::string);
bool read_from_list(std::string *passed_string);
void reset_list();
};

#endif