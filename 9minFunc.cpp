#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
    if(arrSize == 0){
        return nullptr;
    }
    if (arrSize == 1){
        return arr;
    }
    else{
        const int * temp = min(arr, arrSize - 1);
        if (*temp < arr[arrSize - 1]) {
            return temp;
        }   
            else{
                return (arr + (arrSize-1));
        }
    }
}