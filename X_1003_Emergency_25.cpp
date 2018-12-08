#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
const int maxn = 510,inf=1e6;
int n,m,st,ed,num[maxn];
int g[maxn][maxn];
int res[maxn],d[maxn],r[maxn];
int maxres=0;
bool vis[maxn]={false};
set<int> pre[maxn];
vector<int> tmpPath,path;

struct Node{
	int v,dis;
	Node(int _a,int _b):v(_a),dis(_b){
	}
};
vector<Node> adj[maxn];
void BF(int s) {
	
	fill(d,d+maxn,inf);
	memset(num,0,sizeof(num));
	memset(r,0,sizeof(r));
	num[s]=1;
	d[s]=0;
	r[s]=res[s];
	for(int i=0;i<n-1;i++) {
		for(int u=0;u<n;u++) {
			for(int j=0;j<adj[u].size();j++) {
				int v = adj[u][j].v;
				int dis = adj[u][j].dis;
				if(d[u]+dis <d[v]){
					d[v] = d[u]+dis;
					r[v] = r[u] + res[v];
					num[v] = num[u];
					pre[v].clear();
					pre[v].insert(u);
				}else if(d[u] + dis == d[v]) {
					if(r[u] + res[v] > r[v]){
						r[v] = r[u] + res[v];
					}
					pre[v].insert(u);
					num[v] = 0;
					set<int>::iterator it;
					for(it=pre[v].begin();it!=pre[v].end();it++) {
						num[v] += num[*it];
					}
				}
			}
		}
	}
}




int main() {
	scanf("%d %d %d %d",&n,&m,&st,&ed);
	
	for(int i=0;i<n;i++) {
		scanf("%d",&res[i]);
	}
	int c1,c2,c3;
	fill(g[0],g[0]+maxn*maxn,inf);
	for(int i=0;i<m;i++) {
		scanf("%d %d %d",&c1,&c2,&c3);
		adj[c1].push_back(Node(c2,c3));
		adj[c2].push_back(Node(c3,c2));
	}
	
	
	BF(st);
	
	//DFS(ed);
	printf("%d %d",num[ed],r[ed]);
	return 0;
}


