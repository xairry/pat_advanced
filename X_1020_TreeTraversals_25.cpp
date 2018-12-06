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

const int MAX = 50;
int post[MAX],in[MAX],pre[MAX];
int N;

struct node {
	int data;
	node* lchild,*rchild;
};

node* create(int postL,int postR,int inL,int inR) {
	if(postL > postR) {
		return NULL;
	}
	node* root = new node;
	root->data = post[postR];
	int k;
	for(k=inL;k<inR;k++) {
		if(in[k] == post[postR]) {
			break;
		}
	}
	int numLeft = k - inL;
	root->lchild = create(postL,postL+numLeft -1,inL,k-1);
	root->rchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;
} 
int num=0;
void BFS(node* root) {
	queue<node*> q;
	q.push(root);
	while(!q.empty()){
		node* tmp = q.front();
		q.pop();
		printf("%d",tmp->data);
		num++;
		if(num<N) printf(" ");
		if(tmp->lchild != NULL) q.push(tmp->lchild);
		if(tmp->rchild != NULL) q.push(tmp->rchild);
	}
	
	
}


int main() {
	
	scanf("%d",&N);
	
	for(int i=0;i<N;i++) {
		scanf("%d",&post[i]);
	}
	for(int i=0;i<N;i++) {
		scanf("%d",&in[i]);
	}
	node* ans = create(0,N-1,0,N-1);
	BFS(ans);
	return 0;
	
	


	return 0;
}
	



