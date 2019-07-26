#include<isotream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

long long radd(string n,long long radix) {
  long long ans = 0;
  int index = 0,temp = 0;
  for(auto it = n.rbegin();it!=n.rend();it++) {
    temp  = isdigit(*it)? *it-'0' : *it-'a'+10;
    sum+=temp*pow(radix,index++);
  }
}

int main() {
  long long N1,N2;long long tag=0,radix=0,result_radix;
  cin>>N1>>N2>>tag>>radix;




  return 0;
}