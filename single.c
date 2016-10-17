#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc,char *argv[])
{
	if(argc!=2){
		printf("You should input the number of tosses\n");
		return 0;
	}
	
	long long int number_in_circle=0,number_of_toss;
	sscanf(argv[1],"%lld",&number_of_toss);
	srand(time(NULL));
	
	double x,y,distance_squared;
	long long int toss;

	for(toss=0;toss < number_of_toss;toss++){
		x = ((rand()%20000)-9999)/10000.0;
		y = ((rand()%20000)-9999)/10000.0;
		distance_squared = x*x+y*y;
		if(distance_squared <= 1)
			number_in_circle++;
		
	}
	printf("number_in_circle: %lld \n"    
	       "number_of_toss: %lld\n",number_in_circle,number_of_toss);
	printf("The answer is %f\n",4*number_in_circle/(double)number_of_toss);
	return 0;
}

