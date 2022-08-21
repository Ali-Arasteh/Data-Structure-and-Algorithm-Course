#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);
    long long int list[n];
    for (int i=0; i<n; i++) {
        scanf("%lld", &list[i]);
    }
    long long int temp;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (list[j] > list[j+1]) {
                temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
            }
        }
    }
    int m;
    scanf("%d", &m);
    long long int question[n];
    for (int i=0; i<m; i++) {
        scanf("%lld", &question[i]);
    }
    int flag;
    int temp1, temp2;
    for (int i=0; i<m; i++) {
        flag = 0;
        for (int j=0; j<n; j++) {
            temp1 = j+1;
            temp2 = n-1;
            for (int k=0; k<n-1-j-1; k++) {
                if (list[j]+list[temp1]+list[temp2] < question[i]) {
                    temp1 += 1;
                }
                else if (list[j]+list[temp1]+list[temp2] > question[i]) {
                    temp2 -= 1;
                }
                else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) {
                break;
            }
        }
        if (flag == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}