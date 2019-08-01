#include<cstdio>
#include<cstring>
#include<iostream>

const int MOD = 1000000007;
const int maxn = 100010;
using namespace std;


int main() {
  string s;
  cin>>s;
  int len = s.length();
  int leftP[len];
  memset(leftP,0,sizeof(leftP));
  for(int i=0;i<len;i++) {
    if(i>0) {
        leftP[i] = leftP[i-1];
    }if(s[i] == 'P') {
      leftP[i]++;
    }
  }
  int ans = 0,rt = 0;
  for(int i=len-1;i>=0;i--) {
    if(s[i] == 'T' ) {
      rt++;
    }else if(s[i]=='A') {
      ans = (ans + leftP[i]*rt)%MOD;
    }
  }
  printf("%d\n",ans);






  return 0;
}