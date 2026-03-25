#include<stdio.h>

int main()
{
    int c, n, i, j, temp,w[35], p[35];
    float r[35],tp=0;

    printf("Enter the no. of items: ");
    scanf("%f", &n);

    printf("Enter the capacity: ");
    scanf("%f", &c);
    printf("Enter weights items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&w[i]);
    }
    printf("Enter profit items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }

    for(i = 0; i < n; i++)
    {
        r[i] = p[i] / w[i];
    }
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(r[i] < r[j])
            {
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;

                temp = w[i]; w[i] = w[j]; w[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(w[i] <= c)
        {
            tp = tp + p[i];
            c = c - w[i];
        }
        else
        {
            tp = tp + (r[i] * c);
            break;
        }
    }

    printf("\nMax profit is %f", tp);

    return 0;
}
