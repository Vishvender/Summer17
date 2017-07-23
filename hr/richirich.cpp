#include <bits/stdc++.h>
#include<iostream>
using namespace std;
string richieRich(string s,int n,int k){
    int i=0,j=n-1;
    int *arr=(int *)calloc(n,sizeof(int));
    while(i<=j){
      if(s[i]!=s[j]){
        if(k>0){
          s[i]=s[j]=s[i]>s[j]?s[i]:s[j];
          arr[i]=1;
          arr[j]=1;
          k--;
        }
        else{
          return "-1";
        }
      }
      i++;
      j--;

    }
    // cout<<s<<"   "<<k<<endl;
    i=0;
    while(i<=(n/2)){
      if(k>0){
        if(s[i]!='9'){
          if(arr[i]==1 ){
            k--;
            s[i]=s[n-1-i]='9';
          }
          else{
            if(k>1){
              k=k-2;
              s[i]=s[n-1-i]='9';
            }
            else if(i==n/2){
              k--;
              s[i]='9';
            }
          }
        }
      }
      else{
        return s;
      }
      i++;
    }
    return s;
}
int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
