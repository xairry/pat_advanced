#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=101;
int N,sq1[MAXN],in[MAXN],num=0;

struct Node{
	int data;
	int left,right;
}node[MAXN];

void inorder(int root) {
	if(root == -1)return ;
	inorder(node[root].left);
	node[root].data=in[num++];
	inorder(node[root].right);
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	int num=0;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		printf("%d",node[now].data);
		num++;
		if(num<N)printf(" ");
		if(node[now].left!=-1){
			q.push(node[now].left);
		}
		if(node[now].right!=-1){
			q.push(node[now].right);
		}
	}
}


int main() {
	scanf("%d",&N);
	int tp1,tp2;
	for(int i=0;i<N;i++) {
		scanf("%d%d",&tp1,&tp2);
		
			node[i].left=tp1;
		
			node[i].right=tp2;
	
	}
	for(int i=0;i<N;i++) {
		scanf("%d",&in[i]);
	}
	
	sort(in,in+N);
	inorder(0);

	BFS(1);
	
	return 0;
}
