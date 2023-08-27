#include <stdio.h>
int search(int array[], int n, int x) 
{
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i;
  return -1;
}

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x,n = 5;
  printf("Enter the element to be found :");
  scanf("%d",&x);
  int result = search(array, n, x);
  if(result==-1)
   printf("Element not found");
  else
   printf("Element found at index: %d",result);
}