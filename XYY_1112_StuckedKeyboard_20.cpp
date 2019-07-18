#include<stdio.h>
#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

int main() {
  int k;
  string str;
  scanf("%d\n",&k);
  getline(cin,str);
  map<char,int> mp;
  int len = str.length();
  int j;
  map<char,bool> xp;
  for(int i=0;i<len;i=j) {
  for(j=i;j<len && str[j]==str[i];j++);
  int tp = j-i;
  
  if(mp.find(str[i])==mp.end()){
    mp[str[i]] = tp;
    xp[str[i]] =false;
  }else{
    if(tp < mp[str[i]]) {
      mp[str[i]] = tp;
    }
  }
  }
 for(int i=0;i<len;i++) {
    if(mp[str[i]]>=k && xp[str[i]]==false){
      printf("%c",str[i]);
      xp[str[i]]=true;
      continue;
    }
  }
  printf("\n");
  for(int i=0;i<len;) {
    printf("%c",str[i]);
    if(mp[str[i]]>=k){
      i+=(k);
    }else{
      i++;
    }
  }
 return 0;
}