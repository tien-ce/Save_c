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
int main(){
    char thongtinhiepsi[100];
    char masukien[100];
    char filecandung[100];
    FILE *f;
    f=fopen("testcase_input","w");
    if(f==NULL){
        printf("ERROL");
        exit(1);    
    }
    printf("thong tin hiep si: HP LEVEL REMEDY MAIDENKISS PHOENIXDOWN:\n ");
    fflush(stdin); fgets(thongtinhiepsi,sizeof(thongtinhiepsi),stdin);
    xoaxuongdong(thongtinhiepsi);
    printf("\n cac su kien lan luot:\n ");
    fflush(stdin); fgets(masukien,sizeof(masukien),stdin); 
    xoaxuongdong(masukien);
    printf("\n cac file can dung:\n ");
    fflush(stdin); fgets(filecandung,sizeof(filecandung),stdin);
    xoaxuongdong(filecandung);
    stringstream ss;
    ss << thongtinhiepsi << "\n" << masukien << "\n" << filecandung;
    string str = ss.str();
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '\r') {
            continue;
        }
        fputc(str[i], f);
    }
    fclose(f);    
    return 0;
}
