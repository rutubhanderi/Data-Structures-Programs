#include <stdio.h>
int binarySearch(int a[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (a[mid] == x)
      return mid;
    if (a[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return 1;
}

int main() {
  int a[] ={12,13,14,15,16,17,18,19};
  int n=8;
  int key;
  printf("Enter the element to be searched: ");
  scanf("%d",&key);
  int result = binarySearch(a, key, 0, n - 1);
  if (result == 1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}