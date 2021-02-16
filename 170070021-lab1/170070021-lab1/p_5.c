
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h>
#include <sys/wait.h>
#include<fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char **argv) 

{

    int r1,b;
    
    
    close(0);
    b = open(argv[1],O_RDWR|O_CREAT);
    
    
   
    r1 = fork();
   
   
    if(r1!=0)


    {

        wait(NULL);
 
    }
    if(r1==0)

    {  
        
        char *args[] = {NULL};
        execv("./sample",args);
    }

  
    


    return 0; 
} 