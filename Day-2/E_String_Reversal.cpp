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
    

    int n; 
    cin >> n; 

    string s; 
    cin >> s;

    string r = s;
    reverse(r.begin(), r.end()); 

    //maps first position is for storing character and second vector is only for storing the several position of its in vector
    map < char, vi > pos_s, pos_r; 

    for (int i = 0; i < n; i++){
        //taking position of original string and storing its on vector 
        pos_s[s[i]].push_back(i);
        //taking position of reverse string and storing its on vector 
        pos_r[r[i]].push_back(i);
    }

    //printing the pos_s (means original string) position:-
    /* 
    for(auto el : pos_s){
        vi temp = el.second; 
        cout << el.first << "->";
        for(auto value : temp){
            cout << value << " " ;
        }
        cout << endl;
    }

    cout << endl;

    //printing the pos_r (means reverse string) position:-
    for(auto el : pos_r){
        vi temp = el.second; 
        cout << el.first << "->";
        for(auto value : temp){
            cout << value << " " ;
        }
        cout << endl;
    }
    */

    vi permutation(n); 
    for (char ch = 'a'; ch <= 'z'; ch++){
        for(int i  = 0; i < pos_s[ch].size(); i++){
            permutation[pos_r[ch][i]] = pos_s[ch][i]; 
        }
    }

    order_set <int> os; 

    ll ans = 0; 

    for(int i = n - 1; i >= 0 ; i--){
        ans +=os.order_of_key(permutation[i]);
        os.insert(permutation[i]);
    }

    cout << ans << endl; 
    return 0; 
}