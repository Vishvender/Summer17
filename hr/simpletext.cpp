#include <cmath>
#include <cstdio>
#include <vector>
#include<string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    vector<char> curr[1000000];
    int i,x,k,n=0;
    string s;
    cin>>i;
    while(i--){
        cin>>x;
        cout<<"here   "<<x<<endl;
        switch(x){
            case 1:
                cout<<"here";
                n++;
                cout<<"here1";
                curr[n]=curr[n-1];
                cout<<"here2";
                cin>>s;
                for(int i=0;i<s.length();i++)
                    curr[n].push_back(s[i]);
                break;
            case 2:
                n++;
                curr[n]=curr[n-1];
                cin>>k;
                while(k--){
                    curr[n].pop_back();
                }
                break;
            case 3:
                cin>>k;
                cout<<curr[n][k-1]<<endl;
                break;
            case 4:
                curr[n].clear();
                n--;
                break;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
