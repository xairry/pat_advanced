#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

string add(string s) {
  string s1 = s;
  int len = s.length();
  int ca = 0;
  for(int i=len-1;i>=0;i--) {
    int tp = s[i]-'0'+s[i]-'0';
    s1[i] = ((tp+ca)%10+'0');
    ca = (tp+ca)/10;
  }
  if(ca>0)s1 = "1"+s1;
  return s1;
}

int main() {
  string s;
  cin>>s;
  string s1 = add(s);
  int arr[10];
  memset(arr,0,sizeof(arr));
  for(int i=0;i<s.length();i++) {
    arr[s[i]-'0']++;
  }
  for(int i=0;i<s1.length();i++) {
    arr[s1[i]-'0']--;
  }
  for(int i=0;i<10;i++) {
    if(arr[i] !=0){
      cout<<"No\n"<<s1;
      return 0;
    }
  }
  cout<<"Yes\n"<<s1;
  return 0;
}