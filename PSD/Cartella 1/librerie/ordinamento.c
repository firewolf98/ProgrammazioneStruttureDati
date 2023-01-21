#include <stdio.h>

void Insertionsort(int x[], int n) 
{
   int i, j, app;
 
   for (i = 1; i < n; i++)
   {
      app = x[i];
       
      for (j = i - 1; (j >= 0) && (x[j] > app); j--)
               x[j+1] = x[j];
       
      x[j + 1] = app;
   }
}

void Selectionsort(int a[], int N) {
  int i, j, min; 
  int t;

  for (i=0; i < N-1; i++) {
    min = i;
    for (j= i+1; j < N; j++) {
      if (a[j] < a[min]) {
      min = j;
      }
    }
      t = a[min];
      a[min] = a[i];
      a[i] = t;
  }
}

void Bubblesort(int *array, int elemN)
 {
   int i, tmp, ultimo;
   int alto=elemN; 
   ultimo=alto;
   
   while (alto >= 0) 
     { 
         ultimo = -1;
         for (i=0; i<alto-1; i++) 
         {
           if (array[i]>array[i+1])
           { 
             tmp = array[i]; 
             array[i] = array[i+1]; 
             array[i+1] = tmp;
             ultimo = i;
           } 
         }
     alto = ultimo;
     }
 }

