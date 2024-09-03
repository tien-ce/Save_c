#include "stdio.h"
#include "limits.h"
void nhapmang2(int x[],int &n){

do {
	printf("nhap gia tri n(0<n<=100): n=");
	scanf("%d",&n);
	
}	while(n<1||n>100)	;
for (int i=0;i<n;i++){
	printf("x[%d]=",i);	
	scanf("%d",&x[i]);
	
}					
}
void xuatmang2(int x[],int n){

	for(int i=0 ; i<n;i++){
	printf(" %d ",x[i]);
}	
}
void daonguocmang(int x[] ,int n){
	printf("\n gia tri mang dao nguoc\n ");
	for(int i=0;i<n/2;i++){
	int temp;
    temp=x[i];
    x[i]=x[n-i-1];
    x[n-i-1]=temp;
	
	}

}	

int timkiemgiatri(int x[],int n,int giatri){
	int ketqua=0;
	for(int i=0;i<n;i++){
	
	if (x[i]==giatri){
	ketqua=1;
	
}
}
return ketqua;
}

void thtimkiemgiatri(int x[] ,int n){
	int giatri ;
	printf("\n nhap gia tri can tim:");
	scanf("%d",&giatri);
    int k=timkiemgiatri(x,n,giatri);
    if(k==1){
    	printf("co xuat hien trong mang");
    	
	}else{
	printf("khong xuat hien trong mang");	 	
}
}
int min(int x[],int n){
int min=x[0];
for (int i=1;i<n;i++){
if (min>x[i]){
min =x[i];
	
}
}
printf("\ngia tri nho nhat cua mang la %d",min);
return min;
}
int max(int x[],int n){
int max=x[0];
for (int i=1;i<n;i++){
if(max<x[i]){
max=x[i];	
}	
}
printf("\n gia tri lon nhat cua mang la %d",max);	

return max;
}
int hoandoi(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}	
void sapxeptangdan(int x[],int n){
int giatrinhohon=0;
for (int i=0;i<n-1;i++){
for (int j=i+1;j<n;j++){
if (x[i]>x[j]){

hoandoi(x[i],x[j]);
}	
}	
}	
printf("\n sap xep tang dan\n");	
}
void sapxepgiamdan(int x[],int n){
int giatrilonhon=x[0];
for (int i=0;i<n-1;i++){
for (int j=i+1;j<n;j++){
if (x[i]<x[j]){
hoandoi(x[i],x[j]);	
}	
}	
}
printf("\n sap xep giam dan\n");	
}
void giatrinhothu2mang(int x[],int n){
int min1=min(x,n), min2=INT_MAX;
for(int i=0;i<n;i++){
if (x[i]==min1){
continue;	
}else{
if (min2>x[i]){
min2=x[i];	
}	
}	
}
printf("\n gia tri nho thu 2 cua mang la %d ",min2);	
}
void giatrilonthu2mang(int x[],int n){
int max1=max(x,n), max2=INT_MIN;
for (int i=0;i<n;i++){
if(x[i]==max1){
continue;	
}else {
if(x[i]>max2){
max2=x[i];	
}	
}	
}
printf("\n gia tri lon thu 2 cua mang la %d",max2);	
}
int main(){
	int a[100],n;
	nhapmang2(a,n);
	xuatmang2(a,n);
	daonguocmang(a,n);
	xuatmang2(a,n);
	/* min(a,n);
	max(a,n);*/
	sapxeptangdan(a,n);
	xuatmang2(a,n);
	sapxepgiamdan(a,n);
	xuatmang2(a,n);
	thtimkiemgiatri(a,n);
	giatrinhothu2mang(a,n);
	giatrilonthu2mang(a,n);

}














