#include"stdio.h"
#include"string.h"
int my_strlen(char x[]){
int cout=0;	
while(x[cout]!='\0'){
cout++;	
}
return cout;	
}
void noichuoi(char x[],char y[],char z[]){
int dem_x=0;
int dem_y=0;
int cout_x=my_strlen(x);	

int cout_y=my_strlen(y);
int a=cout_x+cout_y;

for(int i=0;i<cout_x;i++){
z[i]=x[dem_x];
dem_x++;	
}
for(int i=cout_x;i<cout_x+cout_y;i++){
z[i]=y[dem_y];
dem_y++;	
}
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
char a[30],b[30], c[sizeof(a)+sizeof(b)];
printf("nhap chuoi a: ");
fgets(a,sizeof(a),stdin);
printf("\n nhap chuoi b:");
fgets(b,sizeof(b),stdin);
xoaxuongdong(a);
xoaxuongdong(b);

noichuoi(a,b,c);
printf("\n sizeof(c)=%d",sizeof(c)/sizeof(char));
printf("\n chuoi duoc noi: %s",c);

}
