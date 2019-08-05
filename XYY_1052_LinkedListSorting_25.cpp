#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100005;
struct Node{
  int address,data,next;
  bool flag;
}node[maxn];

bool cmp(const Node &a,const Node &b){
  if(a.flag == false || b.flag == false){
    return a.flag > b.flag;
  }else{
    return a.data < b.data;
  }
  //return a.data < b.data;
}
int main() {
  for(int i= 0;i<maxn;i++) {
    node[i].flag = false;
  }
  int n,begin,address;
  scanf("%d%d",&n,&begin);
  for(int i=0;i<n;i++) {
    scanf("%d",&address);
    scanf("%d%d",&node[address].data,&node[address].next);
    node[address].address = address;
  }
  int cnt = 0, p = begin;
  while(p!=-1) {
    node[p].flag = true;
    cnt++;
    p = node[p].next;
  }
  if(cnt == 0) {
    printf("0 -1");
  }else{
    sort(node,node + maxn,cmp);
    printf("%d %05d\n",cnt,node[0].address);
    for(int i=0;i<cnt;i++) {
      if( i!= cnt-1) {
        printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
      }else{
        printf("%05d %d -1\n",node[i].address,node[i].data);
      }
    }
  }



  return 0;
}