#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    

    int t; cin>>t; 

    while( t--){
        int n; cin>>n; 
        
        vi v(n); 
        for(int i = 0; i < n; i++) cin>>v[i]; 

        map<tuple<int, int, int>, int> mp; 

        ll ans = 0; 

        for(int i = 0; i < n - 2; i++){
            tuple <int, int, int> triple = make_tuple(v[i], v[i+1], v[i+2]); 
            vector <tuple<int, int, int>> temp(3); 
            temp[0] = make_tuple(0, v[i+1], v[i+2]);
            temp[1] = make_tuple(v[i], 0, v[i+2]);
            temp[2] = make_tuple(v[i], v[i+1], 0);

            for(auto &tri : temp){
                ans += mp[tri] - mp[triple]; 
                mp[tri]++;
            }
            mp[triple]++;
        }
        cout << ans << endl; 
    }
    return 0; 
}