//Q3. WAP to display the array elements in descending order.
#include <stdio.h>
void main ()
{
   int i, j, t, n;
   printf("enter number of elements in an array\n");
   scanf("%d", &n);
   int a[n];
   printf("Enter the elements\n");

   for (i = 0; i < n; ++i)
      scanf("%d", &a[i]);

   for (i = 0; i < n; ++i)
   {
      for (j = i + 1; j < n; ++j)
      {
         if (a[i] < a[j])
         {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
         }
      }
   }
   printf("The numbers in descending order is:\n");
   for (i = 0; i < n; ++i)
   printf("%d\t", a[i]);
   
}