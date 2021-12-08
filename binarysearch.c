#include <stdio.h>
void main()
{
 int n,i,ar[50],k,f,l,mid,flag=0;
 printf("Enter the size of the array\n");
  scanf("%d",&n);
 printf("Enter the sorted array\n");
  for(i=0;i<n;i++)
   scanf("%d",&ar[i]);
 printf("Enter the element to be searched\n");
  scanf("%d",&k);
 f=0;
 l=n-1;
 while(f<=l)
  {
   mid=(f+l)/2;
   if(ar[mid]==k)
    {
     flag=1;
     printf("%d is present at position %d\n",k,(mid+1));
     break;
    }
   else if(ar[mid]<k)
    {
     f=mid+1;
    }
   else if(ar[mid]>k)
    {
     l=mid-1;
    }
   }
 if(flag==0)
  printf("%d is not present\n",k);
}
