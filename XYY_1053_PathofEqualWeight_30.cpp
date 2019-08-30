#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
const int maxn = 110;

struct Node{
	int weight;
	vector<int> child;
}node[maxn];



bool cmp( int a, int b){
	return node[a].weight > node[b].weight;
}

int path[maxn];
int n,m,S;

void dfs(int index,int depth,int sum){
	if(sum > S) return;
	if(sum == S) {
		if(node[index].child.size() != 0)return;
		for(int i=0;i<depth;i++) {
			printf("%d",node[path[i]].weight);
			if(i<depth-1) printf(" ");
			else printf("\n");
		}
		return;
	}
	for(int i=0;i<node[index].child.size();i++) {
		int chi = node[index].child[i];
		path[depth] = chi;
		dfs(chi,depth+1,sum+node[chi].weight);
	}
}



int main() {
	scanf("%d%d%d",&n,&m,&S);
	for(int i = 0; i < n; i++) {
		scanf("%d",&node[i].weight);
	}
	int id,k,child; 
	for(int i = 0; i < m; i++) {
		scanf("%d%d", &id, &k);
		for(int j = 0; j < k; j++) {
			scanf("%d",&child);
			node[id].child.push_back(child);
		}
		sort(node[id].child.begin(),node[id].child.end(),cmp);
	}
	path[0] = 0;
	dfs(0,1,node[0].weight);
	

	return 0;
}