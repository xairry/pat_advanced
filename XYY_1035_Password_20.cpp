#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	scanf("%d",&N);
	vector<string> v;
	for(int j=0;j<N;j++) {
		string name ,s ;
		cin >> name >> s;
		int len = s.length(),flag = 0;
		for(int i=0;i< len;i++){
 			switch(s[i]){
 				case '1':s[i] = '@';flag = 1;break;
 				case '0':s[i] = '%';flag = 1;break;
 				case 'l':s[i] = 'L';flag = 1;break;
 				case 'O':s[i] = 'o';flag = 1;break;
	 		}
	 	
		}
		if(flag){
	 		string temp = name+" "+s;
	 		v.push_back(temp);
		 }
	}
	int cnt = v.size();
	if(cnt) {
		printf("%d\n",cnt);
		for(int i=0;i<cnt;i++) {
			cout<<v[i]<<endl;
		}
	}else if(N == 1) {
        printf("There is 1 account and no account is modified");
    } else {
        printf("There are %d accounts and no account is modified", N);
    }
	
	
	
	return 0;
}
