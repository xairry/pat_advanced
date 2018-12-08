#include<stdio.h>
#include<vector>
#include<cstring>
const int MAXN=1111;
using namespace std;
int N,M,K,now;
vector<int> G[MAXN];
bool vis[MAXN];
void dfs(int v) {
	if(v == now) return;
	vis[v] = true;
	for(int i=0;i<G[v].size();i++) {
		if(vis[G[v][i]]==false) {
			dfs(G[v][i]);
		}
	}
}
int main() {
	scanf("%d%d%d",&N,&M,&K);
	int a,b;
	for(int i=0;i<M;i++) {
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for(int i=0;i<K;i++) {
		scanf("%d",&now);
		memset(vis,false,sizeof(vis));
		int block = 0;
		for(int i=1;i<=N;i++) {
			if(i!=now && vis[i]==false){
				dfs(i);
				block++;
			}
		}
		printf("%d\n",block-1);
	}
}
