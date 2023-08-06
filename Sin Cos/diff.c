#include<stdio.h>
#include<math.h>

#define F(x) (sin(x))


int main(){
	double a  = 0.0;
        double b= 2 * 3.1416;
	int n = 100;
	
	double h = (b-a)/n;
	
	double x[101] , y[101] , dy[101];
	x[0] = a;
	
	for(int i =1 ; i<n ; i++){
		x[i] = x[i-1] +h;
	}
	
	x[n] = b;
	
	for(int i = 0 ; i<=n ; i++){
		y[i] = F(x[i]);
	}	
	
	dy[0] = (y[1] - y[0])/(x[1] - x[0]);
	
	for(int i = 1 ; i<n ; i++){
		dy[i] = (y[i+1] -y[i-1])/(x[i+1] -x[i-1]);
	}
	
	dy[n] = (y[n] - y[n-1])/(x[n] - x[n-1]);
	
	printf("\"x\", \"sin(x)\",\"dy\"\n");	
	
	for(int i = 0 ; i<=n ; i++){
		printf("%lf, %lf, %lf\n",x[i],sin(x[i]),dy[i]);
		
	}
	
	return 0;
	}
	
	
	
