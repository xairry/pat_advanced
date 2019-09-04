#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int N;
const int maxn = 50010;
vector<int> preOrder,inOrder;
struct Node{
  int val;
  Node* left;
  Node* right;
};
bool flag = false;
void create(int preL,int preR,int inL,int inR){
    if(preL>preR) {
      return;
    }
    int k = inL;
    while(inOrder[k] != preOrder[preL]) k++;
    int numleft = k-inL;
    create(preL+1,preL+numleft,inL,k-1);
    create(preL+numleft+1,preR,k+1,inR);
    if(flag == false) {
      printf("%d",inOrder[k]);
      flag = true;
    }
}

int main() {
  
  scanf("%d",&N);
  preOrder.resize(N);
  inOrder.resize(N);
  
  for(int i=0;i<N;i++) {
    scanf("%d",&preOrder[i]);
  }
  for(int i=0;i<N;i++) {
    scanf("%d",&inOrder[i]);
  }
  create(0,N-1,0,N-1);


  return 0;
}