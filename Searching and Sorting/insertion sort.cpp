#include<stdio.h>
void insertion(int a[],int size)
{
	for(int i=1;i<size;i++)
	{
		int key=a[i];
		int j=i-1;
		while(j>=0 && key<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}
int main()
{
	int a[]={8,2,4,9,3};
	int size=sizeof(a)/sizeof(a[0]);
	insertion(a,size);
	for(int i=0;i<size;i++)
	{
		printf("%d",a[i]);
		printf(" ");
	}
}
