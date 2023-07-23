#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) -10)
#define DF(x) (3*(x)*(x) + 8*(x))

int main(void){
	int n = 100 ,i;
	double x0 = 1.25 , x1;
	//if(F(x0)*F(x1) >0) exit(0);
	
	printf("----------------------------------------------------------------\n");
	printf("iter  	 x0        x1        f(x0)       f'(x0)       f(x1)\n");
	printf("----------------------------------------------------------------\n");
	
	for(i=1; i<n ; i++){
		x1 = x0 -(F(x0)/DF(x0));
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i,x0,x1, F(x0),DF(x0),F(x1));
		if(fabs(F(x1)) < EPS){
		printf("ROOT (NR) = %lf\n" , x1);
		exit(0);
		}
		x0 = x1 ;	 
	}
}		     
