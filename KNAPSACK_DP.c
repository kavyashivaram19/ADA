#include <stdio.h>

void knapsack(int n, int m, int w[], int p[]) {
    int table[10][10];
    int x[10];
    for(int i = 0; i <= n; i++)
    {
        table[i][0]=0;

    }
    for(int j = 0; j<= m; j++)
    {
        table[0][j]=0;

    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(w[i] > j)
                table[i][j] = table[i-1][j];
            else {

                if(p[i] + table[i-1][j - w[i]] > table[i-1][j])
                    table[i][j] = p[i] + table[i-1][j - w[i]];
                else
                    table[i][j] = table[i-1][j];
            }
        }
    }
    int i = n, j = m;

    while(i > 0 && j > 0) {
        if(table[i][j] != table[i-1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else{
            x[i]=0;
        }
        i--;
    }

    printf("\nMaximum Profit = %d\n", table[n][m]);

    printf("Selected items:");
    for(int i = 1; i <= n; i++)
        printf("%d ", x[i]);

    printf("\n");
}

int main() {
    int n, m,w[10],p[10];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights and profit of each items:\n");
    for(int i = 1; i <= n; i++)
        scanf("%d %d",&w[i],&p[i]);

    printf("Enter capacity: ");
    scanf("%d", &m);

    knapsack(n, m, w, p);

    return 0;
}
