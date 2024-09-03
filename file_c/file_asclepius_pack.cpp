#include<iostream>
#include"stdlib.h"
#include"string.h"
using namespace std;
void xoaxuongdong(char x[]){
if(x[strlen(x)-1]=='\n'){
x[strlen(x)-1]= '\0';	
}	
}
void chuyendoi(char x[],int &x1){
int dem=0;	
for(int i=0;i<strlen(x);i++){
	if (x[i]!=' '){
	do{
	dem++;	
	}		
	while(x[i+dem]!=' ' &&  x[i+dem]!='\0');    			
	int luythua[20];
	luythua[0]=1;
	for(int j=1;j<10;j++){
	luythua[j]=10*luythua[j-1];	
	}
	x1=(x[i]-48)*luythua[dem-1];	
	for(int j=1;j<dem;j++){
	x1+=((x[i+j])-48)*luythua[dem-j-1];	
	}
	i+=dem;	
	}	
	else{
	continue;
	}
	}
	}	
int main(){
char n[100];
FILE *f;
char c11[100];
int c1;
char r11[100];
int r1;
char m[100][100];
f=fopen("file_asclepius_pack","w");
printf("nhap vao r1:");
fflush(stdin);fgets(r11,sizeof(r11)+1,stdin);xoaxuongdong(r11);
chuyendoi(r11,r1);
printf("nhap vao c1:");
fflush(stdin);fgets(c11,sizeof(c11)+1,stdin);xoaxuongdong(c11);
chuyendoi(c11,c1);
fprintf(f,"%s",c11);
fprintf(f,"\n%s\n",r11);
for(int i=0;i<r1;i++){
printf("\n dong do %d:",i);	
fflush(stdin);fgets(m[i],sizeof(m[i])+1,stdin);xoaxuongdong(m[i]);
fprintf(f,"%s\n",m[i]);	
}
}
