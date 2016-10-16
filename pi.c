#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long int number_in_circle=0;
void pick();
int main(int argc,char *argv[])
{
	long long int hit,
		      number_of_toss,
		      toss=0;
	clock_t start_time,end_time;
	start_time=clock();
	if(argc!=2){
		printf("You should input the number of tosses\n");
		return 0;
	}
	number_of_toss=atoi(argv[1]);
	srand(time(NULL));


	for(toss=0;toss<number_of_toss;toss++){
		pick();
	}


	end_time=clock();
	printf("The answer is %f\n",4*number_in_circle/(double)number_of_toss);
	printf("%f s\n",(double)(end_time-start_time)/1000000);
	return 0;
}
void pick()
{
	double x,y,distance_squared;
	x = ((rand()%100000)+1)/100000.0;
	y = ((rand()%100000)+1)/100000.0;
	distance_squared = x*x+y*y;
	if(distance_squared <= 1)
		number_in_circle++;
}
