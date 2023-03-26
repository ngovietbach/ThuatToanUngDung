#include<bits/stdc++.h>
using namespace std;
vector<string> date;
string trip_code, customer_code , times;
string ngay;
map<string, int > QTY_CUSTOMER; 
set<string> TOTAL_TRIPS;
map<int, int > day_time;
set<int> seconds;
map<string,int> travelmax;
map<string,int> travelmin;
//map<int,int> MAX_CONFLICT_TRIP;
//int max_co = 0 ; 
int TOTAL_QTY = 0; 
string type;
int qty;
int ans;
int daytime_to_second(string day , string times){
    int k;
    k = day[8]*10*24*60*60+day[9]*24*60*60+times[0]*10*60*60+times[1]*60*60+times[3]*10*60+times[4]*60+times[6]*10+times[7];
    return k;
}
//int count_time(string from_date , string from_time , string to_date , string to_time ){

//}
int main(){
    /*freopen( "test_case.txt", "r", stdin);
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);*/
    do{
        cin >> ngay;
        if(ngay=="*")continue;
        date.push_back(ngay);
    }while(ngay!="*");
    do{
        cin >> trip_code;
        if(trip_code=="***")continue;
        cin >> customer_code >> ngay >> times >> qty;
        TOTAL_QTY += qty;
        QTY_CUSTOMER[customer_code] += qty;
        TOTAL_TRIPS.insert(trip_code);
        ans = daytime_to_second(ngay,times);
        day_time[ans]=qty;
        seconds.insert(ans);
        //MAX_CONFLICT_TRIP[daytime_to_second(ngay,times)]++;
        if(ans>travelmax[trip_code])travelmax[trip_code] = ans;
        if(travelmin[trip_code] == 0 )travelmin[trip_code] = ans;
        if(ans < travelmin[trip_code])travelmin[trip_code] = ans; 
    }while(trip_code!="***");
    do{
        cin >> type;
        if(type=="***")continue;
        if(type=="TOTAL_QTY"){
            cout << TOTAL_QTY << endl;
        }
        else if(type=="QTY_CUSTOMER"){
            string customer;
            cin >> customer;
            cout << QTY_CUSTOMER[customer] << endl;
        }
        else if (type=="TOTAL_TRIPS"){
            cout << TOTAL_TRIPS.size() << endl;
        }
        else if (type=="QTY_MAX_PERIOD"){
            int QTY_MAX_PERIOD = 0;
            string from_day, from_time, to_day , to_time;
            cin >> from_day >> from_time >> to_day >> to_time;
            int second1 = daytime_to_second(from_day,from_time);
            int second2 = daytime_to_second(to_day,to_time);
            for(auto it = seconds.begin(); it != seconds.end() ; ++it){
                if(*it >= second1 && *it <= second2){
                    if(day_time[*it] > QTY_MAX_PERIOD)QTY_MAX_PERIOD = day_time[*it];
                }
            }
            cout << QTY_MAX_PERIOD << endl;
        }
        else if (type == "TRAVEL_TIME_TRIP"){
            string travel;
            cin >> travel;
            cout << travelmax[travel] - travelmin[travel] << endl;
        }
        /*else if (type == "MAX_CONFLICT_TRIPS"){
             for(auto it = seconds.begin(); it != seconds.end() ; ++it){
                if(MAX_CONFLICT_TRIP[*it] > max_co)max_co = MAX_CONFLICT_TRIP[*it];
            }
            cout << max_co << endl;
        }*/
        }while (type != "***");
        return 0;
    }