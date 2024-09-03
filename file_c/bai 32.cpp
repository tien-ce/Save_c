#include "stdio.h"
#include "math.h"
int giaithua(int n){
	if(n==0|| n==1)
	return 1;
	return n*giaithua(n-1);
	
	
}
int main(){
	int n,k;
	do {
	printf("nhap n>=0 \n ");
	scanf("%d",&n);
} while (n<0);
     k=giaithua(n);
      printf("n!=%d",k);
		
}
