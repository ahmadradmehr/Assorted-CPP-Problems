/* Count Primes
 * 
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Example:
 * Input: 10
 * Output: 4
 * Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */
 
class CountPrimes {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<int> primes {2};
        for (int i {3}; i < n; i += 2) {
            bool prime {true};
            for (auto &p: primes) {
                if (p > sqrt(i))
                    break;
                if (i % p == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime)
                primes.push_back(i);
        }
        return primes.size();
    }
};