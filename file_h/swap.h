#ifndef swap
#define swap
#include <cstring>
#include"stdio.h"
void chuoi_so(char x[], int &x1) {
    int dem = 0, dau = 1;
    if (x[0] == '-') {
        dau = -1;
        x++;
    }
    for (int i = 0; i <strlen(x); i++) {
        if (x[i] != ' ' && x[i] != ',') {
            do {
                dem++;	
            } while (x[i + dem] != ' ' && x[i + dem] != '\0' && x[i + dem] != ',');    			
            int luythua[20];
            luythua[0] = 1;
            for (int j = 1; j < 10; j++) {
                luythua[j] = 10 * luythua[j - 1];	
            }
            x1 = (x[i] - 48) * luythua[dem - 1];	
            for (int j = 1; j < dem; j++) {
                x1 += ((x[i + j]) - 48) * luythua[dem - j - 1];	
            }
            x1 *= dau; 
            i += dem;	
        } 
		else {
            continue;
        }
    }
}
int chuoi_mang(char x1[],int x[]){
int dem;
int n=0;
for(int i=0;i<strlen(x1);i++){
dem=0;	
if (x1[i]!=' '&&x1[i]!=','){	
do{
dem++;	
}	
while(x1[i+dem]!=' ' &&  x1[i+dem]!='\0'&&x1[i+dem]!=',');    	
int luythua[20];
	luythua[0]=1;
	for(int j=1;j<10;j++){
	luythua[j]=10*luythua[j-1];	
	}
if(x1[i]!='-'){
if(dem==1){
x[n]=0;	
x[n]+=x1[i]-48;	
}
else{	
x[n]=0;	
for(int j=0;j<dem;j++){
x[n]+=(x1[j+i]-48)*luythua[dem-j-1];		
}
}
}
else{
int v=1;	
x[n]=0;
while(x1[i+v]!=' '&&x1[v+i]!='\0'&&x1[v+i]!=','){
x[n]=x[n]*10+(x1[v+i]-48);
v++;	
}
x[n]=-x[n];
}
i+=dem-1;
n++;
}
}
return n;
}
#endif

