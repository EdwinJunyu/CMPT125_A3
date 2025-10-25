#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment3.h"

// used for test Q1-find and Q1-count
bool is_even(int x) { return x%2 == 0; }
bool is_positive(int x) { return x>0; }

void test_q1_find()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (find(A, 6, is_even)==2 && find(A, 6, is_positive)==1) 
    printf("Q1-find ok\n");
  else
    printf("Q1-find ERROR\n");
}

void test_q1_count()  {
  int A[6] = {-1,3,-6,5,2,8};

  if (count(A, 6, is_even)==3 && count(A, 6, is_positive)==4) 
    printf("Q1-count ok\n");
  else
    printf("Q1-count ERROR\n");
}

// used for test Q1-map
int mult4(int x) { return x*4;}

void test_q1_map()  {
  int A[6] = {-1,3,-6,5,2,7};
  map(A, 6, mult4);

  if (A[0]==-4 && A[3]==20) 
    printf("Q1-map ok\n");
  else
    printf("Q1-map ERROR\n");
}

// used for test Q1-reduce
int sum(int x, int y) {return x+y;}
int last(int x, int y) {return y;}

void test_q1_reduce()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (reduce(A, 6, sum)==10 && reduce(A, 6, last)==7) 
    printf("Q1-reduce ok\n");
  else
    printf("Q1-reduce ERROR\n");
}


// used for test test_q2 for sorting in reverse order
int cmpr_ints_rev(const void* a, const void* b) {
  return *(const int*)b - *(const int*)a;
}

bool test_q2()  {
  int len = 6;
  int ar[6] = {7,3,5,1,11,9};
  
  // cmpr_ints_rev sorts the array in reverse order
  int swaps = gen_insertion_sort(ar, len, sizeof(int), cmpr_ints_rev);
  // 7 : [7,3,5,1,11,9]  0
  // 3 : [7,3,5,1,11,9]  0
  // 5 : [7,5,3,1,11,9] +1
  // 1 : [7,5,3,1,11,9]  0
  //11 : [11,7,5,3,1,9] +4
  //11 : [11,9,7,5,3,1] +4
  

  bool okFlag = true;
  for (int i=0;i<len;i++)
    if (ar[i] != 11-2*i)
      okFlag = false;


  if (okFlag && swaps==9) {
    printf("Q2 ok\n");
    return true;
  }
  else  {
    printf("Q2 ERROR\n");
    return false;
  }
}

bool test_q3_merge()  {
  int a[] = {2,4,7,1,2,3,5};
  merge(a,7,3);
  bool okFlag = true;

  int correct_ans[] = {1,2,2,3,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q3-merge ok\n");
    return true;
  }
  else  {
    printf("Q3-merge ERROR\n");
    return false;
  }
}


bool test_q3_merge_sort()  {
  int a[] = {4,1,2,7,5,3,2};
  merge_sort(a,7);
  bool okFlag = true;

  int correct_ans[] = {1,2,2,3,4,5,7};
  for (int i=0;i<7;i++)
    if (a[i]!=correct_ans[i])
      okFlag = false;

  if (okFlag)  {
    printf("Q3-merge sort ok\n");
    return true;
  }
  else  {
    printf("Q3-merge sort ERROR\n");
    return false;
  }
} 

bool test_q4_1() {
  const char* A[] = {"hello", "World", "1", "2", "12345678"};
  sort_strings(A, 5);
  const char* correct_ans[] = { "1", "2", "World", "hello", "12345678"};
  bool flag_ok = true;
  for (int i = 0; i < 5; i++) {
    if (strcmp(A[i], correct_ans[i]) != 0) {
      flag_ok = false;
      break;
    }
  }
  if (flag_ok) {
    printf("Q4-1 ok\n");
    return true;
  }
  else  {
    printf("Q4-1 ERROR\n");
    return false;
  }
}


bool test_q4_2() {
  const char* A[] = {"Wx", "ab", "Zde", "6_@7h", "7", "hij",  "_hh", "b"};
  sort_strings(A, 8);
  const char* correct_ans[] = {"7", "b", "Wx", "ab", "Zde", "_hh", "hij", "6_@7h"};
  bool flag_ok = true;
  for (size_t i = 0; i < 8; i++) {
    if (strcmp(A[i], correct_ans[i]) != 0) {
      flag_ok = false;
      break;
    }
  }
  if (flag_ok) {
    printf("Q4-2 ok\n");
    return true;
  }
  else  {
    printf("Q4-2 ERROR\n");
    return false;
  }
}

#define LEN 100000
bool test_q4_3() {
  char* A[LEN];
  for (int i = 0; i < LEN; i++)
  {
    A[i] = malloc(10);
    sprintf(A[i], "%d", LEN-1-i);
  }
  // create array ["9999","9998","9997",..."1","0"]
  char** correct_ans = (char**) malloc(LEN*sizeof(char*));
  for (int i = 0; i < LEN; i++)
  {
    correct_ans[i] = malloc(10);
    sprintf(correct_ans[i], "%d", i);
  }
  // create array ["0","1","2",...,"9997","9998","9999"]
  
  sort_strings((const char**) A, LEN);

  bool flag_ok = true;
  for (int i = 0; i < LEN; i++) {
    if (strcmp(A[i], correct_ans[i]) != 0) {
      flag_ok = false;
      break;
    }
  }
  if (flag_ok) {
    printf("Q4-3 ok\n");
    return true;
  }
  else  {
    printf("Q4-3 ERROR\n");
    return false;
  }
}


// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now
int main() {
  test_q1_find();
  test_q1_count();
  test_q1_map();
  test_q1_reduce();

  test_q2();

  test_q3_merge();
  test_q3_merge_sort();

  test_q4_1();
  test_q4_2();
  test_q4_3();
  
  return 0;
}
