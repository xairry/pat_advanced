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
#include<queue>
using namespace std;
//const int MAXV = 1000; //最大顶点数 
//const int INF = 0Xffffffff;
//set<int> a[51];




int main() {
	int N,tmp;
	cin>>N;
	map<int,int> mp;
	for(int i=0;i<N;i++) {
		cin>>tmp;
		mp[tmp]++;
	}
	int num=0;
	while(++num) {
		if(mp[num]==0){
			break;
		}
	}
	cout<<num;
	
	return 0;
}
	



