#include"stdio.h"
#include"string.h"
int kiemtradoixung(char x[]){
int len1=strlen(x);

for(int i=0;i<len1-1;i++){
if(x[i]!=x[len1-i-1]){
return 0;	
}	
}
return 1;
}
int main(){
char x[50];
printf("nhap chuoi x: ");
fgets(x,sizeof(x),stdin);
if (x[strlen(x)-1]=='\n'){
x[strlen(x)-1]='\0';	
}
printf("x=%s",x);
int kiemtra=kiemtradoixung(x);
if(kiemtra==1){
printf("\n chuoi doi xung");	
}
else{
printf("\n chuoi khong doi xung");	
}
}
