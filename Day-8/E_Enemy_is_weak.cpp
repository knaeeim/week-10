#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using order_set1 = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T> using order_set2 = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    

    int n; cin>>n; 

    vi v1(n), v2(n); 

    order_set1 <int> os1; 
    order_set2 <int> os2; 

    for(int i = 0; i < n; i++){
        cin>>v1[i]; 
        os1.insert(v1[i]); 
        v2[i] = os1.order_of_key(v1[i]); 
    }

    // range(v1); 
    // cout << endl; 
    // range(v2); 
    // cout << endl; 

    ll ans = 0;

    for(int i = n - 1; i >= 0; i--){
        // cout << v1[i] << " " << os2.order_of_key(v1[i]) << endl; 
        os2.insert(v1[i]); 
        ans += (os2.order_of_key(v1[i]) * v2[i]);
    }

    cout << ans << endl; 
    return 0; 
}