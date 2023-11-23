#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int main(){
  
  int n = 500;
  double a[n][n], b[n][n], c[n][n];
  int i, j, k;
  
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      a[i][j] = 1.;
  
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      b[i][j] = 2.;
  
  for(i = 0; i < n; ++i)
    for(j = 0; j < n; ++j)
      c[i][j]=0;

  //block multiply matrices
  int B = 0;
  printf("Entrer blocsize : ");
  scanf("%d", &B);

   double start = (double)clock() /(double) CLOCKS_PER_SEC;
  
  double s = 0;
  for (int kk = 0; kk < n ; kk+=B)
    for (int jj = 0; jj < n ; jj+=B)
      for (int i = 0; i < n ; i++)
	for (int j = jj; j < jj + B; j++)
	  {
	    s = c[i][j];
	    for (int k = kk; k <kk + B; k++)
	      s += a[i][k] * b[k][j];
	    c[i][j] = s;
	  }

  double end = (double)clock() / (double) CLOCKS_PER_SEC;
  double msec =  (end - start) * 1000.;
  
  double rate = sizeof(double) * (2*n*n) * (1000.0 / msec) / (1024*1024);
  printf("cpu time %fs , rate %f\n",msec, rate);
  
  return 0;
}
