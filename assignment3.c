#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment3.h"

/* Question 1 */

int find(int* A, int n, bool (*pred)(int)) {
  // implement me
  for (int i = 0; i < n; i++)
  {
    if (pred(A[i]))
    {
      return i;
    } 
  }
  return -1;    
}

int count(int* A, int n, bool (*pred)(int)) {
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (pred(A[i]))
    {
      cnt++;
    }
  }
  return cnt;    
}

void map(int* A, int n, int (*f)(int)) {
  for (int i = 0; i < n; i++)
  {
    A[i] = f(A[i]);
  }
}

int reduce(int* A, int n, int (*f)(int,int)) {
  int acc = A[0];
  for (int i = 1; i < n; i++)
  {
    acc = f(acc,A[i]); 
  }
  return acc;    
}

/* Question 2 */

int gen_insertion_sort(void* ar, int n, size_t size, int (*compare)(const void*, const void*)) {
  char* arr = (char*)ar;
  void* key = malloc(size);
  int swaps = 0;
  for (int i = 1; i < n; i++){
    memcpy(key, arr + i * size, size);
    int j = i - 1;
    while (j >= 0 && compare(arr + j * size, key) > 0)
    {
      memcpy(arr + (j+1)* size, arr + j * size, size);
      swaps++;
      j--;
    }
    memcpy(arr+(j+1)*size,key,size);
  }
  free(key);
  return swaps;    
}


/* Question 3 */

void merge(int* ar, int n, int mid) {
  int* temp = (int*)malloc(n*sizeof(int));
  int i = 0;
  int j = mid;
  int k = 0;
  while(i<mid && j < n){
    if (ar[i]<=ar[j])
    {
      temp[k++] = ar[i++];
    }else{
      temp[k++] = ar[j++];
    } 
  }
  while(i<mid){
    temp[k++] = ar[i++];
  }

  while (j<n)
  {
    temp[k++] = ar[j++];
  }
  for (int i = 0; i < n; i++)
  {
    ar[i] = temp[i];
  }
  free(temp);
}


void merge_sort(int* ar, int n) {
  if (n <= 1) return;
    int mid = n / 2;

    merge_sort(ar, mid);
    merge_sort(ar + mid, n - mid);
    merge(ar, n, mid);
} 

/* Question 4 */
int compare(const void* a, const void* b) {  //helper function
    const char* s1 = *(const char**)a;
    const char* s2 = *(const char**)b;

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    if (len1 < len2)
        return -1;
    else if (len1 > len2)
        return 1;
    else
        return strcmp(s1, s2);
}

void sort_strings(const char* A[], int n) {
  qsort(A, n, sizeof(char*), compare);
}

