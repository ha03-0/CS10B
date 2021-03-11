//include any standard libraries needed
#include <iostream>
using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize){
    double sum = 0.0;
    int i = 0;
    for(i = 0; i < arraySize; i++){
        sum += array[i];
    }
    return double(sum)/double(arraySize);
    }
//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index){
    double temp = array[index];
    for(int i=index; i< arraySize-1; i++){
        array[i] = array[i+1];
    }

    array [arraySize-1]=temp;
    arraySize--;
    return;
    }

// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize){
    for(int i=0; i<arraySize-1; i++){
        cout<<array[i]<<",";
    }
    cout<<array[arraySize-1];
    cout<<endl;
    }

const int ARR_CAP = 100;

int main(int argc,char*argv[]) {
   
  if(argc!= 2){
      cout<<"Error opening file."<<endl;
      return 0;
  }
    
    
    //double Array[ARR_CAP];
    string fileName=argv[1];
    ifstream fin;
    fin.open("one_hundred.dat");
    double*array=double[ARR_CAP];
    if(fin){}
    int size = 0;
    
    
    for(unsigned int i=0;i<ARR_CAP;++i){
        cin>>temp;
            Array[ARR_CAP]=temp;
        }
    cout<<endl;
    cout<<"Mean: "<<mean(Array,size)<<endl;
    cout<<endl;
    cout<<"Enter index of value to be removed: ";
    cin>>removeInt;
    cout<<endl;
    cout<<"Before removing value: ";
    display(Array,size);
    remove(Array, size, removeInt);
    cout<<"After removing value: " ;
    display(Array,size);

    return 0;    
    }

   