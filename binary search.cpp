//Recursive
#include<stdio.h>
int binary_search(int a[],int l,int h,int mid,int element)
{
	if(h>=l)
	{
		mid=(l+h)/2;
		if(a[mid]==element)
		 return mid;
		if(a[mid]>element)
		 return binary_search(a,l=0,h=mid-1,mid,element);
		else
		 return binary_search(a,l=mid+1,h,mid,element);
	
	}
	return 1;
}
int main()
{
	int a[]={12,13,14,15,45,67,87,93};
	int l=0,h=8,mid,element;
	printf("Enter the element to be searched: ");
	scanf("%d",&element);
	
	int result=binary_search(a,l,h,mid,element);
	if(result==1)
	 printf("Element not found");
	else
	 printf("Element found at index %d ",result);
}
