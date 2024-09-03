#include <vector>
#include<iostream>
using namespace std;
int main(){
	vector<float> a;
	a.push_back(10);
	a.push_back(20.1);
	a.pop_back();
  for(int i:a){
  	cout<<i<<endl;
  }
}
