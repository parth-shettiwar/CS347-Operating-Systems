#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

#include <string.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t m,m2,m3,m4 ;
pthread_cond_t cv,cv2;
int a,aaa;
struct arg_struct {
    int arg1;
    int arg2;
};
int remain = 0;
int remain1 = 0;

void *critical_section(void *arguments);
int main()

  
{  
    
    int temp;

    pthread_mutex_init(&m, NULL);
    pthread_mutex_init(&m2, NULL);
    pthread_mutex_init(&m3, NULL);
    pthread_mutex_init(&m4, NULL);
    
    pthread_cond_init(&cv, NULL);
    pthread_cond_init(&cv2, NULL);
    printf("Number of Threads: ");
    int num;
    scanf("%d",&num);
    pthread_t thread[num];
    int Priority[num];
    printf("Enter Priority of Threads: ");
    
    remain = num;
    for(int i=0;i<num;i++)
   {
       scanf("%d",&temp);
       Priority[i] = temp;
 
   }
    printf("\n");
   struct arg_struct args[num];

   for(int i=0;i<num;i++)
   {
      args[i].arg1 = i;
      args[i].arg2 = Priority[i]; 
      pthread_create( &thread[i],  NULL, &critical_section,(void *)&args[i]);
   }
   
   for(int i=0;i<num;i++)
   {
      pthread_join( thread[i], NULL);
   }
  
   return 0;
   exit(0);
}


      void *critical_section(void *arguments)
{ 


    pthread_mutex_lock(&m);
    remain = remain - 1; 
   
    if (remain == 0) { 
    	pthread_cond_broadcast(&cv); 
        }
    else {
        while (remain != 0) { 
            
            pthread_cond_wait(&cv, &m); 
    }
    }
    pthread_mutex_unlock(&m);

   struct arg_struct *args1 = arguments;
    
   pthread_mutex_lock(&m4);
   printf("Thread %d arrirrves\n",args1 -> arg1);
   if(args1 -> arg2 == 1)
   {
       remain1 = remain1 + 1;
   }
   printf("Number of current High priority threads in queue or execution = %d\n",remain1);
   pthread_mutex_unlock(&m4);
   pthread_mutex_lock(&m2);
//    

     
   
    
    
        while(remain1 != 0 && args1 -> arg2==0) {
            printf("Thread  %d sleep with priority %d\n",args1 -> arg1,args1 -> arg2);
             pthread_cond_wait(&cv2, &m2); }
         

            pthread_mutex_lock(&m3);
            printf("Thread %d acquires lock with priority %d\n",args1 -> arg1,args1 -> arg2);
            for(int jj = 0;jj<20000;jj++)
            {
                aaa=1;
            }
            if(args1 -> arg2==1)
            {remain1 = remain1 - 1;
            
            
            }
            printf("Thread %d work done with priority %d. High priority threads in queue or execution = %d\n",args1 -> arg1,args1 -> arg2,remain1);
            pthread_mutex_unlock(&m3);
    
    if (remain1 == 0) { 
    	pthread_cond_broadcast(&cv2); 
        
        }
   pthread_mutex_unlock(&m2);

}