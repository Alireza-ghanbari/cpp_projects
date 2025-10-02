#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 5000000;

vector<bool> sieve_primes(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * 1LL * i <= n; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

string to_base(long long x, int k)
{
    if (x == 0)
        return "0";
    string s;
    while (x > 0)
    {
        int d = x % k;
        if (d < 10)
            s.push_back('0' + d);
        else
            s.push_back('A' + (d - 10));
        x /= k;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool is_palindrome(const string &s)
{
    for (int i = 0, j = (int)s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<bool> is_prime = sieve_primes(LIMIT);

    int count = 0;
    for (int num = 2; num <= LIMIT; num++)
    {
        if (is_prime[num])
        {
            string repr = to_base(num, k);
            if (is_palindrome(repr))
            {
                count++;
                if (count == n)
                {
                    cout << num << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}
