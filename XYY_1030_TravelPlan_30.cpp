#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=510,INF=1e5;
int N,M,S,D,d[MAXN],cost[MAXN],minCost=INF;
bool vis[MAXN]={false};
vector<int> pre[MAXN];

vector<int> tmpPath,path;
int G[MAXN][MAXN],c[MAXN][MAXN];

void Dijk(int s) {
	
	fill(d,d+MAXN,INF);
	d[s]=0;
	for(int i=0;i<N;i++) {
		int u=-1,MIN=INF;
		for(int j=0;j<N;j++) {
			if(vis[j]==false && d[j]<MIN) {
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<N;v++) {
			if(vis[v]==false && G[u][v]!=INF) {
				if	(d[u]+G[u][v]<d[v]){
					d[v] = d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
		}
	 }
  }
}
void DFS(int v) {
	
	if(v == S){
		
		tmpPath.push_back(v);
		int tempCost = 0;
		for( int i=tmpPath.size()-1; i>0 ;i--) {
			int id = tmpPath[i],idNext=tmpPath[i-1];
			tempCost += c[id][idNext];
		}
		if(tempCost < minCost) {
			minCost=tempCost;
			path = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(v);
	for(int i=0;i<pre[v].size();i++) {
		DFS(pre[v][i]);
	}
	tmpPath.pop_back();
}


int main () {
	scanf("%d %d %d %d",&N,&M,&S,&D);
	int c1,c2;
	fill(G[0],G[0]+MAXN*MAXN,INF);
	fill(c[0],c[0]+MAXN*MAXN,INF);
	for(int i=0;i<M;i++) {
		scanf("%d %d",&c1,&c2);
		scanf("%d %d",&G[c1][c2],&c[c1][c2]);
		G[c2][c1]=G[c1][c2];
		c[c2][c1]=c[c1][c2];
	
	}

	Dijk(S);
	DFS(D);
	//printf("%d\n",path.size());
	for(int i=path.size()-1;i>=0;i--) {
		printf("%d ",path[i]);
	}
	printf("%d %d\n",d[D],minCost);
	return 0;
}

