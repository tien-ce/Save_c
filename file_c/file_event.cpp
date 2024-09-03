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
char sosukien1[100];
char masukien[500];
int sosukien;
FILE *f;
 f=fopen("file_events","w");

 printf("so su kien cua doi quan:\n");
 fflush(stdin);
 fgets(sosukien1,sizeof(sosukien1),stdin);
 xoaxuongdong(sosukien1);
 fprintf(f,"%s\n",sosukien1);
   chuyendoi(sosukien1,sosukien);
 printf("\ncac su kien lan luot:\n");
 fflush(stdin); fgets(masukien,sizeof(masukien),stdin); 
 fprintf(f,"%s",masukien);
 fclose(f);    
 return 0;
}
