#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 110;
int n,m,max_h;
int arr[maxn] = {0};
vector<int> child[maxn];
void dfs(int index,int depth) {
	max_h = max(depth,max_h);
	if(child[index].size() == 0) {
		arr[depth]++;
		return;
	}
	for(int i=0;i<child[index].size();i++) {
		dfs(child[index][i],depth+1);
	}
}

int main() {
	scanf("%d %d",&n,&m);
	int a,b,k;
	for(int i=0;i<m;i++) {
		scanf("%d %d",&a,&k);
		for(int j=0;j<k;j++) {
			scanf("%d", &b);
			child[a].push_back(b);
		}
		
	}
	dfs(1,1);
	printf("%d",arr[1]);
	for(int i=2;i<=max_h;i++)printf(" %d",arr[i]);

	return 0;
}