#include<iostream>
using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
    	bool has;
    	
		do{
			int len=0;
		string temp="";	
		has=false;
        
        for(int i=0;i<s.length();i++){
  
		 int dem=0;
        for(int j=0;j<part.length();j++){
        
    if(s[i+j]!=part[j]||has==true){
    dem=0;
	temp.push_back(s[i]);

	len++;
	break;
   }
   else {
   	
	   dem++;

   }  
   
        }
  if(dem!=0){
   if(has==false){  
    i+=dem-1;
}
     has=true;
}
        }
     s=temp;   

		}
		while(has!=false); 
return s;
    }
};
int main(){
string s="daabcbaabcbc";
Solution a;
string b=a.removeOccurrences(s,"abc");
cout<<b;
}
