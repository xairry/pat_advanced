#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1e2+1;
int N,M,S,t[MAXN],sum,path[MAXN];
struct Node{
	int weight;
	vector<int> ch;
}node[MAXN];

bool cmp(int a,int b) {
	return node[a].weight > node[b].weight;
}

void DFS(int index,int level,int sum) {
	if(sum>S) return;
	if(sum == S) {
		if(node[index].ch.size() !=0)return;
		for(int i=0;i<level;i++){
			printf("%d",node[path[i]].weight);
			if(i < level-1) printf(" ");
			else printf("\n");
		}
	return;
	}
	for(int i=0;i<node[index].ch.size();i++) {
		int child = node[index].ch[i];
		path[level] = child;
		DFS(child,level+1,sum+node[child].weight);
	}
} 

int main() {
	scanf("%d%d%d",&N,&M,&S);
	for(int i=0;i<N;i++) {
		scanf("%d",&node[i].weight);
	}
	int id,k,tmp;
	for(int i=0;i<M;i++) {
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++) {
			scanf("%d",&tmp);
			node[id].ch.push_back(tmp);
		}
		sort(node[id].ch.begin(),node[id].ch.end(),cmp);
	}
	DFS(0,1,node[0].weight);
	return 0;
}

