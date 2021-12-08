#include <stdio.h>

void main()
{
 int a[100][100],b[100][100],i,j,m,n,k=1,l=1,c[100][3],d[100][3];
 printf("Enter the size of matrices:\n");
 scanf("%d",&m);
 scanf("%d",&n);
 
 printf("Enter the elements of matrix 1:\n");
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
    scanf("%d",&a[i][j]);
 
 printf("Enter the elements of matrix 2:\n");
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
    scanf("%d",&b[i][j]);
   
 for(i=0;i<m;i++)
  for(j=0;j<n;j++)
   {
    if(a[i][j]!=0)   
      {
       
       c[k][0]=i;
       c[k][1]=j;
       c[k][2]=a[i][j];
       k++;
       }
     if(b[i][j]!=0)   
      {
       
       d[l][0]=i;
       d[l][1]=j;
       d[l][2]=b[i][j];
       l++;
       }  
    }
  c[0][0]=m; c[0][1]=n; c[0][2]=k-1;
  d[0][0]=m; d[0][1]=n; d[0][2]=l-1;
    
  printf("SPARSE MATRIX 1:\n"); 
  for(i=0;i<k;i++)
  { for(j=0;j<3;j++)
     printf("%d ",c[i][j]);
    printf("\n"); 
  }
 
  printf("SPARSE MATRIX 2:\n");
  for(i=0;i<l;i++)
  { for(j=0;j<3;j++)
     printf("%d ",d[i][j]);
    printf("\n"); 
  }  
  
  int tran1[k][3],tran2[l][3],p=1,q=1;
  tran1[0][0]=c[0][1]; tran1[0][1]=c[0][0]; tran1[0][2]=c[0][2];
  tran2[0][0]=d[0][1]; tran2[0][1]=d[0][0]; tran2[0][2]=d[0][2];
  for(i=0;i<n;i++)
  {
   for(j=1;j<k;j++)
   {
    if(c[j][1]==i)
     {
      tran1[p][0]=c[j][1];
      tran1[p][1]=c[j][0];
      tran1[p][2]=c[j][2];
      p++;
     }
   }
  }
  
  for(i=0;i<n;i++)
  {
   for(j=1;j<l;j++)
   {
    if(d[j][1]==i)
     {
      tran2[q][0]=d[j][1];
      tran2[q][1]=d[j][0];
      tran2[q][2]=d[j][2];
      q++;
     }
   }
  }
  
  printf("TRANSPOSE MATRIX 1:\n"); 
  for(i=0;i<k;i++)
  { for(j=0;j<3;j++)
     printf("%d ",tran1[i][j]);
    printf("\n"); 
  }
 
  printf("TRANSPOSE MATRIX 2:\n");
  for(i=0;i<l;i++)
  { for(j=0;j<3;j++)
     printf("%d ",tran2[i][j]);
    printf("\n"); 
  }  
}
