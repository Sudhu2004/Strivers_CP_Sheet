#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> req(1001), present(1001);  

bool check(ll x,int n,int k) {
    
    ll sum = 0;

    for(int i=0; i<n ;i++) {
        ll leftout = present[i]  - x * req[i] ;
        if(leftout < 0) {
            sum += abs(leftout);
        }
    }

    return k >= sum;
}
ll getAns(int n, int k) {
    ll low = 0LL , high = 1e12;
    ll ans = 0;
    while(low <= high) {
        ll mid = low + (high - low)/2;

        if(check(mid, n, k)) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<n ;i++) {
        cin >> req[i];
    }
    for(int i=0; i<n ;i++) cin >> present[i];

    cout << getAns(n, k) << endl;
    return 0;
}