#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) return os << "null";
    os << "Data: " << nd->data;
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
    cout << curr << " -> ";
    if (curr) print_list(os, curr->next);
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d)
{
    head = new Node(d, head);
}

bool del_tail(Node*& curr)
{
    if (!curr)
    {
        return false;
    }
    else
    {
        if (!curr->next)
        {
            delete curr;
            curr = nullptr;
            return true;
        }
        else
        {
            del_tail(curr->next);
        }
    }
    return false;
}
/*
 * Get the last node of a list.
 * */
Node* last(Node* head)
{
    if (!head)
    {
        return nullptr;
    }
    else
    {
        if (!head->next)
        {
            return head;
        }
        else
        {
            return last(head->next);
        }
    }

}
