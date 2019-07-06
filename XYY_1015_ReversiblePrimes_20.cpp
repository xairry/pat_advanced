#include<stdio.h>
#include<cmath>
using namespace std;

bool isPrime(int x) {
	if(x<=1)return false;
	for(int i=2;i*i<=x;i++) {
		if (x%i==0) {
			return false;
		}
	}
	return true;
}

int reverseN(int n,int d) {
		int len =0,arr[100];
		do{
			arr[len++] = n%d;
			n = n/d;
		}while(n>0);
		for(int i=0;i<len;i++) {
			n = n*d+arr[i];
		}
		return n;
	
}

int main() {
	int N=0,D=0;
	//printf("%d",reverseN(23,2));
	while(scanf("%d",&N)!=EOF) {
		
		if(N < 0)break;
		scanf("%d",&D);
		if(!isPrime(N)){
			printf("No\n");
			continue;
		}
		printf("%s",isPrime(reverseN(N,D))?"Yes\n":"No\n");
	}
	
	
	
	return 0;
}
