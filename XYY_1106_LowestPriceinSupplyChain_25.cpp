#include<vector>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 100010;
const int inf = 1e9+10;
int n,cnt=0;
double p,r;
vector<int> node[maxn];
double ans = inf;

void dfs(int index,int depth) {
	if(node[index].size() == 0) {
		double tt = p*pow(1+r,depth);
		if(tt < ans){
			ans = tt;
			cnt = 1;
		}else if(tt == ans) {
			cnt++;
		}
		return;

	}
	for(int i=0;i<node[index].size();i++) {
		dfs(node[index][i],depth+1);
	}
}

int main() {
	scanf("%d %lf %lf",&n,&p,&r);
	r /= 100;
	int tp1,k;
	for(int i=0;i<n;i++) {
		scanf("%d",&tp1);
		if(tp1 > 0) {
			
			for(int j=0;j<tp1;j++) {
				scanf("%d",&k);
				node[i].push_back(k);
			}
		}
	}
	dfs(0,0);
	printf("%.4f %d\n",ans,cnt);

	return 0;
}