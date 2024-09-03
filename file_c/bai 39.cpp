#include "stdio.h"
int min(int x[],int n){
int min=x[0];
for(int i=1;i<n;i++){

if(x[i]<min){
	min=x[i];
}	
}
	
	
return min;	
	
	
}
int max(int x[],int n){
	
int max=x[0];
for (int i=1;i<n;i++){
	if (x[i]>max){
	max=x[i];	
		
	}
	
	
	
}	
	
	return max;
	
}






int main(){
	int a[100],n;
	do {
     printf("nhap n (0<n<=100):n=");
	 scanf("%d",&n);
	 	
	} while(n<1||n>100);
	for (int i=0;i<n;i++){
		printf("a[%d]=",i);
	    scanf("%d",&a[i]);
	    
		
	}
	int giatrimin;
	giatrimin=min(a,n);
	printf("gia tri nho nhat cua day:%d",giatrimin);
	int giatrimax;
	giatrimax=max(a,n);
	printf("\n gia tri lon nhat cua day:%d",giatrimax);
	
	}
