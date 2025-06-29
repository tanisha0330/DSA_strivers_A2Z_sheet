#include <iostream>
#include <vector>  
using namespace std ; 


//resizable 
int main(){
  vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

// Get the first element
cout << cars[0]<<endl;  

// Get the second element
cout << cars[1]<<endl;

// Get the first element
cout << cars.front()<<endl;

// Get the last element
cout << cars.back()<<endl;


// Get the third element
cout << cars.at(2)<<endl;

// Change the value of the first element
cars[0] = "Opel";


// Change the value of the first element
cars.at(0) = "maruti";


cars.push_back("Tesla");

cars.pop_back();

cout << cars.size(); 

cout << cars.empty(); 

//iteration 



for (int i = 0; i < cars.size(); i++) {
  cout << cars[i] << " , ";
}

cout<<endl; 

//OR
for (string car : cars) {
  cout << car << ", ";
}


}
  
