#include<bits/stdc++.h>
using namespace std;
#define maxN 1000000
int n;
int A[maxN];
string type;
int k;
int lon_nhat = -1;
int chi_so;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> A[i];
    }
    do{
        cin >> type;
        if(type == "*")break;
        if(type=="insert"){
            cin >> k;
            n = n+1;
            A[n] = k;
        }
        else if(type=="delete-max"){
            for(int i = 1 ; i <= n ; i ++){
                if(A[i] > lon_nhat){
                    lon_nhat = A[i];
                    chi_so=i;
                    }
                
            }
            printf("%d\n",lon_nhat);
            lon_nhat = 0;
            for(int i = chi_so ; i <= n ; i++ ){
                A[i] = A[i+1];
            }
            n--;
        }
        }while(true);
    return 0;   
    }

