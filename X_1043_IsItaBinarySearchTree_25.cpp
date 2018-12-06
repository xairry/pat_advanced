#include<stdio.h>
#include<vector>
using namespace std;
const int MAX=1e3+1;
int N;

struct Node{
	int data;
	Node* lchild,*rchild;
};


void insert(Node *&root,int x) {
	if(root == NULL) {
	root = new Node;
	root->data=x;
	root->lchild=root->rchild=NULL;
		return;
	}else if(x < root->data){
		insert(root->lchild,x);
	}else{
		insert(root->rchild,x);
	}
}


void preOrder(Node* root,vector<int>& vi) {
	if(root==NULL) return;
	vi.push_back(root->data);
	preOrder(root->lchild,vi);
	preOrder(root->rchild,vi);
}

void preMOrder(Node* root,vector<int>& vi) {
	if(root==NULL) return;
	vi.push_back(root->data);
	preMOrder(root->rchild,vi);
	preMOrder(root->lchild,vi);
}

void postOrder(Node* root,vector<int>& vi) {
	if(root==NULL) return;

	postOrder(root->lchild,vi);
	postOrder(root->rchild,vi);
	vi.push_back(root->data);
}

void postMOrder(Node* root,vector<int>& vi) {
	if(root==NULL) return;

	postMOrder(root->rchild,vi);
	postMOrder(root->lchild,vi);
	vi.push_back(root->data);
}

vector<int> ori,pre,preM,post,postM;
int main() {
	Node *root = NULL;
	int tmp;
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d",&tmp);
		ori.push_back(tmp);
		insert(root,tmp);
	}

	
	preOrder(root,pre);
	preMOrder(root,preM);
	postOrder(root,post);
	postMOrder(root,postM);
	
	
	if(ori==pre){
		printf("YES\n");
		for(int i=0;i<post.size();i++) {
			printf("%d",post[i]);
			if(i<post.size()-1){
				printf(" ");
			}
		}
	}else if(ori == preM){
		printf("YES\n");
		for(int i=0;i<postM.size();i++) {
			printf("%d",postM[i]);
			if(i<postM.size()-1){
				printf(" ");
			}
		}
	}else{
		printf("NO\n");
	}
	
	return 0;
}
