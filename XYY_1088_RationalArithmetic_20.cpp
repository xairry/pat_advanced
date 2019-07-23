#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
long long gcd(long long a,long long b) {
  return b == 0? abs(a) : gcd(b,a%b);
}
void func(long long a,long long b) {
    long long gc1 = gcd(a,b);
    a/=gc1;b/=gc1;
    long long int t1 = a/b;
    long long int t2 = a%b;
   
}


int main() {
    long long a1,a2,b1,b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    func(a1,b1);printf(" + ");func(a2,b2);printf(" = ");
    
    
    


    





  return 0;
}