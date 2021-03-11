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

void IntVector::expand(){
    int *arr = _data;
    _capacity *= 2;
    if(_capacity == 0)
        _capacity += 1;
    
   _data = new int[_capacity];
        for(unsigned int i = 0; i<_size; i++){
           _data[i] = arr[i];
        }
  delete[] arr;
}

void IntVector::expand (unsigned amount){
    int *arr = _data;
    _capacity += amount;
    
    _data = new int [_capacity];
        for(unsigned int i = 0; i<_size; i++){
            _data[i] = arr[i];
        }
    delete[] arr;
}

void IntVector::insert(unsigned index, int value){
    if(index > _size){
       throw out_of_range("IntVector::insert_range_check");
    }
    if(_capacity == _size){
        expand();
    }
    _size++;
    for (unsigned int i = _size; i>index; i--){
        _data[i] = _data[i-1];
    }
    _data[index] = value;
}

void IntVector::erase(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::erase_range_check");
    }
    _size--;
    for (unsigned int i= index; i< _size; i++){
        _data[i] = _data[i+1];
    }
}

void IntVector::push_back(int value){
    if(_size+1 >= _capacity){
        expand();
      }
    _size = _size + 1;
     _data[_size-1] = value;
  }  

void IntVector::pop_back(){
    _size--;
}

void IntVector::clear(){
    _size = 0;
}

void IntVector::resize(unsigned size, int value){
    if(size < _size){
       _size = size;
     }
    if (size > _capacity){
        if(size > _capacity*2){
        expand(size - _capacity);
    }
    else{
        expand();
    }
}
    for(unsigned int i = _size; i < size; i++){
        _size = size;
        _data[i] = value;
    }
}

void IntVector::reserve(unsigned n){
    if (n > _capacity){
        expand(n-_capacity);
        }
    }

void IntVector::assign(unsigned n, int value){
      if( _capacity<n){
        if(n<_capacity*2 && _capacity !=0){
            expand();
        }
        else{
            expand(n-_capacity);
        }
    }
    _size = n;
    for(unsigned int i = 0; i<_size;i++){
        _data[i] = value;
    }

}

int& IntVector::at(unsigned index){
    if(index >= _size){
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}
int& IntVector::front(){
    return _data[0];
}
 int& IntVector::back(){
     return _data[_size-1];
}