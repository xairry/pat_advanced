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
const int MAXN = 100010; 
//const int INF = 0Xffffffff;
//set<int> a[51];

double r,p,ans;
int N,M,tmp2;
vector<int> node[MAXN];
int leaf[MAXN],maxLevel=1;

void DFS(int index,int level) {
	if(level>maxLevel)maxLevel=level;
	if(node[index].size()==0) {
		leaf[level]++;
		return;
	}
	for(int i=0;i<node[index].size();i++) {
		DFS(node[index][i],level+1);
	}
}


int main() {
	
	scanf("%d %d",&N,&M);
	if(N==0){
		return 0;
	}
	int nu,ch,root;
	for(int i=0;i<M;i++) {
		scanf("%d%d",&root,&nu);
		for(int j=0;j<nu;j++) {
			scanf("%d",&ch);
			node[root].push_back(ch);
		}
	}
	DFS(1,1);
	printf("%d",leaf[1]);
	for(int i=2;i<=maxLevel;i++) {
		printf(" %d",leaf[i]);
	}
	
	

	
	
	return 0;
}
	



