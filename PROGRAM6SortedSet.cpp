#include <iostream>
#include "SortedSet.h"

using namespace std;

/////////////  constructors and destructor  /////////////////////

SortedSet::SortedSet():IntList(){
    //sorted and no duplicates
    //call copy constructor
}

SortedSet::SortedSet(const SortedSet &copy):IntList(copy){
    //calls baseclass empty list
    //call copy constructor
}

SortedSet::SortedSet(const IntList &copy):IntList(copy){
    this->selection_sort();
    this->remove_duplicates();
}

SortedSet::~SortedSet(){
    this->clear();
    //constructors automatically call base class
    //destructor calls base frist then derived
    //automatic, never call
}

///////////////////////// accessors  ////////////////////////////

bool SortedSet::in(int value){ //exist function from 9.3
   IntNode* curr = head;
    while(curr){
        if(curr->value == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}


SortedSet SortedSet::operator|(const SortedSet & rhs){

//     a= this;
//     b = paramater rhs
//     SortedSet C;
//     return c;
    

    IntNode* a = this->head;
    IntNode* b = rhs.head;
    SortedSet* c = new SortedSet();
    
    while (a){
        c->insert_ordered(a->value);
        a = a->next;
    }
    while(b){
        c->insert_ordered(b->value);
        b = b->next;
    }
    return* c;
    //return* this;
}

    

SortedSet SortedSet::operator&(const SortedSet &rhs){
 //addition and subtraction in lab 4 distance class
    
    // 2 sorted sets and need to merge them into one with no duplicsates and in order 
    //construct and return sorted set
    //merge sore
    //start one pointer at beginnging of left/right and second pointer at beginning of second set
    //dinf min and insert min of both
    //incerement minimum untill you get to the end of one
    //make sure no duplicates
    //if > insert this
    //if righthand is less insert into new list and incrememnt
    //if == chose one pointer and incrememnt them both
    // 3 cases
    //no neseted jsut one loop
    //could call push_back but no other functions then increment
    //keep doing untill one reaches null  
    SortedSet a = SortedSet(rhs);
    SortedSet b;
    
    while(a.head != nullptr){
        if(in(a.head->value)){
        b.push_back(a.head->value);
    }
        a.head = a.head->next;
    }
    return b;
    //return* this;
}

//////////////////////  mutators  //////////////////////////////

void SortedSet::add(int value){
//same as insert_ordered in program 5 but you don't add duplicates so you could call it or write it and dont add the remove duplicates 
//use in(int value) to check if it is a duplicate and if it is not then call insert_ordered NO REMOVE DUPLICATES OR SELECTION SORTED AKA NO NESTED LOOPS
    if(!in(value)){
        IntList::insert_ordered(value);
    }
}

void SortedSet::push_front (int value){ //override and call add
    this->add(value);
}

void SortedSet::push_back(int value){//override and call add
    this->add(value);
}

void SortedSet::insert_ordered(int value){//override and call add so they cant call base
    this->add(value);
}

SortedSet SortedSet::operator|=(const SortedSet &rhs){
    SortedSet temp = *this | rhs;
    *this = temp;
     return temp;
}

SortedSet SortedSet::operator&=(const SortedSet &test){ 
    SortedSet temp = *this & test;
    *this = temp;
    return temp;
}
