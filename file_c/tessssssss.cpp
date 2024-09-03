#include<stack>
#include<iostream>
#include<math.h>

int foldShift(long long key, int addressSize)
{
    stack<int> st;
    while(key!=0){
    st.push(key%10);
    key/=10;
    }
    int sum =0;
    while(!st.empty()){
    	int size = st.size();
        int p = size>addressSize?addressSize:size;
    for(int i = 0 ;i<addressSize;i++){
    	
     if(!st.empty())
     {
 
         cout<<st.top()*pow(10,p-i-1)<<endl;
         sum+=st.top()*pow(10,p-i-1);
         st.pop();
     }
     else{
         break;
     }
    }    
    }
    if(sum==1370)
    cout<<sum<<endl;
    int ans = 0;
    for(int i =0;i<addressSize;i++){
        int temp = sum%10;
        sum/=10;
        ans+=temp*pow(10,i);
    }
    return ans;
}

int rotation(long long key, int addressSize)
{
    int size = 0;
    int temp1=key;
    while(temp1!=0)
    {
        temp1/=10;
        size++;
    }
    int temp = key%10;
    key/=10;
    key+=temp*pow(10,size-1);
    int ans = foldShift(key,addressSize);
   
    return ans;
}
int main(){
	cout << rotation(123456789, 3);
}
