#include"stdio.h"

int main(){
int a[10];
int *x;
x=&a[1];
int n=5;
a[0]=1;
printf("nhap gia tri mang")	;
for(int i=0;i<n;i++){
printf("\n a[%d]=",i);
scanf("%d",x+i);
}
for(int i=0;i<=n;i++){
printf("%d \t ",a[i]);	
}
}
