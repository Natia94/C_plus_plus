#ifndef assignemnt1_vector_h
#define assignemnt1_vector_h
#include <stdexcept>
#include <array>
#include <iostream>
using namespace std;
template <class T>
class Vector{
public:
    Vector ();
    
    ~Vector();
    
    
    unsigned int size();
    
    unsigned int capacity();
    void push_back (const T& elt );
    
    void pop_back();
    
    bool empty();
    
    void insert (const T& elt, int pos);
    
    void erase (int pos);
    void check();
    
    
    T& at(int pos)                                // returns reference to element at position pos if position is valid
    {
        if((pos> 0 || pos == 0) && pos < sizee)  //cheks if position is valid
            return vec[pos];
        else
            throw std::invalid_argument ("  bounds exception  "); // if position is not valid throws exception
    }
   
    
    T& front() // returns reference to the first element
    {
        return vec[0];
    }
    
    
    
    T& back()  //returns reference to the last element
    {
        return vec[sizee-1];
    }
    
    
    T &operator [] (int n) //returns reference to element at position n
    {
        if (n <0 || n>=sizee)
            throw std::invalid_argument ("  bounds exception  ");
        return vec[n];
    }
    
    
    T &operator = (const Vector & v ) //overloading, assignment operator
    {
        for (int i=0; i<sizee; i++ )
        {
            vec[i]=v[i];
        }
        sizee=v.sizee;
        capacityy = v.capacityy;
    }
    
    
private:
    int sizee=0;
    int capacityy=0;
    T *vec;
    
};





template <class T>
Vector<T>::Vector()
{
    vec = new T[0];  //allocates
    
}
template <class T>
Vector<T>::~Vector()
{
    
    delete [] vec;  //dealocates
}

template <class T>
unsigned int Vector<T>::size() //returns current size of vector
{
    return sizee;
}

template <class T>
unsigned int Vector<T>::capacity()  // assert(v1.capacity() > v1.size()) <--- cause we have this code in main.cpp
{
    return capacityy;
}

template <class T>
void Vector<T>::push_back (const T& elt ) //inserts element elt at end of vector and if its necessary doubles size;
{
    vec[sizee]=elt;
    sizee++;
    check(); // to double if its necessary
}

template <class T>
void Vector<T>::pop_back() // deletes the last element of vector
{
    vec[sizee]=0;
    sizee--; // updates size cause the last elt is deleted
}

template <class T>
bool Vector<T> :: empty() //bool-returns true if vector is empty
{
    if (sizee == 0 || sizee<0)
        return true;
    else
        return false;
}

template <class T>
void Vector<T> ::insert (const T& elt, int pos) //inserts element elt at position pos
{
    for(int i=sizee; i < pos; i--)
    {
        vec[i]= vec[i-1];
    }
    vec[pos] = elt;
    sizee++;
    check();
}

template <class T>
void Vector<T> :: erase (int pos) //deleted element at position pos
{
    for(int i=pos; i<sizee; i++)
    {
        vec[i]= vec[i+1];
    }
    sizee--;
}

template <class T>
void Vector<T> ::check() //checks capacity (cause it must be greater then size) and if necessary doubles it.
{
    if(capacityy == sizee)
    {
        capacityy*=2;
    }
}

#endif