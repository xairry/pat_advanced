#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 110;
struct node{
	int val;
	int left,right;
}Node[maxn];

int n,in[maxn],num = 0;

void inorder(int root) {
	if(root == -1)return;
	inorder(Node[root].left);
	Node[root].val = in[num++];
	inorder(Node[root].right);
}

void bfs(int root) {
	queue<int> q;
	q.push(root);
	num = 0;
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		printf("%d",Node[now].val);
		num++;
		if(num<n)printf(" ");
		if(Node[now].left!=-1)q.push(Node[now].left);
		if(Node[now].right!=-1)q.push(Node[now].right);
	}
}

int main() {
	int lc,rc;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d%d",&lc,&rc);
		Node[i].left = lc;
		Node[i].right = rc;
	}
	for(int i=0;i<n;i++) {
		scanf("%d",&in[i]);
	}
	sort(in,in+n);
	inorder(0);
	bfs(0);
	return 0;

	
}