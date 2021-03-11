#include <iostream>
using namespace std;

#include "IntList.h"

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    IntNode *temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void IntList::push_front(int value) {
    IntNode *temp;
    temp = new IntNode(value);
    temp->next = head;
    head = temp;
    
     if (tail == nullptr) {
        tail = temp;
    }
}

void IntList::pop_front() {
    if (head == nullptr)
        return;
    
    if(head == tail){
        delete head;
        head = nullptr;
        tail = nullptr;
    }
             
    else{
        IntNode* temp = head;
        head = head->next;
            delete temp;
     }
}   

bool IntList::empty() const {
    if(head == nullptr) {
            return true;
        }  
        else {
            return false;
        }
}

const int & IntList::front() const{
    return head-> value;
}

const int & IntList::back() const{
    return tail->value;
}

ostream & operator<<(ostream &out, const IntList &val){
    IntNode *list = val.head;
    while (list != nullptr){
        out << list-> value;
        
    if (list->next != nullptr){
        out<<" ";
    }
    list = list->next;
    }
    return out;
}    
    
    
    

