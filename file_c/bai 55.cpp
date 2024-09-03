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
printf("\n");
for (int j=0;j<m;j++){
printf("%d\t",x[i][j]);	
}	
}	
}
/* MAX CUA TUNG COT*/
void maxcot(int x[100][100],int n,int m){
int cot;
A:
printf("\n nhap cot muon tim gia tri lon nhat : ");
scanf("%d",&cot);
if(cot>m||cot<1){
printf("vui long nhap so cot thoa man ");
goto A;	
}
int maxcot=x[0][cot-1];
for (int i=0;i<n;i++){
if(x[i][cot-1]>maxcot){
maxcot=x[i][cot-1];	
}	
}
printf("\n gia tri lon nhat cua cot %d la: %d",cot,maxcot);	
}
/* MIN CUA TUNG COT*/
int mincot(int x[100][100],int n,int m){
int cot;
B:
printf("\n nhap cot muon tim gia tri nho nhat : ");
scanf("%d",&cot);
if(cot>m||cot<1){
printf("\n vui long nhap so cot thoa man ");
goto B;
}
int mincot=x[0][cot-1];
for(int i=0;i<n;i++){
if(x[i][cot-1]<mincot){
mincot=x[i][cot];	
}	
}
printf("\n gia tri nho nhat cua cot %d la : %d",cot,mincot)	;
}
/* MAX CUA TUNG DONG*/
void maxdong(int x[100][100],int n,int m){
int dong;
C:
printf("\n nhap gia tri dong muon tim gia tri lon nhat :");
scanf("%d",&dong);
if(dong>n||dong<0){
printf("\n vui long nhap so dong thoa man ");
goto C;	
}
int maxdong=x[dong-1][0];
for(int i=0;i<m;i++){
if(x[dong-1][i]>maxdong){
maxdong=x[dong-1][i];	
}
}
printf("\n gia tri lon nhat cua dong %d la: %d",dong,maxdong);	
}
/* MIN CUA TUNG DONG*/
void mindong(int x[100][100],int n,int m){
int dong;
D:
printf("\n nhap gia tri dong muon tim gia tri nho nhat: ");
scanf("%d",&dong);
if(dong>n||dong<0){
printf("\n vui long nhap so dong thoa man ");
goto D;	
}
int mindong=x[dong-1][0];
for(int i=0;i<n;i++){
if(x[dong-1][i]<mindong){
mindong=x[dong][i];	
}	
}
printf("\n gia tri nho nhat cua dong %d la : %d",dong,mindong);
}
int main(){
int a[100][100],n,m;
nhapmang2chieu(a,n,m);
xuatmang2chieu(a,n,m);
maxdong(a,n,m);
mindong(a,n,m);
maxcot(a,n,m);
mincot(a,n,m);
}
