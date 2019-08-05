#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;
const int talbe = 100010;
const int maxn = 100005;
struct Node{
  int address,data,next;
  int order;
}node[maxn];
bool isExist[talbe] = {false};
bool cmp (const Node &a,const Node &b) {
  return a.order < b.order;
}
int main() {
  memset(isExist,false,sizeof(isExist));
  for(int i=0;i<maxn;i++){
    node[i].order = 2*maxn;
  }
  int n,begin,address;
  scanf("%d%d",&begin,&n);
  for(int i=0;i<n;i++) {
    scanf("%d",&address);
    scanf("%d%d",&node[address].data,&node[address].next);
    node[address].address = address;
  }
  int countValid = 0,countRemoved = 0,p = begin;
  while(p != -1) {
    if(!isExist[abs(node[p].data)]) {
      isExist[abs(node[p].data)] = true;
      node[p].order = countValid++;
    }else{
      node[p].order = maxn + countRemoved++;
    }
    p = node[p].next;
  }
  sort(node,node+maxn,cmp);
  int count = countValid + countRemoved;
for(int i=0;i<count;i++) {
  if( i != countValid -1 && i!=count-1) {
    printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
  }else{
    printf("%05d %d -1\n",node[i].address,node[i].data);
  }
}
  return 0;
}