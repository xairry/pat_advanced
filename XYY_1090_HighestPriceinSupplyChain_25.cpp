#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>


using namespace std;
const int maxn = 100010;
vector<int> child[maxn];
double p,r;
int n,maxD = 0,num = 0;

void dfs(int index, int depth) {
	if(child[index].size() == 0) {
		if(depth > maxD) {
			maxD = depth;
			num=1;
		}else if(maxD == depth) {
			num++; 
		}
		return ;
	}
	for(int i=0;i<child[index].size();i++) {
		dfs(child[index][i],depth+1);
	}
}
int main() {
	scanf("%d %lf %lf",&n,&p,&r);
	r/=100;
	int tp1,tp2,root;
	for(int i=0;i<n;i++) {
		scanf("%d",&tp1);
		if(tp1 == -1) {
			root = i;
		}else{
      child[tp1].push_back(i);
    }
	}
  dfs(root,0);
  printf("%.2f %d\n",p*pow(1+r,maxD),num);
	return 0;
}