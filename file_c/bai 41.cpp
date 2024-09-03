#include "stdio.h"
void xuatmang(int x[],int n){
	printf("gia tri cua mang:")	;
		
	for(int i=0;i<n;i++){
	printf("\n %d",x[i]);
	}
	
	
}
void xuatmangnguoc(int x[],int n){
	printf("\n dao nguoc mang");
	for(int i=n-1;i>=0;i--){
		
	printf("\n %d",x[i]);	
		
		
	}
	
}
void daonguocmang(int x[],int n){
	for (int i=0;i<n/2;i++){
	int tamthoi=x[i];
	x[i]=x[n-i-1];
	x[n-i-1]=tamthoi;
		
	}
	
	
	
	
	
	
	
	
}

int main(){
	int a[100],n;
	
	do {
		printf("nhap n (0<n<=100):n=");
		scanf("%d",&n);
	}while (n<1||n>100);
	for(int i=0;i<n;i++){
		printf("a[%d]=",i);
		scanf("%d",&a[i]);
		
		
	}
  daonguocmang(a,n);
	xuatmang(a,n);
	
}
