#ifndef chuoi
#define chuoi
#include<iostream>

using namespace std;
void nhap(char p[]){
	cout<<"Nhap chuoi:\n";
	fgets(p,100,stdin);	
	}

int len(char *p){
	int dem=0;
	while(p[dem]!='\0'){
		dem++;
	}
	return dem;
}
void xuat(char p[]){
	for(int i=0;i<len(p);i++){
		cout<<p[i];
	}
}

void noi(char p1[], char p2[]) {
    int i = 0;
    int len_1=len(p1);
    while (p2[i] != '\0') {
        p1[i+len_1] = p2[i];
        i++;
    }
   
}
void cpy(char p1[],char p2[]){
	int i=0;
	while(p2[i]!=0){
	p1[i]=p2[i];
	i++;		
	}
}

#endif
