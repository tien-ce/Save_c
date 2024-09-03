#include <iostream>
#include <string>

using namespace std;

string fun1(string &str,int start){
    if(start==str.length()){
        return "";
    }
    if(str[start]==' '){
        return fun1(str,start+1);
    }
    else{
        return str[start]+fun1(str,start+1);
    }
}

int main(){
	string ans="msaas kas ed";
	string ans1=fun1(ans,0);
	cout<<ans1;
	}
