#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() 
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int numbers[n][m];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d", &numbers[i][j]);
        }
    }
    int matrix[n][m/2+1][m][k];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m/2+1; j++) {
            for (int p=0; p<m; p++) {
                for (int q=0; q<k; q++) {
                    if (j == 0) {
                        if (q == 0) {
                            matrix[i][j][p][q] = 0;
                        }
                        else {
                            matrix[i][j][p][q] = -1;
                        }
                    }
                    else {
                        if (p == 0) {
                            int temp = numbers[i][p] % k;
                            if (q == temp) {
                                matrix[i][j][p][q] = numbers[i][p];
                            }
                            else if (q == 0) {
                                matrix[i][j][p][q] = 0;
                            }
                            else {
                                matrix[i][j][p][q] = -1;
                            }
                        }
                        else {
                            int temp = ((-1)*(numbers[i][p]-q)) % k;
                            if (temp < 0) {
                                temp += k;
                            }
                            if (matrix[i][j-1][p-1][temp] >= 0) {
                                matrix[i][j][p][q] = matrix[i][j-1][p-1][temp]+numbers[i][p];
                            }
                            else {
                                matrix[i][j][p][q] = -1; 
                            }
                            if (matrix[i][j-1][p][q] > matrix[i][j][p][q]) {
                                matrix[i][j][p][q] = matrix[i][j-1][p][q];
                            }
                            if (matrix[i][j][p-1][q] > matrix[i][j][p][q]) {
                                matrix[i][j][p][q] = matrix[i][j][p-1][q];
                            }
                        }
                    }
                }
            }
        }
    }
    int maximums[n][k];
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            if (i == 0) {
                maximums[i][j] = matrix[i][m/2][m-1][j];
            }
            else {
                maximums[i][j] = -1;
                for (int p=0; p<k; p++) {
                    int temp_mat = (j+p)%k;
                    int temp_max = ((-1)*(j+p))%k+j;
                    if (temp_max < 0) {
                        temp_max += k;
                    }
                    if (matrix[i][m/2][m-1][temp_mat] != -1 && maximums[i-1][temp_max] != -1) {
                        if (matrix[i][m/2][m-1][temp_mat]+maximums[i-1][temp_max] > maximums[i][j]) {
                            maximums[i][j] = matrix[i][m/2][m-1][temp_mat]+maximums[i-1][temp_max];
                        }
                    }
                }
            }
        }
    }
    printf("%d", maximums[n-1][0]);
    return 0;
}