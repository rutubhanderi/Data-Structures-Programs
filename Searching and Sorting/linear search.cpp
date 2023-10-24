//Linear search
#include<stdio.h>
int main()
{
	int a[]={11,22,33,44,55,66,77,88};
	int key,i,counter=0;
	printf("Enter element to be searched:");
	scanf("%d",&key);
	for(i=0;i<8;i++)
	{
		if(a[i]==key)
	    {  
		  counter=0;
	      break;
	    }
		else
	      counter++;
    }
    if(counter==0)
      printf("Element %d found at  %d",key,i+1);
    else
      printf("Element not found");
    return 0;
}
