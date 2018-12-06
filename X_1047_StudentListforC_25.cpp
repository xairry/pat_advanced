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

const int M=40010;
char name[M][5];
vector<int> selCourse[M];
bool cmp(int a,int b){
	return strcmp(name[a],name[b]) <0;
}
	
int main() {
	int N,K;
	
	scanf("%d %d",&N,&K);
	for(int i=0;i<N;i++) {
		int x,course;
		scanf("%s %d",name[i],&x);
		for(int j=0;j<x;j++) {
			scanf("%d",&course);
			selCourse[course].push_back(i);
		}
		
	}
	for(int i=1;i<=K;i++) {
		printf("%d %d\n",i,selCourse[i].size());
		sort(selCourse[i].begin(),selCourse[i].end(),cmp);
		for(int j=0;j<selCourse[i].size();j++) {
			printf("%s\n",name[selCourse[i][j]]);
		}
	}

	return 0;
}
	



