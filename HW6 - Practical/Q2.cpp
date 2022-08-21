#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>

int main()
{
    std::srand(std::time(nullptr));
    double pi = 0;
    double r1, r2;
    for (int i = 1; i <= pow(10, 8); i++) {
        r1 = (float)(rand()) / (float)(RAND_MAX);
        r2 = (float)(rand()) / (float)(RAND_MAX);
        if (pow(r1, 2) + pow(r2, 2) <= 1) {
            pi += 1;
        }
    }
    pi = pi*4/pow(10, 8);
    printf("%f", pi);
    return 0;
}