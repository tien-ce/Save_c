#include "stdio.h"
int a[100],b[100];
int n,m;
void nhapmang(int x[],int &n,char a){
do{
printf("nhap gia tri cua %c (0<%c<=100):\n  ",a);
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
printf("\n");	
}
void hoandoi(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}
void sapxeptangdan(int x[],int n){
for (int i=0;i<n-1;i++){
for (int j=i+1;j<n;j++){
if (x[i]>x[j]){
hoandoi(x[i],x[j]);	
}	
}	
}	
}
void chenphantu(int x[],int &n,int giatri,int vitri){
n++;
for(int i=n-1;i>vitri;i--){
x[i]=x[i-1];
x[vitri]=giatri;	
}	
}
int main(){
nhapmang(a,n,'n');	
nhapmang(b,m,'m');
xuatmang(a,n);
xuatmang(b,m);	
do{
n++;
a[n-1]=b[m-1];
m--;	
}
while (m>1);
sapxeptangdan(a,n);
for(int i=0;i<n;i++){
if (a[i]>=b[0]){
chenphantu(a,n,b[0],i);
break;	
}	

}
xuatmang(a,n);
}
