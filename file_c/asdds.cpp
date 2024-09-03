#include"stdio.h"
#include <iostream>
using namespace std;
int** readArray()
{
   //TODO
   bool exitOuterLoop = false;
   int a[10][10];
   for(int i=0;i<10;i++){
   for(int j=0;j<10;j++){
     cin>>a[i][j];  
   if(i==j&&a[i][j]==0){
   	  exitOuterLoop = true;
    for(int m=i+1;m<10;m++){
    for(int n=j+1;n<10;n++){
    a[m][n]=0;    
    }       
    }
   break;
   }
   } 
   if(exitOuterLoop){
   break;	
   }
   }
    int** ptr = new int*[10];
     for (int i = 0; i < 10; i++) {
        ptr[i] = new int[10];
        for (int j = 0; j < 10; j++) {
            ptr[i][j] = a[i][j];
        }
    }
   return ptr;
}
int main(){
int** arr = readArray();
}
