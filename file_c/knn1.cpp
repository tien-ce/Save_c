		#include "kNN.hpp"
        #include <chrono>
		#include<vector>
		#include<algorithm>
		/* TODO: You can implement methods, functions that support your data structures here.
		 * */
		
	////////////////////// class dataset	

		 Dataset::Dataset(){
		 data = new SLLinkedlist<SLLinkedlist<int>*>();
		 first = new SLLinkedlist<string>();
		}
		Dataset::~Dataset(){
		delete data;
		}
Dataset& Dataset::operator=(const Dataset& other) {
    if (this != &other) { 
  delete data; 
        delete first; 

        data = new SLLinkedlist<SLLinkedlist<int>*>(*other.data);
        first = new SLLinkedlist<string>(*other.first);
    }
    return *this;
}
      
	   
bool Dataset::loadFromCSV(const char* fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Cannot open file" << endl;
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
			void Dataset::printHead(int nRows, int nCols) const{
				
				if(nRows>data->length()){
			
					nRows=data->length();
				}
				if(nCols>first->length()){
					nCols=first->length();
				}
		    for(int i=0;i<nCols;i++){
		    	cout<<first->get(i)<<" ";
			}
			cout<<endl;
			
			for(int i=0;i<nRows;i++){
				SLLinkedlist<int> * row = data->get(i);
			for(int j=0;j<nCols;j++){			
			cout<<row->get(j)<<" ";	
			}
			if(i!=nRows-1)
			{
				cout<<"\n";	
			}
			
			}
			}
			////////////////   print Tail
			void Dataset::printTail(int nRows, int nCols) const{
				if(nRows>data->length()){
					nRows=data->length();
				}
				if(nCols>first->length()){
					nCols=first->length();
				}
			for(int i=first->length()-nCols;i<first->length();i++){
		    	cout<<first->get(i)<<" ";
			}
			cout<<endl;
			for(int i=data->length()-nRows;i<data->length();i++){
				SLLinkedlist<int> * row = data->get(i);
			for(int j=row->length()-nCols;j<row->length();j++){
			
			cout<<row->get(j)<<" ";	
			}
			if(i!=data->length()-1)
			cout<<endl;
			}
			}
			///////////////////////////////    getShape
			void Dataset::getShape(int &nRow,int& nCol) const{
				nRow=data->length();		
				nCol=first->length();
			}
			void Dataset::columns() const{
			for(int i=1;i<first->length();i++){
				cout<<first->get(i)<<" ";
			}
			}
			bool Dataset::drop(int axis,int index,string colums){
				if(axis!=0&&axis!=1){
					return false;
				}
				else if(axis==0){
				if(index>=data->length())
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
			//////////////////////////  extract
			Dataset Dataset::extract(int startRow,int endRow,int startCol,int endCol) const{
	             auto start = std::chrono::high_resolution_clock::now();
				Dataset a ;
				int nrow=0,ncol = 0; 
				
				getShape(nrow,ncol);
				
			    if(endRow==-1){
			    	endRow=nrow-1;
				}
				if(endCol==-1){
					endCol=ncol-1;
				}
		
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
			 auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end-start;

    std::cout << "time for extract " << diff.count() << " s\n";
				return a;
			}
		
			SLLinkedlist<string>* Dataset::get_first() const{
				return this->first;
			}
			SLLinkedlist<SLLinkedlist<int>*>* Dataset::get_data() const{
			 	return this->data;
			 }
			 SLLinkedlist<SLLinkedlist<int>*>* Dataset::getData() const{
			 	return this->data;
			 }
			////// class kNN
			kNN::kNN(int k ){
				this->k=k;
			}
			void kNN::fit(const Dataset& X_train, const Dataset& Y_train){
				this->X_train = X_train;
				this->Y_train=Y_train;
            
			}
			Dataset kNN::predict(const Dataset& x_Test){
			 auto start = std::chrono::high_resolution_clock::now();
		    Dataset ans;
	ans.get_first()->push_back(Y_train.get_first()->get(0));

	int rowtrain= X_train.get_data()->length();
	int rowtest=  x_Test.get_data()->length();

	vector<pair<float,int>> distan(rowtrain);
	vector<int> nums(10);
	
	for(int i=0;i<rowtest;i++){
    fill(nums.begin(), nums.end(), 0);
    SLLinkedlist<int>* ans_row = new SLLinkedlist<int>();
    for(int j=0;j<rowtrain;j++){
        float s = 0;
        for(int k=0;k<X_train.get_data()->get(j)->length();k++){
            s+= pow(x_Test.get_data()->get(i)->get(k)-X_train.get_data()->get(j)->get(k) ,2);		    		
        }
        distan[j] = make_pair(sqrt(s), Y_train.get_data()->get(j)->get(0));
    }
    sort(distan.begin(),distan.end());
    for(int j=0;j<k&&j<distan.size();j++){
        nums[distan[j].second]++;
    }
    int max= 0;
    for(int j=0;j<10;j++){
        if(nums[max]<nums[j]){
            max=j;
        }
    }
    ans_row->push_back(max);
    ans.get_data()->push_back(ans_row);
}
 auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end-start;

    std::cout << "time for predic " << diff.count() << " s\n";
return ans;
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
				return tr / nrow;
			}
			
void train_test_split(Dataset&  x,Dataset&  y,double test_size,Dataset& x_train,Dataset& x_test,Dataset& y_train,Dataset& y_test){
	int nrow=0,ncol=0;
	x.getShape(nrow,ncol);			
	int testrow=(test_size*nrow+0.5);
	x_test=x.extract(nrow-testrow+1,nrow-1,0,ncol-1);
	y_test=y.extract(nrow-testrow+1,nrow-1,0,0);
    x_train=x.extract(0,nrow-testrow,0,ncol-1);
	y_train=y.extract(0,nrow-testrow,0,0);	
	}



