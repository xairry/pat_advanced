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
int minlevel=MAXN,cnt=0;
void DFS(int index,int level) {
	
	if(node[index].size() == 0){
		if(level<minlevel){
			minlevel=level;
			cnt=1;
		}else if(level==minlevel){
			cnt++;
		}
		return ;
	}
	for(int i=0;i<node[index].size();i++) {
		DFS(node[index][i],level+1);
	}
}


int main() {
	
	scanf("%d %lf %lf",&N,&p,&r);
	r/=100;
	int ch;
	for(int i=0;i<N;i++) {
		scanf("%d",&M);
		if(M!=0){
			for(int j=0;j<M;j++) {
			scanf("%d",&ch);
			node[i].push_back(ch);
		}
		}
		
	}
	DFS(0,0);
	ans = p*pow(1+r,minlevel);
	printf("%.4f %d",ans,cnt);
	

	
	
	return 0;
}
	



