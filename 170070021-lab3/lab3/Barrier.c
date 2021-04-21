#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t mutex;
pthread_cond_t cond;

int a,left;

void *critical_section(int i);

int main() {

	pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);
    printf("Number of Threads:");
    int num;
    scanf("%d",&num);
    printf("\n");
    left = num;
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
for (int x = 1; x < 200; x++)
{a = 1;}


pthread_mutex_lock(&mutex);
printf("%d Threads remaining to come\n",left);
left = left - 1; 

if (left == 0) { 
	printf("Last thread has arrived\n");
	pthread_cond_broadcast(&cond); 

    }
else {
    while (left != 0) { 
        printf("Thread %d sleeping after Task 1 completion\n",i);
        pthread_cond_wait(&cond, &mutex); 
}
}
pthread_mutex_unlock(&mutex);
printf("Thread %d wakes up and goes to Task2\n",i);
// Task 2
for (int x = 1; x < 200; x++)
{a = 1;}
}