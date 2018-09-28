#include<cstdio>
#include <cstdlib>
#include<algorithm>
using namespace std;
int v[100],n;
int partitie(int v[], int l, int h)
{
    int pivot = v[h];
    int i=l-1;
    for (int  j=l;j<=h-1;j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1],v[h]);
    return i+1;
}
int partitie_r(int v[],int l,int h)
{
    int random=l+rand()%(h-l);
    swap(v[random], v[h]);
    return partitie(v, l, h);
}
void qsort(int v[],int l, int h)
{
    if(l<h)
    {
        int pi=partitie_r(v,l,h);
        qsort(v,l,pi-1);
        qsort(v,pi+1,h);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&v[i]);
    qsort(v,0,n-1);
    for(int i=0;i<n;i++)printf("%d ",v[i]);
    return 0;
}
