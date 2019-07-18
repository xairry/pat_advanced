#include<iostream>
#include<string>
using namespace std;


int main() {
	int j,n;
	string s;
	cin>>s>>n;
	for(int cc=1;cc<n;cc++) {
		string t;
		for(int i=0;i<s.length();i = j) {
			for(j=i;j<s.length()&&s[i]==s[j];j++);
			t+=s[i]+to_string(j-i);
		}
		s = t;
	}
	cout<<s<<endl;
	return 0;
	
}
