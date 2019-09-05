#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
const int maxn = 1e4+10;
int N,M,K;
int fa[maxn] = {0},cnt[maxn] = {0}; 

int findFa(int x) {
  if(x == fa[x])return x;
  int a = x;
  while(x!=fa[x]){
    x = fa[x];
  }
  while(a!=fa[a]) {
    int z = a;
    a = fa[a];
    fa[z] = x;
  }
  return x;
}

void merge(int a,int b) {
  int f_a = findFa(a);
  int f_b = findFa(b);
  if(f_a != f_b)
  fa[f_a] = f_b;
  return;
}
bool isroot[maxn] = {false};
bool exist[maxn] = {false};
int main() {
  scanf("%d",&N);
  for(int i=1;i<=maxn;i++) {
    fa[i] = i;
  }
  int root,tp;
  for(int i=0;i<N;i++) {
    scanf("%d %d",&K,&root);
    exist[root] = true;
    for(int j=1;j<K;j++) {
      scanf("%d",&tp);
      merge(tp,root);
      exist[tp] = true;
    }
    
  }
  for(int i=1;i<=maxn;i++) {
      if(exist[i] == true) {
        cnt[findFa(i)]++;
      }
    }
  int numB = 0,numT = 0;
  for(int i=1;i<=maxn;i++) {
    if(exist[i] == true && cnt[i]!=0)
     {
      numT++;
      numB+=cnt[i];
    }
  }
  printf("%d %d\n",numT,numB);
  scanf("%d",&M);
  int id1,id2;
  while(M--) {
    scanf("%d %d",&id1,&id2);
    printf("%s\n",(findFa(id1) == findFa(id2))?"Yes":"No");
  }
  return 0;
}