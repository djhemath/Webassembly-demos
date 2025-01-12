#include <stdio.h>
#include <emscripten.h>

extern "C" {
    EMSCRIPTEN_KEEPALIVE;
    int prime(int n, bool* primes) {
        for (int i = 0; i <= n; i++) {
            primes[i] = true;
        }
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        return 0;
    }
}