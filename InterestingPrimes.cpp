/*
Given a number N, the task is to find the number of interesting primes less than equal to N.
An interesting prime is any prime number which can be written as a2 + b4, where a and b are positive integers.
For e.g. The smallest interesting prime number is 2 = 12 + 14. 
Examples: 
 

Input: N = 10 
Output: 2 
2 = 12 + 14 
5 = 22 + 14 
Both are interesting primes less than equal to 10
Input: N = 1000 
Output: 28 


*/

#include <bits/stdc++.h>
using namespace std;

// Function to find all prime numbers
void SieveOfEratosthenes(
	int n,
	unordered_set<int>& allPrimes)
{
	// Create a boolean array "prime[0..n]"
	// and initialize all entries as true.
	// A value in prime[i] will finally
	// be false if i is Not a prime.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {

		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true) {

			// Update all multiples of p
			// greater than or equal to
			// the square of it
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Store all prime numbers
	for (int p = 2; p <= n; p++)
		if (prime[p])
			allPrimes.insert(p);
}

// Function to check if a number
// is perfet square or not
int countInterestingPrimes(int n)
{
	// To store all primes
	unordered_set<int> allPrimes;

	SieveOfEratosthenes(n, allPrimes);

	// To store all interseting primes
	unordered_set<int> intersetingPrimes;

	vector<int> squares, quadruples;

	// Store all perfect squares
	for (int i = 1; i * i <= n; i++) {
		squares.push_back(i * i);
	}

	// Store all perfect quadruples
	for (int i = 1; i * i * i * i <= n; i++) {
		quadruples.push_back(i * i * i * i);
	}

	// Store all interseting primes
	for (auto a : squares) {
		for (auto b : quadruples) {
			if (allPrimes.count(a + b))
				intersetingPrimes.insert(a + b);
		}
	}

	// Return count of interseting primes
	return intersetingPrimes.size();
}

// Driver code
int main()
{
	int N = 10;

	cout << countInterestingPrimes(N);

	return 0;
}
