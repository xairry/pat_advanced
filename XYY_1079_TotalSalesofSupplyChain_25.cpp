#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100010;
int n,k,tp1,tp2;
double p,r,sum = 0.0;

struct node{
	double val;
	vector<int> child;
}Node[maxn];

void dfs(int depth,int root) {
	if(Node[root].child.size() == 0) {
		sum += Node[root].val*p*pow(1+r,depth);
		return; 
	}
	for(int i=0;i<Node[root].child.size();i++) {
		dfs(depth+1,Node[root].child[i]);
	}
}

int main() {
	
	scanf("%d %lf %lf",&n,&p,&r);
	r /= 100;
	for(int i=0;i<n;i++) {
		scanf("%d",&tp1);
		if(tp1 == 0) {
			scanf("%lf",&Node[i].val);
		}else{
			for(int j=0;j<tp1;j++) {
				scanf("%d",&tp2);
				Node[i].child.push_back(tp2);
			}
			
		}
		
	}
	dfs(0,0);
		printf("%.1f\n",sum);
		return 0;
}