#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

struct Node{
    char id[20];
    int hh,mm,ss;
}tmp,ans1,ans2;

bool great(const Node &a,const Node &b){
  if(a.hh!=b.hh) return a.hh>b.hh;
  if(a.mm!=b.mm) return a.mm>b.mm;
  return a.ss>b.ss; 
}
int main() {
  int m;
  scanf("%d",&m);
  
  ans1.hh = 24,ans1.mm=60,ans1.ss=60;
  ans2.hh = 0,ans2.mm=0,ans2.ss = 0;
  for(int i=0;i<m;i++) {
    scanf("%s %d:%d:%d",tmp.id,&tmp.hh,&tmp.mm,&tmp.ss);
    if(great(tmp,ans1)==false) ans1 =tmp;
    scanf("%d:%d:%d",&tmp.hh,&tmp.mm,&tmp.ss);
    if(great(tmp,ans2)==true) ans2=tmp;
  } 
  

printf("%s %s\n",ans1.id,ans2.id);
return 0;
}