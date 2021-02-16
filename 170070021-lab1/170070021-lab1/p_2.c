
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h>
#include <sys/wait.h>

int main() 

{

    int r1,r2,r3;
   
    r1 = fork();
   
   
    if(r1!=0)
    {
        printf("I am parent with PID %d\n",getpid());
        r2 = fork();
        if(r2!=0)
        {
            r3=fork();
            if(r3==0)
            {
                printf("I am child with PID %d from PPID %d\n",getpid(),getppid()); 
            }
        }
        if(r2==0)
        {
           printf("I am child with PID %d from PPID %d\n",getpid(),getppid()); 
        }
        wait(NULL);
       
       
    }
    if(r1==0)

    {  
        printf("I am child with PID %d from PPID %d\n",getpid(),getppid());
    }

    


    return 0; 
} 
