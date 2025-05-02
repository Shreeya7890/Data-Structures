// n blocks from 1 to n-1. 
//First line- number of testcases and second line- number of towers
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#define ll long long
using namespace std;

void Max(vector<ll> &towers, int num){
    for(ll i=0;i<num;i++){
        if(towers[i]>towers[0]){
            towers[0] += ((towers[i]-towers[0]+1) /2);
        }
    }
    
}
int main(){
    ll testcases;
    cin>>testcases;
    while(testcases--){
        ll num;
        cin>>num;
        vector<ll> towers(num);
        for(ll i=0;i<num;i++){
            cin>>towers[i];
        }
        sort(towers.begin(),towers.end());
        Max(towers,num);
        cout<<towers[0]<<endl;
    }
    return 0;
}