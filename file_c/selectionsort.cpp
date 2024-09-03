#include<iostream>
#include<vector>
using namespace std;
	void insertionSort(int n, vector<int> &arr){
	    // Write your code here.
	for(int i=1;i<n;i++){
		int temp=arr[i];
	for(int j=i-1;j>=0;j--){
		if(arr[j]>temp){
	arr[j+1]=arr[j];
	arr[j]=temp;
		}
		else{
			break;
		}
	}	
	}
	
	}
int main(){
	vector<int> arr;
	arr.push_back(2);
	arr.push_back(5);
	arr.push_back(7);
	arr.push_back(3);
	arr.push_back(1);
	insertionSort(arr.size(),arr);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<< " ";
	}
}
