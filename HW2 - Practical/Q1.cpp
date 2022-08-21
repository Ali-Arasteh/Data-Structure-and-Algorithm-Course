#include <iostream>
#include <iomanip>
#include <stdio.h>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);
    int ml[n][4], o[n];
    for(int i=0; i<n; i++) {
        scanf("%d %d %d %d", &ml[i][0], &ml[i][1], &ml[i][2], &ml[i][3]);
    }
    for(int i=0; i<n; i++) {
        double temp;
        for(int j=0; j<3; j++) {
            for(int k=0; k<3-j; k++) {
                if(ml[i][k] > ml[i][k+1]) {
                    temp = ml[i][k+1];
                    ml[i][k+1] = ml[i][k];
                    ml[i][k] = temp;
                }
            }
        }
    }
    for(int i=0; i<n; i++) {
        o[i] = ml[i][0] * ml[i][2];
        printf("%d\n", o[i]);
    }
    return 0;
}