
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
        printf("Parent: My process ID: %d\n",getpid());
        printf("Parent: Child’s process ID: %d\n",r);
        getchar();
       
    }
    if(r==0)
    {
        printf("Child: My process ID: %d\n",getpid());
        printf("Child: Parent’s process ID: %d\n",getppid());
    }

    return 0; 
} 
