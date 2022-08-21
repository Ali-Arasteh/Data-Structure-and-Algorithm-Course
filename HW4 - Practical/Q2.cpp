#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() 
{
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    long int tree[4][n+q];
    for (int i=0; i<n+q; i++) {
        scanf("%lld", &tree[0][i]);
    }
    if (n == 0) {
        printf("%lld\n", 0);
    }
    int temp;
    int layer;
    int flag;
    long long int sum;
    for (int i=0; i<n+q; i++) {
        if (i == 0) {
            tree[1][i] = -1;
            tree[2][i] = -1;
            tree[3][i] = 0;
        }
        else {
            temp = 0;
            layer = 0;
            flag = 1;
            while (flag == 1) {
                layer += 1;
                if (tree[0][i] < tree[0][temp]) {
                    if (tree[1][temp] != -1) {
                        temp = tree[1][temp];
                    }
                    else {
                        tree[1][temp] = i;
                        tree[1][i] = -1;
                        tree[2][i] = -1;
                        tree[3][i] = layer;
                        flag = 0;
                    }
                }
                else if (tree[0][i] > tree[0][temp]) {
                    if (tree[2][temp] != -1) {
                        temp = tree[2][temp];
                    }
                    else {
                        tree[2][temp] = i;
                        tree[1][i] = -1;
                        tree[2][i] = -1;
                        tree[3][i] = layer;
                        flag = 0;
                    }
                }
                else {
                    tree[1][i] = tree[1][temp];
                    tree[2][i] = tree[2][temp];
                    tree[3][i] = tree[3][temp];
                    flag = 0;
                }
            }
        }
        if (i >= n-1) {
            layer = 0;
            for (int j=0; j<=i; j++) {
                if (tree[3][j] > layer) {
                    layer = tree[3][j];
                }
            }
            long int left[layer+1];
            for (int j=0; j<=layer; j++) {
                left[j] = -1;
                left[j] = -1;
            }
            for (int j=0; j<=i; j++) {
                if (left[tree[3][j]] == -1) {
                    left[tree[3][j]] = tree[0][j];
                }
                else {
                    if (tree[0][j] < left[tree[3][j]]) {
                        left[tree[3][j]] = tree[0][j];
                    }
                }
            }
            sum = 0;
            for (int j=0; j<=layer; j++) {
                sum += left[j];
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}