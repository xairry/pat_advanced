#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;


int main() {
  string arr[] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
  string arr1[] = {"####","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
  int N;
  scanf("%d\n",&N);
  
  for(int i=0;i<N;i++) {
    string s;
    
    getline(cin,s);
    
    if(s[0]>='0' && s[0]<='9') {
      int s1 = stoi(s);
      int a = s1/13,b = s1%13; 
      if(a)cout<<arr1[a];
      if(a&&b)cout<<" ";
      if(b || s1==0)cout<<arr[b];
    }else{
      int t1=0,t2=0;
      string s1=s.substr(0,3),s2;
     
      if(s.length()>4) {
        s2 = s.substr(4,3);
      
      }
      for(int j=1;j<=12;j++) {
        if(s1==arr[j] || s2==arr[j]) t1=j;
        if(s1==arr1[j]) t2=j;
      }
      cout<<t2*13+t1;
    }
    cout<<endl;
  }


  return 0;
}