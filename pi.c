#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char *argv[])
{
	long long int hit,
		      number_in_circle=0,
		      number_of_toss,
		      toss=0;
	if(argc!=2){
		printf("You should input the number of tosses\n");
		return 0;
	}
	number_of_toss=atoi(argv[1]);
	double x,y,distance_squared;
	srand(time(NULL));
	for(toss=0;toss<number_of_toss;toss++){
		x = ((rand()%10000)+1)/10000.0;
		y = ((rand()%10000)+1)/10000.0;
		distance_squared = x*x+y*y;
		if(distance_squared <= 1)
			number_in_circle++;
	}

	printf("The answer is %f\n",4*number_in_circle/(double)number_of_toss);
	return 0;
}
