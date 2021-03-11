//2.10 LAB 2.1: File I/O - Sum of integers
#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string filename);

int main() {

   string filename;
   int sum = 0;
   
   cout << "Enter the name of the input file: ";
   cin >> filename;
   cout << endl;
   
   sum = fileSum(filename);

   cout << "Sum: " << sum << endl;
   
   return 0;
}

int fileSum (string filename){
int num;
int sum = 0;

ifstream inFS;
inFS.open(filename);

if(!inFS.is_open()){
cout<<"Error opening "<<filename<<endl;
exit(1);

}
 while(inFS>>num){
 sum = sum + num;
 
 }

inFS.close();
    
return sum;
}