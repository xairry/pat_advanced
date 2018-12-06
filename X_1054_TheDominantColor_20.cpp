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

int main() {
	int M,N,num;
	scanf("%d%d",&M,&N);
	map<int,int> mp;
	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			scanf("%d",&num);
			if(mp.find(num) != mp.end()) mp[num]++;
			else mp[num] = 1;
		}
	}
	int a,b=0;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
		if(it->second > b) {
			a=it->first;
			b=it->second;
		}
	}
	printf("%d\n",a);
	
	


	return 0;
}
	



