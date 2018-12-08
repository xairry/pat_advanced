#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=21;
int N,ans[MAXN];

struct node{
	int v,height;
	node*left,*right;
};
node *root;

node* newNode(int v) {
	node * Node=new node;
	Node->v=v;
	Node->height=1;
	Node->left=Node->right=NULL;
	return Node;
}
int getHeight(node* root) {
	if(root == NULL) return 0;
	return root->height;
}

void updateHeight(node* root) {
	root->height=max(getHeight(root->left),getHeight(root->right))+1;
}

int getBalanceFa(node* root){
	return getHeight(root->left)-getHeight(root->right);
}

void L(node* &root) {
	node *tmp = root->right;
	root->right=tmp->left;
	tmp->left=root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void R(node* &root) {
	node *tmp = root->left;
	root->left=tmp->right;
	tmp->right=root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}

void insert(node* &root,int x) {
	if(root==NULL){
		
		root = newNode(x);
		return;
	}
	if(x<root->v){
		insert(root->left,x);
		updateHeight(root);
		if(getBalanceFa(root) == 2) {
			if(getBalanceFa(root->left)==1){
				R(root);
				
			}
			else if(getBalanceFa(root->left)==-1) {
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right,x);
		updateHeight(root);
		if(getBalanceFa(root) == -2) {
			if(getBalanceFa(root->right)==1){
				R(root->right);
				L(root);
				
			}
			else if(getBalanceFa(root->right)==-1) {
				L(root);
			}
		}
	}
}

node* Create(int data[],int n) {
	root = NULL;
	for(int i=0;i<n;i++) {
		insert(root,data[i]);
	}
	return root;
}


int main() {
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d",&ans[i]);
		//insert(root,ans[i]);
	}
	
	Create(ans,N);
	//printf(" haha");
	printf("%d\n",root->v);
	return 0;
 }
