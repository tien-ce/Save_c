#include <iostream>
#include <vector>
using namespace std;	
void meger(vector <int> &arr,int s,int e){
    int point_main=s;
    int mid=s+(e-s)/2;
    int len_1=mid-s+1;
    int len_2=e-mid;
    int *arr_1=new int[len_1]; 
    int *arr_2=new int [len_2];
   int s1=0,s2=0;
    for(int i=0;i<len_1;i++){
        arr_1[i]=arr[point_main++];
      
    }
    for(int i=0;i<len_2;i++){
        arr_2[i]=arr[point_main++];
       
    }

    point_main=s;
    while(s1<len_1&&s2<len_2){
        if(arr_1[s1]<arr_2[s2]){
           arr[point_main++]=arr_1[s1++]; 
          
        }
        else{
             arr[point_main++]=arr_2[s2++];
        }
    }
    while(s1<len_1){
        arr[point_main++]=arr_1[s1++];
    }
    while(s2<len_2){
        arr[point_main++]=arr_2[s2++];
    }
    
    delete [] arr_1;
    delete [] arr_2;
}
void meger_sort(vector<int> &arr,int s,int e){
int mid=s+(e-s)/2;
if(s>=e)
return;
meger_sort(arr,mid+1,e);
meger_sort(arr,s,mid);
meger(arr,s,e);

}
bool isposble(vector<int> arr,int k,int m){
    int count_cow=1,langets=0,temp=0;
    for(int i=1;i<arr.size();i++)
{
	
    if(arr[i]-arr[temp]>=m){
   
	    count_cow++;
    
        temp=i;
    }

}
 if(count_cow>=k)
    return true;
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    meger_sort(stalls,0,stalls.size()-1);
    int s=0,e=0;
  
		for(int i=0;i<stalls.size();i++){
        e+=stalls[i];
    }
   
    int mid=s+(e-s)/2;
int ans;
while(s<=e){
	
if(isposble(stalls, k, mid)){

ans=mid;
s=mid+1;
}
else{
    e=mid-1;
}
mid=s+(e-s)/2;
}
return ans;
}
int main(){
	vector<int> arr;
  arr.push_back(4);
  arr.push_back(2);
  arr.push_back(1);
  arr.push_back(3);
  arr.push_back(6);


  meger_sort(arr,0,arr.size()-1);
 
  cout<<aggressiveCows(arr,2);

	return 0;
}
