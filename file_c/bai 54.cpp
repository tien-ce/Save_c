#include "stdio.h"
#include "math.h"
/* NHAP MANG*/
void nhapmang2chieu(int x[100][100],int &n,int &m){
A:
printf("nhap gia tri n(0<n<=100):\n");
scanf("%d",&n);
if (n<1||n>100){
printf("hay nhap n thoa man \n");
goto A;	
}
B:
printf("nhap gia tri m(0<m<=100):\n");
scanf("%d",&m);
if(m<1||m>100){
printf("hay nhap m thoa man \n");
goto B;	
}
for (int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("x[%d][%d]=",i,j);
scanf("%d",&x[i][j]);	
}	
}	
}
/*XUAT MANG*/
void xuatmang2chieu(int x[100][100],int n,int m){
for (int i=0;i<n;i++){
for (int j=0;j<m;j++){
printf("%d\t",x[i][j]);	
}	
}	
}
/* GIA TRI LON HAT*/
void max(int x[100][100],int n,int m){
int max=x[0][0];
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if (x[i][j]>max){
max=x[i][j];	
}	
}	
}
printf("\n gia tri lon nhat cua mang la: %d",max);	
}
/*GIA TRI NHO NHAT*/
void min(int x[100][100],int n ,int m){
int min=x[0][0];
for (int i=0;i<n;i++){
for (int j=0;j<m;j++){
if (x[i][j]<min){
min=x[i][j];	
}	
}		
}
printf("\n gia tri nho nhat cua mang la: %d",min);
}	
int main(){
int a[100][100],n,m;
nhapmang2chieu(a,n,m);
xuatmang2chieu(a,n,m);
max(a,n,m);
min(a,n,m);	
	
}
