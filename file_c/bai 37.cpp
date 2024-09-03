#include "stdio.h"
float trungbinhcong(int x[],int n){
	int i;
int tong=0;
for (i=0;i<n;i++){
	
tong=tong+x[i];	
}		
	return (float)tong/n;
}
int sophantuduong(int x[],int n){
	int i;
	int a=0;
	for(i=0;i<n;i++){
	if (x[i]>0){ 
	a=a+1;}	
	}
	return a;
}

float tongsoduong(int x[],int n){
int i;
int tongsoduong=0;
for( i=0;i<n ;i++){
	
	if (x[i]<0) continue ;
	tongsoduong+=x[i];
	}	

	 return tongsoduong;
}



int main(){
     int n,tong,i;
	float trungbinh;
	do {
		

	
	printf("nhap n(0<n<=100):n=");
	scanf("%d",&n);}while(n<1||n>100);
	
int x[200];

for(i=0;i<n;i++){
printf("\n x[%d]=",i);
scanf("%d",&x[i]);
}
trungbinh=trungbinhcong(x,n);
	printf("trung binh cong =%.2f",trungbinh);
float trungbinhsoduong=(float)tongsoduong(x,n)/sophantuduong(x,n);
if (sophantuduong(x,n)>0){

printf("\n trung binh conng so duong =%.2f",trungbinhsoduong);}
else 
printf("\n khong the tinh trung binh so duong");
}

