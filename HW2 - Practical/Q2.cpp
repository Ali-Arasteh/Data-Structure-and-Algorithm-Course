#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
using namespace std;

int af(int [], int [], int, int, int, int);

int main() 
{
    int n;
    scanf("%d", &n);
    int a[n], p[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &p[i]);
    }
    int output;
    output = min(p[0], p[n-1]);
    int temp;
    for(int i=1; i<=n-1; i++) {
        temp = af(a, p, i, 0, output, n);
        if(temp < output) {
            output = temp;
        }
    }
    printf("%d", output);
    return 0;
}

int af(int ta[], int tp[], int ts, int tsum, int tmin, int length) {
    if(ts == 0 || ts == length) {
        return tsum;
    }
    int max1 = ta[0];
    int imax1 = 0;
    int min2 = ta[length - 1];
    int imin2 = length - 1;
    for(int i=1; i<ts; i++) {
        if(ta[i] > max1) {
            max1 = ta[i];
            imax1 = i;
        }
    }
    for(int i=ts; i<=length-2; i++) {
        if(ta[i] < min2) {
            min2 = ta[i];
            imin2 = i;
        }
    }
    if(max1 < min2) {
        return tsum;
    }
    int count1 = 0;
    int count2 = 0;
    for(int i=0; i<=length-1; i++) {
        if(i<ts && ta[i] > min2) {
            count1 += 1;
        }
        if(i>=ts && ta[i] < max1) {
            count2 += 1;
        }
    }
    int count = count1 + count2 - 1;
    int ta1[count], tp1[count];
    int j = 0;
    for(int i=0; i<=length-1; i++) {
        if((i<ts && ta[i] > min2 && ta[i] < max1) || (i>=ts && ta[i] < max1)) {
            ta1[j] = ta[i];
            tp1[j] = tp[i];
            j += 1;
        }
    }
    int output1 = tmin;
    if(tsum + tp[imax1] < tmin) {
        output1 = af(ta1, tp1, count1 - 1, tsum + tp[imax1], tmin, count);
    }
    int ta2[count], tp2[count];
    j = 0;
    for(int i=0; i<=length-1; i++) {
        if((i<ts && ta[i] > min2) || (i>=ts && ta[i] < max1 && ta[i] > min2)) {
            ta2[j] = ta[i];
            tp2[j] = tp[i];
            j += 1;
        }
    }
    int output2 = tmin;
    if(tsum + tp[imin2] < tmin) {
        output2 = af(ta2, tp2, count1, tsum + tp[imin2], tmin, count);
    }
    return min(output1, output2);
}