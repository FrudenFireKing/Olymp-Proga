#include <iostream>
#include <vector>

using namespace std;

const int MAX_PRIME_BOUND = 200000;
vector<long long> primes;

void solve() {
    int n;
    cin >> n;
    
    
    cout << primes[0];
    for (int i = 1; i < n; i++) {
        long long next_val = primes[i - 1] * primes[i];
        cout << " " << next_val;
    }
    cout << "\n";
}

int main() {
    vector<bool> is_prime(MAX_PRIME_BOUND, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX_PRIME_BOUND; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX_PRIME_BOUND; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAX_PRIME_BOUND; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
    
    
            cout << primes[0];
            for (int i = 1; i < n; i++) {
                long long next_val = primes[i - 1] * primes[i];
                cout << " " << next_val;
            }
            cout << "\n";;
            }
    }
    return 0;
}