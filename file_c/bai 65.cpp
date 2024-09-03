#include "stdio.h"
void hoandoi1(int a,int b){
int temp=a;
a=b;
b=temp;
	
}
void hoandoi2(int &a,int &b){
int temp=a;
a=b;
b=temp;	
}
void hoandoi3(int *a,int *b){
int s;
b=&s;
s=100;
int temp=*a;
*a=*b;
*b=temp;

	
}
int main(){
int a=5;
int b=10;	
printf("truoc hoan doi : %d , %d",a,b);
hoandoi1(a,b);

printf("\n sau khi hoan doi 1: %d , %d",a,b);
hoandoi2(a,b);
printf("\n sau khi hoan doi 2: %d , %d",a,b);
hoandoi3(&a,&b);
printf("\n %d , %d",a,b);
}
