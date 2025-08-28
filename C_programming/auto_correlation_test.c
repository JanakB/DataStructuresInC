//Program to implement auto-correlation test 
#include<stdio.h>
#include<math.h>
#define N 100
int main(){
	int i, n, m, I, k;
	float r[N], Rho, M, sd, k_value = 0.0, Z0;
	float alpha, alphaValue;
	printf("Enter number of random number to be tested: ");
	scanf("%d", &n);
	
	printf("Enter alpha: ");
	scanf("%f", &alpha);
	
	printf("Enter alpha value: ");
	scanf("%f", &alphaValue);
	
	printf("Enter the random numbers: ");
	for(i = 0; i < n; i++){
		scanf("%f",&r[i]);
	}
	
	printf("Enter the value of difference of number to be tested (m): ");
	scanf("%d",&m);
	
	printf("Enter the starting point from to be tested (i): ");
	scanf("%d",&I);
	
	M = floor(((n-I)/m)-1);
	printf("M = %.2f\n",M);
	
	for( k = 0; k < M; k++ ){
		k_value = k_value + (r[I+k*m] * r[I+(k+1)*m]); 
	}
	
	Rho = ((1/(M+1)) * k_value) - 0.25;
		printf("Rho = %.2f\n", Rho);
	
	sd = (sqrt(13*M + 7) / (12*(M + 1)));
	printf("Standard Deviation = %.2f\n", sd);	
	
	Z0 = Rho / sd;
	printf("Z0 = %.2f\n", Z0);
	
	if(Z0 < alphaValue){
		printf("----------------------------\n");
		printf("The Hypothesis is ACCEPTED.");
		printf("----------------------------");
	}
	else{
		printf("----------------------------\n");
		printf("The Hypothesis is REJECTED.");
		printf("----------------------------");
	}
	
}
