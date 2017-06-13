#include <iostream>
using namespace std;

const long long MOD = 1000000007LL;

int main()
{
	long long n;
	long long res;
	long long nMod;

	n = 0LL;
	res = 1LL;

	// Get N
	cin >> n;
	nMod = n % MOD;

	for (long long i = 1, sqr = 0; (sqr = i * i) <= n; ++i) {
		if (n % i == 0) {
			// base condition: n != sqr^2
			if (n != sqr) {
				res = res * nMod;
				res %= MOD;
			}
			// base condition: n == sqr^2
			else {
				res = res * (i % MOD);
				res %= MOD;
			}
		}
	}

	// Print Result
	cout << res << '\n';

	return EXIT_SUCCESS;
}