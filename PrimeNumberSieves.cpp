#include<bits/stdc++.h>

using namespace std; 
 
#define all(v) v.begin(), v.end() 
typedef unsigned long long int ulli; 
typedef long long int ll;
 
vector<ulli> sieve(ulli n) 
{ 
	 
	vector<bool> prime(n + 1, true); 
 
	prime[0] = false; 
	prime[1] = false; 
	long long int m = sqrt(n); 
 
	for (ulli p = 2; p <= m; p++) { 
 
		// If prime[p] is not changed, then it 
		// is a prime 
		if (prime[p]) { 
 
			// Update all multiples of p 
			for (ulli i = p * 2; i <= n; i += p) 
				prime[i] = false; 
		} 
	} 
 
	// push all the primes into the vector ans 
	vector<ulli> ans; 
	for (long long int i = 0; i < n; i++) 
		if (prime[i]) 
			ans.push_back(i); 
	return ans; 
} 
 
vector<ulli> sieveRange(ulli start, ulli end) 
{ 
	// find primes from [0..end] range 
	vector<ulli> ans = sieve(end); 
 
	// Find index of first prime greater than or 
	// equal to start 
	// O(sqrt(n)loglog(n)) 
	long long int lower_bound_index = lower_bound(all(ans), start) - 
											ans.begin(); 
 
	// Remove all elements smaller than start. 
	// O(logn) 
	ans.erase(ans.begin(), ans.begin() + lower_bound_index); 
 
	return ans; 
} 


int main()
{
	int t;
	ulli start=1;
	ulli end=9999;
	vector<ulli> ans = sieveRange(start, end); 
	for(int x:ans)
		cout<< x<<" ";
	cout<<'\n';
}
