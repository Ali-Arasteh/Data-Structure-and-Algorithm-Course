#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() 
{
    double count[3], p[3];
    scanf("%lf %lf %lf %lf %lf %lf", &count[0], &count[1], &count[2], &p[0], &p[1], &p[2]);
    double min = 1000, temp;
    int index = -1;
    for(int i=0; i<3; i++) {
        temp = count[i] / p[i];
        if(temp < min) {
            min = temp;
            index = i;
        }
    }
    for(int i=0; i<3; i++) {
        cout << fixed << setprecision(6) << count[i] - p[i] * count[index] / p[index] << " ";
    }
    return 0;
}