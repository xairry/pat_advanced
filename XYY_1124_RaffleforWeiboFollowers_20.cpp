#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;


int main() {
  int M,N,S;
  cin>>M>>N>>S;
  string arr[1010];
  for(int i=1;i<=M;i++) {
    cin>>arr[i];
  }
  if(S>M) {
  cout<<"Keep going...";
  return 0;
  }
  if(N+S>M) {
    cout<<arr[S];
  }
  set<string> st;
  for(int i=S;i<=M;) {
    if(st.find(arr[i])!=st.end()){
      i++;
      continue;
    }else{
      cout<<arr[i]<<endl;
      st.insert(arr[i]);
      i+=N;

    }
  }



  return 0;
}