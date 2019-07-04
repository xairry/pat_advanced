#include<stdio.h>
#include<cmath>
using namespace std;

bool isPrime(int x) {
	if(x<=1) {
		return false;
	}
	int sq = (int)sqrt(x*1.0);
	for(int i=2;i<=sq;i++) {
		if(x%i == 0){
			return false;
		}
	}
	
}


int main() {
	int n;
	scanf("%d",&n);
	if(isPrime(n) && isPrime(n-6))printf("Yes\n%d\n",n-6);
	else if(isPrime(n) && isPrime(n+6))printf("Yes\n%d\n",n+6);
	else{
		while(!(isPrime(n)&&isPrime(n-6)) && !(isPrime(n)&&isPrime(n+6))){
			++n;
		}
		printf("No\n%d\n",n);
	}
	
	
	return 0;
}
