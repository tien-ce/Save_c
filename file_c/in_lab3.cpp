#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int *arr=new int [k];
      int i1=0;	
      int *arr1=new int[nums.size()-k];
     for(int i=0;i<k;i++){
     	arr[i]=nums[i1++];
	 } 
	 for(int i=0;i<nums.size()-k;i++){
	 	arr1[i]=nums[i1++];
	 	
	 }
	 i1=0;
	 for(int i=0;i<nums.size()-k;i++){
	 	nums[i1++]=arr1[i];
	 }
	  for(int i=0;i<=k;i++){
     	nums[i1++]=arr[i];
	 
	 }
	 delete []arr1;
	 delete []arr; 
    }
};
int main(){
	vector<int > arr1;
		arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(3);
	arr1.push_back(4);
		arr1.push_back(5);
			arr1.push_back(6);
				arr1.push_back(7);
Solution a;
a.rotate(arr1,3);
for(int i:arr1){
	cout<<i;
}

}

