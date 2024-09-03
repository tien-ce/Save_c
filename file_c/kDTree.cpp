#include "kDTree.hpp"
/* TODO: You can implement methods, functions that support your data structures here.
 * */

void merge(vector<LabeledPoint>& labeledPoints, int start ,int end, int axis) {
    	
	int mid = start+(end-start)/2;
	/// copy data
	int len1 = mid-start+1;
	int len2 = end - mid;
    
	LabeledPoint* l1 = new LabeledPoint[len1];
	LabeledPoint* l2 = new LabeledPoint[len2];
    	
	int main_index = start;

	for(int i =0 ;i<len1;i++){
		l1[i] = labeledPoints[main_index++];
	}
    for(int i =0 ;i<len2;i++){
		l2[i] = labeledPoints[main_index++];
	}

    	
	int index1 = 0;
	int index2 = 0;
	main_index=start;
	while(index1<len1&&index2<len2){
		if(l1[index1].data[axis]<=l2[index2].data[axis]){
			labeledPoints[main_index++] = l1[index1++];
		}
		else{
			labeledPoints[main_index++] = l2[index1++];
		}
	}
	while(index1<len1){
		labeledPoints[main_index++] = l1[index1++];
	}
	while(index2<len2){
		labeledPoints[main_index++] = l2[index2++];
	}
    delete []l1;
    delete []l2;
}

void merge_sort(vector<LabeledPoint>& labeledPoints, int start, int end, int axis) {
    if (start >= end)
    return;
    int mid = start+(end-start)/2;

    merge_sort(labeledPoints, start, mid, axis);
    merge_sort(labeledPoints, mid + 1, end, axis);
    merge(labeledPoints, start, end, axis);
}

void meger( vector<vector<int>> &listpoint,int start,int end,int axis){
	
	int mid = start+(end-start)/2;
	/// copy data
	int len1 = mid-start+1;
	int len2 = end - mid;
	vector<int>* v1 = new vector<int>[len1];
	vector<int>* v2 = new vector<int>[len2];
	
	int main_index = start;

	for(int i =0 ;i<len1;i++){
		v1[i] = listpoint[main_index++];
	
	}
	for(int i =0;i<len2;i++){
		v2[i] = listpoint[main_index++];
		
	}
	
	
	int index1 = 0;
	int index2 = 0;
	main_index=start;
	while(index1<len1&&index2<len2){
		if(v1[index1][axis]<=v2[index2][axis]){
			listpoint[main_index++] = v1[index1++];
		}
		else{
			listpoint[main_index++] = v2[index2++];
		}
	}
	while(index1<len1){
		listpoint[main_index++] = v1[index1++];	
	}
	while(index2<len2){
		listpoint[main_index++] = v2[index2++];
	}
	delete []v1;
	delete []v2;
}
void meger_sort( vector<vector<int>> &listpoint,int start,int end,int axis){
	if(start>=end)
	return;
	int mid = start+(end-start)/2;
	
	meger_sort(listpoint,start,mid,axis);
	meger_sort(listpoint,mid+1,end,axis);
	meger(listpoint,start,end,axis);
}
////// build tree
void kDTree::buildTree( vector<vector<int>> &pointList,int start,int end,int axis){
	if(start>end)
	return;
	
	meger_sort(pointList,start,end,axis);
	
	int mid = start+(end-start)/2;
	this->insert(pointList[mid]);
	if(axis<this->k-1)
	axis++;
	else
	axis = 0;
	buildTree(pointList,start,mid-1,axis);
	buildTree(pointList,mid+1,end,axis);
}


void kDTree::buildTree(const vector<vector<int>> &pointList){
int axis = 0;
if(pointList.empty())
return;
int size = pointList.size();
vector<vector<int>> pointList1 = pointList;
buildTree(pointList1,0,size-1,0);
}

void kDTree::buildTree(vector<LabeledPoint> &labeledPoints, int start, int end, int axis) {
    if (start > end)
        return;

    merge_sort(labeledPoints, start, end, axis);

    int mid = start + (end - start) / 2;
    this->insert(labeledPoints[mid].data, labeledPoints[mid].label);
	if (axis < this->k - 1)
        axis++;
    else
        axis = 0;

    buildTree(labeledPoints, start, mid - 1, axis);
    buildTree(labeledPoints, mid + 1, end, axis);
}
void kDTree::buildTree(const vector<vector<int>> &pointList,vector<int> label){
	vector<LabeledPoint> labeledPoints;
	for(int i =0;i<(int)pointList.size();i++){
		LabeledPoint p;
		p.data = pointList[i];
		p.label = label[i];
		labeledPoints.push_back(p);
	}
	int size = pointList.size();
	vector<LabeledPoint> labeledPoints1 = labeledPoints;
	buildTree(labeledPoints1,0,size-1,0);
}

