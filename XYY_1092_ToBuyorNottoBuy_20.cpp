#include<iostream>
#include<cstring>
using namespace std;

int main() {
  string str1,str2;
  cin>>str1>>str2;
  int len1 = str1.length(),len2 = str2.length();
  int arr[128];
  memset(arr,0,sizeof(arr));
  for(int i=0;i<len2;i++) {
    arr[str2[i]]++;
  }
  int ans1 = 0,ans2 = 0;
  for(int i=0;i<len1;i++) {
    
    arr[str1[i]]--;
    
  }
  bool flag = false;
  for(int i=0;i<128;i++) {
    if(arr[i] > 0){
      flag = true;
      ans1+=arr[i];
      }else{
      ans2-=arr[i];
      }
    
  }
  if(flag)printf("No %d",ans1);
  else printf("Yes %d",ans2);
  return 0;
}