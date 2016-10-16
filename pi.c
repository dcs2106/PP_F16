#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#define thread_count 4

long long int number_in_circle=0,number_of_toss;
pthread_mutex_t mutex;
void *pick();
int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("You should input the number of tosses\n");
		return 0;
	}
	
	long thread;

	sscanf(argv[1],"%lld",&number_of_toss);
	srand(time(NULL));
	pthread_t *thread_handles;
	pthread_t thread1,thread2,thread3,thread4;
	thread_handles = (pthread_t *)malloc (thread_count*sizeof(pthread_t));
	pthread_mutex_init(&mutex,NULL);//mutex initial
	for(thread = 0; thread < thread_count ; thread++)
		pthread_create(&thread_handles[thread],NULL,pick,NULL);
	
	
	for(thread = 0; thread < thread_count ; thread++)
		pthread_join(thread_handles[thread],NULL);
	
	pthread_mutex_destroy(&mutex);
	free(thread_handles);
	printf("%lld    %lld\n",number_in_circle,number_of_toss);
	printf("The answer is %f\n",4*number_in_circle/(double)number_of_toss);
	return 0;
}
void *pick()
{
	double x,y,distance_squared;
	long long int toss,
		      bound=number_of_toss/thread_count;
	for(toss=0;toss < bound;toss++){
		x = ((rand()%100000)+1)/100000.0;
		y = ((rand()%100000)+1)/100000.0;
		distance_squared = x*x+y*y;
		if(distance_squared <= 1){
			pthread_mutex_lock(&mutex);
			number_in_circle++;
			pthread_mutex_unlock(&mutex);
		}
	}
	pthread_exit(NULL);
}
