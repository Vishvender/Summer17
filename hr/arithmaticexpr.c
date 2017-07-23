#include<stdio.h>

char stac[100];
int recursivecall(int i,int n,int tot,int* arr){
    int t;
    if(i<n){
      t=arr[i];
      int a=recursivecall(i+1,n,tot+t,arr);
      if(a==1){
        stac[n-i-1]='+';
        return 1;
      }
      a=recursivecall(i+1,n,tot-t,arr);
      if(a==1){
        stac[n-i-1]='-';
        return 1;
      }
      a=recursivecall(i+1,n,tot*t,arr);
      if(a==1){
        stac[n-i-1]='*';
        return 1;
      }
    }
    else if(tot%101==0){
      return 1;
    }
    return 0;
}

int main() {
    int n,t,itr;
    scanf("%d",&n);
    itr=n;
    int *arr;
    while(itr--){
      scanf("%d",&arr[n-itr-1]);
    }
    recursivecall(1,n,arr[0],arr);
    for(int i=0;i<n-1;i++){
      printf("%d%c",arr[i],stac[i]);
    }
    printf("%d",arr[n-1]);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
