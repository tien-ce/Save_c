#include"stdio.h"
#include"string.h"
void xoaxuongdong(char x[]){
int size;
size=strlen(x);
char *ptr;
ptr=x;
if(*(ptr+size-1)=='\n'){
*(ptr +size-1)='\0';	
}
}
char *my_strstr(char x[],char y[]){
int len1=strlen(x);
int len2=strlen(y);
for(int i=0;i<len1;i++){
if (x[i]==y[0])	{
for(int j=1;j<len2;j++){
if(x[i+j]!=y[j]){
break;	
}
return &x[i];	
}	
}
}
return NULL;
}
int main(){
char x[50],y[50];
printf("nhap chuoi x: ");
fgets(x,sizeof(x),stdin);
printf("nhap chuoi y: ");
fgets(y,sizeof(y),stdin);
xoaxuongdong(x);
xoaxuongdong(y);
printf("\n x=%s",x);
printf("\n y=%s",y);
char *ptr;
ptr=my_strstr(x,y);
printf("\n dia chi lay tu chuoi con : %s",ptr);
}
