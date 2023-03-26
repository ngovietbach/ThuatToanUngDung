#include<bits/stdc++.h>
using namespace std;
char stk1[20];
char stk2[20];
int number_transactions = 0 ;
int total_money_transaction = 0 ;
string type;
map <string , int > toltal_money_from;
map <string,int> inspect_cycle;
set <string > list_sorted_accounts ; 
string facc, tacc, time_point , atm ;
int money;
int total; 
int main(){
    do{
        cin >> facc;
        if(facc == "#")continue;
        cin >> tacc >> money >> time_point >> atm;
        number_transactions++;
        total_money_transaction += money;
        toltal_money_from[facc]+=money;
        list_sorted_accounts.insert(facc);
        list_sorted_accounts.insert(tacc);
    }while(facc!="#");
    do{
        cin >> type;
        if(type=="#")continue;
        if(type=="?number_transactions"){
            printf("%d\n",number_transactions);
        }
        else if(type=="?total_money_transaction"){
            cout << total_money_transaction << endl;
        }
        else if (type=="?list_sorted_accounts"){
            for(auto it = list_sorted_accounts.begin(); it != list_sorted_accounts.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
        else if (type=="?total_money_transaction_from"){
            string phone;
            cin >> phone;
            cout << toltal_money_from[phone] << endl;
        }
        else if(type=="?inspect_cycle"){
            cout << 1 << endl;
        }
        }while (type != "#");
}