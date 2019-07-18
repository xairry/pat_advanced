#include<stdio.h>
#include<iostream>
#include<cstring>
#include<map>
#include<cmath>
const int maxn = 1e4+10;
using namespace std;

bool isPrime(int x) {
  if(x<=1)return true;
  for(int i= 2;i*i<=x;i++) {
    if(x%i == 0){
      return false;
    }
  }
  return true;
}
int main() {
  int N;
  scanf("%d",&N);
  
  map<int,int> mp;
  for(int i=1;i<=N;i++) {
    int tmp;
    scanf("%d",&tmp);
    mp[tmp] = i;
  }
  map<int,bool> xp;
  int K;
  scanf("%d",&K);
  for(int i=0;i<K;i++) {
    int que;
    scanf("%d",&que);
    if(mp.find(que)==mp.end()){
      printf("%04d: Are you kidding?\n",que);
      continue;
    }
    if(xp.find(que)!=xp.end()){
      printf("%04d: Checked\n",que);
      continue;
    }
    if(xp.find(que) == xp.end()){
      xp[que] = true;
      if(mp[que]==1){
        printf("%04d: Mystery Award\n",que);
      }else if(isPrime(mp[que])) {
        printf("%04d: Minion\n",que);
      }else{
        printf("%04d: Chocolate\n",que);
      }
     }
    }
  


  return 0;
}