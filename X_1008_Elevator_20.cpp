#include<iostream> 
#include<stdio.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>


using namespace std;


int main() {
	int cost,N;
	scanf("%d",&N);
	if(N==0)return 0;
	int a[N];
	for(int i=0;i<N;i++){
		scanf("%d",&a[i]);
	}

	cost+=a[0]*6;
	for(int i=1;i<N;i++){
		if(a[i]>a[i-1]){
			cost+=(a[i]-a[i-1])*6;
		}else{
		cost+=(a[i-1]-a[i])*4;
		}
	}
	cost+=N*5;
	printf("%d",cost);
	return 0;
} 
