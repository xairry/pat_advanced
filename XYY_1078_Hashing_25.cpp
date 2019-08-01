#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 11111;
bool isP(int x){
  if(x<=1) return false; 
  for(int i=2;i*i<=x;i++) {
    if(x%i==0)return false;
  }

  return true;
}
bool hashTable[N] = {0};
int main() {
  int n,Tsize,a;
  
  scanf("%d %d",&Tsize,&n);
 
  while(isP(Tsize)==false){
     Tsize++;
  }
  
  
  for(int i=0;i<n;i++) {
    
    scanf("%d",&a);
    int M = a%Tsize;
    if(hashTable[M]==false){
      
      hashTable[M]=true;
      if(i==0) {
        printf("%d",M);
      }else{
        printf(" %d",M);
      }
      
    }
    else{
      
      int j=1;
      for(j ;j < Tsize; j++) {
        M = (a+j*j) % Tsize;
        if(hashTable[M] == false) {
          hashTable[M] = true;
          if(i==0){
            printf("%d",M);
          }else printf(" %d",M);
          break;
          
        }
      }
    if(j>=Tsize){
     if(i>0)printf(" ");
     printf("-");
    
    }
    
    
  }
  }

  return 0;
}