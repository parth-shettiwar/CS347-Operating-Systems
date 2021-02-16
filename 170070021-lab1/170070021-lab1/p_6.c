
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h>
#include <sys/wait.h>

int main(int argc,char **argv) 

{   
   
    int r1;
    r1 = fork();
    
   

   
    
    if(r1==0)

    {   
        printf("Child: Child process ID:%d\n",getpid());
        printf("Child: Parent process ID:%d\n",getppid());
        sleep(2);
  
        printf("Child: Child process ID:%d\n",getpid());
        printf("Child: Parent process ID:%d\n",getppid());

        
        
        
       
  
    }
   

    if(r1!=0)
    
    {   
        sleep(1);
        printf("Parent: Parent process ID:%d\n",getpid());

   
    }
   
    
    return 0; 
} 
