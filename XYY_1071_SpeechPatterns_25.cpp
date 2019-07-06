 #include<iostream>
#include <stdio.h>
#include <cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cctype>
using namespace std;
//const int MAXV = 1000; //最大顶点数 
//const int INF = 0Xffffffff;
set<int> a[51];

int gcd(int a,int b) {
	if(b==0)return a;
	else return gcd(b,a%b);
}

bool isprime(int n) {
	if( n<=1)return false;
	for(int i=2;i<sqrt((double)n);i++) {
		if(n%i==0) return false;
	}
	return true;
}
bool check(char c) {
	if(c>='0' && c<='9') return true;
	if(c>='a' && c<='z') return true;
	if(c>='A' && c<='Z') return true;
	return false;	
}

int main() {
	string str;
	int i=0;
	map<string,int> mp;
	getline(cin,str);
while(i<str.length()) {
		string word;
		while(check(str[i])) {
			if(str[i]>='A' && str[i]<='Z'){
				str[i]+=32;
			}
				
			word+=str[i++];		
		}
		if(word != "") {
			if(mp.find(word) ==mp.end()) mp[word] =1;
			else mp[word]++;
		}
		if(!check(str[i])){
			i++;
		}
		
	}
	string ans;
	int max=0;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++) {
		if(it->second>max){
			
			ans = it->first;
			max = it->second;
		}
	
	}
	
	
		cout<<ans<<" "<<max<<endl;
	


	return 0;
}
	



