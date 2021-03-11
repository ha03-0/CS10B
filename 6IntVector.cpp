#include<iostream>
#include<stdexcept>
#include "IntVector.h"
using namespace std;


IntVector::IntVector(unsigned capacity, int value){
     _size = capacity;
     _capacity = capacity;
     _data = nullptr;
    if(capacity > 0){
         _data = new int[capacity];
         for (unsigned int i = 0; i<_size; i++){
             _data[i] = value; //same as _data[i] = *(_data+i)
        }
    }
}

IntVector::~IntVector(){
    delete[]_data;
    }

unsigned IntVector::size()const{
    return _size;
}

unsigned IntVector::capacity()const{
    return _capacity;
}

bool IntVector::empty()const{
    if(_size==0){
        return true;
    }
    else{
        return false;
    }
}

const int& IntVector::at(unsigned index) const{
    if(index >= _size){
       throw out_of_range("IntVector::at_range_check");
    }
    else{
        return _data[index];
    }
}

const int& IntVector::front()const{
    return _data[0];
}

const int& IntVector::back() const{
    return _data[_size-1];
}