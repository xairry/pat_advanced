#include<stdio.h>
#include<string>
#include<vector>
using namespace std;

int main() {
	int N,M;
	scanf("%d %d",&N,&M);
	vector<string> ori;ori.clear();
	while(N--) {
		string str;
		scanf("%s",&str);
		ori.push_back(str);
		
	}
	for(int i=0;i<N;i++) {
		printf("%c",ori[i]);
	}
	
	
	return 0;
}
