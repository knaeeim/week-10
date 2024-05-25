#include<bits/stdc++.h>
using namespace std;
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
        ll a, b, k; 
        cin>>a>>b>>k; 

        ll cnt = 0;

        while( true ){
            if((b%k == 0) and (b/k >= a)){
                cnt++;
                b/=k;
            }
            else if(b%k == 0){
                cnt +=(b-a);
                break;
            }
            else{
                int temp = b%k; 
                cnt +=temp;
                b -=temp;
            }
        }

        cout << cnt << endl; 
    }
    return 0; 
}