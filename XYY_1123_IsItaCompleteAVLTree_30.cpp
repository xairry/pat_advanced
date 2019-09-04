#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Node{
  int val;
  Node *left,*right;
  Node(int v) :val(v),left(NULL),right(NULL) {};
};

Node* R( Node* root) {
  Node* tmp = root->left;
  root->left = tmp->right;
  tmp->right = root;
  return tmp;
}

Node* L( Node* root) {
  Node* tmp = root->right;
  root->right = tmp->left;
  tmp->left = root;
  return tmp;
}

Node* LR(Node* root) {
  root->left = L(root->left);
  return R(root);
}

Node* RL(Node* root) {
  root->right = R(root->right);
  return L(root);
}





void update(Node* &root) {
  root->height = max( getHeight(root->left),getHeight(root->right) )+1;
}

int getHeight(Node* root) {
  return root==NULL ? 0: max(getHeight(root->left) , getHeight(root->right)) + 1;
}

int getBF(Node *root) {
  return getHeight(root->left) - getHeight(root->right);
}
void insert(Node* &root, int v) {
    if(root == NULL) return new Node(v);
    if(v<root->val) {
      root->left = insert(root->left,v);
      if(abs(getHeight(root->left)-getHeight(root->right)) > 1)
      return v<
    }
} 

vector<int> levelorder(Node* root) {
  queue<Node*> q;
  vector<int> v;
  q.push(root);
  while(!q.empty()) {
    Node* top = q.front();
    q.pop();
    v.push_back(top->val);
    if(top->left != NULL) {
      if
    }
  }
}

int main() {



  return 0;
}