void insert(kDTreeNode*& root,const vector<int>& point,int axis,int k){
	if(root == nullptr)
	{
		root = new kDTreeNode(point,axis);
		return;
	}	
	else if(point[axis]<root->data[root->axis] )
	{
		
		if(axis <k-1)
		axis++;
		else 
		axis = 0;
	
		insert(root->left,point,axis,k);
	}
	else{
	
		if(axis <k-1)
		axis++;
		else 
		axis = 0;
		insert(root->right,point,axis,k);
	}
	
}
void insert(kDTreeNode*& root,const vector<int>& point,int axis,int k ,int label){
	if(root == nullptr)
	{
		root = new kDTreeNode(point,axis,label);
	
		return;
	}	
	else if(point[axis]<root->data[root->axis] )
	{
		
		if(axis <k-1)
		axis++;
		else 
		axis = 0;
		insert(root->left,point,axis,k,label);
	}
	else{
	
		if(axis <k-1)
		axis++;
		else 
		axis = 0;
		insert(root->right,point,axis,k,label);
	}
	
}
/////////insert
void kDTree::insert(const vector<int>& point){
	if(point.size()!=this->k)
	return;
	if(this->root==nullptr)
	{

		root = new kDTreeNode(point,0);
	}
	else
	::insert(this->root,point,0,this->k);
}
void kDTree::insert(const vector<int>& point,int label){

	if(point.size()!=this->k)
	return;
	if(this->root==nullptr)
	{
		root = new kDTreeNode(point,0,label);
	}
	else
	::insert(this->root,point,0,this->k,label);
}
void postorderTraversal(kDTreeNode* root,  int k){
	if(root==nullptr)
	return ;
	postorderTraversal(root->left,k);
	postorderTraversal(root->right,k);
	cout<<"(";
    for(int i = 0 ;i<k;i++){
    	cout<<root->data[i];
    	if(i!=k-1)
    	cout<<",";
	}
	cout<<")";
	cout<<" ";
}

//////// pos
void kDTree::postorderTraversal()const{
::postorderTraversal(this->root,this->k);
}
void preorderTraversal(kDTreeNode* root,const int &k){
	if(root == nullptr)
	return;
	cout<<"(";
    for(int i = 0 ;i<k;i++){
    	cout<<root->data[i];
    	if(i!=k-1)
    	cout<<",";
	}
	cout<<")";
	cout<<" ";
	preorderTraversal(root->left,k);
	preorderTraversal(root->right,k);
}
void kDTree::preorderTraversal() const{
	:: preorderTraversal(this->root,this->k);
}
///// pre
void inorderTraversal(kDTreeNode* root, const int & k) {
	if(root == nullptr)
	return;
	inorderTraversal(root->left,k);
	cout<<"(";
    for(int i = 0 ;i<k;i++){
    	cout<<root->data[i];
    	if(i!=k-1)
    	cout<<",";
	}
	cout<<")";
	cout<<" ";
	inorderTraversal(root->right,k);
}
void kDTree::inorderTraversal() const {
	
	::inorderTraversal(root, k);
}
////// in
 kDTree::kDTree(int k){
	this->k = k;
	this->root = nullptr;
}
int height(kDTreeNode* root){
	if(root==nullptr)
	return 0;
	return max(height(root->left)+1,height(root->right)+1);
}
int kDTree::height() const{

return ::height(this->root);
}
int nodeCount(kDTreeNode* root){
	if(root == nullptr)
	return 0;
	return 1+nodeCount(root->left)+nodeCount(root->right);
}
int kDTree::nodeCount() const {
return ::nodeCount(this->root);
}
int leafCount(kDTreeNode* root){
	if(root==nullptr)
	return 0;
	if(!root->left&&!root->right)
	return 1;
	return leafCount(root->left)+leafCount(root->right);
}
int kDTree::leafCount() const{
return ::leafCount(this->root);
}
kDTreeNode* search(kDTreeNode* root,const vector<int>& point){
	if(root == nullptr)
	return nullptr;	
	bool find = true;
	int size =point.size();
	for(int i = 0;i<size;i++){
		if(point[i]!=root->data[i]){
			find = false;
			break;
		}
	}
	if(find)
	return root;
	else{
	
		if(point[root->axis]<root->data[root->axis])
		return search(root->left,point);
		else
		return search(root->right,point);
	}
}
bool kDTree::search(const vector<int> &point){
	if(point.size()!=this->k)
	return false;
	return ::search(this->root,point)!=nullptr;
}
kDTreeNode* findLeast(kDTreeNode* root,int axis){
	if(root == nullptr||(root->left==nullptr&&root->right==nullptr))
	return root;
	if(root->axis==axis)
	{
		if(root->left==nullptr)
		return root;
		return findLeast(root->left,axis);
	}
	else {
	kDTreeNode* left = findLeast(root->left,axis);
	kDTreeNode* right = findLeast(root->right,axis);
	kDTreeNode* least;
	if(left==nullptr)
	{

		least = right;
	}
	else if(right ==nullptr)
	least= left;
	else
	{
		if(left->data[axis]<=right->data[axis])
		least = left;
		else 
		least = right;
	}
	if(least->data[axis]<root->data[axis])
	return least;
	else  
	return root;		
	}
}

