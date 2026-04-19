class Solution {
    public int largestPrime(int n) {
        List<Integer> primes = getPrimeList(n);
        int sum = 0, mx = 0; // FIXED

        for (int it : primes) {
            sum += it;
            if (sum > n) break; // optimization

            if (checkPrime(sum)) {
                mx = Math.max(mx, sum);
            }
        }
        return mx;
    }

    boolean checkPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static List<Integer> getPrimeList(int n) {
        boolean[] isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);

        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }

        List<Integer> primeList = new ArrayList<>();
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primeList.add(i);
            }
        }
        return primeList;
    }
}