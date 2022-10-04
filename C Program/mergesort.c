#include <stdio.h>
#define MAX 50
void merge(int *a,int,int,int);
void mergesort(int *a,int,int);
void printarray(int *a,int);
int main()
{
    int n,i,a[MAX];
    printf("Enter the number of elements you want: ");
    scanf("%d",&n);
    printf("The entered elements are: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergesort(a,0,n-1);
    printarray(a,n);  
}
void mergesort(int*a,int low,int high)
{
    if(low<high)
    {
        int mid;
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}
void merge(int *a,int mid,int low,int high)
{
    int i,j,k,b[MAX];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
        while(i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
        while(j<=high)
        {
            b[k]=a[j];
            j++;
            k++;
        }
        for(i=low;i<=high;i++)
        {
            a[i]=b[i];
        }
}
void printarray(int *a,int n)
{
    printf("The elements after sorting are:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}