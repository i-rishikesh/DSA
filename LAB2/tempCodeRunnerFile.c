/*6. Given an unsorted array arr and two numbers x and y, find the minimum
distance between x and y in arr. The array might also contain duplicates. Youmay assume that both x and y are different and present in arr. Input: arr[] ={3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, x = 3, y = 6 Output: Minimum distance
between 3 and 6 is 4.*/
#include <stdio.h>
void minDistance(int *Arr, int n, int x, int y)
{
int distance[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, a = 0, s = 0;
;
for (int i = 0; i <= n; i++)
{
if ((Arr[i] == x || Arr[i] == y) && s == 0)
{
if (Arr[i] == x)
{
s = 1;
// printf("Start by %d",Arr[i]);
}
else if (Arr[i] == y)
{
s = 2;
// printf("Start by %d\n",Arr[i]);
}
}
else if (s == 1 && Arr[i] == y)
{
s = 0;
a++;
// printf("end by %d\n",Arr[i]);
}
else if (s == 2 && Arr[i] == x)
{
s = 0;
a++;
// printf("end by %d\n",Arr[i]);
}
if (s != 0)
distance[a]++;
}
int min = distance[0];
for (int i = 0; i < n; i++)
{
if (distance[i] <= min && distance[i] != 0)
min = distance[i];
}
printf("Min Distance between %d and %d is %d\n", x, y, min);
}
int main()
{
int Arr[50] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3}, n = 12, a, b;
// limit from a to b.
a = 3;
b = 6;
minDistance(Arr, n, a, b);
return 0;
}