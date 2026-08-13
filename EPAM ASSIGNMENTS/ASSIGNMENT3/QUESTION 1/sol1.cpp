#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n; cin>>n; 
    vector<ll> points(n, 0), dp(n, 0);
    for(int i=0; i<n; i++) cin>>points[i];
    dp[0] = points[0];
    dp[1] = max(points[0], points[1]);
    if(n == 1) {
        cout << points[0];
        return 0;
    } if(n == 2) {
        cout << max(points[0], points[1]);
        return 0;
    } for(int i=2; i<n; i++)
        dp[i] = max(dp[i-1], dp[i-2]+points[i]);
    cout << dp[n-1] << endl;
    return 0;
}