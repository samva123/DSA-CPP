// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std ; 

int main() {
    string sex ;
    cin >> sex ;

    int experience ;
    cin >> experience;
    
    string positio ;
    cin >> positio ;
    
    if(sex == "male"){
        if(experience > 10){
            if(positio == "graduate"){   
                cout << "salary is 10000";
            }
            else{
                cout << "slary is 3000";
            }
         
            }

            else{
                cout << "salary is 9000";
            }
        
    }
    else{
        cout << "female";
    }
    

    return 0;
}