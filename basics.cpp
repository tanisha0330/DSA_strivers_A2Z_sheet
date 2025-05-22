#include <iostream>
using namespace std;

// 1. Check if the i-th bit is set or not
bool isIthBitSet(int num, int i) {
    // Your code here
     
    if (num & 1<<i){return true;}



    return false;
}

// 2. Check if a number is odd or not
bool isOdd(int num) {
   if (num & 1==1){return true;}
    // Your code here
    return false;
}

// 3. Check if a number is power of 2 or not
bool isPowerOfTwo(int num) {
  if (num & num-1 ==0) return true;
    // Your code here
    return false;
}

// 4. Count the number of set bits
int countSetBits(int num) {
    int cnt=0; 
    while (num!=0)
    {
        num=num&(num-1);
        cnt++; 
    }
    return cnt; 
 
    // Your code here
   
}

// 5. Set the rightmost unset bit
int setRightmostUnsetBit(int num) {
    

 

    // Your code here
    return (num+1);  // i am not sure about this .
}

// 5. Unset the rightmost set bit
int unsetRightmostSetBit(int num) {
    num=num & (num-1);
    // Your code here
    return num;
}

// 6. Swap two numbers without using a third variable
void swapNumbers(int &a, int &b) {
    // Your code here
    a=a^b; 
    b=a^b; 
    a=a^b; 
}


        
        
    
int main() {
    // Sample driver code to test your functions

    int num = 13, i = 1;
    cout << "Is " << i << "-th bit set in " << num << "? " << (isIthBitSet(num, i) ? "Yes" : "No") << endl;

    cout << num << " is " << (isOdd(num) ? "Odd" : "Even") << endl;

    cout << num << " is " << (isPowerOfTwo(num) ? "" : "not ") << "a power of 2" << endl;

    cout << "Number of set bits in " << num << " is " << countSetBits(num) << endl;

    cout << "After setting rightmost unset bit of " << num << ": " << setRightmostUnsetBit(num) << endl;
    cout << "After unsetting rightmost set bit of " << num << ": " << unsetRightmostSetBit(num) << endl;

    int a = 5, b = 7;
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    swapNumbers(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;

   

    int c= 0 & 0; 
    cout << c; 
    return 0;


}
