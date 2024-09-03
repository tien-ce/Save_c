#include "stdio.h"
int a[100],b[100];
int n,m;
void nhapmang(int x[],int &n){
do{
printf("nhap gia tri cua n(0<n<=100):\n n= ");
scanf("%d",&n);
}while(n<=0||n>100);
for(int i=0;i<n;i++){
printf("x[%d]=",i);
scanf("%d",&x[i]);
}	

}
void xuatmang(int x[],int n){
for(int i=0;i<n;i++){
printf("%d \t ",x[i]);	
}	
}
int timmin(int x[],int n ){
int min=x[0];
for(int i=1;i<n;i++){
if(x[i]<min){
min=x[i];	
}	
}
return min;	
}
int timmax(int x[],int n){
int max=x[0];
for(int i=1;i<n;i++){
if(x[i]>max){
max=x[i];	
}	
}
return max;	
}
int timminthu2(int x[],int n){
int u=timmin(x,n);
int minthu2=9999;
for(int i=0;i<n;i++){
if(x[i]==u){
continue;	
}else{
if(x[i]<minthu2){
minthu2=x[i];	
}
}
}
return minthu2;
}
void timucln(int x[],int n){
int ucln;
int h=timmin(x,n);
int u=timminthu2(a,n);
if(h==0){
ucln=u;	
}else {
ucln==u;	
}
int m;
do{
m=0;
for(int i=0;i<n;i++){
if(x[i]%ucln==0){
m++;
}
}
ucln--;
}
while(m<n);
printf("\n uoc chung lon nhat cua mang la : %d",ucln+1);
}
void timbcnn(int x[],int n){
int u=0;	
for(int i=0;i<n;i++){
if(x[i]==0){
u=1	;
}	
}
if(u==1){
printf("khong co boi chung");	
}
else{
int bcnn=timmax(x,n);
int m;
do{
m=0;
for(int i=0;i<n;i++){
if(bcnn%x[i]==0){
m++;	
}	
}	
bcnn++;
}
while(m<n);
printf("\n boi chung nho nhat cua mang la: %d",bcnn-1);
}	
}
int main(){
nhapmang(a,n);
xuatmang(a,n);	
timminthu2(a,n);
timucln(a,n);
timbcnn(a,n);
}
