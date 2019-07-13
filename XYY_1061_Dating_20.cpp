#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int main() {
  char week[7][15] = {
    "MON","TUE","WED","THU","FRI","SAT","SUN"
  };
  string str1,str2,str3,str4;
  getline(cin,str1);
  getline(cin,str2);
  getline(cin,str3);
  getline(cin,str4);
  int len1 = str1.length();
  int len2 = str2.length();
  int len3 = str3.length();
  int len4 = str4.length();

  int i;
  for(i=0;i<len1 && i<len2;i++) {
    if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i]<='G') {
      printf("%s ",week[str1[i]-'A']);
      break;
    }
  }

  for(i++;i<len1 && i<len2;i++) {
    if(str1[i] == str2[i]){
      if(str1[i]>='0' && str1[i]<='9') {
        printf("%02d:",str1[i]-'0');
        break;
      }else if(str1[i]>='A' && str1[i]<='N'){
        printf("%02d:",str1[i]-'A'+10);
        break;
      }
    }
  }
  for(i=0;i<len3 && i<len4;i++) {
    if(str3[i] == str4[i]) {
      if((str3[i] >= 'A' && str3[i]<='Z') || (str3[i]>='a' && str3[i]<='z')){
        printf("%02d",i);
        break;
      }
    }
  }
  return 0;
}