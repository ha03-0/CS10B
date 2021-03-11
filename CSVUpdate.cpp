#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
   
   string inputFile; 
   string outputFile;  
    
    inputFile = argv[1] ;
    outputFile =  argv [2];
 
    ifstream inFS;
    ofstream onFS;
    
     inFS.open(inputFile);
     onFS.open(outputFile);
 
    if(!inFS.is_open()){
       cout<< "Error opening "<<inputFile<<endl;
       exit(1);
       
   }
  
    if(!onFS.is_open()){
       cout<< "Error opening "<<outputFile<<endl;
       exit(1);

    }
    vector<int>list;
   // char ch;
    int num; 
    int sum=0;
    int avg;
   int count=0;
     
        char ch;
    while(inFS>>num){
        list.push_back(num);
        sum += num;
          count +=1;
         inFS>>ch;
        
    }
    
        
        
    avg= sum/list.size();
    for (unsigned int i=0; i< list.size(); ++i){
     list.at(i)=list.at(i)-avg;
  
    }
    for(unsigned int i=0; i< list.size(); ++i){
        onFS << list.at(i);
        if(i<list.size()-1){
            onFS<<",";
        }
    }
    inFS.close();
       onFS.close();
   // Convert each value within vector to be the difference between the original value and the average.
   
   // Create output stream and open/create output csv file.

   // Verify file opened or was created correctly.
   // Output error message and return 1 if file stream did not open correctly.
   
   // Write converted values into ouptut csv file, each integer separated by a comma.
   
   // Close output stream.
   
   return 0;
}
