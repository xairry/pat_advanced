#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 1010;
int toll[25];
struct Node{
  char name[25];
  int mongth, dd, hh, mm;
  bool status;
}rec[maxn],tmp;

bool cmp(const Node &a,const Node &b) {
  int s =strcmp(a.name,b.name);
  if(s!=0)return s<0;
  else if(a.month!=b.month) return a.month < b.month;
  else if(a.dd!=b.dd)return a.dd<b.dd;
  else if(a.hh!=b.hh) return a.hh < b.hh;
  else return a.mm < b.mm;
}

void get_ans(int on,int off,int &time,int &money) {
  tmp = rec[0];
  while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm) {
    time++;
    money += toll[temp.hh];
    if (temp.mm >= 60) {
      temp.mm = 0;
      temp.hh++
    }
  }
}