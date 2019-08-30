#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
	int v,height;
	node *left,*right;
} *root;

node* newNode(int v) {
	node* Node = new node;
	Node->v = v;
	Node->height = 1;
	Node->left = Node->right = NULL;
	return Node;
}

int getH(node* root) {
	if(root == NULL) return 0;
	return root->height;
}

void updateH(node* root) {
	root->height = max(getH(root->left),getH(root->right))+1;
}

int getBF(node* root) {
	return getH(root->left)-getBF(root->right);
}

void L(node* root) {
	node* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	updateH(root);
	updateH(temp);
	root = temp;
}

void R(node* root) {
	node* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	updateH(root);updateH(temp);
	root = temp;
}

void insert(node* &root, int v) {
	if(root == NULL) {
		root = newNode(v);
		return;
	}
	if(v < root->v) {
		insert(root->left,v);
		updateH(root);
		if(getBF(root) == 2) {
			if(getBF(root->left) == 1) {
				R(root);
			}else if(getBF(root->left)==-1) {
				L(root->left);
				R(root);
			}
		}
	}else {
		insert(root->right,v);
		updateH(root);
		if(getBF(root) == -2) {
			if(getBF(root->right)==-1) {
				L(root);
			}else if(getBF(root->right)==1) {
				R(root->right);
				L(root);
			}
		}
	}
}

node* create(int data[],int n) {
	node* root = NULL;
	for(int i=0;i<n;i++) {
		insert(root,data[i]);
	}
	return root;
}

int main() {
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d\n",root->v);

	return 0;
}