#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }
    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }

    void insert(const T &value)
    {
        //TODO
        insert(root,value);
    }

    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};//Helping functions
/// pLeft , pRight, data
void insert(Node*& root,const T& value){
    if(root == nullptr)
    {
    root = new Node(value);    
    return;
    }
  
    if(root->data<=value){
      insert(root->pRight,value);
      root->balance = RH;
    }
    else{
        insert(root->pLeft,value);
        if(!taller(root))
        return;
    }
}

Node* rotateRight(Node* &root) {
    //TODO: Rotate and return new root after rotate
if(root == nullptr)
return root;
Node* ans = root->pLeft;
root->pLeft = ans->pRight;
if(ans)
ans->pRight = root;
return ans;
}

Node* rotateLeft(Node* &root) {
    //TODO: Rotate and return new root after rotate
  if(root == nullptr)
  return root;
  Node* ans =root->pRight;
  root->pRight = ans->pLeft;
  if(ans)
  ans->pLeft = root;
 
  return ans;
}
bool taller(Node* &root){
    //// inset left
    
    if(root ->balance == EH){
        root->balance = LH;
        return true;
    }
    else if(root ->balance == RH){
        root->balance = EH;
        return false;
    }
    else{
        //// unbalance
        if(root->pLeft->balance==LH){
            /// left of left
        root = rotateRight(root);
        root->balance = EH;
        root->pRight->balance = EH;
        return false;
        }
        else{
            /// right of left
           root =  rotateLeft(root->pLeft);
            root = rotateRight(root);
            root ->balance = EH;
            root ->pRight->balance = EH;
            root->pLeft->balance = EH;
            return false;
        }
    }
    
    
}
int main(){
		
AVLTree<int> avl;
for (int i = 0; i >= -10; i--){
    avl.insert(i);
}
avl.printTreeStructure();
return 0;
}




