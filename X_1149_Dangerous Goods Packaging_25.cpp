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
//const int MAXV = 1000; //最大顶点数 
//const int INF = 0Xffffffff;
using namespace std;




int main() {
	int N,K,t1,t2;
	map<int,vector<int> > mp;
	scanf("%d %d",&N,&K);
	for (int i=0;i<N;i++) {
		scanf("%d %d",&t1,&t2);
		mp[t1].push_back(t2);
		mp[t2].push_back(t1);
	}
	while (K--) {
		int n,tmp,flag=-1,a[100000] ={0};
		
		scanf("%d",&n);
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			scanf("%d",&v[i]);
			a[v[i]] = 1;
		}	
		for(int i=0;i<v.size();i++) {
			for(int j=0;j<mp[v[i]].size();j++) {
				if(a[mp[v[i]][j]] == 1)flag=1;
			}
		}
		//printf("%d",flag);
		printf("%s\n",(flag!=-1)?"No":"Yes");
	}
	return 0;
}
	



