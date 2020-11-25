#include <bits/stdc++.h>
#include "Column.h"
using namespace std;
template<class T>
// Default constructor
Column<T>::Column()
{
    my_capacity = 0;
    my_size = 0;
    array = 0;
}

// Constructor from another constant Column
template<class T>
Column<T>::Column(const Column<T> & v)
{
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    array = new T[my_size];  
    for (unsigned int i = 0; i < my_size; i++)
        array[i] = v.array[i];  
}

// Constructor that Constructs a given sized Column
template<class T>
Column<T>::Column(unsigned int size)
{
    my_capacity = size;
    my_size = size;
    array = new T[size];
}

// Constructor that Constructs a given sized Column and making all data given initial value
template<class T>
Column<T>::Column(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    array = new T [size];
    for (unsigned int i = 0; i < size; i++)
        array[i] = initial;
}

// Clone Method for Column Class
template<class T>
Column<T> & Column<T>::operator = (const Column<T> & v)
{
    delete[ ] array;
    my_size = v.my_size;
    my_capacity = v.my_capacity;
    array = new T [my_size];
    for (unsigned int i = 0; i < my_size; i++)
        array[i] = v.array[i];
    return *this;
}
// A method that returns first variable in that array
template<class T>
T& Column<T>::front()
{
    return array[0];
}
// A method that returns last variable in that array
template<class T>
T& Column<T>::back()
{
    return array[my_size - 1];
}

// A method that appends that array and adds that variable into that new place
template<class T>
void Column<T>::push_back(const T & v)
{
    if (my_size >= my_capacity)
        // if capacity is less we have expand the array
        reserve(my_capacity +5);
    array [my_size++] = v;
}

// A method that changes capacity
template<class T>
void Column<T>::reserve(unsigned int capacity)
{
    if(array == 0)
    {
        my_size = 0;
        my_capacity = 0;
    }    
    // Declearing new array which has new size 
    T * Newarray = new T [capacity];

    // Make sure it does not acceed capacity
    unsigned int l_Size = capacity < my_size ? capacity : my_size;
    
    // Passing old array to new one
    for (unsigned int i = 0; i < l_Size; i++)
        Newarray[i] = array[i];

    // changing capacity variable
    my_capacity = capacity;

    // deleting old array
    delete[] array;
    
    // changing arrays (pointes)
    array = Newarray;
}

// Returning size of the array
template<class T>
unsigned int Column<T>::size()const
{
    return my_size;
}

// Resizing array 
template<class T>
void Column<T>::resize(unsigned int size)
{
    reserve(size);
    my_size = size;
}

// resizing array and filling array with input value
template<class T>
void Column<T>::resize(unsigned int size, T val)
{
    reserve(size);
    my_size = size;
    fill(array , array + size, val);
}

// [] operator overload to return array[index]
template<class T>
T& Column<T>::operator[](unsigned int index)
{
    return array[index];
}  

// A method that returns capacity
template<class T>
unsigned int Column<T>::capacity()const
{
    return my_capacity;
}

// Column Class Destructor
template<class T>
Column<T>::~Column()
{
    // deleting array
    delete[ ] array;
}

// A method that resets that Column object
template <class T>
void Column<T>::clear()
{
    my_capacity = 0;
    my_size = 0;
    array = 0;
}
