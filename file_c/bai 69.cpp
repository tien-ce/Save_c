#include"stdio.h"
#include"string.h"
int my_strlen(char x[]){
int cout=0;	
while(x[cout]!='\0'){
cout++;	
}
return cout;	
}
int main(){
char c[50]="tien";
int cout=my_strlen(c);
printf("do dai: %d",cout);
}
