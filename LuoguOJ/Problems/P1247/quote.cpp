#include <cstdio>

int n;
int a[500005];

int main()
{
    scanf("%d",&n);
    int check=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        check^=a[i];
    }
    if(!check)
    {
        printf("lose\n");
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if((check^a[i])<a[i])
        {
            printf("%d %d\n",a[i]-(check^a[i]),i);
            for(int j=1; j<=n; j++)
                if(j!=i)
                    printf("%d ",a[j]);
                else    printf("%d ",check^a[i]);
            break;
        }
    }
    return 0;
}