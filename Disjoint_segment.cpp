#include<bits/stdc++.h>
using namespace std;
#define maxN 100000
int A[maxN],B[maxN];
int n;
int solve = 0;
int a,b;
int k;
void input(){
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++ ){
        scanf("%d %d",&A[i],&B[i]);
    }
}
void sapxep(){
    int swap;
    for(int i = 1; i <= n-1 ; i++ ){
        for(int j = i+1 ; j <=n ; j++){
            if(A[j] < A[i] ){
                swap = A[i];
                A[i] = A[j];
                A[j] = swap;
                swap = B[i];
                B[i] = B[j];
                B[j] = swap;
            }
        }
    }
}
void thamlam(){
    int value;
    do{
        value = -1;
        int i = k+1;
        a = B[k];
        b = B[k+1];
        if(k+1 > n)break;
        for(i ; i <=n ; i++ ){
            if((A[i] > a) && (B[i] <= b)){
                k = i;
                b = B[i];
                value = 1;
            }
        }
        printf("%d\n",b);
        solve++;
    }while(value == 1);
}
void jarimas(){
    a = B[1];
    k = 1;
    for(int i = 2 ; i <= n ; i++  ){
        if(B[i] < a){
            a = B[i];
            k = i;
        }
    }
    printf("%d %d %d\n",a,b,k);
    solve++;
    thamlam();
    printf("%d",solve);
}
int main(){
    input();
    sapxep();
     for(int i = 1 ;i <= n ; i++){
        printf("%d %d \n",A[i],B[i]);
    }
    jarimas();
    return 0;
}
