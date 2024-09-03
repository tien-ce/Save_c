#include <fstream>
#include <sstream>
#include "string.h"
#include <iostream>
using namespace std;
void xoaxuongdong(char x[]){
    if(x[strlen(x)-1]=='\n'){
        x[strlen(x)-1]= '\0';    
    }    
}
void chuyendoi(char x[], int &x1) {
    int dem = 0, dau = 1;
    if (x[0] == '-') {
        dau = -1;
        x++;
    }
    for (int i = 0; i < strlen(x); i++) {
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
int main(){
    char thongtinhiepsi[100][100];
    char masukien[100];
    char filecandung[100];
    char soluonghiepsi1[100];
	int soluonghiepsi;
    FILE *f;
    f=fopen("file_armyknights","wb");
    if(f==NULL){
        printf("ERROL");
        exit(1);    
    }
    printf("so luong hiep si:\n");
    scanf("%s",&soluonghiepsi1);
    chuyendoi(soluonghiepsi1,soluonghiepsi);
    fprintf(f,"%s\n",soluonghiepsi1);
    for(int i=0;i<soluonghiepsi;i++){
    printf("nhap tong tin hiep si thu %d:HP LEVEL PHOENIXDOWN GIL ANTIDOTE\n",i+1);
	fflush(stdin);fgets(thongtinhiepsi[i],sizeof(thongtinhiepsi[i]),stdin);	
	xoaxuongdong(thongtinhiepsi[i]);
	fprintf(f,"%s\n",thongtinhiepsi[i]);
	}
	fclose(f);	
}
