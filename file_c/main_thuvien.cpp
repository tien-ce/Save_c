#include "chuoi.h"

int main() {
    char t[100] = "nguyen van tien";
    char h[20] = "asdas";
    cpy(t,h);
    
   for(int i=0;i<len(t);i++){
   	cout<<t[i]<<"\t";
   }
    return 0;
}
