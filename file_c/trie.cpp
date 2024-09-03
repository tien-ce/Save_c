#include<iostream>
#include<string>
using namespace std;
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
	Node* st[26]={nullptr};
	bool flag =false;
	Node(){
	}
};

class Trie {

public:
Node* root=new Node();
    /** Initialize your data structure here. */
    Trie() {

    }

    /** Inserts a word into the trie. */
    void insert(string word) {
    	Node *temp=this->root;
for(auto i:word){
	if(temp->st[i-'a']==nullptr)
	{
	
		temp->st[i-'a']=new Node();
	}
    temp= temp->st[i-'a'];
}
temp->flag =true;
    }

    /** Returns if the word is in the trie. */
bool search(string word) {
Node* temp=this->root;
for(auto i: word ){

	if(temp->st[i-'a']==nullptr)
{

	return false;
}
	temp=temp->st[i-'a'];
}
if(temp->flag==false)
return false;
return true;
}

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
Node* temp =this->root;
for(auto i: prefix ){
	if(!temp->st[i-'0'])
	return false;
	temp=temp->st[i-'0'];
}
return true;
    }
   
};
int main(){
	Trie* a= new Trie();
	a->insert("help");
	a->insert("hello");


	return 0;
}
