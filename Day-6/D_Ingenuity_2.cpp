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
        int n; string s1; 
        cin>>n>>s1; 

        int x = 0, y = 0; 

        for(int i = 0; i < n; i++){
            if(s1[i] == 'N') y++;
            else if(s1[i] == 'S') y--;
            else if(s1[i] == 'W') x--;
            else x++;
        }

        if(abs(x) % 2 == 1 or abs(y) % 2 == 1) no; 
        else if(n == 2 and x == 0 and y == 0) no;
        else{
            int n = 0, s = 0, e = 1, w = 1;
            char m[2] = { 'R', 'H'};
            string ans = ""; 

            for(auto ch : s1){
                if(ch == 'N') ans += m[n], n = 1 - n; 
                else if(ch == 'S') ans += m[s], s= 1 - s;
                else if(ch == 'W') ans += m[w], w = 1 - w;
                else ans += m[e], e = 1 - e;  
            }

            cout << ans << endl; 

        }

    }
    return 0; 
}