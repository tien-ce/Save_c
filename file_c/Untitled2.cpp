#include<iostream>
#include<vector>
#include<queue>
#include <utility>
using namespace std;
int secondsToBeRotten(vector<vector<int>>& grid) {
    queue<pair<    long unsigned int,long unsigned int>> q;
    long unsigned int m=grid.size();
    long unsigned int n=grid[0].size();

      for(int i=0;i<grid.size();i++){
       for(int j=0;j<grid[i].size();j++){
           if(grid[i][j]==2){
               q.push(make_pair(i,j));
           }
       }
   }

   int ans=0;
   while(!q.empty()){
     
   int size=q.size();
       for(int i=0;i<size;i++){
            pair<int,int> p = q.front();
            int x=p.first;
            int y =p.second;
   
        if(x+1<m&&grid[x+1][y]==1){
            grid[x+1][y]=2;
            q.push(make_pair(x+1,y));
        }
        if(x-1>=0&&grid[x-1][y]==1){
              grid[x-1][y]=2;
               q.push(make_pair(x-1,y));
        }
        if(y-1>=0&&grid[x][y-1]==1){
            grid[x][y-1]=2;
            q.push(make_pair(x,y-1));
        }
         if(y+1<n&&grid[x][y+1]==1){
              grid[x][y+1]=2;
                 q.push(make_pair(x,y+1)); 
        }
       
       q.pop();
       }
          
    ans++; 
   
   }
   
   for(auto i:grid){

       for(auto j:i){
         
           if(j==1)
           return -1;
       }
   
   }
    if(ans==0)
    return 0;
    return ans-1;
}
int main(){
   int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) cin >> grid[i][j];
    }
    cout << secondsToBeRotten(grid);
}
