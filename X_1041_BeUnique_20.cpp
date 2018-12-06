#include<iostream> 
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;


int main() {
	int b[100000],a[100001]={0};
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++) {
		scanf("%d",&b[i]);
		a[b[i]]++;
		
	}
	int ans=-1;
	for(int i=0;i<N;i++) {
		if(a[b[i]]==1){
			ans=b[i];
			break;
		}
	}
	if(ans == -1) printf("None");
	else printf("%d",ans);
	
	return 0;
} 
