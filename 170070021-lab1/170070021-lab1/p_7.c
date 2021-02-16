
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
        printf("Child: %d\n",getpid());
        getchar();
  
    }
   

    if(r1!=0)
    
    {   printf("Parent: %d\n",getpid());
        sleep(60);
        wait(NULL);
        printf("Exiting Parent: %d\n", getpid());
    
        
    }
   
   

    
    


  
    


    return 0; 
} 
