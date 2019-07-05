#include<stdio.h>
#include<vector>
using namespace std;
int M,N;
vector<int> arr;
void postorder(int index) {
	if(index>=N+1)return;
	postorder(index*2);
	postorder(index*2+1);
	printf("%d%s",arr[index],index == 1?"\n":" ");	
}

int main() {
	
	scanf("%d %d",&M,&N);
	arr.resize(N+1);
	for(int i=0;i<M;i++) {
		
		for(int j=1;j<=N;j++) {
			scanf("%d",&arr[j]);
		}
		int isMax = 1;
		int isMin = 1;
		for(int q=2;q<=N;q++) {
			if(arr[q/2]<arr[q])isMax=0;
			if(arr[q/2]>arr[q])isMin=0;
		}
		if(isMax){
			printf("Max Heap\n");
		}else{
			printf("%s Heap\n",isMin?"Min":"Not");
		}
		postorder(1);
			
	}
	return 0;
}
