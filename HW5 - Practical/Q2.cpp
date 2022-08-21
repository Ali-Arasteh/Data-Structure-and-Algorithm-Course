#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int main() 
{
    int n;
    scanf("%d", &n);
    double values[n];
    for (int i=0; i<n; i++) {
        scanf("%lf ", &values[i]);
    }
    string word;    
    string words[n];
    for (int i=0; i<n; i++) {
        getline(cin, word);
        words[i] = word;
    }
    const int MAXS = 500 + 1;
    const int MAXC = 62 + 1;
    int g[MAXS][MAXC];
    int o[MAXS][n];
    int f[MAXS];
    memset(g, -1, sizeof g);
    memset(o, 0, sizeof o);
    int states = 1;
    for (int i=0; i<n; i++)
    {
        const string &word = words[i];
        int currentState = 0;
        for (int j=0; j<word.length(); j++)
        {
            int ch;
            if (word[j] == ' ') {
                ch = 62;
            }
            else if (word[j] >= '0' && word[j] <= '9') {
                ch = 52 + word[j] - '0';
            }
            else {
                ch = word[j] - 'A';
                if (ch > 25) {
                    ch -= 6;
                }
            }
            if (g[currentState][ch] == -1) {
                g[currentState][ch] = states;
                states += 1;
            }
            currentState = g[currentState][ch];
        }
        o[currentState][i] = 1;
    }
    for (int ch=0; ch<MAXC; ch++) {
        if (g[0][ch] == -1) {
            g[0][ch] = 0;
        }
    }
    memset(f, -1, sizeof f);
    queue<int> q;
    for (int ch=0; ch<MAXC; ch++) {
        if (g[0][ch] != 0) {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }
    while (q.size()) {
        int state = q.front();
        q.pop();
        for (int ch=0; ch<MAXC; ch++) {
            if (g[state][ch] != -1) {
                int failure = f[state];
                while (g[failure][ch] == -1) {
                    failure = f[failure];
                }
                failure = g[failure][ch];
                f[g[state][ch]] = failure;
                for (int i=0; i<n; i++) {
                   if (o[g[state][ch]][i] == 0) {
                       o[g[state][ch]][i] = o[failure][i];
                   }
                }
                q.push(g[state][ch]);
            }
        }
    }
    int sum = 0;
    int G[states][states];
    double E[states][states];
    memset(G, 0, sizeof G);
    memset(E, 0, sizeof E);
    for (int i=0; i<states; i++) {
        for (int ch=0; ch<MAXC; ch++) {
            int answer = i;        
            while (g[answer][ch] == -1) {
                answer = f[answer];
            }
            if (G[i][g[answer][ch]] == 0) {
                sum += 1;
                G[i][g[answer][ch]] = 1;
                for (int j=0; j<n; j++) {
                    E[i][g[answer][ch]] += values[j]*o[g[answer][ch]][j];
                }
            }
        }
    }
    int Edges[sum][2];
    int count = 0;
    for (int i=0; i<states; i++) {
        for (int j=0; j<states; j++) {
            if (G[i][j] == 1) {
                Edges[count][0] = i;
                Edges[count][1] = j;
                count += 1;
            }
        }
    }
    double start = 0;
    double end = 0;    
    for (int i=0; i<n; i++) {
        end += values[i];
    }
    int flag;
    double middle;
    double E_prime[states][states];    
    double dist[states];
    bool temp_dist[states];
    int temp1;
    int temp2;
    while (end - start > pow(10, -6)) {
        flag = 0;
        middle = (start + end) / 2;
        memset(dist, 0, sizeof dist);
        memset(temp_dist, false, sizeof temp_dist);
        temp_dist[0] = true;
        for (int i=0; i<states; i++) {
            if (G[i][i] == 1 && E[i][i] > middle) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            start = middle;
            continue;
        }
        for (int i=0; i<states; i++) {
            for (int j=0; j<states; j++) {
                E_prime[i][j] = middle - E[i][j];
            }
        }
        for (int i=1; i<states; i++) {
            for (int j=0; j<sum; j++) {
                temp1 = Edges[j][0];
                temp2 = Edges[j][1];
                if (temp_dist[temp1]) {
                    if (temp_dist[temp2]) {
                        if (dist[temp1] + E_prime[temp1][temp2] < dist[temp2]) {
                            dist[temp2] = dist[temp1] + E_prime[temp1][temp2];
                        }
                    }
                    else {
                        temp_dist[temp2] = true;
                        dist[temp2] = dist[temp1] + E_prime[temp1][temp2];
                    }
                }
            } 
        }
        for (int i=0; i<sum; i++) {
            temp1 = Edges[i][0];
            temp2 = Edges[i][1];
            if (temp_dist[temp1]) {
                if (temp_dist[temp2]) {
                    if (dist[temp1] + E_prime[temp1][temp2] < dist[temp2]) {
                        flag = 1;
                        break;
                    }
                }
                else {
                    flag = 1;
                    break;
                }
            }
        } 
        if (flag == 1) {
            start = middle;
        }
        else {
            end = middle;
        }
    } 
    printf("%.6lf", (start + end) / 2);
    return 0;
}