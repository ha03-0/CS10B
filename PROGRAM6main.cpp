#include <iostream>
#include "SortedSet.h"
using namespace std;

// int main() {
//     return 0;
// }

int main() {
   SortedSet* a = new SortedSet();
    a->add(10);
    a->add(20);
    a->add(50);
    a->add(205);
    cout << *a << endl;
   // cout << "testing" <<endl;
        
    SortedSet b;
    cout << "PushBack 10" << endl;
    b.push_back(10);
    
    cout << "PushBack 21" << endl;
    b.push_back(21);
    
    cout << "PushBack 40" << endl;
    b.push_back(40);
    
    cout << "PushBack 32" << endl;
    b.push_back(32);
    
    cout << "PushBack 41" << endl;
    b.push_back(41);
    
    cout << "PushFront 44" << endl;
    b.push_front(44);
    
    cout << "PushFront 26" << endl;
    b.push_front(26);
    
    cout << "PushFront 89" << endl;
    b.push_front(89);
    
    cout << "PushFront 30" << endl;
    b.push_front(30);
    
    cout << "InsertOrdered 23" << endl;
    b.insert_ordered(23);
    
    cout << "InsertOrdered 42" << endl;
    b.insert_ordered(42);
    
    cout << "InsertOrdered 49" << endl;
    b.insert_ordered(49);
    
    cout << "InsertOrdered 678" << endl;
    b.insert_ordered(678);
    
    SortedSet c;
    cout<< "Insert 80" << endl;
    c.insert_ordered(80);
    
    cout<< "Insert 10" << endl;
    c.insert_ordered(10);
    
    cout<< "Insert 50" << endl;
    c.insert_ordered(50);
    
    cout<< "Insert 101" << endl;
    c.insert_ordered(101);
    
    cout<< "Insert 23" << endl;
    c.insert_ordered(23);
    
    return 0;
}