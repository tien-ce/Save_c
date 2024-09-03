#include "stdio.h"
#include "math.h"
int a[100][100];
int n,m;
int b[10000];
int k;
void nhapmatran(int x[100][100],int &n){
printf("nhap ma tran vuong cap n : n=");
scanf("%d",&n);
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
printf("x[%d][%d]=",i,j);
scanf("%d",&x[i][j]);	
}
}
}

void xuatmatran(int x[100][100],int n){
for(int i=0;i<n;i++){
printf("\n");
for(int j=0;j<n;j++){
printf("%d \t",x[i][j]);	
}	
}
}
void kiemtradoixung(int x[100][100],int n){
int demchinh=0;
int demphu=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i==j){
continue;	
}
else{
if(x[i][j]==x[j][i]){
demchinh++;	
}
}
}	
}
if (demchinh==pow(n,2)-n){
printf("\n ma tran doi xung qua duong cheo chinh");	
}
else{
printf("\n ma tran khong doi xung qua duong cheo chinh");	
}
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(i+j==n-1){
continue;	
}
else{
if(x[i][j]==x[n-1-j][n-1-i]){
demphu++;	
}	
}	
}	
}
if(demphu==pow(n,2)-n){
printf("\n ma tran doi xung qua duong cheo phu");	
}
else{
printf("\n ma tran khong doi xung qua duong cheo phu");	
}	
}
int main(){
nhapmatran(a,n);
xuatmatran(a,n);	
kiemtradoixung(a,n);
}
