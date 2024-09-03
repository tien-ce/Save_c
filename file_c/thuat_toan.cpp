#include<iostream>
#include<vector>
using namespace std;
vector<int> count(long long int n){	
	vector<bool> smaller(n+1,true);
	vector<int> x;
    int count =0;
	for(long long int i=2;i<n+1;i++){

    if(smaller[i]==true){
	
    x.push_back(i);	
    }
    for(int j=i*2;j<n+1;j+=i){
    	smaller[j]=false;
	}
	
	}

	return x;
}
long long int sohoa(int n,int m){
	vector<int> x=count(n+m);
	long long int count=0;
	
	for(int i=0;i<x.size();i++){
	for(int j=1;j<=n;j++){
	if(x[i]-j<=m&&x[i]-j>0){	
	count++;		
	}

	
	}	
	}
	return count;
}
int main(){	
count(2*10000000);
}
