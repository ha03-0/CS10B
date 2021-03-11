#include <iostream>
#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
    _name = "none";
    _description = "none";
    _price = 0;
    _quantity = 0;
}
    
ItemToPurchase::ItemToPurchase(std::string name, std::string description, int price, int quantity){
    _name=name;
    _description=description;
    _price=price;
    _quantity=quantity; 
}

void ItemToPurchase::setName(std::string name){
    _name = name;
}

void ItemToPurchase::setPrice(int price){
    _price = price;
}

void ItemToPurchase::setQuantity(int quantity){
    _quantity = quantity;
}
void ItemToPurchase::setDescription(std::string description){
    _description = description;
}

std::string ItemToPurchase::name(){
    return _name;
}

int ItemToPurchase::price(){
    return _price;
}

int ItemToPurchase::quantity(){
   return  _quantity;
}
std::string ItemToPurchase::description(){
    return _description;
}
void ItemToPurchase::printItemCost(){
   std::cout<<_name<<" "<<_quantity<<" @ $"<<_price<<" = $"<<(_quantity* _price)<<std::endl;
}
void ItemToPurchase::printItemDescription(){
    std::cout<<_name<<": "<<_description<<std::endl;
}