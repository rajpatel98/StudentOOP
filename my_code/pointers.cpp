#include <iostream>
#include "pointers.h"

using namespace std;

void inc_by_value(int n)
{
    n++;
}


void inc_with_pointer(int* iptr)
{
    (*iptr)++;
}


void inc_with_reference(int& n)
{
    n++;
}


Thing** create_array_of_things(int n)
{
    
    for(int i = 0; i < n; i++)
    {
        
    }
    return nullptr;
}

void print_all_things(Thing** things, int n) {
}

void double_all_things(Thing** things, int n) {
}

void delete_all_things(Thing** things, int n) {
}


void assignTA(Student* s, Student* ta) {
    s->ta = ta;
}

void printTAs(vector<Student*>& students) {
    for (Student* student : students) {
        if (student->ta == nullptr) {
            cout << student->name << " has no TA\n";
        }
        else {
            cout << student->name << " has TA " << student->ta->name << endl;
        }
    }
}
