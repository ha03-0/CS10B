#include <iostream>
#include "Distance.h"
using namespace std;

Distance::Distance(){
    feet=0;
    inches=0.0;
    return;
}

Distance::Distance(unsigned ft, double in){
    double temp1;
    if(in<0)
        in *= -1;
    temp1=static_cast<double>(ft)*12+in;
    unsigned int fts = (static_cast<int>(temp1)/12);
    inches=temp1-(static_cast<double>(fts)*12);
    feet= fts;
    return;
}

Distance::Distance(double in){
    if(in<0){
        in*=-1;
    }
    unsigned int temp = static_cast<int>(in)/12;
    inches=in-(static_cast<double>(temp)*12);
    feet=temp;
    return;
    }

unsigned Distance::getFeet() const{
    return feet;
}

double Distance::getInches() const{
    return inches;
}

double Distance::distanceInInches() const{
    return(inches+(static_cast<double>(feet)*12.0));
}

double Distance::distanceInFeet() const{
    return(static_cast<double>(feet)+(inches/12.0));
}

double Distance::distanceInMeters() const{
    return((inches+(static_cast<double>(feet)*12.0))*0.0254);
}

 Distance Distance::operator+(const Distance &rhs) const{
    Distance temp;
    unsigned int ft = (static_cast<int>(inches + rhs.inches)/12);
    temp.inches = (inches + rhs.inches) - (static_cast<double>(ft)*12);
    temp.feet = feet + rhs.feet + ft;
    return temp;
}
 Distance Distance::operator-(const Distance &rhs)const{
    Distance temp;
    double temp1;
    double temp2;
    double in;
    temp1=static_cast<double>(feet)*12+inches;
    temp2=static_cast<double>(rhs.feet)*12+rhs.inches;
    in = temp1-temp2;
    if(in<0)
        in *=-1;
    unsigned int ft= (static_cast<int>(in)/12);
    temp.inches = in - (static_cast<double>(ft)*12);
    temp.feet=ft;
    return temp;
}
ostream& operator<<(ostream &out, const Distance &rhs){
    out<< rhs.feet<<"' " << rhs.inches <<"\"";
    return out;
}




