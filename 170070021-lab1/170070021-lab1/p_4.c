
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
    int r1;
    
    

    int b;
    
    b = open(argv[1],O_RDWR|O_CREAT);
    r1 = fork();
    
    if(r1==0)

    {   
 
        write(b,"Hello world! I am child",strlen("Hello world! I am child"));
    
    }
   

    if(r1!=0)
    {
    write(b,"Hello world! I am parent\n",strlen("Hello world! I am parent\n"));
    wait(NULL);

    printf("The child process with process ID %d has terminated\n",r1);
    
    }
   
   

    
    


  
    


    return 0; 
} 
