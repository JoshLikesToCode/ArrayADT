#include <iostream>
#include <array>
#include "ArrayADT.h"

using namespace std;


int main() {

    int sorted_array1[10] = {1,22,33,99,100,500};
    int int_array1[10] = {1,2,3,4,5};
    int int_array2[10] = {5,4,3,2,1,-420};
    
    
    ArrayADT arr1(int_array1, 5, 10);
    ArrayADT arr2(int_array2, 6, 10);
    ArrayADT sorted_array(sorted_array1,6,10);
    
    arr1.display();
    
    arr1.merge_array(arr2);
    arr1.display();
    arr2.negatives_to_the_left();
    arr2.display();
    cout << endl;
    arr1.display();
    arr1.binary_search(3);
    arr1.binary_search(5);
    arr1.binary_search(100000);
    arr1.display();
    arr1.linear_search(3);
    arr1.linear_search(5);
    arr1.linear_search(100000);
    arr1.display();
    
    arr1.append(5);
    arr1.display();
    
    arr1.insert(6, 420);
    arr1.display();
    
    arr1.get(5);
    arr1.display();
    
    cin.get();
    
    
    return 0;
}