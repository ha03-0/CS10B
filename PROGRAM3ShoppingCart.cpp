#include <iostream>
#include <vector>
#include "ShoppingCart.h"
//#include "ItemToPurchase.h"
using namespace std;

ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1, 2016";
}
string ShoppingCart::customerName(){
    return _customerName;
}
void ShoppingCart::addItem(ItemToPurchase item){
    _cartItems.push_back(item);
}
ShoppingCart::ShoppingCart(std::string name, std::string date){
    _customerName = name;
    _currentDate = date;
}

std::string ShoppingCart::date(){
    return _currentDate;
}


void ShoppingCart::removeItem(std::string name){
  if(_cartItems.empty()){
      cout<<"Cart is Empty"<<endl;
      return;
  }
  bool status=false;
    for(unsigned int i=0; i<_cartItems.size();i++){
        if(_cartItems.at(i).name()==name){
            status = true;
            _cartItems.erase(_cartItems.begin()+i);
        }
    }
        if(!status)
    cout<<"Item not found in cart. Nothing removed."<<endl;
}
int ShoppingCart::numItemsInCart(){
    int finalQuantity = 0;
    for(unsigned int i=0; i<_cartItems.size();i++){
        finalQuantity += _cartItems[i].quantity();
    }
    return finalQuantity;
    }
void ShoppingCart::modifyItem(ItemToPurchase &item){
    string desc= item.description();
    string name=item.name();
    int price= item.price();
    int quant = item.quantity();
   // bool status = false;
    
    for(unsigned i=0; i<_cartItems.size();i++){
        if(_cartItems[i].name()==name){
            if(desc != "none")
                _cartItems[i].setDescription(desc);
            if(quant != 0)
                _cartItems[i].setQuantity(quant);
            if(price != 0)
                _cartItems[i].setPrice(price);
            return;
        }
     cout<<"Item not found in cart. Nothing modified."<<endl;
    }
}

void ShoppingCart::printTotal(){
    int finalQuantity = 0;
    for(unsigned i=0; i<_cartItems.size();i++){
        finalQuantity += _cartItems[i].quantity();
    }
    cout<<_customerName<<"'s Shopping Cart - "<<_currentDate<<endl;
    cout<<"Number of Items: "<<finalQuantity<<endl;
    cout<<endl;
    if(_cartItems.empty()){
        cout<<"SHOPPING CART IS EMPTY"<<endl;
        cout<<endl;
        cout<<"Total: $"<<costOfCart()<<endl;
        cout<<endl;
}
    else{
    for(unsigned int i=0; i< _cartItems.size(); i++){
      cout<< _cartItems.at(i).name()<<" "<<_cartItems[i].quantity()<<" @ $"<<_cartItems[i].price()<<" = $"<<_cartItems[i].quantity()*_cartItems[i].price()<<endl;
    }
    cout<<endl<<"Total: $"<<costOfCart()<<endl;
        cout<<endl;
}
}

int ShoppingCart::costOfCart(){
    int cost = 0;
    for(unsigned int i=0; i<_cartItems.size();i++){
    cost += _cartItems.at(i).price()*_cartItems.at(i).quantity();
    }
    return cost;
}

void ShoppingCart::printDescriptions(){
    cout<<_customerName<<"'s Shopping Cart - " <<_currentDate<<endl << endl;
    cout<<"Item Descriptions"<<endl;
    
    if(_cartItems.size()>0)
        for(unsigned int i=0; i< _cartItems.size();i++)
            _cartItems[i].printItemDescription();
    else
        cout << "SHOPPING CART IS EMPTY\n";
}
