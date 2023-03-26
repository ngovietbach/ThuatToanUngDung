#include<bits/stdc++.h>
using namespace std;
int n = 3 ; // em be
int m  = 5; // tong keo
int f = 0; // so keo da chia
int p = n-1 ; // so em be con lai
int dem = 0 ;
int A[10];
int m0 ; 
/*void Try1(int k){// liet ke xau nhi phan do dai n 
    for(int i = 0 ; i <= 1 ; i++){
        A[k] = i ;
        if(k==n)solution();
        else Try1(k+1);
    }
}
void Try2(int k){// liet ke hoan vi n phan tu
    for(int i = 1 ; i <= n ; i++){
        if(bMark[i]==false){
            A[k] = i;
            bMark[i] = true;
            if(k==n)solution;
            else Try2(k+1);
            Bmark[i] = false;
        }
    }
}*/
void Try3(int k){// chia keo
    int m0 ; // so keo toi da co the chia cho em k
    m0 = m - f - p;
    if(k==n){
        A[k] = m0 ; 
       if(m0 > 0) dem++;
       for(int i  = 1 ; i <=  n ; i++){
        printf("%d",A[i]);
       }
    }
    else{
        for(int i = 1 ; i <= m0 ; i++){
           A[k] = i ;
           f+=i;
           p--;
           Try3(k+1);
           f-=i;
           p++;
        }
    }
}
int main(){
    Try3(1);
    printf("%d",dem);
}