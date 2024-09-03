#include"iostream"
#include"string"
#include"vector"
using namespace std;
bool sole(int x){
for(int i=0;i<)	
}
int specialCells(int arr[][1000], int row, int col) {
int tongcot[col];
int tonghang[row];
int dem=0;
int n;
for(int j=0;j<col;j++){
tongcot[j]=0;
n=0;
do{
tongcot[j]+=arr[n][j];
n++;	
}
while(n<row);	
}
for(int i=0;i<row;i++){	
tonghang[i]=0;
for(int j=0;j<row;j++){
tonghang[i]+=arr[i][j];
}	
}
for(int i=0;i<row;i++){
for(int j=0;j<col;j++){
if(songuyento(tonghang[i])==true && songuyento(tongcot[j])==true){
dem++;
}	
}	
}
return dem;
}
int main(){	
int arr[][1000] = {{37,53,74},{12,37,60},{98,13,15}};
cout << specialCells(arr,3,3);
}
