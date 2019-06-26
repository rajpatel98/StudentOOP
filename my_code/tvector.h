#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include <string>
#include <vector>

const int DEF_CAPACITY = 10;
const int CAPACITY_MULT = 2;


template <typename DATA>
class MyVec {
public:
    class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
        friend bool operator!=(Iterator& rhs, Iterator& lhs)
        {
            return (rhs.iptr != lhs.iptr);
        }
        
    public:
        Iterator(int* ip) : iptr(ip) {}
        
        
        
        Iterator& operator++()
        {
            iptr++;
            return *this;
        }
        
        int operator*() { return *iptr; }
        
    private:
        int* iptr;
    };
    
    MyVec() : sz(0) {
        capacity = DEF_CAPACITY;
        data = new int[DEF_CAPACITY];
    }
    
    
    MyVec(int sz, int val = 0) : sz{sz}
    {
        data = new int[sz];
        for (int i = 0; i < sz; i++)
        {
            data[i] = val;
        }
    }
    
    
    MyVec(const MyVec& v2) {
        copy(v2);
    }
    
    ~MyVec() {
        delete [] data;
    }
    
    MyVec& operator=(const MyVec& v2) {
        if (this != &v2) {
            delete [] data;
            copy(v2);
        }
        return *this;
    }
    
    void push_back(int val) {
        sz++;
        if (sz > capacity) {
            cout << "Increasing capacity\n";
            int* old_data = data;
            data = new int[capacity * CAPACITY_MULT];
            for (int i = 0; i < sz; i++) {
                data[i] = old_data[i];
            }
            capacity *= CAPACITY_MULT;
            delete [] old_data;
        }
        data[sz - 1] = val;
    }
    
    /*
     * this [] is for reading items from the MyVec:
     * It returns the i-th element.
     * */
    int operator[](int i) const {
        return data[i];
    }
    
    /*
     * this [] allows write access to items in the MyVec:
     * It returns a reference to the i-th element.
     * */
    int& operator[](int i) {
        return data[i];
    }
    

    
    int size() const { return sz; }
    
    MyVec::Iterator MyVec::begin() const
    {
        return MyVec::Iterator(data);
    }
    
    MyVec::Iterator MyVec::end() const
    {
        
        return MyVec::Iterator(data + size());
    }
    
private:
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new int[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }    int* data;
    int sz;
    int capacity;
};


void print_vector(const MyVec& v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}

bool operator==(MyVec& v1, MyVec& v2)
{
    return true;
}

#endif
