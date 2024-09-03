#include "stdio.h"
int sofibonacci( int n){
int r;
if(n==0)
return 0;
else if(n==1)
return 1;
else
{


return sofibonacci(n-1)+sofibonacci(n-2); 	

}
	
	
	



	}
	

int main(){
	int n;
	do{ 

	printf("nhap n=");
	scanf("%d",&n);}
	while (n<0);
	int r;
	r=sofibonacci(n);
	printf("%d",r);
	
	
	
}
