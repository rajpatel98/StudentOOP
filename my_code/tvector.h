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
        Iterator(DATA* ip) : iptr(ip) {}
        
        
        
        Iterator& operator++()
        {
            iptr++;
            return *this;
        }
        
        DATA operator*() { return *iptr; }
        
    private:
        DATA* iptr;
    };
    
    MyVec() : sz(0) {
        capacity = DEF_CAPACITY;
        data = new DATA[DEF_CAPACITY];
    }
    
    
    MyVec(int sz, DATA val = 0) : sz{sz}
    {
        data = new DATA[sz];
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
    
    void push_back(DATA val) {
        sz++;
        if (sz > capacity) {
//            cout << "Increasing capacity\n";
            DATA* old_data = data;
            data = new DATA[capacity * CAPACITY_MULT];
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
    DATA operator[](int i) const {
        return data[i];
    }
    
    /*
     * this [] allows write access to items in the MyVec:
     * It returns a reference to the i-th element.
     * */
    DATA& operator[](int i) {
        return data[i];
    }
    

    
    int size() const { return sz; }
    
    Iterator begin() const
    {
        return Iterator(data);
    }
    
    Iterator end() const
    {
        
        return Iterator(data + size());
    }
    
private:
    void copy(const MyVec& v2) {
        sz = v2.sz;
        capacity = v2.capacity;
        data = new DATA[capacity];
        for (int i = 0; i < sz; i++) {
            data[i] = v2.data[i];
        }
    }
    DATA* data;
    int sz;
    int capacity;
};

template <typename DATA>
void print_vector(const MyVec<DATA>& v) {
    for (DATA i : v) std::cout << i << " ";
    std::cout << std::endl;
}

template <typename DATA>
bool operator==(MyVec<DATA>& v1, MyVec<DATA>& v2)
{
    if (v1.size() != v2.size()) return false;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i]) return false;
    }
    return true;
}

#endif
