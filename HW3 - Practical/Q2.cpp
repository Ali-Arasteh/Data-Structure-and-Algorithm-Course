#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    long long int x0;
    scanf("%d %lld", &n, &x0);
    long long int boundaries[n][2];
    long long int all_boundaries[2*n];
    for (int i=0; i<n; i++) {
        scanf("%lld %lld", &boundaries[i][0], &boundaries[i][1]);
        all_boundaries[2*i] = boundaries[i][0];
        all_boundaries[2*i+1] = boundaries[i][1];
    }
    long long int temp, temp1, temp2;
    temp = all_boundaries[0];
    for (int i=0; i<2*n-1; i++) {
        for (int j=0; j<2*n-1-i; j++) {
            if (all_boundaries[j] > all_boundaries[j+1]) {
                temp = all_boundaries[j+1];
                all_boundaries[j+1] = all_boundaries[j];
                all_boundaries[j] = temp;
            }
        }
    }
    long long int right[2*n], left[2*n], matrix[2*n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<2*n; j++) {
            if (i == 0) {
                if (all_boundaries[j] >= boundaries[i][0] && all_boundaries[j] <= boundaries[i][1]) {
                    matrix[j] = abs(x0 - all_boundaries[j]);
                }
                else if (all_boundaries[j] < boundaries[i][0]) {
                    matrix[j] = abs(x0 - all_boundaries[j]) + abs(boundaries[i][0] - all_boundaries[j]);
                }
                else {
                    matrix[j] = abs(x0 - all_boundaries[j]) + abs(boundaries[i][1] - all_boundaries[j]);
                }
            }
            else {
                if (j == 0) {
                    right[j] = matrix[j] + abs(boundaries[i][0] - all_boundaries[j]);
                }
                else {
                    temp1 = matrix[j];
                    if (all_boundaries[j-1] >= boundaries[i][0] && all_boundaries[j-1] <= boundaries[i][1]) {
                        temp2 = right[j-1] + abs(all_boundaries[j-1] - all_boundaries[j]);
                    }
                    else if (all_boundaries[j-1] < boundaries[i][0]) {
                        temp2 = right[j-1] + abs(all_boundaries[j-1] - all_boundaries[j]) - abs(boundaries[i][0] - all_boundaries[j-1]);
                    }
                    else {
                        temp2 = right[j-1] + abs(all_boundaries[j-1] - all_boundaries[j]) - abs(boundaries[i][1] - all_boundaries[j-1]);
                    }
                    if (temp1 < temp2) {
                        temp = temp1;
                    }
                    else {
                        temp = temp2;
                    }
                    if (all_boundaries[j] >= boundaries[i][0] && all_boundaries[j] <= boundaries[i][1]) {
                        right[j] = temp;
                    }
                    else if (all_boundaries[j] < boundaries[i][0]) {
                        right[j] = temp + abs(boundaries[i][0] - all_boundaries[j]);
                    }
                    else {
                        right[j] = temp + abs(boundaries[i][1] - all_boundaries[j]);
                    }
                }
            }
        }
        for (int j=2*n-1; j>-1; j--) {
            if (i != 0) {
                if (j == 2*n-1) {
                    left[j] = matrix[j] + abs(boundaries[i][1] - all_boundaries[j]);
                }
                else {
                    temp1 = matrix[j];
                    if (all_boundaries[j+1] >= boundaries[i][0] && all_boundaries[j+1] <= boundaries[i][1]) {
                        temp2 = left[j+1] + abs(all_boundaries[j+1] - all_boundaries[j]);
                    }
                    else if (all_boundaries[j+1] < boundaries[i][0]) {
                        temp2 = left[j+1] + abs(all_boundaries[j+1] - all_boundaries[j]) - abs(boundaries[i][0] - all_boundaries[j+1]);
                    }
                    else {
                        temp2 = left[j+1] + abs(all_boundaries[j+1] - all_boundaries[j]) - abs(boundaries[i][1] - all_boundaries[j+1]);
                    }
                    if (temp1 < temp2) {
                        temp = temp1;
                    }
                    else {
                        temp = temp2;
                    }
                    if (all_boundaries[j] >= boundaries[i][0] && all_boundaries[j] <= boundaries[i][1]) {
                        left[j] = temp;
                    }
                    else if (all_boundaries[j] < boundaries[i][0]) {
                        left[j] = temp + abs(boundaries[i][0] - all_boundaries[j]);
                    }
                    else {
                        left[j] = temp + abs(boundaries[i][1] - all_boundaries[j]);
                    }
                }
                if (right[j] <= left[j]) {
                    matrix[j] = right[j];
                }
                else {
                    matrix[j] = left[j];
                }
            }
        }   
    }   
    temp = matrix[0];
    for (int i=0; i<2*n; i++) {
        if (matrix[i] < temp) {
            temp = matrix[i];
        }
    }
    printf("%lld", temp);
    return 0;
}