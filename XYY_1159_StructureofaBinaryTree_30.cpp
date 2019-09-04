#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
vector<int> in,post;
struct node{
  int key,level,father;
  int lchild= -1,rchild = -1;
};

node t[1111];
bool flag = 0;

void create(int &r,int il,int ir,int pl,int pr,int level,int father) {
  int i = il;
  while(in[i]!=post[pr-1])++i;
}
int main() {
  int n,m;
  cin>>n;
  in.resize(n);
  post.resize(n);
  for(int i=0;i<n;i++) {
    cin>>post[i];
  }
  for(int i=0;i<n;i++) {
    cin>>in[i];
  }
  int root;
  create(root,0,n,0,n,1,-1);
  cin>>m;
  getchar();
  while(m--) {
    string s;
    getline(cin,s);
    
  }
  return 0;
}