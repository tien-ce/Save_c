#include "stdio.h"
int main(){
    int i,n;
   do{
   
	printf("nhap n(0<n<=20):n=");
	scanf("%d",&n);}
	while(n<0||n>20);
	int a[20];
	for (i=0;i<n;i++){
	printf("a[%d]=",i);
	scanf("%d",&a[i]);
	
	
	}
	printf("\n mang vua nhap la:");
	for (i=0;i<n;i++){
	printf(" %d",a[i]);
	}

	int tong;
	for(i=1;i<n;i++){
	
	tong+=a[i];
}
	printf("\n tong=%d",tong);	
	

}
