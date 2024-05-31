#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using order_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define endl "\n"
#define ll long long int
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define vi vector<int>
#define vll vector<ll>
#define vp vector<pair<ll,ll>>
#define sorta(arr) sort(arr.begin(), arr.end());
#define sortd(arr) sort(arr.begin(), arr.end(), greater<int>());
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique((X).begin(),(X).end()),(X).end())
#define range(arr) for(auto el: arr) cout<<el<<" ";


int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL); 
    

    ll n, k; 
    cin>>n>>k; 

    vll v(n); 
    for(int i = 0; i < n; i++) cin>>v[i]; 

    order_set <ll> os; 
    for(int i  = 0; i < k; i++){
        os.insert(v[i]); 
    }

    ll odd_m = *os.find_by_order((k+1)/ 2 - 1); 
    ll sum = 0; 
    for(int i = 0; i < k; i++){
        sum += abs(v[i] - odd_m);
    }

    cout << sum << " ";

    for(int i = 0; i < n - k; i++){
        os.erase(os.find_by_order(os.order_of_key(v[i])));
        os.insert(v[i+k]);
        ll m = *os.find_by_order((k+1)/2 - 1);
        sum += abs(m - v[i + k]) - abs(odd_m - v[i]);
        if(k % 2 == 0){
            sum -= (m - odd_m);
        }
        odd_m = m; 
        cout << sum << " "; 
    }

    return 0; 
}