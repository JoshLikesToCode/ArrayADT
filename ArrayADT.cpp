#include "ArrayADT.h"
#include <iostream> 

ArrayADT::ArrayADT(int* a, int s, int l)
    : A(a), size(s), length(l) {
}


void ArrayADT::display() const {
    std::cout << "\nElements are: " << std::endl;
    for(int i{0}; i < length; i++)
    std::cout << A[i] << " ";
    std::cout << std::endl;
}

void ArrayADT::append(int val) {
    std::cout << "\nEntering " << val << " into ArrayADT[" << length << "] :" << std::endl;
    A[length] = val;
    length++;
}

bool ArrayADT::insert(int index, int value) {
    // if the element size is invalid
    if (index < 0 || index > length) {
        std::cout << "\nInvalid index." << std::endl;
        return false;
    }
    
    // shift the array elements over
    for (int i=length; i > index; i--) 
        A[i] = A[i-1];
    
    A[index] = value;
    return true;
}

int ArrayADT::get(int index) const {
    // if the element size is invalid
    if (index < 0 || index > length) {
        std::cout << "\nInvalid index." << std::endl;
        return -9999;
    }
    // display value at index    
    std::cout << "\nArrayADT[" << index << "] = " << A[index] << std::endl;
    return A[index];
}

bool ArrayADT::set(int index, int value) {
    // if the element size is invalid
    if (index < 0 || index > length) {
        std::cout << "\nInvalid index." << std::endl;
        return false;
    } 

    A[index] = value;
    return true;
}


bool ArrayADT::del(int index) {
    
    // if the size is invalid
    if (index < 0 || index > length) {
        std::cout << "\nInvalid index." << std::endl;
        return false;
    }
    
    // remove the value from given index (by placing in temp)
    int temp{0};
    temp = A[index];
    
    // shift the elements over
    for(int i=index; i < (length-1); i++)
        A[i] = A[i+1];
    
    return true;
}


int ArrayADT::find_max() {
    int temp;
    temp = A[0];
    
for(int i{0}; i < length; ++i) {
    if (temp < A[i]) {
        temp = A[i];
    }
}
    std::cout << "The max element in the array is " << temp << std::endl;
    return temp;
}

double ArrayADT::find_avg() {
    int SIZE = length + 1;
    double total;
    
    for (int i{0}; i < length; ++i )
        total += A[i];
    
    std::cout << "The average of the array values is " << (double)(total / SIZE) << std::endl;
    return (total/SIZE);
}

int ArrayADT::find_sum() {
    int total{0};
    
    for (int i{0}; i < length; ++i)
        total += A[i];
        
        std::cout << "The total of all the array's values is " << total << std::endl;
        return total;
}

void ArrayADT::rev() {
    
    int *B;
    int count{0};
    B= new int[length];
    
    for (int i=length - 1; i >= 0; i--) {
        B[count] = A[i];
        count++;
    }
    
    // replace arr with B's newly reversed array
    for(int i{0}; i < length;++i)
        A[i] = B[i];
    
    delete [] B;
}


void ArrayADT::left_rotation() {
    
    int *B;
    B = new int [length];
    int place_holder;
    place_holder = A[0];
    
    for (int i{0}; i < length; ++i) {
        B[i] = A[i+1];
    }
    
    for(int i{0}; i < length;++i)
        
        
        A[i] = B[i];
    
    delete [] B;
    
    A[length-1] = place_holder;
}


bool ArrayADT::is_sorted() {
    int temp;
    temp = A[0];
    
    for(int i{0}; i < length; ++i) {
        if (temp > A[i+1])
            return false;
    }
    // list is sorted
    return true;
}


ArrayADT ArrayADT::merge_array(const ArrayADT &arr) {
    int combinedSIZE;
    combinedSIZE = (length + arr.length);

    int temp_array[combinedSIZE];
    ArrayADT temp(temp_array, combinedSIZE, combinedSIZE);
    
   int count{0};
    
    for(int i{0}; i < length; ++i) {
        temp.A[i] = A[i];
    }
    for (int i = length; i <= combinedSIZE; ++i) {
        temp.A[i] = arr.A[count];
        count++;
    }
    
    std::cout << "Merged Elements are : ";
    for (int i{0}; i < temp.length; ++i) {
        std::cout << temp.A[i] << " ";
    }
    
    return temp;
}

void ArrayADT::negatives_to_the_left() {

    int count{0};
    int i;
    i = length-1;
    
    while(count < i) {
        while (A[count] < 0 ) {count++;}
        while (A[i] >= 0) {i--;}
        if (count < i ) {
            int temp = A[count];
            A[count] = A[i];
            A[i] = temp;
            
        }
    }
}

bool ArrayADT::binary_search(int value) const {
    int left, right;
    
    left = 0;
    right = (length-1);
    
    while (left <= right) {
        int middle = (left+right) / 2;
        if (A[middle] == value) {
            std::cout << value << " was found at index " << middle << std::endl;
            return true;
        } else if (A[middle] > value) 
            right = middle -1;
        else
            left = middle + 1;
    }
    std::cout << value << " was not found." << std::endl;
    return false;
}

bool ArrayADT::linear_search(int value) const {
    int count{0};
    
    for (int i{0}; i < length; i++) {
        if (A[i] == value) {
            // using bring to head method for easier search next time
            // swap(&arr.A[i], &arr.A[0]);
            std::cout << value << " is located at index " << count << std::endl;
            return true;
        } else {
            count++;
        }
    }
    std::cout << value << " was not found." << std::endl;
    return false;
}

ArrayADT::~ArrayADT() {
    std::cout << "~ArrayADT() called." << std::endl;
    delete [] A;
}





