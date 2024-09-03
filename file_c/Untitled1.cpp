#include<iostream>

using namespace std;
template<class T>
void printArray(T* start,T* end){
	 int size = end - start;
        for (int i = 0; i < size; i++)
            cout << start[i] << " ";
        cout << endl;
}
template<class T>
void sortSegment(T* start, T* end, int cur_segment_total) {
    // TODO
    for(T* i=start,*j=start+cur_segment_total;j!=end;i++,j++){
        if(*j<*i){
            T temp=*j;
            *j=*i;
            *i=temp;
        }
        T* past=i;
        T* past1=past-cur_segment_total;
        while(past1>=start){
            
            if(*past1>*past){
                T temp=*past1;
                *past1=*past;
                *past=temp;
            }
            past-=cur_segment_total;
            past1=past-cur_segment_total;
        }
    }
}
template<class T>
 void ShellSort(T* start, T* end, int* num_segment_list, int num_phases) {
    // TODO
    // Note: You must print out the array after sorting segments to check whether your algorithm is true.
     while(num_phases>0){
         int segments = *(num_segment_list+num_phases-1);
         num_phases--;
         
         sortSegment(start,end,segments);
          cout<<segments<<" segments: ";
            printArray(start,end);
    }
}
void fun(int *a,int *b){
	int * t=new int;
	*t=*a;
	*a=*b;
	*b=*t;
	delete t;
}
int main(){
	int* a=new int(20);
		int* b=new int(10);
		fun(a,b);
		cout<<*a<<" ,"<<*b;
}
