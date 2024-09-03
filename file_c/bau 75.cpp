#include "stdio.h"
#include"string.h"
int my_strlen(char x[]){
int dem=0;
while(dem!='\0'){
dem++;	
}
return dem;	
}
void inhoakitu(char x[]){
int len1=my_strlen(x);
if (x[0]>='a'&&x[0]<='z'){
x[0]-=32;	
}
for(int i=1;i<len1;i++){
if (x[i]>='a'&&x[i]<='z'&&x[i-1]==' '){
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
inhoakitu(x);
printf("%s",x);
}
