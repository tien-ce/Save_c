#include "stdio.h"
#include "limits.h"
void nhapmang (int x[],int &n){
do {
printf("nhap gia tri n(0<n<=100) : n= ");
scanf("%d",&n);
for (int i=0;i<n;i++){
printf("x[%d]=",i);
scanf("%d",&x[i]);	
}
}
while (n<1||n>100);		
}
void xuatmang(int x[],int n){
for (int i=0;i<n;i++){
printf(" %d ",x[i]);	
}	
}
void hoandoi(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}
void daonguocmang(int x[], int n){
for(int i=0;i<n/2;i++){
hoandoi(x[i],x[n-i-1]);		
}
printf("\n gia tri mang dao nguoc:");	
}
void sapxeptangdan(int x[],int n){
for(int i=0;i<n-1;i++){
for (int j=i+1;j<n;j++){
if(x[i]>x[j]){
hoandoi(x[i],x[j]);	
}	
}	
}
printf("\n sap xep tang dan:");	
}
void sapxepgiamdan(int x[],int n){
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if (x[i]<x[j]){
hoandoi(x[i],x[j]);	
}	
}	
}
printf("\n sap xep giam dan: ");	
}
int max(int x[],int n){
int max=x[0];
for (int i=1;i<n;i++){
if(x[i]>max){
max=x[i];	
}	
}
printf("\n gia tri lon nhat cua mang la %d:",max);	
}
int min(int x[], int n){
int min=x[0];
for(int i=1;i<n;i++){
if (x[i]<min){
min=x[i];
}	
}
printf("\n gia tri nho nhat cua mang la %d",min);	
}
void themgiatrivaocuoimang(int x[],int &n){
int giatri;
printf("\n them gia tri vao cuoi mang \n");
printf("\n nhapgiatrimuonthem:");
scanf("%d",&giatri);
x[n]=giatri;
n++;	
}
void themgiatridaumang(int x[],int &n){
n++;
int giatri;
printf("\n them gia tri vao dau mang \n ");
printf("nhap gia tri muon them: ");
scanf("%d",&giatri);
for(int i=n;i>0;i--){
x[i]=x[i-1];	
}
x[0]=giatri;	
}
void themgiatritaivitrik(int x[],int &n){
int k,giatri;
printf("\n chon vi tri muon them:k=");
scanf("%d",&k);
printf("chon gia tri muon them:");
scanf("%d",&giatri);
for(int i=n;i>=k;i--){
x[i]=x[i-1];
}
x[k]=giatri;
n++;	
}
void xoaphantuthuMtrongmang(int x[],int &n,int m){

for(int i=m;i<n-1;i++){
x[i]=x[i+1];	
}
n--; 		
}
void xoaphantucogiatriTtrongmang(int x[],int &n){
	
int t;
printf("\n nhap gia tri muon xoa: T=");
scanf("%d",&t);
for(int i=0;i<n;i++){
if(x[i]==t){
xoaphantuthuMtrongmang(x,n,i);
i--;
}	
}
}
void xoacacphantulonhonT(int x[],int &n){
int t;
printf("\n xoa cac phan tu x[i]>T:T=");
scanf("%d",&t);
for(int i=0;i<n;i++){
if(x[i]>t){
xoaphantuthuMtrongmang(x,n,i);
i--;
}	
}	
}
void xoacacphantunhohonT(int x[],int &n){
int t;
printf("\n xoa cac phan tu nho hon T: T=");
scanf("%d",&t);	
for(int i=0;i<n;i++){
if (x[i]<t){
xoaphantuthuMtrongmang(x,n,i);	
i--;
}	
}	
}
void timkiemphantu(int x[],int n){
int giatri;
int khongco=0;
printf("\n nhap gia tri can tim kiem:");
scanf("%d",&giatri);
for (int i=0;i<n;i++){
if(x[i]==giatri){	
khongco=1;	
}
}
if(khongco==0){
printf("gia tri khong xuat hien trong mang");
}
else{printf("gia tri co xuat hien trong mang");
}	
}
void timkiemsonguyento(int x[],int n){
printf("\n cac so nguyen to la: ");
for (int i=0;i<n;i++){
for (int k=2;k<x[i];k++){
if(x[i]%k==0){
continue;		
}
printf("%d",x[i]);	
}	
}	
}	
int main(){
int a[100],n;
nhapmang(a,n);
xuatmang(a,n);
/*  daonguocmang(a,n);
xuatmang(a,n);	
sapxeptangdan(a,n);
xuatmang(a,n);
sapxepgiamdan(a,n);
xuatmang(a,n);
max(a,n);
min(a,n);
themgiatrivaocuoimang(a,n);
themgiatridaumang(a,n);
xuatmang(a,n);
themgiatritaivitrik(a,n);
xuatmang(a,n);
xoaphantuthuMtrongmang(a,n);
xuatmang(a,n);
xoaphantucogiatriTtrongmang(a,n);
xuatmang(a,n);
xoacacphantulonhonT(a,n);
xuatmang(a,n);
xoacacphantunhohonT(a,n);
xuatmang(a,n);*/
timkiemphantu(a,n);
timkiemsonguyento(a,n);
}
