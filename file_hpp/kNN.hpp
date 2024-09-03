#include "main.hpp"
/* TODO: Please design your data structure carefully so that you can work with the given dataset
 *       in this assignment. The below structures are just some suggestions.
 */
template <class T>
class List {
public:
    virtual ~List() = default;
    virtual int getindex(T item) =0;
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(int index) = 0;
    virtual T& get(int index) const = 0;
    virtual int length() const = 0 ;
    virtual void clear() = 0;
    virtual void print() const = 0;
    virtual void reverse() = 0;
};
template <class T>
class SLLinkedlist;
	template <class T>
		class Node {
			private:
			T data;
			Node* next;
			public:
	
			Node (T data){
				this->data=data;
				next=nullptr;
			}
			friend class SLLinkedlist<T>;
		};
		template <class T>
	class SLLinkedlist : public List<T>{
			private:
			Node<T>* head;
			Node<T>* tail;
			int count;
			public:
		SLLinkedlist(){
			count=0;
			head=nullptr;
			tail=nullptr;
		}
		SLLinkedlist(const SLLinkedlist& other) {
    count = 0;
    head = nullptr;
    tail = nullptr;
    Node<T>* temp = other.head;
    while (temp != nullptr) {
        this->push_back(temp->data);
        temp = temp->next;
    }
   }
   ///   1	
		~SLLinkedlist() {
		    this->clear();
		}
	/// 2	
	void push_back(T value){
			Node<T>* a=new Node<T>(value);
			if(head==nullptr){
				head=a;
				tail=a;
			}
			else{
				tail->next=a;
				tail=tail->next;
			}
			count++;
		}
	/// 3	
		void push_front(T value){
			Node<T>* a=new Node<T> (value);
			if(this->count==0||head==nullptr){
				head=a;
				tail=a;
			}
			else{
				a->next=head;
				head=a;
			}
			count++;
		}
	//// 4	
	void insert(int index,T value){
		if(index<0||index>count){
			return;		
		}	
		else if(index==0){
			push_front(value);
		}
		else if(index==count){
			push_back(value);
		}
		else
		{
		Node<T>* newNode = new Node<T>(value);
        Node<T>* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
		}
		
		}
		
		////5 
		
		void remove(int  index){

			if(index<0 || index>=count){
			return;
			}
			else if(index==0)
			{
				Node<T>* temp=head;
				head=head->next;
				delete temp;
			}

			else if(index==count-1){
		
			Node<T>* temp=head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			tail=temp;
			
			delete tail->next;
			tail->next=nullptr;
			}
			
			else{
			Node<T>* temp=head;
			for(int i=0;i<index-1;i++){
			temp=temp->next;
			}
			Node<T> *temp1=temp->next;
			temp->next=temp1->next;
			delete temp1;
				
			}	
			count--;
		}
		
		///6 
		T& get(int index) const{
		if(index<0||index>=count){	
		throw out_of_range("get(): Out of range");			
		}
			Node<T> * temp=head;
		for(int i=0;i<index;i++){
			temp=temp->next;
		}
		return temp->data;	
				
		}	
        int getindex(T item){
        	Node<T> * temp = head;
        	int ans=0;
        	while(temp!=nullptr){
        		if(temp->data==item){
        			return ans;
				}
				else{
					ans++;
					temp=temp->next;
				}
			}
			return -1;
		}		
		int length() const{
			return this->count;
		}
		void clear() {
	    Node<T>* current = head;
	    while (current != nullptr) {
	        Node<T>* nextNode = current->next;
	        delete current;
	        current = nextNode;
	    }
	    head = nullptr;
	    tail = nullptr;
	    count = 0;
	}
		void print() const{
			Node<T> * temp=head;
			while(temp!=nullptr){
				if(temp->next==nullptr){
				cout<<temp->data;
			break;
			}
				cout<<temp->data<<" ";
			
			temp=temp->next;	
			}
			
		}
		void reverse(){
			if(head==nullptr||head->next==nullptr)
			{
				return ;
			}
			
			Node<T> * past=nullptr;
			Node<T> * pre=head;
			Node<T> * nex=head->next;
			while(pre!=nullptr){
				pre->next=past;
				past=pre;
				pre=nex;
				if(nex!=nullptr)
				{	
					nex=nex->next;
				}
			}
			tail=head;
			head=past;
		}
		void set_array(int* a){
		Node<int>* temp =head;
		for(int i=0;i<count;i++)
		{
			a[i] = temp ->data;
			temp=temp->next;
		}
		}	

		};	
	
class Dataset {
private:
   SLLinkedlist<SLLinkedlist<int>*>* data;
   SLLinkedlist<string>* first;
public:
    Dataset();
    ~Dataset();
    Dataset( const  Dataset& other);
    Dataset& operator=(const Dataset& other);
    bool loadFromCSV(const char* fileName);
    void printHead(int nRows = 5, int nCols = 5) const;
    void printTail(int nRows = 5, int nCols = 5) const;
    void getShape(int& nRows, int& nCols) const;
    void columns() const;
    bool drop(int axis = 0, int index = 0, std::string columns = "");
    Dataset extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const;
    SLLinkedlist<SLLinkedlist<int>*>* get_data() const;
    SLLinkedlist<SLLinkedlist<int>*>* getData() const;
    SLLinkedlist<string>* get_first() const;
    
};

class kNN {
private:
    int k;
      Dataset X_train;
	  Dataset Y_train;
	    /// x dac trung khong phai nhan , y nhan tuong ung voi dac trung
    //You may need to define more
public:
    kNN(int k = 5);
    void fit(const Dataset& X_train, const Dataset& y_train);
    Dataset predict(const Dataset& X_test);
    double score(const Dataset& y_test, const Dataset& y_pred);
};

void train_test_split(Dataset& X, Dataset& y, double test_size, 
                        Dataset& X_train, Dataset& X_test, Dataset& y_train, Dataset& y_test);

// Please add more or modify as needed
