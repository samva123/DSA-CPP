// #include <iostream>
// class TollBooth {
// private:
//     int totalCars;
//     double totalCash;
// public:
//     // Constructor
//     TollBooth() : totalCars(0), totalCash(0.0) {}
//     // Function to count a paying car
//     void payingCar() {
//         totalCars++;
//         totalCash += 50.0;
//     }
//     // Function to count a nonpaying car
//     void nopayCar() {
//         totalCars++;
//     }
//     // Function to display the totals
//     void display()  {
//         std::cout << "Total Cash : " << totalCash << "/-" << std::endl;
//         std::cout << "Total Cars : " << totalCars << std::endl;
//     }
// };
// int main() {
//     TollBooth tollbooth;
//     char input;
//     //std::cout << "Enter 'p' for paying car, 'n' for nonpaying car, 'q' to quit:" << std::endl;
//     while (std::cin >> input) {
//         if (input == 'p') {
//             tollbooth.payingCar();
//         } else if (input == 'n') {
//             tollbooth.nopayCar();
//         } else if (input == 'q') {
//             tollbooth.display();
//             break;
//         } 
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string binary) {
  // Write your code here
  int decimal = stoi(binary, nullptr, 2);
  return decimal;
  
}

int main(){
   cout <<  binaryToDecimal("101001");
}