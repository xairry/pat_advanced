#include<cstdio>
#include<algorithm>

using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
}

int in[50],post[50],pre[50];
int n;
Node* create(int postL,int postR,int inL,int inR) {
    if(postL>postR)return NULL;

    Node *root = new Node;
    root->val = post[postR];
    int k;
    for(k=inL,k<inR;k++) {
        if(in[k] == post[postR]) {
            break;
        }
    }
    int numLeft = k-inL;
    root->left = create(postL,postL+numLeft-1,inL,k-1);
    root->right = create(postL+numLeft,postR-1,k+1,inR);
}
void bfs(Node *root) {
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node *top = q.front();
        q.pop();
        printf("%d",top->val);
        num++;
        if(num<n)printf(" ");
        if(top->left!=NULL) q.push(top->left);
        if(top->right!=NULL)q.push(top->right);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&post[i]);
    }
    
    for(int i=0;i<n;i++) {
        scanf("%d",&in[i]);
    }
    Node *root = create(0,n-1,0,n-1);
    bfs(root);
    return 0;
}