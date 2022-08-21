#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);
    int sequence[n];
    double max = 0;
    for(int i=0; i<n; i++) {
        scanf("%d", &sequence[i]);        
        if(sequence[i] > max) {
            max = sequence[i];
        }
    }
    int sum = 0;
    int c = 0;
    long int mul = 1;
    long int f = 1;
    for(int i=0; i<n-max; i++) {
        sum += sequence[i];
        c += i + 1;
        mul *= sequence[i];
        f *= i + 1;
    }
    if(sum == c && mul == f) {
        cout << n-max;
    }
    else {
        cout << max;
    }
    return 0;
}