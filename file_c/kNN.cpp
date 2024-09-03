#include "kNN.hpp"
#include "main.hpp"
		/* TODO: You can implement methods, functions that support your data structures here.
		 * */
		
	////////////////////// class dataset	
void sort(pair<float,int>* a,pair<float,int>* b){
	for(auto i=b-1;i>a;i--){
		bool swap = false;
		for(auto j=i;j>a;j--){
		if(j->first<(j-1)->first){
		auto temp = *j;
		*j = *(j-1);
		*(j-1)	= temp;
		swap = true;
		}	
		}
		if(!swap){
			return;
		}
	}
}

//// 2
		 Dataset::Dataset(){
		 data = new SLLinkedlist<SLLinkedlist<int>*>();
		 first = new SLLinkedlist<string>();
		}
///// 3
		
		
		Dataset::~Dataset(){
		if(data!=nullptr)
		{
			delete data;
			data= nullptr;
		}
		if(first!=nullptr)
		{
			delete first;
			first = nullptr;
		}
		}
///// 4
Dataset::Dataset(const  Dataset& other){
	 
        data = new SLLinkedlist<SLLinkedlist<int>*>();
        first = new SLLinkedlist<string>();
        for(int i=0 ;i<other.get_first()->length();i++){
        	this->first->push_back(other.get_first()->get(i));
		}
		   for(int i=0 ;i<other.get_data()->length();i++){
        	SLLinkedlist<int> * temp = new SLLinkedlist<int>();
        	SLLinkedlist <int >* cur = other.getData()->get(i);
        	for(int j = 0 ;j<cur->length();j++){
        		temp->push_back(cur->get(j));
			}
			this->getData()->push_back(temp);
		}

}
///// 5	
Dataset& Dataset::operator=(const Dataset& other) {
    if (this != &other) { 
        delete data; 
        delete first; 
        data = new SLLinkedlist<SLLinkedlist<int>*>();
        first = new SLLinkedlist<string>();
        for(int i=0 ;i<other.get_first()->length();i++){
        	this->first->push_back(other.get_first()->get(i));
		}
		   for(int i=0 ;i<other.get_data()->length();i++){
        	SLLinkedlist<int> * temp = new SLLinkedlist<int>();
        	SLLinkedlist <int >* cur = other.getData()->get(i);
        	for(int j = 0 ;j<cur->length();j++){
        		temp->push_back(cur->get(j));
			}
			this->getData()->push_back(temp);
		}
		return *this;
    }
    return *this;
}
//// 1 

    //// 6
bool Dataset::loadFromCSV(const char* fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        return false;
    } else {
        string line;
        
        
        // Read the first line using getline
        getline(file, line);
        stringstream ss(line);
        
        string s;
        while (getline(ss, s, ',')) {
            first->push_back(s);
          
        }
        while (getline(file, line)) {
            SLLinkedlist<int>* row = new SLLinkedlist<int>();
            stringstream ss(line);
            int value;
            while (ss >> value) {
                row->push_back(value);
                if (ss.peek() == ',') {
                    ss.ignore();
                }
            }
            data->push_back(row);
        }

        file.close();
        return true;
    }
}
////7 

			void Dataset::printHead(int nRows, int nCols) const{
		    if(nRows<0||nCols<0)
		    return;
				if(nRows>data->length()){
					nRows=data->length();
				}
				if(nCols>first->length()){
					nCols=first->length();
				}
		    for(int i=0;i<nCols;i++){
		    	cout<<first->get(i);
		    	if(i!=nCols-1) cout<< " ";
			}
			cout<<endl;
			
			for(int i=0;i<nRows;i++){
				SLLinkedlist<int> * row = data->get(i);
			for(int j=0;j<nCols;j++){
			
			cout<<row->get(j);
				if(j!=nCols-1) cout<< " ";	
			}
			if(i!=nRows-1)
			cout<<endl;
			}
		
			}
//// 8 
void Dataset::printTail(int nRows, int nCols) const{
	        if(nRows<0||nCols<0)
	        return;
				if(nRows>data->length()){
					nRows=data->length();
				}
				if(nCols>first->length()){
					nCols=first->length();
				}
			for(int i=first->length()-nCols;i<first->length();i++){
		    	cout<<first->get(i);
		    	if(i!=first->length()-1)
		    	cout<<" ";
			}
			cout<<endl;
			for(int i=data->length()-nRows;i<data->length();i++){
				SLLinkedlist<int> * row = data->get(i);
			for(int j=row->length()-nCols;j<row->length();j++){
			
			cout<<row->get(j);	
		    	if(j!=row->length()-1)
		    	cout<<" ";
			}
			if(i!=data->length()-1)
			cout<<endl;
			}
			}
//// 9 
			void Dataset::getShape(int &nRow,int& nCol) const{	
				nRow=data->length();		
				nCol=first->length();
			}
//// 10			
			void Dataset::columns() const{
			for(int i=1;i<first->length();i++){
				cout<<first->get(i);
				if(i!=first->length()-1)
				cout<<" ";
			}
			}
