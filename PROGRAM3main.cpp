#include <string>
#include <iostream>
#include "ShoppingCart.h"
using namespace std;

void printMenu(ShoppingCart&);

int main(){
    string name;
    string date;
    
    cout<<"Enter customer's name: ";
    getline(cin, name);
    cout<<endl;
    cout<<"Enter today's date: ";
    getline(cin, date);
    cout<<endl;
    cout<<endl;
    
    cout<<"Customer name: "<<name<<endl;
    cout<<"Today's date: "<<date<<endl;
    cout<<endl;
    ShoppingCart cart(name,date);
    printMenu(cart);
    return 0;
}

void printMenu(ShoppingCart &cart){
  char temp =' ';
    while(temp != 'q'){
        temp = ' ';
    cout<<"MENU"<<endl;
    cout<< "a - Add item to cart"<<endl;
    cout<<"d - Remove item from cart"<<endl;
    cout<<"c - Change item quantity"<<endl;
    cout<<"i - Output items' descriptions"<<endl;
    cout<<"o - Output shopping cart"<<endl;
    cout<<"q - Quit"<<endl<<endl;
    
        while(temp != 'a' && temp != 'd' && temp != 'c'&&
             temp != 'i' && temp != 'o' && temp != 'q'){
              cout<<"Choose an option: ";
              cin>>temp;
              cout << endl;
        }
    
    if(temp == 'a'){
    cin.ignore();
    string name;
    cout << endl;
    cout<<"Enter the item name: ";
    getline(cin,name);
    cout << endl;
    string description;
    cout<<"Enter the item description: ";
    getline(cin, description);
    cout << endl;
    int price;
    cout<<"Enter the item price: ";
    cin>>price;
    cout << endl;
    int quantity;
    cout<<"Enter the item quantity: ";
    cin>>quantity;
    cout << endl;
    ItemToPurchase item(name, description, price, quantity);
    cart.addItem(item);
    }
    else if (temp == 'd'){
        cin.ignore();
        cout << endl;
        cout<<"REMOVE ITEM FROM CART"<<endl;
        string name;
        cout<<"Enter the item name: ";
        getline(cin, name);
         cout << endl;
        cart.removeItem(name);
    }
    else if(temp == 'c'){
        cin.ignore();
        string name;
        cout << endl;
        cout<<"Enter the item name: ";
        getline(cin,name);
         cout << endl;
        int quantity;
        cout<<"Enter new quantity: ";
        cin>>quantity;
         cout << endl;
        
        ItemToPurchase item;
        item.setName(name);
        item.setQuantity(quantity);
        cart.modifyItem(item);
   
    }
    else if(temp == 'i'){
        cin.ignore();
        cout<<"OUTPUT ITEMS' DESCRIPTIONS"<<endl;
    cart.printDescriptions();
    }
    else if(temp == 'o'){
        cin.ignore();
        cout<<"OUTPUT SHOPPING CART"<<endl;
        cart.printTotal();
    }
    }

}