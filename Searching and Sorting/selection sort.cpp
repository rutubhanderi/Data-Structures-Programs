#include<stdio.h>
int main()
{
	int arr[]={5,4,7,8,6};
	int n=5,flag,min_idx;
	for(int i=0;i<n-1;i++)
	{   
	    flag=0;
	    min_idx=i;
		for(int j=i+1;j<n;j++)
		{
			flag++;
			if(arr[j]<arr[min_idx])
			{
				
				int temp=arr[j];
				arr[j]=arr[min_idx];
				arr[min_idx]=temp;
				min_idx=j;
			}
			
		}
		if(flag==0)
		{
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
