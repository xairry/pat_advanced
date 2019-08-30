#include<stdio.h>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int fa[maxn];
bool isRoot[maxn]={false};
vector<int> G[maxn];

int findf(int x) {
	int a = x;
	while(x!=fa[x]){
		x = fa[x];
	}
	while(a!=fa[a]) {
		int z = a;
		a = fa[a];
		fa[z] = x;
	}
	return x;
	
}

void merg(int a,int b) {
	int ffa = findf(a);
	int ffb = findf(b);
	if(ffa>ffb){
		swap(ffa,ffb);
	}
	fa[ffa] = ffb;
}

void init(int n) {
	for(int i=1;i<=n;i++) {
		fa[i] = i;
	}
}

int calblock(int n) {
	int block = 0;
	for(int i=1;i<=n;i++) {
		isRoot[findf(i)] = true;
	}
	for(int i=1;i<=n;i++) {
		block += isRoot[i];
	}
	return block;
}
int maxH = 0;
vector<int> temp,ans;

void dfs(int u,int hi,int pre) {
	if(hi > maxH) {
		temp.clear();
		temp.push_back(u);
		maxH = hi;
	}else if(hi == maxH) {
		temp.push_back(u);
	}

	for(int i = 0; i<G[u].size(); i++) {
		if(G[u][i] == pre)continue;
		dfs(G[u][i],hi+1,u);
	}
}

int main () {
	
	int a,b,n;
	scanf("%d",&n);
  init(n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
		merg(a,b);
	}
	int block = calblock(n);
	if(block!=1) {
		printf("Error: %d components\n",block);
	} else {
		dfs(1,1,-1);
		ans = temp;
		dfs(ans[0],1,-1);
		for(int i=0;i<temp.size();i++) {
			ans.push_back(temp[i]);
		}
		sort(ans.begin(),ans.end());
		printf("%d\n",ans[0]);
		for(int i=1;i<ans.size();i++) {
			if(ans[i] != ans[i-1]) {
				printf("%d\n",ans[i]);
			}
		}
	}
	return 0;
}
