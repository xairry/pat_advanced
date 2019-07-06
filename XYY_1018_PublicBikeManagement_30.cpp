#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=500,inf=1e9;
bool vis[maxn]={false};
int c,n,s,m,ca=maxn;
int minNeed = inf, minBack = inf;
int ce[maxn],d[maxn],g[maxn][maxn],cap[maxn];
vector<int> pre[maxn];
vector<int> tempPath,path;

void Dijk(int st) {
	fill(d,d+maxn,inf);
	d[st]=0;
	for(int i=0;i<=n;i++) {
		int u=-1,min=inf;
		for(int j=0;j<=n;j++) {
			if(vis[j] == false && d[j]<min) {
				u = j;
				min = d[j];
			}
		}
		if(u == -1) return ;
		vis[u] = true;
		for(int v=0;v<=n;v++) {
			if(vis[v] == false && g[u][v]!=inf){
				if(d[u]+g[u][v] < d[v]){
					d[v] = d[u]+g[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+g[u][v] == d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int v) {
	if(v == 0){
		tempPath.push_back(v);
        int need = 0, back = 0;
        for(int i = tempPath.size() - 1; i >= 0; i--) {
            int id = tempPath[i];
            if(cap[id] > 0) {
                back += cap[id];
            } else {
                if(back > (0 - cap[id])) {
                    back += cap[id];
                } else {
                    need += ((0 - cap[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = tempPath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = tempPath;
        }
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++) {
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
	
	
}
int main() {
	scanf("%d%d%d%d",&c,&n,&s,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",&cap[i]);
		cap[i] = cap[i]-c/2;
	}
	fill(g[0],g[0]+maxn*maxn,inf);
	int c1,c2;
	for(int i=0;i<m;i++) {
		scanf("%d%d",&c1,&c2);
		scanf("%d",&g[c1][c2]);
		g[c2][c1] = g[c1][c2];
	}
	Dijk(0);
	DFS(s);
	//printf("%d",ca);
    printf("%d 0", minNeed);
    for(int i = path.size() - 2; i >= 0; i--)
        printf("->%d", path[i]);
    printf(" %d", minBack);
	return 0;
}
