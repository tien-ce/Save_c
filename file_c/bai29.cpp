#include "stdio.h"
#include "math.h"
int kiemtraSCP(int a){
  int i= sqrt(a);
  if(i==1){
  	return 0; 
  }
  else if(pow(i,2)==a){
  	return 1;
  }	
    return 0;
    
}
int main(){
	printf("nhap cac so chinh phuong nho hon n \n ");
    int n;

	do{
		printf("nhap n>1:\n n=");
		scanf("%d",&n);
	} while(n<=1);
	
	int k;
	for (k=1;k<n;k++){
	int kt=kiemtraSCP(k);
	if(kt==1){
		printf("\n %d",k);
	}	
	}
}
