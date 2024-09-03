#include "stdio.h"
#include"string.h"
int my_strlen(char x[]){
int dem=0;
while(x[dem]!='\0'){
dem++;	
}
return dem;	
}
void xoaxuongdong(char x[]){
int size;
size=strlen(x);
char *ptr;
ptr=x;
if(*(ptr+size-1)=='\n'){
*(ptr +size-1)='\0';	
}
}
void hoandoi(char &a,char &b){
int temp=a;
a=b;
b=temp;	
}
void my_strrev(char x[]){
int len1=my_strlen(x);
printf("len1=%d\n",len1);
for(int i=0;i<=(len1-1)/2;i++){
hoandoi(x[i],x[len1-i-1]);
}
}
int main(){
char x[50],y[50];
printf("nhap chuoi x: ");
fgets(x,sizeof(x),stdin);
printf("nhap chuoi y: ");
fgets(y,sizeof(y),stdin);
my_strlen(x);
xoaxuongdong(x);
my_strrev(x);
printf("x=%s",x);	
}
