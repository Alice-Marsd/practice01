#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector< vector<double> > dp(n+1,vector<double>(m+1, 0.0));
    for(int i = 1; i <= n; ++i) {
        double nf = i;
        dp[i][0] = 1.0;
        dp[i][1] = nf/(nf+1.0);
        dp[i][2] = nf/(2.0+nf) + 2.0/(2.0+nf)*(2.0-1.0)/nf*dp[i-1][0];
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 3; j <= m; ++j) 
		{
            double nf = i, mf = j;
            dp[i][j] = nf/(nf+mf) + mf/(nf+mf)*(mf-1.0)/(nf+mf-1.0)*(mf-2.0)/(mf+nf-2.0)*dp[i][j-3]+ mf/(nf+mf)*(mf-1.0)/(nf+mf-1.0)*nf/(mf+nf-2.0)*dp[i-1][j-2];
        }
    cout << setprecision(4) << dp[n][m] << endl;
    return 0;
}
