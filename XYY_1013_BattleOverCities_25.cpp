// #include<cstdio>
// #include<algorithm>
// #include<vector>
// #include<cstring>

// using namespace std;
// const int N = 1111;
// vector<int> G[N];
// bool vis[N];
// int currentNode;

// void dfs(int v) {
// 	if(v == currentNode)return;
// 	vis[v] = true;
// 	for(int i=0;i<G[v].size();i++) {
// 		if(vis[G[v][i]] == false) {
// 			dfs(G[v][i]);
// 		}
// 	}
// }
// int n,m,k;


// int main() {
// 	scanf("%d%d%d",&n,&m,&k);
// 	for(int i=0;i<m;i++) {
// 		int a,b;
// 		scanf("%d%d",&a,&b);
// 		G[a].push_back(b);
// 		G[b].push_back(a);
// 	}
// 	for(int i=0;i<k;i++) {
// 		scanf("%d",&currentNode);
// 		memset(vis,false,sizeof(vis));
// 		int block = 0;
// 		for(int j=1;j<=n;j++) {
// 			if(j!=currentNode && vis[j] == false) {
// 				dfs(j);
// 				block++;
// 			}
// 		}
// 		printf("%d\n",block - 1);
// 	}
// 	return 0;
// }
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1111;
vector<int> G[N];
int fa[N];
bool vis[N];

int findFa(int x) {
	int a = x;
	while(x!=fa[x]) {
		x = fa[x];
	}
	while(a != fa[a]){
		int z = a;
		a = fa[a];
		fa[z] = x;
	}
	return x;
}

void union(int a,int b) {
	int fA = findFa(a);
	int fB = findFa(b);
	if (fA > fB) swap(fA,fB);
	fa[fA] = fB;
}

void init() {
	for(int i=1;i<N;i++) {
		fa[i] = i;
		vis[i] = false;
	}
}

int n,m,k;


int main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int currentNode;
	for(int q = 0;q<k;q++) {
		scanf("%d",&currentNode);
		init();
		for(int i=1;i<=n;i++) {
			for(int j = 0;j<G[i].size();j++) {
				int u = i,v = G[i][j];
				if(u == currentNode || v == currentNode)continue;
				union(u,v);
			}
		}
		int block = 0;
		for(int i=1;i<=n ;i++) {
			if (i==currentNode)continue;
			int fa_i = findFa(i);
			if(vis[fa_i]==false) {
				block++;
				vis[fa_i] = true;
			}
		}
		printf("%d\n",block - 1);
	}
	return 0;
}