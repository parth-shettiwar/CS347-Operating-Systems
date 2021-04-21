#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

int count = 0;
 
pthread_mutex_t m;;
struct arg_struct {
    int arg1;
    int arg2;
};

void *critical_section(void *arguments)
{  
   struct arg_struct *args1 = arguments;
   pthread_mutex_lock( &m ); 
   count = count + 1;  
   printf("Critical section count: %d\n",count);
   printf("Thread number %d with order number %d executed\n",args1-> arg1,args1-> arg2); 
   
   pthread_mutex_unlock( &m );
}


main()

  
{  
   pthread_mutex_init(&m, NULL);
   printf("Number of Threads: ");
   int num;
   scanf("%d",&num);
   pthread_t thread[num];
   int Ordering[num];
   struct arg_struct args[num];
   int temp;
   printf("Enter Order of Threads: ");
   for(int i=0;i<num;i++)
   {
       scanf("%d",&temp);
       Ordering[temp-1] = i;
       
   }
   
   printf("\n");

   for(int i=0;i<num;i++)
   {
      args[i].arg1 = Ordering[i];
      args[i].arg2 = i+1;
      pthread_create( &thread[Ordering[i]], NULL, &critical_section,(void *)&args[i]);
      pthread_join( thread[Ordering[i]], NULL);
   }

  
  

   exit(0);
}


      