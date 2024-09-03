#include "stdio.h"
void nhapmang1(int x[],int &n){
	do{
	printf("nhap gia tri n(0<n<=100): n=");
	scanf("%d",&n);
	
} while (n<1||n>100);
for(int i=0;i<n;i++){
	printf("\n x[%d]=",i);
	scanf("%d",&x[i]);
	
}

	
	
}

	void xuatmang1(int x[],int n){
	printf("gia tri cua mang:")	;
		
	for(int i=0;i<n;i++){
	printf("\n %d",x[i]);
	}
}
void daonguocmang1(int x[],int n){
	
	for(int i=0;i<n/2 ;i++){
	int tamthoi;
	tamthoi=x[i];
	x[i]=x[n-i-1];
	x[n-i-1]=tamthoi;
	
}
}
int main(){
    int a[100],n;
	nhapmang1(a,n);
	xuatmang1(a,n);
	printf("\n dao nguoc mang \n ");
	daonguocmang1(a,n);
	xuatmang1(a,n);
}

















