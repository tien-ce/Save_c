#include <iostream>
#include <string>

using namespace std;
void fun1(string& ans, string &temp, int count, int start = 0) {
    if (start == count)
        return;
    ans += temp;
    fun1(ans, temp, count, start + 1);
}
string expand(string s,string ans, int &st,int loop){
 
    if(st>=s.length()-1)
    {
    	return ans;
	}
	char c=s[st];
    cout<<c<<endl;
    st+=1; 

	cout<<ans<<endl;

   
    if(c<'9'&&c>'0'){
      loop=c-'0';
    }
    else if(c==')'){
    	return ans;
	}
    else if(c=='('){
  //      fun1(loop,expand(s,"",st));
   string temp=expand(s,"",st,loop);
   cout<<"temp: "<<temp;
   for(int i=0;i<loop;i++){  	
  	ans+=temp;
	}

        loop=0;
    }
    else {
        ans+=c;
    }
    return expand(s,ans,st,loop);

     
}
string expand(string s) {
  int start = 0;
    int count=0;
    return expand(s,"",start,count);
}	

int main(){
cout << expand("2(ab3(cde)x)") << "\n";
	}
