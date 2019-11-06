 #ifndef _ARRAYADT_H_
#define _ARRAYADT_H_

class ArrayADT
{
private:
    int *A;
    int size;
    int length;
    
public:
    // Constructor
    ArrayADT(int* a, int s, int l);


    // displays array
    void display() const; 
    
    // appends a value into the end of the array
    void append(int val);
    
    // Inserts a value and shifts the array accordingly
    bool insert(int index, int value);
    
    // displays value at given index
    int get(int index) const;
    
    // sets the ArrayADT[]'s value at given index, doesn't bother to shift.
    bool set(int index, int value);
    
    // Deletes value at given index
    bool del(int index);
    
    // find max value, find average of the values, find the total of the values added together
    int find_max();
    double find_avg();
    int find_sum();
    
    // Reverses the array
    void rev();
    
    // Rotates the array to the left
    void left_rotation();
    
    // check to see if array is sorted or not
    bool is_sorted();
    
    // Returns an ArrayADT containing the operating array merged with the parameter array
    ArrayADT merge_array(const ArrayADT &arr);
    
    // Places negative numbers to the left of the array
    void negatives_to_the_left();
    
    // Binary search array
    bool binary_search(int value) const;
    
    // Linear search the array
    bool linear_search(int value) const;
    
    // dctor
    ~ArrayADT();
    
    

};

#endif // _ARRAYADT_H_
