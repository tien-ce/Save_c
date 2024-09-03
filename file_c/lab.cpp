#include<iostream>
#include <math.h>
using namespace std;
int countWaySumOfSquare(int x)
{
int diemdung;
int socach=0;
int giatri=0;
int i=0;
int n;
diemdung=sqrt(x);

if(pow(diemdung,2)==x){
	socach++;
	diemdung--;
}
while(diemdung>0){
n=1;	
while(diemdung-n>0){
giatri=pow(diemdung,2);
i=0;
while(i<diemdung-i-n>0){
while(giatri<x){
	giatri+=pow(diemdung-i-n,2);
    i++;
}
}
if(giatri==x){
socach++;	
}
n++;
}
diemdung--;	
}
return socach;
}




int main()
{   
cout << countWaySumOfSquare(100);
}


