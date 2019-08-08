#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 110;
int n,num = 0;
struct node {
	int left,right;
}Node[maxn];
bool notRoot[maxn] = {false};
void print(int id) {
	printf("%d",id);
	num++;
	if(num < n)printf(" ");
	else printf("\n");
}
void inOrder(int root) {
	if(root == -1)return ;
	inOrder(Node[root].left);
	print(root);
	inOrder(Node[root].right);
}
void postOrder(int root) {
	if(root == -1)return;
	postOrder(Node[root].left);
	postOrder(Node[root].right);
	swap(Node[root].left,Node[root].right);
}

void bfs(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		print(now);
		if(Node[now].left!=-1)q.push(Node[now].left);
		if(Node[now].right!=-1)q.push(Node[now].right);
	}
}


int str2n(char c) {
	if(c == '-') return -1;
	else {
		notRoot[c-'0'] = true;
		return c-'0';
	}
}

int findRoot() {
	for(int i=0;i<n;i++) {
		if(notRoot[i] == false) {
			return i;
		}
	}
}
int main() {
	scanf("%d",&n);
	char left,right;
	for(int i=0;i<n;i++) {
			scanf("%*c%c %c",&left,&right);
			Node[i].left = str2n(left);
			Node[i].right=str2n(right);
		}
	int root = findRoot();
	postOrder(root);
	bfs(root);
	num = 0;
	inOrder(root);

	return 0;
}