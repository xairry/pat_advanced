#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
int N,C;

struct Node{
  int a;
  char b[10];
  int c;
}node[100001];

bool cmp(Node x,Node y) {
  if(C == 1) {
    return x.a<y.a;
  }else if( C == 2) {
    if (strcmp(x.b,y.b) == 0)return x.a < y.a;
    return strcmp(x.b,y.b) <= 0;
  } else{
    if(x.c == y.c) return x.a < y.a;
    return x.c <= y.c;
  }
}
int main() {
  scanf("%d %d",&N,&C);
  for(int i=0;i<N;i++) {
    
    scanf("%d %s %d",&node[i].a,node[i].b,&node[i].c);
    
  }
  sort(node,node+N,cmp);
    for(int i=0;i<N;i++) {
      printf("%06d %s %d\n",node[i].a,node[i].b,node[i].c);
    }

  return 0;
}