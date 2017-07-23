#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
char rotate(char c,int k){
    if((c<='Z' && c>='A') || (c<='z' && c>='a')){
        if(c>'A' && c<'Z'){
            if(c+k>'Z'){
                return 'A'+(k-('Z'-c))%26-1;
            }
            else{
                return c+k;
            }
        }
        else{
            if(c+k>'z'){
                return 'a'+(k-('z'-c))%26-1;
            }
            else{
                return c+k;
            }
        }
    }
    return c;
}
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for(int i=0;i<s.length();i++){
        s[i]=rotate(s[i],k);
    }
    cout<<s;
    return 0;
}
