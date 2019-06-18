#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}


MyVec::MyVec()
{
    data = new int[DEF_CAPACITY];
    sz = 0;
    capacity = DEF_CAPACITY;
}

MyVec::MyVec(const MyVec& v2)
{
    data = new int[v2.capacity];
    sz = v2.sz;
    capacity = v2.capacity;
    for (int i = 0; i < sz; i++)
    {
        data[i] = v2[i];
    }
}

MyVec::~MyVec()
{
    delete[] data;
}

MyVec& MyVec::operator=(const MyVec& v2)
{
    delete[] data;
    sz = v2.sz;
    capacity = v2.capacity;
    data = new int[v2.capacity];
    for (int i = 0; i < sz; i++)
    {
        data[i] = v2[i];
    }
    return *this;
}


/*
 * == is true when every element of the vectors are the same in
 * the same order. (Thus they must be the same size.)
 * */
bool operator==(MyVec& v1, MyVec& v2)
{
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

/*
 * Puts an element at the back of a vector.
 * */
void MyVec::push_back(int val)
{
    if (sz == capacity)
    {
        int* old_data = data;
        data = new int[capacity * 2];
        for (int i = 0; i < sz; i++) {
            data[i] = old_data[i];
        }
        capacity *= 2;
        delete [] old_data;
    }
    data[sz++] = val;
}


/*
 * this [] is for reading items from the MyVec:
 * It returns the i-th element.
 * */
int MyVec::operator[](int i) const
{
    return data[i];
}

/*
 * this [] allows write access to items in the MyVec:
 * It returns a reference to the i-th element.
 * */
int& MyVec::operator[](int i)
{
    return *(data+i);
}
