#include <iostream>
#include <string>

using namespace std;
#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance){}


void Warrior::attack(Character &opponent){
    double damage = 0.0;
    
    if(opponent.getType() == WARRIOR){
      Warrior &opp = dynamic_cast<Warrior &>(opponent);
    if (opp.allegiance == this->allegiance){
        cout<<"Warrior "<<this->name<<" does not attack Warrior "<<opp.name<<"."<<endl;
        cout<<"They share an allegiance with "<<allegiance<<"."<<endl;
        return;
   }
}
    
    damage = (health / MAX_HEALTH)* attackStrength;
    opponent.damage(damage);
    cout<<"Warrior "<< this->name << " attacks " << opponent.getName() << " --- SLASH!!" <<endl;
    cout<<opponent.getName()<<" takes "<<damage<<" damage."<<endl;
    return;
}



