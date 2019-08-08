#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 1010;
int fa[maxn],isRoot[maxn]={0},hobby[maxn]={0};

int findFather(int x) {
	if(x == fa[x])return x;
	else return findFather(fa[x]);
}

bool merge(int a,int b) {
	int faA = findFather(a),faB = findFather(b);
	if (faA==faB) return false;
	if(faA > faB)swap(faA,faB);
	fa[faA] = faB;
}
bool cmp(int &a,int &b){
	return a > b;
}
int main() {
	int n,k,h;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		isRoot[i]=0;
		fa[i] = i;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d: ",&k);
		for(int j=0;j<k;j++) {
			scanf("%d",&h);
			if(hobby[h]==0) {
				hobby[h] = i;
			}
			merge(i,hobby[h]);
		}
	}
	for(int i=1;i<=n;i++) {
		isRoot[findFather(i)]++;
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(isRoot[i]!=0)ans++;
	}
	printf("%d\n",ans);
	sort(isRoot +1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;i++) {
		printf("%d",isRoot[i]);
		if(i<ans)printf(" ");
	}
	return 0;
}