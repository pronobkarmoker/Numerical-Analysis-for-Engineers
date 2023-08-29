#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) -10)

int main(void){
	int n = 100 ,i;
	double a = 1.5 , b= 2 , c;
	
	
	printf("--------------------------------------------------------------------------\n");
	printf("iter  	 a           b          c        f(a)        f(b)        f(c)\n");
	printf("--------------------------------------------------------------------------\n");
	
	for(i=1; i<n ; i++){
		
		c = b-(((F(b))*(b-a))/(F(b)-F(a)));
		
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i,a,b,c, F(a),F(b),F(c));
		if(fabs(F(c)) < EPS){
		printf("ROOT(FP) = %lf\n" , c);
		exit(0);
		}
		else{
		     a=b;
		     b=c ;
		}     	 
	}
}		     
