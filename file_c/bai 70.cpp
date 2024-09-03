#include"stdio.h"
#include"string.h"
int my_strlen(char x[]){
int cout=0;	
while(x[cout]!='\0'){
cout++;	
}
return cout;
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
int main(){
char *ptr;
char ten[50];
printf("ten cua ban : ");

fgets(ten, sizeof(ten),stdin);
xoaxuongdong(ten);
int cout=my_strlen(ten);

printf("do dai: %d",cout);
}