/////Remove
void remove(kDTreeNode*& root,const vector<int>& point){

	if(root== nullptr)
	return;
	bool find = true;
	int size =point.size();
	for(int i = 0;i<size;i++){
		if(point[i]!=root->data[i]){
			find = false;
			break;
		}
	}
	if(!find){
		if(point[root->axis]<root->data[root->axis])
		remove(root->left,point);
		else
		remove(root->right,point);
	}
	else{
		if(!root->left&&!root->right)
	{
	////not child

	delete root;
	root = nullptr;
	}
	else if(root->right){
		kDTreeNode* least = findLeast(root->right,root->axis);
		root->axis = least->axis;
		root->data=least->data;
		remove(root->right,least->data);
	}
	else{
			kDTreeNode* least = findLeast(root->left,root->axis);
		root->axis = least->axis;
		root->data=least->data;
		root->right = root->left;
		root->left=nullptr;
		remove(root->right,least->data);
	}
	
	}
	
}

void kDTree::remove(const vector<int>& point){
	if(this->k!=point.size())
	return;
		::remove(this->root,point);
}




/////////////// hang xom gan nhat
void nearestNeighbour(kDTreeNode* root,const vector<int> target,kDTreeNode* &best){
		
	if(root ==nullptr)
	{

		return;
	}
	if(!root->left&&!root->right&&best==nullptr){
	
		best = root;
		return;
	}
	
	
	if(root->data[root->axis]>target[root->axis]){
		if(!root->left&&best==nullptr){
		best = root;
		return;
		}		
		nearestNeighbour(root->left,target,best);
	//// de quy nguoc	
	float distan  = 0;
	float near_distan=0;
	int size = root->data.size();
			
	for(int i =0 ;i<size;i++){
		near_distan+=pow(target[i] - best->data[i],2);
	}
	near_distan=sqrt(near_distan);

	for(int i =0 ;i<size;i++){
		distan+=pow(target[i] - root->data[i],2);
	}
	distan  = sqrt(distan);
	if(distan<=near_distan)
	{
		best = root;
		near_distan = distan;
	}	
	if(root->data[root->axis]-target[root->axis]<near_distan){
	
		nearestNeighbour(root->right,target,best);
	}
	else{
		return;
	}
	
	}
	else {
	if(!root->right&&best==nullptr){
		best = root;
		return;
	}
	nearestNeighbour(root->right,target,best);
			//// de quy nguoc	
	float distan  = 0;
	float near_distan=0;
	int size = root->data.size();
	
	for(int i =0 ;i<size;i++){
		near_distan+=pow(target[i] - best->data[i],2);
	}
	near_distan=sqrt(near_distan);
	
	for(int i =0 ;i<size;i++){
		distan+=pow(target[i] - root->data[i],2);
	}
	distan  = sqrt(distan);
	
	if(distan<=near_distan)
	{
		best = root;
		near_distan = distan;
	}	
	if(target[root->axis]-root->data[root->axis]<near_distan){
		nearestNeighbour(root->left,target,best);
	}
	else{
		return;
	}
	
	}
	
	
}
void kDTree::nearestNeighbour(const vector<int> &target, kDTreeNode *&best){	
	:: nearestNeighbour(this->root,target,best);
}
///// sort
void sort(vector<kDTreeNode*> &best,const vector<int>& target){

	int size = best.size();
	for(int i =0;i<size;i++){
		for(int j =i+1;j<size;j++){
			int distan1 = 0;
			int distan2 = 0;
			for(int k =0 ;(int)k<best[i]->data.size();k++){
			
			distan1+=pow(target[k] - best[i]->data[k],2);
			distan2+=pow(target[k] - best[j]->data[k],2);
			}
		
			if(distan2>distan1)
			swap(best[i],best[j]);
		}
	}
}

