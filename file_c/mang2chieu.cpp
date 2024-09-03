#include "stdio.h"
#include "math.h"
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
void xuatmang2chieu(int x[100][100],int n,int m){
for (int i=0;i<n;i++){
for (int j=0;j<m;j++){
printf("%d\t",x[i][j]);	
}	
}	
}
int timkiem(int x[100][100],int n , int m ,int giatritimkiem){
int kq=0,dem=0;	
for (int i=0;i<n;i++){
for (int j=0 ;j<n;j++){
if 	(x[i][j]==giatritimkiem){
kq=1;
dem++;	
}
}	
}
if (kq==1){
printf("\n gia tri xuat hien trong mang");	
}
else{
printf("\n gia tri khong xuat hien trong mang");	
}
return dem;	
}
void thuchientimkiem(int x[100][100],int n,int m){
int giatritimkiem;
printf("\n nhap gia tri can tim: ");
scanf("%d",&giatritimkiem);
int solan=timkiem(x,n,m,giatritimkiem);
if (solan>=1){

printf("\n gia tri xuat hien %d lan",solan);	
}
}
/* Trung binh cong cac so chinh phuong*/
void trungbinhcong(int x[100][100],int n,int m){
int tong=0,dem=0;
printf("\n cac so chinh phuong la:\n");
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
if(pow(sqrt(x[i][j]),2)==x[i][j]){
tong=tong+x[i][j];
dem++;
printf("%d\t",x[i][j]);	
}
}
}	
float trungbinh=(float)tong/dem;
printf("\n trung binh cong cac so chinh phuong: \n");
printf("%.2f",trungbinh);
}

int main(){
int a[100][100],n,m;	
nhapmang2chieu(a,n,m);
xuatmang2chieu(a,n,m);
thuchientimkiem(a,n,m);
trungbinhcong(a,n,m);
}


