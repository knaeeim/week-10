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

    while(t--){
        int n, k;
        cin>>n>>k; 

        vi v(n);

        for(int i = 0; i < n; i++){
            cin>>v[i];
        }

        vi suffix(n, 0); 
        suffix[n-1] = 1;
        for(int i = n-2; i >= 0; i--){
            suffix[i] = suffix[i+1] + (v[i] == v[n-1]);
        }

        if(v[0] == v[n-1]){
            if(suffix[0] % k == 0 or suffix[0] >= k){
                yes;
                continue;
            }
        }

        bool ok = false;
        int cnt = 0;

        for(int i = 0; i <= n-2; i++){
            cnt +=(v[i] == v[0]);
            if(cnt % k == 0 and suffix[i+1] >= k){
                ok = true;
                break;
            }
        }

        if(ok) yes;
        else no;

    } 

    return 0; 
}