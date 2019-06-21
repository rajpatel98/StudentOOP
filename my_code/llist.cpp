#include <iostream>
#include "llist.h"

using namespace std;


ostream& operator<<(ostream& os, const Node* nd) {
    if (!nd) return os << "null";
    os << "Data: " << nd->data;
    return os;
}


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


void print_list(ostream& os, const Node* curr)
{
    cout << curr << " -> ";
    if (curr) print_list(os, curr->next);
}


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


void add_at_front(Node*& head, int d)
{
    head = new Node(d, head);
}


bool del_head(Node*& head)
{
    if (head)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
    return false;
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


Node* duplicate(Node* head)
{
    if (!head)
    {
        return head;
    }
    else
    {
        return new Node(head->data, duplicate(head->next));
    }
}


Node* reverse(Node* curr, Node* new_next)
{
    if (!curr)
    {
        return new_next;
    }
    else
    {
        return reverse(curr->next, new Node(curr->data, new_next));
    }
}


Node* join(Node*& list1, Node* list2)
{
    if (list1)
    {
        last(list1)->next = list2;
        return list1;
    }
    else
    {
        return list2;
    }
}


