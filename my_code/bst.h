#include <iostream>

void indent(int level) {
    // indent more at each level:
    for (int i = 0; i < level; i++) std::cout << "  ";
}

template <typename T>
class Bst
{
    friend void print_bst(const Bst<T>& bst, int level=0)
    {
        indent(level);
        level++;

        std::cout << "data: " << bst.data << std::endl;
        indent(level + 1);
        std::cout << "left: ";
   
        if (!bst.left) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.left, level);
        }
        indent(level + 1);
        std::cout << "right: ";
        if (!bst.right) std::cout << "nullptr\n";
        else {
            std::cout << "\n";
            indent(level);
            print_bst(*bst.right, level);
        }
        std::cout << std::endl;
    }

public:
    Bst(T d, Bst* p=nullptr, Bst* l=nullptr, Bst* r=nullptr)
        : data(d), parent(p), left(l), right(r) {}

    Bst<T>* insert(const T d)
    {
        if (d == data) return nullptr;
        else if (d < data)
        {
            if (!left)
            {
                left = new Bst(d, this, nullptr, nullptr);
                return left;
            }
            else
            {
                return left->insert(d);
            }
        }
        else
        {
            if (!right)
            {
                right = new Bst(d, this, nullptr, nullptr);
                return right;
            }
            else
            {
                return right->insert(d);
            }
        }
    }
    
    T min()
    {
        if (!left)
        {
            return data;
        }
        else
        {
            return left->min();
        }
        
    }

    T max()
    {
        if (!right)
        {
            return data;
        }
        else
        {
            return right->max();
        }
    }
    
    Bst<T>* search(const T d)
    {
        if (d == data) return this;
        else if (d < data)
        {
            if (left) return left->search(d);
            else return nullptr;
        }
        else
        {
            if (right) return right->search(d);
            else return nullptr;

        }
    }

    Bst<T>* predecessor(T d)
    {
        Bst<T>* curr = search(d);
        if(curr->left != nullptr)
        {
            return search(curr->left->max());
        }
        else
        {
            Bst<T>* parent = curr->parent;
            
            while(parent != nullptr)
            {
                //without using key comparison -- only using left, right pointer
                //if(node == parent.left){
                //    node = parent;
                //}
                //else break;
                if(parent->data < curr->data)
                {
                    return parent;
                }
                
                parent = parent->parent;
            }
            
            return 0;
        }
    }
    
    Bst<T>* successor(T d)
    {
        Bst<T>* curr = search(d);
        if(curr->right != nullptr)
        {
            return search(curr->right->min());
        }
        else
        {
            Bst<T>* parent = curr->parent;
            
            while(parent != nullptr)
            {
                //without using key comparison -- only using left, right pointer
                //if(node == parent.right){
                //    node = parent;
                //}
                //else break;
                if(parent->data > curr->data)
                {
                    return parent;
                }
                
                parent = parent->parent;
            }
            return nullptr;
        }
    }

    T get_val() const
    {
        return data;
    }

private:
    T data;
    Bst* parent;
    Bst* left;
    Bst* right;
};



//template <typename T>
//void print_bst(const Bst<T>& bst) {
//void print_bst(Bst<int> bst) {
//    std::cout << "data: " << bst.data << "; left: ";
//
//    if (!bst.left) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.left);
//    }
//    std::cout << "; right: ";
//    if (!bst.right) std::cout << "nullptr ";
//    else {
//        std::cout << "\t\n";
//        print_bst(*bst.right);
//    }
//    std::cout << std::endl;
//}

