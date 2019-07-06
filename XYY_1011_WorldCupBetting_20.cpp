#include<cstdio>


int main(){
	char S[] = {'W','T','L'};
	char aa[3];
	double ans =1.0,tmp,a;
	int idx;
	for(int i=0;i<3;i++) {
		tmp = 0.0;
		for(int j=0;j<3;j++) {
			scanf("%lf",&a);
			if(a>tmp) {
				tmp = a ;
				idx = j ;
			}
		}
		ans *= tmp;
		aa[i]=S[idx];
	}
	for(int i=0;i<3;i++){
		printf("%c ",aa[i]);
	}
	printf("%.2f",(ans*0.65-1)*2);

	return 0;
	
} 
