#include "stdio.h"
int a[100][100];
int n,m;
int b[10000];
int k;
void nhapmatran(int x[100][100],int &n,int &m){
printf("nhap gia tri cua hang: n=");
scanf("%d",&n);
printf("nhap gia tri cua cot: m=");
scanf("%d",&m);	
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
printf("x[%d][%d]=",i,j);
scanf("%d",&x[i][j]);	
}
}
}

void xuatmatran(int x[100][100],int n,int m){
for(int i=0;i<n;i++){
printf("\n");
for(int j=0;j<m;j++){
printf("%d \t",x[i][j]);	
}	
}	
}
void xuatmang1chieu(int x[100],int n){
for(int i=0;i<n;i++){
printf("%d \t ",x[i]);	
}	
}
void hoandoi(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}
void hoandoi2hang(int x[100][100],int n,int m){
int g,h;
printf("\n nhap 2 hang muon hoan doi(tinh tu 0): ");
scanf("%d",&g);	
printf("va ");
scanf("%d",&h);
for(int i=0;i<m;i++){
hoandoi(x[g][i],x[h][i]);
}
}
void hoandoi2cot(int x[100][100],int n,int m){
int g,h	;
printf("\n nhap 2 cot muon hoan doi (tinh tu 0): ");
scanf("%d",&g);
printf("va ");
scanf("%d",&h);
for(int i=0;i<n;i++){
hoandoi(x[i][g],x[i][h]);	
}
}
void chuyenmang1chieu(int x[100][100],int n,int m,int y[10000],int &k){
int vitri=0;
k=m*n;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
y[vitri]=x[i][j];
vitri++;	
}	
}	
}
void sapxepmang1chieu(int x[],int n){
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if (x[i]>x[j]){
hoandoi(x[i],x[j]);	
}
}	
}
}
void chuyenmatran(int x[100][100],int n,int m,int y[10000],int k){
int vitri=0;
k=m*n;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
x[i][j]=y[vitri];
vitri++;	
}	
}	
}

int main(){
nhapmatran(a,n,m);
xuatmatran(a,n,m);
hoandoi2hang(a,n,m);
printf("\n \n \n");
xuatmatran(a,n,m);
hoandoi2cot(a,n,m);
printf("\n \n \n ");
xuatmatran(a,n,m);
printf("\n \n \n");
chuyenmang1chieu(a,n,m,b,k);
sapxepmang1chieu(b,k);
chuyenmatran(a,n,m,b,k);
xuatmatran(a,n,m);
}


