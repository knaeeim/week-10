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
    

    int n, k; 
    cin>>n>>k; 

    vi v (n);
    order_set < pair< int, int > > os;  

    for (int i = 0; i < n; i++){
        cin>>v[i];
    }

    int left = 0, right = 0; 

    while ( right < n ){
        os.insert({v[right], right}); 
        if(right - left + 1 == k){
            int pos = k/2;
            if(k % 2 == 0) pos--;
            auto ans = os.find_by_order(pos);
            cout << ans->first << " ";
            os.erase({v[left], left});
            left++;
        }
        right++;
    }
    return 0; 
}