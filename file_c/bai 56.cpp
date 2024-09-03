#include "stdio.h"
#include "math.h"
void xuatmang1chieu(int x[],int n){
printf("\n MANG MOT CHIEU \n");
for (int i=0;i<n;i++){
printf("%d\t",x[i]);	
}	
}
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
for (int i=0;i<n;i++){\
printf("\n");
for (int j=0;j<m;j++){
printf("%d\t",x[i][j]);	
}	
}	
}
/* CHUYEN MA TRAN THANH MANG 1 CHIEU*/
void chuyenmatran(int x[100][100],int n,int m,int y[10000],int &k){
int vitri=0;
k=m*n;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
y[vitri]=x[i][j];
vitri++;	
}
}
}
int main(){
int n,m,k;	
int a[100][100],b[10000];
nhapmang2chieu(a,n,m);
xuatmang2chieu(a,n,m);
chuyenmatran(a,n,m,b,k);
xuatmang1chieu(b,k);
}
