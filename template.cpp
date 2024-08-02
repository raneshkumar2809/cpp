#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define V(T) vector<T>
#define MAX_HEAP(T) priority_queue<T>
#define MIN_HEAP(T) priority_queue<T, vector<T>, greater<T>>
#define MOD 1000000007

// add fun using mod
inline ll add(ll a, ll b) {
    return (a + b) % MOD;
}

// Efficient modular subtraction
inline ll sub(ll x, ll y) {
    return (x - y + MOD) % MOD;
}

// Efficient modular multiplication
inline ll multiply(ll a, ll b) {
    return (a * b) % MOD;
}

// Efficient modular exponentiation (iterative version)
ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans = multiply(ans, a);
        a = multiply(a, a);
        b >>= 1;
    }
    return ans;
}
// fun to fin nCr
long long nCr(ll n, ll r) {
    if (r > n) {
        return 0;
    }
    if (r == 0 || r == n) {
        return 1;
    }

    // Since C(n, r) = C(n, n-r)
    if (r > n - r) {
        r = n - r;
    }

    long long result = 1;
    for (ll i = 0; i < r; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}
// Function to check whether given number is prime or not
bool isPrime(long long num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    long long sqrtNum = static_cast<long long>(std::sqrt(num));
    for (long long i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}
// function to find next prime number;
long long nextPrime(long long n) {
    if (n < 2) return 2;
    if (isPrime(n)) return n;  // Return n if it's already prime
    long long nextNum = n + 1;
    if (nextNum % 2 == 0) ++nextNum; // Start with next odd number
    while (!isPrime(nextNum)) {
        nextNum += 2; // Check only odd numbers
    }
    return nextNum;
}

void fun(){
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int T;
	cin>>T;
	while(T--){
	    fun();
	    cout<<endl;
	}
	return 0;
}
