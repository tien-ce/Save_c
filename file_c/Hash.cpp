#include<iostream>
#include <utility>
using namespace std;
class Node{
	int a;
	int b;
	int sum;
	Node* next;
	public:
	Node(){
		this->a=-1;
		this->b=-1;
	}
	Node(int a,int b){
		this->a=a;
		this->b=b;
		sum = a+b;
		this->next=nullptr;
	}
};
class SLL{
	private:
	Node* head;
	Node* tail;
	public:
	SLL(){
		this->head=nullptr;
		this->tail= nullptr;
	}
	SLL (int a,int b){
		head = new Node(a,b);
		tail = head;
	}
};
int hash(int x,int n){
	return x%n;
}
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
SLL* sum = new SLL[n];
for(int i =0;i<n;i++){
	for(int j = i+1;j<n;j++){
		sum[hash(arr[i]+arr[j],n)] = new SLL(a,b);
	}
}
}
int main(){
	
}
