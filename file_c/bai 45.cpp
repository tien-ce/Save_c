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
void chenphantucuoimang(int x[],int &n){
int giatri;	
int size=sizeof(x)/sizeof(x[0]);
if (size==n){
printf("da dat toi da phan tu ");	
}
else{
printf("\n nhap gia tri can chen cuoi mang : ");
scanf("%d",&giatri);
x[n]=giatri;
n++;
}
}
void chenphantudaumang(int x[],int &n ){
int giatri;
printf("nhap phan tu chen dau mang :");
scanf("%d",&giatri);
n++;	
for(int i=n-1;i>0;i--){
x[i]=x[i-1];	
}
x[0]=giatri;
}	
void chenphantuvaovitri(int x[],int &n){
int vitri,giatri;
printf("\n nhap vi tri can chen:");
scanf("%d",&vitri);
printf("nhap gia tri can chen:");
scanf("%d",&giatri);
n++;
for(int i=n-1;i>vitri;i--){
x[i]=x[i-1];
}	
x[vitri]=giatri;	
}
int main(){
           int a[100],n;
           int giatri;
nhapmang2(a,n);
xuatmang2(a,n);
chenphantuvaovitri(a,n);
chenphantucuoimang(a,n);
chenphantudaumang(a,n);
xuatmang2(a,n);
}
