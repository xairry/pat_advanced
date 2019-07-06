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
using namespace std;
//const int MAXV = 1000; //最大顶点数 
//const int INF = 0Xffffffff;
set<int> a[51];
void compare(set<int> a,set<int> b) {
	set<int>::iterator it=a.begin();
	int cnt=0,sum=b.size();
	for(it;it!=a.end();it++) {
		if(b.find(*it) != b.end()) {
			cnt++;
		}else{
			sum++;
		}
	}
	printf("%.1f%%\n",(cnt*100.0/sum));
} 

int main() {
	int n1;
	scanf("%d",&n1);
	
	for(int i=1;i<=n1;i++) {
		int n2,tmp;
		
		scanf("%d",&n2);
		
		 for(int j=1;j<=n2;j++) {
		 	
		 	scanf("%d",&tmp);
		 	a[i].insert(tmp);
		 }
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++) {
		int q1,q2;
		scanf("%d %d",&q1,&q2); 
		compare(a[q1],a[q2]);
	}
	
	
	


	return 0;
}
	



