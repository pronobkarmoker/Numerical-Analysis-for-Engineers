#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define EPS 10.0e-6
#define F(x) ((x)*(x)*(x) + 4*(x)*(x) -10)

int main(void){
	int n = 100 ,i;
	double a = 1.25 , b= 1.5 , c;
	if(F(a)*F(b) >0) exit(0);
	
	printf("--------------------------------------------------------------------------\n");
	printf("iter  	 a           b          c        f(a)        f(b)        f(c)\n");
	printf("--------------------------------------------------------------------------\n");
	
	for(i=1; i<n ; i++){
		c=(a+b)/2;
		printf("%3d %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf %10.6lf\n", i,a,b,c, F(a),F(b),F(c));
		if(fabs(F(c)) < EPS){
		printf("ROOT (BM) = %lf\n" , c);
		exit(0);
		}
		if(F(a)*F(c) <0)
			b =c;
		else 
		     a =c ;	 
	}
}		     