//// 11			
			bool Dataset::drop(int axis,int index,string colums){
				if(axis!=0&&axis!=1){
					return false;
				}
				else if(axis==0){
				if(index>=data->length()||index<0)
				return false;
				else
				data->remove(index);
				}
				else if(axis==1){
					int re=first->getindex(colums);
				
					if(re==-1){
						return false;
					}
					else{						
						first->remove(re);
						for(int i=0;i<data->length();i++){
							data->get(i)->remove(re);
						}
					}

				}
					return true;				
			}
 ///// 12
			Dataset Dataset::extract(int startRow,int endRow,int startCol,int endCol) const{
				Dataset a ;
				
				int nrow=0,ncol = 0; 
				getShape(nrow,ncol);
				if(nrow==0||ncol==0)
				return a;
			    if(endRow==-1){
			    	endRow=nrow-1;
				}
				if(endCol==-1){
					endCol=ncol-1;
				}
		        if(startCol<-1||endRow<-1||startCol<-1||endCol<-1||startCol>endCol||startRow>endRow)
		        throw out_of_range("get(): Out of range");			
				 for(int i=startRow;i<=endRow;i++){
				 	SLLinkedlist<int> * row = new SLLinkedlist<int>();
     	        for(int j =startCol ; j <=endCol;j++){
     	        	row->push_back(data->get(i)->get(j)) ;
				 }
				
				 a.data->push_back(row);
	            }
	           
				 for(int i=startCol;i<=endCol;i++){
				 a.first->push_back(first->get(i));
				 }
	
				return a;
			}

////// KNN
//// 2
			
void kNN::fit(const Dataset& X_train, const Dataset& Y_train){
				this->X_train = X_train;
				this->Y_train=Y_train;
			}
double fun1(SLLinkedlist<int>*x , SLLinkedlist<int>* y){
	int x_size = x->length();
	int y_size = y->length();
	int *x_new = new int [x_size];
     x->set_array(x_new);
	int *y_new = new int [y_size];
	 y->set_array(y_new);
	double s = 0;
	for(int  i=0;i<x_size;i++){
		s += pow(y_new[i] - x_new[i],2);
	}
	return s;
}
Dataset kNN::predict(const Dataset& x_Test){
		    Dataset ans;	
			ans.get_first()->push_back(Y_train.get_first()->get(0));
		    int rowtrain= X_train.get_data()->length();
		    int rowtest=  x_Test.get_data()->length();
		    int coltrain= X_train.get_data()->get(0)->length();
		     SLLinkedlist<SLLinkedlist<int>*>* s11=x_Test.get_data();
			 SLLinkedlist<SLLinkedlist<int>*>* s22=X_train.get_data();
			 SLLinkedlist<SLLinkedlist<int>*>* s00= Y_train.get_data();
			for(int i=0;i<rowtest;i++){
			pair<float,int> * distan  = new pair<float,int>[rowtrain];
				    int  nums[10]= {0};
				    SLLinkedlist<int>* ans_row = new SLLinkedlist<int>();
				   
				for(int j=0;j<rowtrain;j++){			
				SLLinkedlist<int>* s0 = s00->get(j);
				distan[j] = make_pair(fun1(s11->get(i),s22->get(j)),s0->get(0));			
			}
			sort(distan,distan+rowtrain);
			for(int j=0;j<k;j++){
				nums[distan[j].second]++;
			}
		
			int max_label = 0;
		for(int j=0;j<10;j++){
		
    	if(nums[j] >nums[max_label]||nums[j]==nums[max_label]&&j<max_label){
        max_label = j;
    }

    }
ans_row->push_back(max_label);
ans.get_data()->push_back(ans_row);
}
	return ans;
}
	
		SLLinkedlist<string>* Dataset::get_first() const{
			return this->first;
			}
			SLLinkedlist<SLLinkedlist<int>*>* Dataset::get_data() const{
			 	return this->data;
			 }
			 
			 SLLinkedlist<SLLinkedlist<int>*>* Dataset::getData() const {
			 return this->data;
			 }
			////// class kNN
			kNN::kNN(int k ){
				this->k=k;
			}

			double kNN::score(const Dataset& y_test,const Dataset& y_pred){
				double tr = 0;
				int nrow ,ncol;
				y_test.getShape(nrow,ncol);
				for(int i=0;i<nrow;i++){
				if(y_pred.get_data()->get(i)->get(0)==y_test.get_data()->get(i)->get(0))
				{
				tr++;			
				}
	          
				}
				  cout<<tr;
				return tr / nrow;
			}
			
void train_test_split(Dataset&  x,Dataset&  y,double test_size,Dataset& x_train,Dataset& x_test,Dataset& y_train,Dataset& y_test){
	int nrow=0,ncol=0;
	x.getShape(nrow,ncol);			
	int testrow=(ceil(test_size*nrow));
	
    x_train=x.extract(0,nrow-testrow-1,0,ncol-1);
	y_train=y.extract(0,nrow-testrow-1,0,0);
	x_test=x.extract(nrow-testrow,nrow-1,0,ncol-1);
	y_test=y.extract(nrow-testrow,nrow-1,0,0);

	}


