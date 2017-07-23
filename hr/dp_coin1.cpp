#include <bits/stdc++.h>

using namespace std;

//long getWays(long n, vector < long > c){
    // Complete this function
//}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    long dp[n+1][m+1];
    for(int i=0;i<=m;i++)   dp[0][i]=1;
    for(int i=1;i<=n;i++)   dp[i][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // cout<<"calc "<<i<<" "<<j<<endl;
            dp[i][j]=dp[i][j-1];
            if(i>=c[j-1]){
                dp[i][j]+=dp[i-c[j-1]][j];
            }
            // cout<<"val = "<<dp[i][j]<<endl;
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    //long ways = getWays(n, c);
    cout<<dp[n][m];
    return 0;
}
