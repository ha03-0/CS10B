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

IntList::IntList(const IntList &cpy){
    head = nullptr;
    tail = nullptr;
    
    int temp;
    for(IntNode* x = cpy.head; x != nullptr; x = x->next){
        temp = x->value;
        push_back(temp);
    }
    return;
}
    //the copy constructor. Make sure this performs deep copy.
    
IntList& IntList::operator=(const IntList &rhs){
    if(rhs.head == nullptr){
        clear();
        return *this;
    }
    if (this == &rhs){
        return *this;
    }
    else{
        clear();
        int temp;
        for(IntNode* x = rhs.head; x != nullptr; x = x->next){
            temp = x->value;
            push_back(temp);
        }
    }
    return *this;
   // delete temp;  ////////////////////////
}
    //the overloaded assignment operator. Make sure this performs deep copy.
    
void IntList::push_back(int value){
    IntNode* temp = new IntNode(value);
    
    if (empty()){
        tail = temp;
        head = temp;
    }
    else{
        tail->next = temp;
        tail = tail->next;
    }
}
    //Inserts a data value (within a new node) at the back end of the list.
    
void IntList::clear(){
    head = nullptr;
    tail =  nullptr;
        
}
    //Removes (deallocates) all IntNodes in the IntList. Don't forget to set both head and tail to appropriate values for an empty list. DO NOT leave them dangling!
    
void IntList::selection_sort(){
    int num;
    for(IntNode* lastSorted = head; lastSorted != nullptr; lastSorted = lastSorted->next){
        IntNode* temp = lastSorted;
        for(IntNode* diff = temp; diff != nullptr; diff = diff->next){
            if(diff->value< temp->value){
                temp = diff;
            }
        } 
        num = lastSorted->value;
        lastSorted->value = temp->value;
        temp->value = num;
    }
}        
    //Sorts the integers in the list into ascending order. Do NOT move the nodes, just the integers.
    
void IntList::insert_ordered(int value){
    if(head == nullptr){
        push_front(value);
    }
    else if(head->next == nullptr){
        if(head->value >= value){
            push_front(value);
        }
        else{
            push_back(value);
        }
    }
    else if(tail->value <= value){
        push_back(value);
    }
    else if(head->value >= value){
        push_front(value);
    }
    else{
        IntNode* input = head;
        IntNode* def = head->next;
        IntNode* temp = nullptr;
        
    for(temp = head; !(input->value <= value && value <= def->value); temp = temp->next){
        //temp != nullptr && temp != tail && def; temp = temp->next){
        input = temp->next;
        def = temp->next->next;
    }
        IntNode* prev = new IntNode(value);
        prev->next=def;
        input->next =prev;

       // }
        }
        }


   //(within a new node) in an ordered list. Assumes the list is already sorted in ascending order (i.e., 
    //Do not sort the list first, assume the list is already is sorted.) This function loops through the list until if finds the 
    //correct position for the new data value and then inserts the new IntNode in that location. This function may NOT ever sort the list.
    
void IntList::remove_duplicates(){
    IntNode* num = nullptr;
    IntNode* prev = head;

    for(IntNode* m = head; m != nullptr; m = m->next){
       num = m->next;
        prev = m;
        while (num != nullptr){
            if(m->value == num->value){
                IntNode* n = num;
                
                if(num == tail){
                    num = nullptr;
                    prev->next = nullptr;
                    tail = prev;
                    delete n;
                }
                else{
                    prev->next = num->next;
                    num = num->next;
                    delete n;
                }
            }
            else{
                num = num->next;
                prev = prev->next;
            }
        }
    }
}

//nested loop and nested if does not need to be complicated
//find duplicate
//check to see
//tail and curr are stroing the same
//remove the last node
//could point to new last node
//could set tail to what prev is pointing to
//**POINT TAIL TO PREV**///
// Fix a node n in the list.
// For each node m that follows n in the list, if m is a duplicate of n, then you need to remove m. It will be useful to maintain a pointer that points to the node before m (call this prev) so that you can set the next pointer of prev to the node that follows m. After you deallocate m, you'll want to increment your iterating pointer to prev->next, and prev should be kept at the same location. Otherwise, if m is not a duplicate of n, then you can set prev equal to m, and increment m to the next node in the list.

// Please remember to handle the special case in which the tail node is a duplicate value and needs to be removed.