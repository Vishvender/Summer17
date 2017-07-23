#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int t,n,min;
    cin>>t;
    while(t--){
        min=INT_MAX;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(min>arr[i]){
                min=arr[i];//calculate the min value in array
            }
        }
        int count[5]={0},steps=0;
        // if min is 7
        // count[0] will collect count of all elements who are converted to 7 with only -5 so no extra step needed.
        // like 12 37 107 512
        // similarly count[1] will be count of all elements who just need one -1 step to convert to 7.
        // similarly others for 2 3 4.
        for(int i=0;i<n;i++){
            count[(arr[i]-min)%5]++;
            steps+=(arr[i]-min)/5;
        }
        int a1,a2,a3;
        // a1 if we converge to min only.
        // a2 if we converge to min-1 so adding the extra steps.
        // a3 if we converge to min-2 so adding the extra steps.
        a1=count[1]+count[2]+2*count[3]+2*count[4];
        a2=count[0]+count[1]+2*count[2]+2*count[3]+count[4];
        a3=count[0]+2*count[1]+2*count[2]+count[3]+2*count[4];
        // finding min extra steps needed to make all of them equal.
        int min_steps=a1;
        min_steps=a2<min_steps?a2:min_steps;
        min_steps=a3<min_steps?a3:min_steps;
        // answer is previous sum + now calculated min step.
        cout<<steps+min_steps<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
