#include <iostream>
#include <stack>
#include<vector>
#include <cmath>
using namespace std;
void in_matran(int a[100][100],int n,int m){
	for(int i=0;i<n;i++){
	cout<<"\n";
	for(int j=0;j<m;j++){
	cout<<a[i][j]<<" ";	
	}	
	
	}
}
int my_max(int a,int b){
	return a>b?a:b;
}
vector<int> nextsmallerelemnt(vector <int> &arr,int n){
stack<int> st;
vector<int> ans(n);
st.push(-1);
for(int i=n-1;i>=0;i--){
while(arr[st.top()]>=arr[i]&& st.top()!=-1){
	st.pop();
}
ans[i]=st.top();
st.push(i);
}
return ans;
}
vector<int> beforesmallerlemt(vector<int> &arr,int n){
stack <int> st;
vector <int> ans(n);
st.push(-1);
for(int i=0;i<n;i++){
	while(arr[st.top()]>=arr[i] && st.top()!=-1){
		st.pop();
	}
	ans[i]=st.top();
	st.push(i);
}		
	return ans;
} 
class Solution{
	public:
	int lanrgest(vector<int> height){
	int dien_tich;
	int max=0;
		int n=height.size();
		
		vector<int> next=nextsmallerelemnt(height,n);
        vector<int> preve=beforesmallerlemt(height,n);   
  	for(int i=0;i<n;i++){
    
		if(next[i]==-1){
			next[i]=n;
					}
	int h=height[i];
	int l=next[i]-preve[i]-1;
	
	int dien_tich=l*h;
	max=my_max(max,dien_tich);
	}   
return max;
	}
	
int max_area(int a[100][100] ,int n,int m){
vector<int >st(m);
int max_are=0;

int dien_tich;
for(int i=0;i<m;i++){
	st[i]=0;
}
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	if(a[i][j]==0){
	
		st[j]=0;
	}	
	else{	
  
		st[j]+=a[i][j];

	}
    
	}
dien_tich=lanrgest(st);
max_are=my_max(max_are,dien_tich);

}
return max_are;
}
};

int main(){	
 Solution x;
    int n, m;
    cin >> n >> m;
    int a[100][100];
    for (int i = 0; i < n; i++) {  
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        }
    in_matran(a,n,m);
    cout<<"\n";
cout<<x.max_area(a,n,m);
}
