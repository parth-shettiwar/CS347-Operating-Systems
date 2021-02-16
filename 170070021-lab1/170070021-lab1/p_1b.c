
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h>
#include <sys/wait.h>

int main() 

{

    int r;
  
   
    r = fork();
    if(r!=0)
    {
      
        wait(NULL);
        printf("The child process with process ID %d has terminated\n",r);
       
    }
    if(r==0)
    {
        printf("Child process ID: %d\n",getpid());
    }

    return 0; 
} 
