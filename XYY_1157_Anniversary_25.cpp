#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;
unordered_set<string> st;
int main(){
	string s;
	int n,m;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s;
		st.insert(s);
	}
	cin>>m;
	vector<string> a,b;
	for(int i=0;i<m;++i){
		cin>>s;
		if(st.find(s)!=st.end()) a.push_back(s);
		else b.push_back(s);
	}
	cout<<a.size()<<endl;
	if(a.empty()){
		int age=99999999;
		for(string &r:b){
			if(stoi(r.substr(7,8))<age){
				age=stoi(r.substr(7,8));
				s=r;
			}
		}
		cout<<s<<endl;
	}else{
		int age=99999999;
		for(string &r:a){
			if(stoi(r.substr(7,8))<age){
				age=stoi(r.substr(7,8));
				s=r;
			}
		}
		cout<<s<<endl;
	}
	return 0;
} 