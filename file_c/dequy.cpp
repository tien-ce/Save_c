#include<iostream>
#include<vector>
using namespace std;

    // Write your code here


long long int floorSqrt(int n)
{
	
	int start=1;
	int end=n;
	int mid=start+(end-start)/2;
	while(start<=end){
	if(mid<=n/mid && (mid+1)>n/(mid+1))
	{
	return mid;
	}
	else if(mid>n/mid)
	{
	end=mid-1;	
	}
	else {
		start=mid+1;
	}
	 mid=start+(end-start)/2;
	}
	
}


int main(){
cout<<floorSqrt(24);
}
