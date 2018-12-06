 #include<iostream>
#include <stdio.h>
#include <cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cctype>
#include<queue>
using namespace std;

const int MAX = 110;
int pre[MAX],in[MAX],post[MAX];
int N;

struct node {
	int lchild,rchild;
}Node[MAX];
bool notRoot[MAX] = {false}; 


int num=0;
void print(int id) {
	printf("%d",id);
	num++;
	if(num<N){
		printf(" ");
	}else{
		printf("\n");
	}
}
void BFS(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		print(tmp);
	
		if(Node[tmp].lchild != -1) q.push(Node[tmp].lchild);
		if(Node[tmp].rchild != -1) q.push(Node[tmp].rchild);
	}
}

void inT(int root) {
	if(root==-1){
		return ;
	}
	inT(Node[root].lchild);
	print(root);
	
	inT(Node[root].rchild);
	
	
}

void postT(int root) {
	if(root== -1) {
		return ;
	}
	postT(Node[root].lchild);
	postT(Node[root].rchild);
	swap(Node[root].lchild,Node[root].rchild);
}

int strToNum(char a) {
	if(a=='-') return -1;
	else {
		notRoot[a-'0'] =true;
		return a-'0';
	}
}
int findRoot() {
	for(int i=0;i<N;i++) {
		if(notRoot[i]==false){
			return i;
		}
	}
}


int main() {
	char lchild,rchild;
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%*c%c %c",&lchild,&rchild);
		Node[i].lchild=strToNum(lchild);
		Node[i].rchild=strToNum(rchild);
	}
	int root =findRoot();
	postT(root);
	BFS(root);
	num=0;
	
	inT(root);
	
	return 0;
}
	



