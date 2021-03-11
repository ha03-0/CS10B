using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, string familyName): Character(ELF, name, health, attackStrength), familyName(familyName){}
  
void Elf::attack(Character& opponent){
    double damage = 0.0;
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        
        if(opp.familyName == this->familyName){
            cout<<"Elf "<< this->name << " does not attack Elf " << opp.getName()<<"."<<endl;
            cout<<"They are both members of the "<<familyName << " family."<<endl;
            return;
        }
    
    }
    damage = (health/ MAX_HEALTH)* attackStrength;
    opponent.damage(damage);
    cout<<"Elf "<<name<<" shoots an arrow at "<<opponent.getName()<< " --- TWANG!!" <<endl;
    cout<< opponent.getName() << " takes " <<damage<<" damage."<<endl;
            
  //   double damage = (health/ MAX_HEALTH)* attackStrength;
   // cout<<"Elf"<<name<<damage<<"damage."<<endl;
}

    
    
    
 

    
    
    
