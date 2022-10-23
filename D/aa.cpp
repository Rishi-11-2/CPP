#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define el endl
#define vi vector<int>
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define ht unordered_map
#define uset unordered_set
#define int long long int
#define lld long double
#define INF INT_MAX
void solve();
const int MAX = 1000001;
bool prime[10010];

// array to store prime factors
int factor[MAX] = {0};

// function to generate all prime factors
// of numbers from 1 to 10^6
void generatePrimeFactors()
{
    factor[1] = 1;

    // Initializes all the positions with their value.
    for (int i = 2; i < MAX; i++)
        factor[i] = i;

    // Initializes all multiples of 2 with 2
    for (int i = 4; i < MAX; i += 2)
        factor[i] = 2;

    // A modified version of Sieve of Eratosthenes to
    // store the smallest prime factor that divides
    // every number.
    for (int i = 3; i * i < MAX; i++)
    {
        // check if it has no prime factor.
        if (factor[i] == i)
        {
            // Initializes of j starting from i*i
            for (int j = i * i; j < MAX; j += i)
            {
                // if it has no prime factor before, then
                // stores the smallest prime divisor
                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}

// function to calculate number of factors
int calculateNoOfFactors(int n)
{
    if (n == 1)
        return 1;

    int ans = 1;

    // stores the smallest prime number
    // that divides n
    int dup = factor[n];

    // stores the count of number of times
    // a prime number divides n.
    int c = 1;

    // reduces to the next number after prime
    // factorization of n
    int j = n / factor[n];

    // false when prime factorization is done
    while (j != 1)
    {
        // if the same prime number is dividing n,
        // then we increase the count
        if (factor[j] == dup)
            c += 1;

        /* if its a new prime factor that is factorizing n,
           then we again set c=1 and change dup to the new
           prime factor, and apply the formula explained
           above. */
        else
        {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }

        // prime factorizes a number
        j = j / factor[j];
    }

    // for the last prime factor
    ans = ans * (c + 1);

    return ans;
}
void sieveOfErasthenes(int n)
{

    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    generatePrimeFactors();
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{

    int q;
    cin >> q;
    int arr[q];
    int n = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> arr[i];
        n = max(n, arr[i]);
    }
    sieveOfErasthenes(n);
    for (int i = 0; i < q; i++)
    {
        int k = arr[i];
        int s = 2;
        int *pref = new int[k + 2];
        for (int i = 0; i < k + 2; i++)
            pref[i] = 0;
        pref[0] = 2;
        int z = 1;
        for (int p = 3; p <= k; p++)
        {
            if (prime[p])
            {
                s += p;
                pref[z] = pref[z - 1] + p;
                z++;
            }
        }
        int count = 0;
        for (int i = 0; i < z; i++)
        {
            int g = s % 2;
            int h = pref[i] % 2;
            if (g == h)
            {
                count += calculateNoOfFactors(pref[i]);
            }
        }
        delete[] pref;
        cout << count << el;
    }
}