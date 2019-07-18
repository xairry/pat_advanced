#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

string rev(string s){
  reverse(s.begin(),s.end());
  return s;
}
string add(string s1,string s2){
  string s = s1;
  int ca = 0;
  for(int i=s1.size()-1;i>=0;i--) {
    s[i] = (s1[i]-'0'+s2[i]-'0'+ca)%10+'0';
    ca = (s1[i]-'0'+s2[i]-'0'+ca)/10;
  }
  if(ca>0)s="1"+s;
  return s;


}
int main() {
  
  int n =10;
  string s,sum;
  cin>>s;
  if(rev(s) == s){
    //printf("%s is a palindromic number.",s);
    cout<<s<<" is a palindromic number.\n";
    return 0;
  }
  while(n--) {
    sum = add(s,rev(s));
    cout << s << " + " << rev(s) << " = " << sum << endl;
    if (sum == rev(sum)) {
            cout << sum << " is a palindromic number.\n";
            return 0;
        }
        s = sum;
  }
cout << "Not found in 10 iterations.\n";
  return 0;
}