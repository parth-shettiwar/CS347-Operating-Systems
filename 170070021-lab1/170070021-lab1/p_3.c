
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h>
#include <sys/wait.h>

int main() 

{

    int r1;
   
    r1 = fork();
   
   
    if(r1!=0)
    {
        wait(NULL);
        
       
    }
    if(r1==0)

    {  
       
        char *args[] = {NULL};
        execv("./runme",args);
    }

  
    


    return 0; 
} 
