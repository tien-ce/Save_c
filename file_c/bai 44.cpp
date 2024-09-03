#include "stdio.h"
void nhapmang2(int x[],int &n){

do {
	printf("nhap gia tri n(0<n<=100): n=");
 	scanf("%d",&n);
	
}	while(n<1||n>100)	;
for (int i=0;i<n;i++){
	printf("x[%d]=",i);	
	scanf("%d",&x[i]);
	
}					
}
void xuatmang2(int x[],int n){

	for(int i=0 ; i<n;i++){
	printf(" %d ",x[i]);
}	
}
void xoamangtaivitri(int x[],int &n,int vitri){
for (int i=vitri;i<n-1;i++){
x[i]=x[i+1];	
}	
n--;
}
void xoamangtheogiatri(int x[],int &n){
int giatri;

printf("\n nhap vao gia tri can xoa: ");
scanf("%d",&giatri);
for (int i=0;i<n;i++){
if(x[i]==giatri){
xoamangtaivitri(x,n,i);	
}
}	
}	

int main(){
int a[100],n;
nhapmang2(a,n);
xuatmang2(a,n);
xoamangtheogiatri(a,n);
xuatmang2(a,n);
}
