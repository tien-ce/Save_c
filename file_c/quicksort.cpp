#include<iostream>
#include<vector>
using namespace std;


void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int paration(vector<int> arr,int s,int e){
    int count=0;
   
    for(int i=s+1;i<=e;i++){
    if(arr[i]<=arr[s])

    count++;  
    }
return s+count;
}
void quickSort(vector<int> &arr,int s,int e){
    if(s>=e)
    return;
    int point=paration(arr, s,  e);
   
    swap(arr[point],arr[s]);
  
int i=s;
int j=e;
while(i<point && j>point){
	while(arr[i]<=arr[point]){
		i++;
	}
	while(arr[j]>arr[point]){
		j--;
	}
	if(i<point && j>=point){
		swap(arr[i++],arr[j--]);
	}
	
}


    quickSort(arr, s, point-1);
    quickSort(arr, point+1, e);
     
}
int main(){
	vector<int> arr;
	arr.push_back(6);
		arr.push_back(6);
	arr.push_back(-6);
	arr.push_back(-2);
	arr.push_back(-4);
		arr.push_back(-6);
	arr.push_back(2);
	arr.push_back(-6);
	quickSort(arr,0,arr.size()-1);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}
