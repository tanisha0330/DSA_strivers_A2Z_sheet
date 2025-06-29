#include <iostream>
#include <list>
using namespace std ; 


// resizable 
// you cannot jump to random index to access it 
// to store multiple elements of same type 


int main()
{
  //list<string> cars;
  list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

  for (string car : cars) {
  cout << car << " , ";
}
cout <<endl ; 



// Get the first element
cout << cars.front();  // Outputs Volvo
cout <<endl ; 


// Get the last element
cout << cars.back();  // Outputs Mazda
cout <<endl ; 


// Add an element at the beginning
cars.push_front("Tesla");

// Add an element at the end
cars.push_back("VW");


// Remove the first element
cars.pop_front();

// Remove the last element
cars.pop_back();

cout << cars.size();
cout <<endl ; 


cout << cars.empty();  
cout <<endl ; 







}
  
