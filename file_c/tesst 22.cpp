#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(vector<vector<int>> graph, int start) {
	queue<int> st;
	int n = graph.size();
	vector<bool> visit(n,false);
	vector<int> ans;
	while(ans.size()!=n){
	    for(int i=0;i<n;i++){
	        if(graph[start][i]==1&&visit[i]==false){
	       st.push(i);     
	       ans.push_back(i);     
	        if(ans.size()!=n){
	            cout<<i<<" ";
	        }
	        else {
	            cout<<i;
	        }
	        visit[i]=true;
	        }
	    }
	start=st.front();
	}
}
int main(){
		int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
				    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]) graph[i].push_back(j);
		}
	}

	bfs(graph, 0);
}
