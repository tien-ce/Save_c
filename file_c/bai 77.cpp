#include"stdio.h"
#include"string.h"
int my_strlen(char x[]){
int dem=0;
while(x[dem]!=0){
dem++;	
}
return dem;	
}
char *my_strchr(char x[],char diachi){
int len1=my_strlen(x);
for(int i=0;i<len1;i++){
if (x[i]==diachi){
return &x[i];	
}
}
return NULL;
}
int main(){
char x[50],y[50];
char *ptr;
printf("nhap chuoi x: ");
fgets(x,sizeof(x),stdin);
printf("x=%s",x);
ptr=my_strchr(x,'e');
printf("%s",ptr);
}
