#include<iostream>
#include<vector>
using namespace std;
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;
        
        while(start<=end) {
            cout<<"mid="<<mid<<endl;
            int element = matrix[mid/col][mid%col];
            
            if(element == target) {
                return 1;
            }
            
            if(element < target) {
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }
};
int main(){
	vector<vector<int>> arr(3,vector<int>(3));
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		cin>>arr[i][j];
		}
	}
	Solution a;
	cout<<a.searchMatrix(arr,4);
return 0;
}
