#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=2020;
int N,tmp[MAXN],CBT[MAXN],index=0;

void inorder(int root){
	if(root>N)return;
	inorder(root*2);
	CBT[root] = tmp[index++];
	inorder(root*2+1);
}

int main() {
	scanf("%d",&N);
	

	for(int i=0;i<N;i++) {
		scanf("%d",&tmp[i]);
	}
	sort(tmp,tmp+N);
	inorder(1);
	for(int i=1;i<=N;i++) {
		printf("%d",CBT[i]);
		if(i<N) printf(" ");
	}
	
	return 0;
}
