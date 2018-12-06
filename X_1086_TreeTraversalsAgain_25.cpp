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
//const int MAXV = 1000; //最大顶点数 
//const int INF = 0Xffffffff;
//set<int> a[51];

const int MAX = 50;
int pre[MAX],in[MAX],post[MAX];
int N;

struct node {
	int data;
	node* lchild,*rchild;
};

node* create(int preL,int preR,int inL,int inR) {
	if(preL > preR) {
		return NULL;
	}
	int k;
	node *root= new node;
	root->data = pre[preL];
	for(k=inL;k<inR;k++) {
		if(in[k] == pre[preL]) {
			break;
		}
	}
	int numLeft = k-inL;
	root->lchild = create(preL+1,preL+numLeft,inL,k-1);
	root->rchild = create(preL+numLeft+1,preR,k+1,inR);
	return root;
} 
int num=0;


void postT(node* root) {
	if(root==NULL){
		return ;
	}
	postT(root->lchild);
	postT(root->rchild);
	printf("%d",root->data);
	num++;
	if(num<N)printf(" ");
}


int main() {
	stack<int> st;
	
	scanf("%d",&N);
	char str[5];
	int x,ct1=0,ct2=0;
	for(int i=0;i<2*N;i++) {
		scanf("%s",str);
		if(!strcmp(str,"Push")) {
			scanf("%d",&x);
			st.push(x);
			pre[ct1++]=x;
		}
		if(!strcmp(str,"Pop")) {
			in[ct2++] = st.top();
			st.pop();
		}
		
	}
	node *ans = create(0,N-1,0,N-1);
	postT(ans);
	return 0;
}
	



