 #include<iostream>
#include <stdio.h>
#include <cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<set>
#include<map>
#include<cmath>
#include<cctype>
#include<queue>
using namespace std;
const int MAXN = 100010; 
//const int INF = 0Xffffffff;
//set<int> a[51];
int N;
double r,p,ans;
struct Node{
	vector<int> child;
}node[MAXN];
int cnt=0,maxdep=0;
void DFS(int index,int depth){
	if(node[index].child.size()==0){
		if(depth>maxdep){
			cnt=1;
			maxdep=depth;
		}else if(depth==maxdep){
			cnt++;
		}
		
		return;
	}
	for(int i=0;i<node[index].child.size();i++) {
		DFS(node[index].child[i],depth+1);
	}
}

int main() {
	scanf("%d %lf %lf",&N,&p,&r);
	r/=100;
	int tp1,tp2,root;
	for(int i=0;i<N;i++) {
		scanf("%d",&tp1);
		if(tp1==-1){
			root=i;
		}
		node[tp1].child.push_back(i);
		
	}
	DFS(root,0);
	printf("%.2f %d",p*pow(1+r,maxdep),cnt);

	
	
	return 0;
}
	



