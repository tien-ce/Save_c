#include "main.hpp"
#include "Dataset.hpp"
/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */

struct LabeledPoint {
    vector<int> data;
    int label;
};
struct kDTreeNode
{
	int axis;
	int label;
    vector<int> data;
    kDTreeNode *left;
    kDTreeNode *right;
    kDTreeNode(vector<int> data, kDTreeNode *left = nullptr, kDTreeNode *right = nullptr)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    kDTreeNode(vector<int> data,int axis,kDTreeNode *left = nullptr, kDTreeNode *right = nullptr){
    	this->data = data;
        this->left = left;
        this->right = right;
    	this->axis = axis;
    	
	}
    kDTreeNode(vector<int> data,int axis ,int label,kDTreeNode *left = nullptr, kDTreeNode *right = nullptr){
    	this->data = data;
        this->left = left;
        this->right = right;
    	this->axis = axis;
    	this->label=label;
	}
    int get_label(){
        return this->label;
    }

};

class kDTree
{
private:
    int k;
    kDTreeNode *root;
	void buildTree(vector<vector<int>> &pointList,int start,int end,int axis);
	void buildTree(vector<LabeledPoint> &labeledPoints, int start, int end, int axis);
public:
    kDTree(int k = 2);
    ~kDTree(){};
	kDTreeNode* get_root(){
		return this->root;
	}
    const kDTree &operator=(const kDTree &other);
    kDTree(const kDTree &other);
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int height() const;
    int nodeCount() const;
    int leafCount() const;
	void insert(const vector<int> &point);
    void insert(const vector<int> &point,int label);
    void remove(const vector<int> &point);
    bool search(const vector<int> &point);
    
    void buildTree(const vector<vector<int>> &pointList);
    
    void buildTree(const vector<vector<int>> &pointList,vector<int> label);
    void nearestNeighbour(const vector<int> &target, kDTreeNode *&best);
   
    void kNearestNeighbour(const vector<int> &target, int k, vector<kDTreeNode *> &bestList);
};

class kNN
{
private:
    int k;
    Dataset *X_train;
    Dataset *y_train;
    int numClasses;
	
public:
    kDTree tree;
    kNN(int k = 5);
    void fit(Dataset &X_train, Dataset &y_train);
    Dataset predict(Dataset &X_test);
    double score(const Dataset &y_test, const Dataset &y_pred);
};

// Please add more or modify as needed
