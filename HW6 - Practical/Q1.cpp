#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>

int main()
{
    std::srand(std::time(nullptr));
    double e = 0;
    double sum;
    double N;
    for (int i = 1; i <= pow(10, 8); i++) {
        sum = 0;
        N = 0;
        while (sum < 1) {
            sum += (float)(rand()) / (float)(RAND_MAX);
            N += 1;
        }
        e = e*(i-1)/i + N/i;
    }
    printf("%f", e);
    return 0;
}