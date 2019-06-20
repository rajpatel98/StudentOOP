#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) return os << "null \n";
    os << "Data: " << nd->data << " -> ";
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
    if (!head)
    {
        head = new Node(d, nullptr);
    }
    else
    {
        add_at_end(head->next, d);
    }
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr)
{
    cout << curr;
    if (curr) print_list(os, curr->next);
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d)
{
    head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head)
{
    if (!head->next)
    {
        return head;
    }
    else
    {
        return last(head->next);
    }
    return nullptr;
}
