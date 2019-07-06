#include<iostream> 
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;


int main() {
	string str;
	cin>>str;
	int len = str.length();
	int x;
	if((len+2)%3==0){
		 x=(len+2)/3;
	}else{
		 x=(len+2)/3+(len+2)%3;
	}
	int y=(len-x)/2;
	for(int i=0;i<y;i++) {
		cout<<str[i];
		for(int j=1;j<x-1;j++) {
		cout<<" ";
		}
		cout<<str[len-i-1]<<endl;
	}
	for(int i=y;i<x+y;i++) {
		cout<<str[i];
	}
	return 0;
} 
