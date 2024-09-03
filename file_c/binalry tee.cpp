#include<iostream>
#include<queue>
#include<stack>
using namespace std;


class Node {
	public:
	int data;
	Node* left;
	Node* right;
	Node(int data){
		this->data=data;
		this->left=nullptr;
		this->right=nullptr;
	}
};
queue <int> a;

Node* bulid_tree(Node* root){
	int data;
	cout<<"enter data:"<<endl;
	cin>>data;
	root=new Node(data);
	if(data==-1)
	return nullptr;
	cout<<"enter data for left of " <<root->data<<":"<<endl;
	root->left=bulid_tree(root->left);
	cout<<"enter data for right of " <<root->data<<":"<<endl;
	root->right=bulid_tree(root->right);
	return root;
}
void level0_travel(Node* root){
	queue <Node*> q;
	q.push(root);
	q.push(nullptr);
	
	while(!q.empty()){
		Node* temp=q.front();
		
		
	q.pop();
	if(temp==nullptr){/// hoan thanh level
		cout<<"\n";
		if(!q.empty()){//// node con node con
			q.push(nullptr);
		}
	}
	else{
	cout<<temp->data<<" ";	
	if(temp->left){
	q.push(temp->left);	
	}
	if(temp->right){
	q.push(temp->right);	
	}
	}

	}
	
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
int main(){
	Node* root=nullptr;
	root=bulid_tree(root);
	level0_travel(root);
	return 0;
}
