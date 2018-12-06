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
const int MAXN = 110; 
//const int INF = 0Xffffffff;
//set<int> a[51];

double r,p,ans;
vector<int> child[MAXN];
int cntlevel[MAXN];
void DFS(int root,int depth) {
	cntlevel[depth]++;
	if(child[root].size()==0){
		return ;
		
	}
	for(int i=0;i<child[root].size();i++) {
		DFS(child[root][i],depth+1);
	}
}

int main() {
	int N,M,tmp2;
	scanf("%d %d",&N,&M);

	for(int i=0;i<M;i++) {
		int tmp=0,nt=0;
		scanf("%d %d",&tmp,&nt);
		for(int j=0;j<nt;j++) {
			scanf("%d",&tmp2);
			child[tmp].push_back(tmp2);
		}
	}
	DFS(1,1);
	int maxlevel=-1,maxnum=0;
	for (int i=0;i<MAXN;i++) {
		if(cntlevel[i]>maxnum){
			maxnum=cntlevel[i];
			maxlevel=i;
		}
	}
	printf("%d %d",maxnum,maxlevel);
	

	
	
	return 0;
}
	



