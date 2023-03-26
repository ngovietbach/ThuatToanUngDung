#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int a[MAX];
int count_total_transactions = 0;
int count_total_money = 0;
int count_total_account = 0;
string account[MAX];
map <string,int> amount_f;
void checkaccount(string acc){
    int l = -1;
    if(count_total_account == 0 ){
        account[count_total_account]= acc;
        count_total_account++;
    }
    else{
        for(int k = 0 ; k < count_total_account ; k++){
            if(account[k]==acc){
                l=k;
                break;
            }
        }
        if(l == -1 ){
            account[count_total_account]= acc;
            count_total_account++;
        }
    }
}
int main(){
    do{
        string facc,tacc,time,atm;
        int i;
        cin >> facc;
        if(facc == "#")break; 
        cin >> tacc >> i >> time >> atm;
        count_total_money += i;
        checkaccount(facc);
        checkaccount(tacc);
        count_total_transactions++;
        amount_f[facc] += i;
    }while(true);
    sort(a,a+count_total_account);
    do{
        string ques;
        cin >> ques;
        if(ques=="#")break;
        else if(ques=="number_transactions"){
            cout << count_total_transactions << endl;
        }
        else if(ques=="?count_total_money"){
            cout << count_total_money << endl; 
        }
        else if(ques=="?list_sorted_account"){
            for(int k = 0 ; k < count_total_account ; k++){
                cout << account[k];
            }
        }
    }while(true);
    return 0;
}

