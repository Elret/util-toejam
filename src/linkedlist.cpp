#include "linkedlist.h"

Linked_List::Linked_List() {
    start = new Node;
}

Linked_List::~Linked_List() {
    delete start;
    
}

Linked_List::Node::~Node() {
    delete next;
}

void Linked_List::add_to_list(std::string passed_string) {
    current = start;
    while(current->next != 0){
        current = current->next;
    }
    current->line = passed_string;
    current->next = new Node;
    current = current->next;
    current->next = 0;
}

bool Linked_List::read_from_list(std::string *passed_string) {
    if (current->next == 0) {
        return false;
    }
        *passed_string = current->line;
        current = current->next;
        return true;

}

void Linked_List::reset_list() {
    current = start;
}