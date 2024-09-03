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
int n_1;
printf("nhap n=: ");
scanf("%s",&n);
chuyendoi(n,n_1);
f=fopen("file_merlin_pack","w");
fprintf(f,"%s\n",n);
char a[100][100];
for(int i=0;i<n_1;i++){
printf("a[%d]=",i);	
fflush(stdin);fgets(a[i],100,stdin);xoaxuongdong(a[i]);	
fprintf(f,"%s\n",a[i]);
}
fclose(f);

}
