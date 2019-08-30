#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110;
int n,m;
vector<int> Node[maxn];
int hashTable[maxn] = {0};

void dfs(int index,int level) {
	hashTable[level]++;
	if(Node[index].size()==0){
		return;
	}
	for(int i=0;i<Node[index].size();i++) {
		dfs(Node[index][i],level+1);
	}
}
int main() {
	int pa,k,chi;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%d %d",&pa,&k);
		for(int j=0;j<k;j++) {
			scanf("%d",&chi);
			Node[pa].push_back(chi);
		}
	}
	dfs(1,1);
	int maxlevel = -1,maxval = 0;
	for(int i=1;i<maxn;i++) {
		if(hashTable[i] > maxval) {
			maxval = hashTable[i];
			maxlevel = i;
		}
	}
	printf("%d %d\n",maxval,maxlevel);

	return 0;
}