#include <stdio.h> 
#include <unistd.h> 
  
void main() 
{ 
    fork();
    fork() && fork() || fork() ;
    printf("2");
    return 0; 
} 

please explain how this code is printing '2' 16 times 