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

        stack <int> value; 
        stack <int> index; 

        for(int i = 0; i < n; i++){

            while( value.size() > 1 and value.top() > v[i]){
                int current = value.top(); 
                value.pop();
                if(current >= value.top()){
                    index.pop();
                }
                else{
                    value.push(current);
                    break;
                }
            }

            value.push(v[i]); 
            index.push(i);
        }

        int last_value = value.top(); 
        value.pop(); 
        int last_index = index.top(); 
        index.pop(); 

        ll cost = 0; 

        while( !index.empty() ){
            cost += max(last_value, value.top()) * (last_index - index.top());
            last_value = value.top(); 
            value.pop();
            last_index = index.top(); 
            index.pop();
        }

        cout << cost << endl; 
    }
    return 0; 
}