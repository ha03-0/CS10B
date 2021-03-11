#include <iostream>
using namespace std;
#include "IntVector.h"


int main(){
//unit test for IntVector
    IntVector test(4,9);
    cout<<"Testing IntVector.";
    for (unsigned int i = 0; i<test.size(); i++){
        cout<<test.at(i)<<endl;
    }

//unit test for testing at
    IntVector test2(4,1);
    if(test2.at(1) != 1){
        cout<<"Error in index 1. Coude should output: "<<test2.at(1)<<endl;
    }
    
    
//unit test for empty : v.empty == true;
    IntVector v;
    bool expected = true;
    bool actual = v.empty();
    if(actual != expected) {
        cout<<"Error: IntVector()::empty(). Actual: "<< actual <<", Expected: "<< expected << endl;

    }
    return 0;
    
//unit test for testing front
    IntVector test3(8,7);
    if(test3.front() != 7){
        cout<<"Error in value. Code should output "<<test3.front()<<endl;
    }
    
//unit test for testing back
    IntVector test4(4,7);
    if (test4.back() != 7){
        cout<<"Error with back() function. Code should output "<<test4.back()<<endl;
    }
    
//unit test for testing size
    IntVector test5(3,4);
        if(test5.size() != 4){
            cout<<"Error with size() function. Code should output "<<test5.size()<<endl;
        }
    
    
//unit test for testing capacity 
   IntVector test6(2,5);
        if(test5.capacity() != 5){
            cout<<"Error with capacity() function. Code should output "<<test5.capacity()<<endl;
        }
    
    

    IntVector TestVector1;
    IntVector TestVector2(3);
    IntVector TestVector3(7, 2);
    
    //push_back 
    //cout<<"vector 1 should have a value of 2"<<endl;
    cout << "Result: " << TestVector1.size() << " " << TestVector1.at(0)<<endl;
    cout << " " << TestVector2.size() << endl;
    
    //testing all in one
    unsigned int SIZE; 
    int VALUE;
    
    cout << "Enter size: ";
    cin >> SIZE;
    cout << endl;
    
    cout << "Enter value: ";
    cin >> VALUE;
    cout << endl;
    
    IntVector num = IntVector (SIZE, VALUE);
   // cout << "Array at 3: " << num->at(3) << endl;
   // cout << "First element: " << num->front() << endl;
   // cout << "Last element: " << num->back() << endl;
    num.erase(1);
   // num.expand();
   // num.expand(1); 
   // num.insert(1);
    num.clear();
    num.resize(5, 2);
    num.assign(2, 5);

    //i used these test cases to see if my expand was working bc my expand was causing all of these cases to fail 
}

