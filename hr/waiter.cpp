#include <bits/stdc++.h>

using namespace std;
int calcNext(int a){
    a++;
    while(1){
        int flag=1;
        for(int i=2;i<a;i++){
            if(a%i==0){
                flag=0;
                break;
            }
        }
        if(flag==1)
            return a;
        else
            a++;
    }
}

int main() {
    int n;
    int q,a;
    cin >> n >> q;
    vector<int> number[q+1];
    for(int number_i = 0; number_i < n; number_i++){
       cin >> a;
       number[0].push_back(a);
    }
    vector<int> B[q+1];
    a=0;
    int prime=1;
    while(a<q && !number[a].empty()){
        prime=calcNext(prime);
        for(int i=number[a].size()-1;i>=0;i--){
            if(number[a][i]%prime==0)
                B[a+1].push_back(number[a][i]);
            else
                number[a+1].push_back(number[a][i]);
        }
        a++;
    }
    for(a=1;a<=q;a++){
        if(B[a].empty())
            break;
        for(int i=B[a].size()-1;i>=0;i--){
            cout<<B[a][i]<<endl;
        }
    }
    for(int i=number[q].size()-1;i>=0;i--){
        cout<<number[q][i]<<endl;
    }
    return 0;
}