void kNearestNeighbour(kDTreeNode*&root,const vector<int>& target,int k,vector<kDTreeNode*> &best){			
	if(root ==nullptr)
	{
		return;
	}
	if(!root->left&&!root->right&&(int)best.size()<k){
		best.push_back(root);
		return;
	}
	if(root->data[root->axis]>target[root->axis]){
	/////// left
	if(!root->left&&(int)best.size()<k){
		best.push_back(root);
		kNearestNeighbour(root->right,target,k,best);
		}		
	else{
		kNearestNeighbour(root->left,target,k,best);
	}
	//// de quy nguoc	
	if(root->left){
		if((int)best.size()<k){
	best.push_back(root);
	
	kNearestNeighbour(root->right,target,k,best);
	}
	else{
	float distan  = 0;
	float near_distan=0;
	int size = root->data.size();
	//// sort dua khoang cach lon nhat len dau
	
	sort(best,target);
	for(int i =0 ;i<size;i++){
		near_distan+=pow(target[i] - best[0]->data[i],2);
	}
	near_distan=sqrt(near_distan);
	
	
	for(int i =0 ;i<size;i++){
		distan+=pow(target[i] - root->data[i],2);
	}
	distan  = sqrt(distan);

	if(distan<=near_distan)
	{

		best[0] = root;
		/// tiep tuc sort v� t�m ra kc lon nhat

		sort(best,target);
		near_distan=0;
		for(int i =0 ;i<size;i++){
		near_distan+=pow(target[i] - best[0]->data[i],2);
	
		}
		near_distan=sqrt(near_distan);
	}	
	if(root->data[root->axis]-target[root->axis]<near_distan){
		kNearestNeighbour(root->right,target,k,best);
	}
	else{
		return;
	}
	
	}
	}
	else{
	if((int)best.size()<k){
		best.push_back(root);
	}
	else{
		return;
	}	
	}
	
	}
	else{
	//////// right
	if(!root->right&&(int)best.size()<k){
		kNearestNeighbour(root->left,target,k,best);
		}		
	else{
		kNearestNeighbour(root->right,target,k,best);
	}
	//// de quy nguoc	
	if(root->right){
		if((int)best.size()<k){

		best.push_back(root);
	
		kNearestNeighbour(root->left,target,k,best);
	}
	else{
	float distan  = 0;
	float near_distan=0;
	int size = root->data.size();
	//// sort dua khoang cach lon nhat len dau

	sort(best,target);

	for(int i =0 ;i<size;i++){
		near_distan+=pow(target[i] - best[0]->data[i],2);
	}
	near_distan=sqrt(near_distan);

	for(int i =0 ;i<size;i++){
		distan+=pow(target[i] - root->data[i],2);
	}
	distan  = sqrt(distan);
	if(distan<=near_distan)
	{
			
		best[0] = root;

		/// tiep tuc sort v� t�m ra kc lon nhat
		sort(best,target);
		near_distan=0;
		for(int i =0 ;i<size;i++){
		near_distan+=pow(target[i] - best[0]->data[i],2);
		}
		near_distan=sqrt(near_distan);
	}	
	if(target[root->axis]-root->data[root->axis]<near_distan){
		kNearestNeighbour(root->left,target,k,best);
	}
	else{
		return;
	}
			
	}
	}
	else{
		if((int)best.size()<k){
			best.push_back(root);
		}
		else{
			return;
		}
	}
}

}
void kDTree::kNearestNeighbour(const vector<int> &target, int k, vector<kDTreeNode *> &bestList){
	:: kNearestNeighbour(this->root,target,k,bestList);
}
kNN::kNN(int k):tree(784){
	this->k=k;
}

void kNN::fit(Dataset &X_train, Dataset &y_train) {
    vector<vector<int>> data;
    vector<int> label;
	this->X_train = &X_train;
	this->y_train = &y_train;
    for(const auto i: X_train.data){
    	vector<int> data1;
    	for(const auto  j:i){
    		data1.push_back(j);
		}
		data.push_back(data1);
	}
	for(auto i: y_train.data){
		label.push_back(i.front());
	}
	this->tree.buildTree(data,label);
}
Dataset kNN::predict(Dataset& X_test){
	Dataset ans;
	ans.columnName.push_back(X_test.columnName.front());
    for(const auto i:  X_test.data){
    vector<int> data (next(i.begin()) ,i.end());
    vector<kDTreeNode*> bestList;
    tree.kNearestNeighbour(data,this->k,bestList);
    int nums[10] = {0};
    for(const auto j : bestList){
    nums[j->get_label()]++;
    }
	int label_max = 0;
	for(int k =1;k<10;k++){
	
		if(nums[k]>nums[label_max])
		label_max = k;
	}
	list<int> ans1;
	ans1.push_back(label_max);
	ans.data.push_back(ans1);
    }

    return ans;
}
double kNN::score(const Dataset &y_test, const Dataset &y_pred){
	double sc = 0.0;
	int tr = 0;
	int row ,col;
	y_test.getShape(row,col);
	 auto  yt = y_test.data.begin();
	 auto yp = y_pred.data.begin();
	for(int i =0;i<row;i++){
		if(yt->front()==yp->front())
		tr++;
		yt++;
		yp++;
	}
	sc = (float)tr/row;
	return sc;
}

			

