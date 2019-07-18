#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;


int main() {
  
  int K;
  cin>>K;
  for(int i=0;i<K;i++) {
    string str;
    cin>>str;
    int len = str.size();
    if(len % 2 ==1){
      printf("No\n");
      continue;
    }
    string a = str.substr(0,len/2);
    string b = str.substr(len/2,len/2);
    int A=stoi(a),B=stoi(b),Z = stoi(str);
    if( A*B != 0 && Z%(A*B)==0 ) {
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  


  return 0;
}