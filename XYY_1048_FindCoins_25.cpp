#include<iostream> 
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
const int n=1005;

using namespace std;
int hashTable[n];

int main() {
	int N,M;
	
	scanf("%d %d",&N,&M);
	int pay;
	for(int i=0;i<N;i++) {
		scanf("%d",&pay);
		hashTable[pay]+=1;
	}
	
	for(int i=0;i<M;i++) {
		if(hashTable[i]&&hashTable[M-i]){
			if(i==M-i&&hashTable[i]<=1){
				continue;
			}
			printf("%d %d",i,M-i);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
} 
