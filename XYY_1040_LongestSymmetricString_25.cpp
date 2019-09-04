#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

string s;
bool isSym(int left,int right) {
  while(1) {
    if(left >= right)return 1;
    if(s[left]!=s[right])return 0;
    left++;
    right--;
  }
}
int main() {

  getline(cin,s);
//  getchar();
int flag = 0;
int L;
  int len = s.length();
for(L = len;;L--) {
  for(int i=0;i+L<=len;i++) {
    if(isSym(i,i+L-1)) {
      flag = 1;
      break;
    }
  }
  if(flag)break;
}
  
  printf("%d",L);
  return 0;
}