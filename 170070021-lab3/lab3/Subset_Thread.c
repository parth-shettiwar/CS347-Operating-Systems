#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t mutex,mutex2;
pthread_cond_t cond;

int a,left;

void *critical_section(int i);

int main() {

	pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&mutex2, NULL);
    pthread_cond_init(&cond, NULL);
    printf("Number of Threads: ");
    int num;
    scanf("%d",&num);
    printf("Number of Subset of Threads working at one time: ");
    scanf("%d",&left);
    printf("\n");
    pthread_t thread[num];
    for (int i = 0; i < num; i++)  
        
           { pthread_create(&thread[i], NULL, &critical_section, i);}

   for(int i=0;i<num;i++)
   {
      pthread_join( thread[i], NULL);
   }
    exit(0);
}



void *critical_section(int i) {
// Task 1    
for (int x = 1; x < 1000; x++)
{a = 1;}

pthread_mutex_lock(&mutex);

while (left == 0) { 
        printf("Thread %d sleeping after Task 1 completion\n",i);
        pthread_cond_wait(&cond, &mutex); 

}



if(left!=0)
{
left = left - 1; 
}
printf("Thread %d running. Buffer Size = %d\n",i,left);
pthread_mutex_unlock(&mutex);


// Task 2
for (int x = 1; x < 100000; x++)
{a = 1;}
pthread_mutex_lock(&mutex2);
left = left + 1;
printf("Thread %d Finished. Buffer Size = %d\n",i,left);

pthread_cond_broadcast(&cond); 
pthread_mutex_unlock(&mutex2);
}