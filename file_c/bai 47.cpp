#include "stdio.h"
#include "limits.h"
void nhapmang (int x[],int &n,int size,char phanbiet){
	
do {
printf("\n nhap gia tri n (0<n<=%d) : n%c= ",size,phanbiet);
scanf("%d",&n);
for (int i=0;i<n;i++){
printf("x[%d]=",i);
scanf("%d",&x[i]);	
}
}
while (n<1||n>size);		
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

void tronmang(int x1[100],int n1,int x2[100],int n2,int x3[200],int &n3){
printf("\n tron mang \n");	
n3=n1+n2;	
int i1=0,i2=0,i3=0;
while(i3<n3){
if(i1>=n1){
x3[i3]=x2[i2];
i2++;	
}
else if(i2>=n2){
x3[i3]=x1[i1];
i1++;
}
else if(x1[i1]<x2[i2]){
x3[i3]=x1[i1];
i1++;	
}
else{
x3[i3]=x2[i2];
i2++;	
}
i3++; 	
}	
}
int main(){
int n1,n2,n3;
int a[100],b[100],c[200];
nhapmang(a,n1,100,'A');
sapxeptangdan(a,n1);
xuatmang(a,n1);
	
nhapmang(b,n2,100,'B');
sapxeptangdan(b,n2);
xuatmang(b,n2);
tronmang(a,n1,b,n2,c,n3);
xuatmang(c,n3);

}
