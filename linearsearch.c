#include <stdio.h>
void main()
{
 int n,i,ar[50],k,f=0;
 printf("Enter the size of the array\n");
  scanf("%d",&n);
 printf("Enter the array elements\n");
  for(i=0;i<n;i++)
   scanf("%d",&ar[i]);
 printf("Enter the element to be searched\n");
  scanf("%d",&k);
 for(i=0;i<n;i++)
  {
   if(ar[i]==k)
    {
     f=1;
     break;
    }
  }
  if(f==1)
   printf("%d is present at position %d\n",k,(i+1));
  else
   printf("%d is not present\n",k);
} 
 
