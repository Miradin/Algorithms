//
// An example of how to generate permutations
// using Heap's algorithm
//
#include <stdio.h>

// an array of stuff to permute
const int N = 4;
char A[N+1] = "abcd"; 

void print() {
  for(int i=0; i<N; i++)
    printf("%c ", A[i]);
  printf("\n");
}

int main(int argc, char * argv[])
{
  // make an idx array filled with zero
  int idx[N];
  for(int i=0; i < N; i++)
    idx[i] = 0;

  print();

  // heap's algorithm, iterative version
  for (int i=1; i < N;) {
    if (idx[i] < i) {
      int swap = i % 2 * idx[i];
      int tmp = A[swap];
      A[swap] = A[i];
      A[i] = tmp;
      print();
      idx[i]++;
      i = 1;
    } else {
      idx[i++] = 0;
    }
  }
  return 0;
}
