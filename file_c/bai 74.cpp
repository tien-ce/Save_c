#include"stdio.h"
#include"string.h"
int my_strlen(char x[]){
int dem=0;
while(x[dem]!='0'){
dem++;	
}
return dem;	
}
void my_strlwr(char x[]){
int len1=my_strlen(x)-1;
for(int i=0;i<len1;i++){
if(x[i]>='A'&&x[i]<='Z'){
x[i]+=32;
}	
}	
}
void my_strup(char x[]){
int len1=my_strlen(x)-1;	
for(int i=0;i<len1; i++){
if (x[i]>='a'&&x[i]<='z'){
x[i]-=32;	
}	
}	
}
int main(){
char x[50],y[50];
printf("nhap chuoi x: ");
fgets(x,sizeof(x),stdin);
printf("nhap chuoi y: ");
fgets(y,sizeof(y),stdin);
my_strup(x);
printf("%s",x);

my_strlwr(y);
printf("%s",y);
}
