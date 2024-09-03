#include <cstdlib>
#include<iostream>
#include<ctime>
#include<random>
using namespace std;
int main(){
random_device r;
float *p;
int n;
cin>>n;
p=new float [n];
for(int i=0;i<n;i++){
	p[i]=((rand()%2)-1)*0.01;
}	
for(int i=0;i<n;i++){
cout<<p[i]<<" ";
}	
return 0;
}

