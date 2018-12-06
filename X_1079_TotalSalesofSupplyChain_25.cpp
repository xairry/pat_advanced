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
const int MAXN = 100010; //最大顶点数 
//const int INF = 0Xffffffff;
//set<int> a[51];


int N;
double p,r,ans=0.0;
	
	
struct Node {
	double data;
	vector<int> child;
}node[MAXN];

void DFS(int index,int depth) {
	if(node[index].child.size()==0) {
		ans+=node[index].data*pow(1+r,depth);
		return ;
	}
	for(int i=0;i<node[index].child.size();i++) {
		DFS(node[index].child[i],depth+1);
	}
}

int main() {
	
	scanf("%d %lf %lf",&N,&p,&r);
	r/=100;
	int tp1,tp2;
	for(int i=0;i<N;i++) {
		scanf("%d",&tp1);
		if(tp1 ==0) {
			scanf("%lf",&node[i].data);
		}else {
			for(int j=0;j<tp1;j++) {
				scanf("%d",&tp2);
				node[i].child.push_back(tp2);
			}
		}
	}
	DFS(0,0);
	printf("%.1f\n",p*ans);
	
	
	return 0;
}
	



