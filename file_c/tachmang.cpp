#include"stdio.h"
int a[100],b[100],c[100],d[100],e[100];
int n1,n2,n3;

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
void xuatmang(int x[],int n,char tenmang){
printf("\n gia tri cua mang %c:",tenmang);
for (int i=0;i<n;i++){
printf(" %d ",x[i]);	
}	
}
void tachmangtheodieukien(int x1[],int x2[],int x3[],int n1,int &n2, int &n3,int &i2,int &i3, int dieukien,int giatri){
	
if (dieukien==1){
x2[i2]=giatri;
i2++;
n2++;
printf("i2=%d,n2=%d",i2,n2);
}
if(dieukien==2){
x3[i3]=giatri;
i3++;
n3++;	
}		
}
void mangchanle(int x[],int n){
printf("\n mang chan le \n ");
int giatri;	
int dieukien;	
int i2=0,i3=0;
int n2=0;n3=0;
for (int i=0;i<n;i++){
if (x[i]%2==0){
dieukien=1;
giatri=x[i];	
}
else{
dieukien=2;
giatri=x[i];	
}	
tachmangtheodieukien(a,b,c,n1,n2,n3,i2,i3,dieukien,giatri);		
}
xuatmang(b,n2,'B');
xuatmang(c,n3,'C');
}
void mangsonguyento(int x[],int n){
printf(" \n mang so nguyen to \n");
int giatri,k;
int dieukien;
int i2=0,i3=0;
int n2=0;n3=0;
for(int i=0;i<n;i++){
if(x[i]==1){
giatri=x[i];
dieukien=1;	
}
else if(x[i]==2){
giatri=x[i];
dieukien=2;	
}
else{
k=0;
for(int j=2;j<x[i];j++){
if(x[i]%j==0){
k=1;	
}

if(k==1){
dieukien=1;
giatri=x[i];	
}
else{
dieukien=2;
giatri=x[i];	
}	
}
}
tachmangtheodieukien(a,d,e,n1,n2,n3,i2,i3,dieukien,giatri);	
}
xuatmang(d,n2,'D');
xuatmang(e,n3,'E');
} 
int main(){
nhapmang(a,n1);
xuatmang(a,n1,'A');
mangchanle(a,n1);
mangsonguyento(a,n1);
}
