class Solution {
public: // Approach-3: Sieve of Eratosthenes-> 0(n log (logn)).

    int countPrimes(int n) {

        // initially assume every number is prime
        vector<bool> isprime(n + 1, true);

        // 0 and 1 are not prime
        isprime[0] = false;
        isprime[1] = false;

        // We only need to check till sqrt(n)
        for(int i = 2; i * i <= n; i++) {

            // if i is prime, mark all its multiples as non-prime
            if(isprime[i] == true) {

                // start from i*i because smaller multiples
                // have already been marked by smaller primes
                for(int j = i * i; j <= n; j += i) {
                    isprime[j] = false;
                }
            }
        }

        // count all prime numbers less than n
        int count = 0;

        for(int i = 2; i < n; i++) {
            if(isprime[i] == true) {
                count++;
            }
        }

        return count;
    }
};