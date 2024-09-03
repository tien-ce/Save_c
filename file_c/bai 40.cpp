#include "stdio.h"
void hoandoi(int &a, int &b){
	
	int tamthoi;
	tamthoi=a;
	a=b;
	b=tamthoi;
	
}
void sapxeptangdan(int x[],int n){

for(int i=0;i<n-1;i++){
	
	int j;
	for (j=i+1;j<n;j++){
	if (x[i]>x[j]){
		
	hoandoi(x[i],x[j]);
		
		
		
	}	
			
	}
	
}
}


void printfmang(int x[],int n){
	for (int i=0;i<n;i++){
		printf("\n %d",x[i]);
		
		
	}
	
	
	
}
int main(){
	int a[100],n;
	do {
	printf("nhap n (0<n<=100):n=");
	scanf("%d",&n);
}while (n<1||n>100);
	for (int i=0;i<n;i++){
	printf("a[%d]=",i);
	scanf("%d",&a[i]);		
	}	
	sapxeptangdan(a,n);
    printf("sap xep tang dan \n");
	printfmang(a,n);
	
	
	
	
	
	
}
