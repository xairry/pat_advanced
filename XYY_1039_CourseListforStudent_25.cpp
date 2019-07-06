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
const int M = 26*26*26*10;//学生数上限 

vector<int> selCourse[M];
int getid(char name[]) {
	int id=0;
	for(int i=0;i<3;i++) {
		id=id*26+(name[i]-'A');
	}
	id =  id*10 + (name[3]-'0');
	return id;
}


int main() {
	int N,K;
	char name[5];
	scanf("%d %d",&N,&K);
	for(int i=0;i<K;i++) {
		int course,x;
		scanf("%d%d",&course,&x);
		for(int j=0;j<x;j++) {
			scanf("%s",name);
			int id=getid(name);
			selCourse[id].push_back(course);
		}
	}
	for(int i=0;i<N;i++) {
		scanf("%s",name);
		int id=getid(name);
		printf("%s %d",name,selCourse[id].size());
		sort(selCourse[id].begin(),selCourse[id].end());
		for(int j=0;j<selCourse[id].size();j++) {
			printf(" %d",selCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}
	



