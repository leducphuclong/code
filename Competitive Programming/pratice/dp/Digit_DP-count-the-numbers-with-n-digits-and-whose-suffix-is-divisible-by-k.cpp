
// C++ implementation to Count the 
// numbers with N digits and whose 
// suffix is divisible by K
 
#include <bits/stdc++.h>
 
using namespace std;
 
int mod = 1000000007;
int dp[1005][105][2];
int powers[1005];
int powersModk[1005];
 
// Suffix of length pos with 
// remainder rem and Z representing
// whether the suffix has a 
// non zero digit until now
int calculate(int pos, int rem, 
           int z, int k, int n)
{
    // Base case
    if (rem == 0 && z) {
         
        // If count of digits 
        // is less than n
        if (pos != n)
             
            // Placing all possible 
            // digits in remaining 
            // positions
            return (powers[n - pos - 
                        1] * 9) % mod;
        else
            return 1;
    }
     
    // If remainder non zero 
    // and suffix has n digits
    if (pos == n)
        return 0;
     
    // If the subproblem 
    // is already solved
    if (dp[pos][rem][z] != -1)
        return dp[pos][rem][z];
 
    int count = 0;
 
    // Placing all digits at MSB 
    // of suffix and increasing 
    // it's length by 1
    for (int i = 0; i < 10; i++) {
        if (i == 0)
            count = (count + (calculate(pos + 1, (rem + (i * powersModk[pos]) % k) % 
                    k, z, k, n))) % mod;
 
        // Non zero digit is placed
        else
            count = (count + (calculate(
                pos + 1, (rem + (i * 
                powersModk[pos]) % k) % 
                k, 1, k, n))) % mod;
    }
 
    // Store and return the 
    // solution to this subproblem
    return dp[pos][rem][z] = count;
}
 
// Function to Count the numbers 
// with N digits and whose suffix 
// is divisible by K
int countNumbers(int n, int k)
{
 
    // Since we need powers of 10 
    // for counting, it's better to 
    // pre store them along with their 
    // modulo with 1e9 + 7 for counting
    int st = 1;
    for (int i = 0; i <= n; i++) {
        powers[i] = st;
        st *= 10;
        st %= mod;
    }
 
    // Since at each recursive step 
    // we increase the suffix length by 1
    // by placing digits at its leftmost 
    // position, we need powers of 10
    // modded with k, in order to fpos 
    // the new remainder efficiently
    st = 1;
    for (int i = 0; i <= n; i++) {
        powersModk[i] = st;
        st *= 10;
        st %= mod;
    }
 
    // Initialising dp table values -1
    // represents subproblem hasn't 
    // been solved yet
    memset(dp, -1, sizeof(dp));
 
    return calculate(0, 0, 0, k, n);
}
 
// Driver Code
int main()
{
    int N = 2;
    int K = 2;
 
    cout << countNumbers(N, K);
 
    return 0;
}
