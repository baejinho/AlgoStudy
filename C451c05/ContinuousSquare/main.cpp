#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007

typedef long long LL;

int powMod(int root, int power, int mod);
int _powMod(int root, int power, int mod);

int main()
{
	int n;
	vector<int> seq;

	// input elements size
	cin >> n;
	seq.resize(n);
	// input elements value
	for (int i = 0; i < n; ++i)
		cin >> seq[i];
	
	// using reverse iterator: for proper calculation
	for (vector<int>::reverse_iterator rit = seq.rbegin() + 1; 
		rit != seq.rend(); 
		++rit) 
	{
		*rit = powMod(*rit, *(rit-1), MOD);
	}

	cout << seq[0] << '\n';

	return EXIT_SUCCESS;
}

// O(lg(power))
int powMod(int root, int power, int mod)
{
	LL ret;

	// base condition: power == 0
	if (power == 0)
		return 1;
	// base condition: power == 1
	if (power == 1)
		return root;

	// base condition: is power even?
	ret = (powMod(root, power / 2, mod) % mod);
	if ((power & 1) == 0) {
		return (ret * ret) % mod;
	}
	// base condition: is power odd?
	else {
		return (((ret * ret) % mod) * root) % mod;
	}
}

// O(power)
int _powMod(int root, int power, int mod)
{
	LL ret = 1;
	
	// (root^power)%mod
	for (int i = 0, modRoot = root % mod; i < power; ++i) {
		ret *= modRoot;
		ret %= mod;
	}

	return static_cast<int>(ret);
}