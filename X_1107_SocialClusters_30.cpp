#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int N;
int father[MAXN],isroot[MAXN] = {0},course[MAXN] = {0};
bool cmp(int a,int b) {
	return a>b;
}
void init(int N){
	for(int i=1;i<=N;i++) {
		father[i] = i;
		isroot[i] = false;
	}
}

int findfather(int x) {
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
}

void Union(int a,int b) {
	int faA = findfather(a);
	int faB = findfather(b);
	if(faA!=faB) {
		father[faA] = faB;
	}
}

int main() {
	scanf("%d",&N);
	int K=0,a,b;
	init(N);
	for(int i=0;i<N;i++) {
		scanf("%d:",&K);
		for(int j=0;j<K;j++) {
			scanf("%d",&a);
			if(course[a]==0){
				course[a]=i;
			}
			Union(i,findfather(course[a]));
			
		}
	}
	for(int i=1;i<=N;i++) {
		isroot[findfather(i)]++;
	}
	int ans=0;
	for(int i=1;i<=N;i++) {
		if(isroot[i]!=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isroot+1,isroot+N+1,cmp);
	for(int i=1;i<=ans;i++) {
		printf("%d",isroot[i]);
		if(i<ans)printf(" ");
	}

	
	
	return 0;
}
