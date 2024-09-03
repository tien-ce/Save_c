#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void swap(int &x,int &y){
		int temp=x;
		x=y;
		y=temp;
	}
	void  permute(vector<int>nums,vector<vector<int>> &ans,int s,vector<int> temp){
	
		if(s>=nums.size()){
			ans.push_back(temp);
			return ;
		}
		vector<int> x=nums;
		for(int i=s;i<x.size();i++){
			swap(x[i],x[s]);
			temp.push_back(x[s]);
			permute(x,ans,s+1,temp);
		temp.pop_back();
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int > temp;
        vector<vector<int>> ans;
      permute(nums,ans,0,temp);
      
	  return ans;  
    }
};
int main(){
vector<int> x;
x.push_back(1);
x.push_back(2);
x.push_back(3);
    Solution a;
    vector<vector<int >> b=a.permute(x);

    for(int i=0;i<b.size();i++){
    	for(int j=0;j<b[i].size();j++){
    cout<<b[i][j]<<" ";		
		}
	cout<<"\n";	
	}
	return 0;	
}
