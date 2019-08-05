#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100010;
struct Node {
  char data;
  int next;
  bool flag;
}node[maxn];
int main() {
  for(int i=0;i<maxn;i++) {
    node[i].flag = false;
  }
  int s1,s2,n;
  scanf("%d%d%d",&s1,&s2,&n);
  int address,next;
  char data;
  for(int i=0;i<n;i++) {
    scanf("%d %c %d",&address,&data,&next);
    node[address].data = data;
    node[address].next = next;
  }
  int P;
  for(P = s1;P!=-1;P = node[P].next){
    node[P].flag = true;
  }
  for(P = s2;P!=-1;P = node[P].next){
    if(node[P].flag == true)break;
  }
  if(P!=-1) {
    printf("%05d\n",P);
  }else{
    printf("-1\n");
  }

  return 0;
}