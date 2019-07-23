#include<iostream>
#include<stdio.h>
using namespace std;
struct Node{
  int val;
  Node* left;
  Node* right;
};

int main() {
  int N;
  scanf("%d",&N);
  int preOrder[N],inOrder[N];
  memset(preOrder,0,sizeof(preOrder));
  memset(inOrder,0,sizeof(inOrder));
  for(int i=0;i<N;i++) {
    scanf("%d",&preOrder[i]);
  }
  for(int i=0;i<N;i++) {
    scanf("%d",&inOrder[i]);
  }


  return 0;
}