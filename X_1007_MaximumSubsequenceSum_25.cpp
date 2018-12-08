#include<stdio.h>
#include<algorithm>


using namespace std;


int main() {
	int n;
	scanf("%d",&n);
	int a[n],dp[n];
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);
	}
	dp[0]=a[0];
	
	for(int i=1;i<n;i++) {
		dp[i] = max(a[i],dp[i-1]+a[i]);
	}
	int k=0;
	for(int i=0;i<n;i++){
	//	printf("%d\n",dp[i]);
	 	if(dp[i] >dp[k]){
	 		k=i;
		  }
	 }	
	 int m=k;
	 while(m--){
	 	if(dp[m]<0)break;
	 }
	 int sum=0;
	 for(int i=m+1;i<=k;i++) {
	 	sum+=a[i];
	 }
	 printf("%d %d %d",sum,a[m+1],a[k]);
	
	//printf("%d",k);
	return 0;
}

