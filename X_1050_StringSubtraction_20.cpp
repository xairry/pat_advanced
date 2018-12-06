#include<iostream> 
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;
bool hashTable[128];

int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b); 
	for(int i=0;i<b.length();i++) {
		hashTable[b[i]]=true;
	}
	for(int i=0;i<a.length();i++) {
		if(hashTable[a[i]]==false){
			printf("%c",a[i]);
		}
	}
	
	return 0;
} 
