#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct node{
    int val;
    node* left;
    node* right;
};
int n,data;

void insert(node* &root,int x) {
    if(root == NULL) {
        root = new node;
        root->val = x;
        root->left = root->right = NULL;
        return;
    }
    if(x < root->val) insert(root->left,x);
    else insert(root->right,x);
}

void preorder(node* root,vector<int>& vi) {
    if(root == NULL) return;
    vi.push_back(root->val);
    preorder(root->left,vi);
    preorder(root->right,vi);
}

void preorderM(node* root,vector<int>& vi) {
    if(root == NULL) return;
    vi.push_back(root->val);
    preorderM(root->right,vi);
    preorderM(root->left,vi);
}
void postorder(node* root,vector<int>& vi) {
    if(root==NULL) return;
        postorder(root->left,vi);
        postorder(root->right,vi);
        vi.push_back(root->val);
    
}

void postorderM(node* root,vector<int>& vi) {
    if(root==NULL) return;
        postorderM(root->right,vi);
        postorderM(root->left,vi);
        vi.push_back(root->val);
    
}
vector<int> origin,pre,preM,post,postM;
int main() {
	scanf("%d",&n);
    
    node* root = NULL;
    for(int i=0;i<n;i++) {
        scanf("%d",&data);
        origin.push_back(data);
        insert(root,data);
    }
    preorder(root,pre);
    preorderM(root,preM);
    postorder(root,post);
    postorderM(root,postM);
    if(origin == pre) {
        printf("YES\n");
        for(int i=0;i<post.size();i++) {
            printf("%d",post[i]);
            if(i<post.size()-1)printf(" ");
        }
    }else if(origin == preM) {
        printf("YES\n");
        for(int i=0;i<postM.size();i++) {
            printf("%d",postM[i]);
            if(i<postM.size()-1)printf(" ");
        }
    }else{
        printf("NO\n");
    }
    return 0;
}