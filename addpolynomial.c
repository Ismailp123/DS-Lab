#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
typedef struct
{
 int expon;
 float coeff;
}polynomial;
polynomial terms[MAX_TERMS];
int avail=0;
int COMPARE(int a,int b)
{
 if(a>b)
  return 1;
 else if(a<b)
  return -1;
 else
  return 0;
 }

void attach(float coefficient,int exponent)
{
 /*if(avail<=MAX_TERMS)
  {
   fprintf(stderr,"Too many terms");
   exit(0);
  }*/
  terms[avail].coeff=coefficient;
  terms[avail++].expon=exponent;
 }  
  
void padd(int startA,int finishA,int startB,int finishB,int startD,int finishD)
 {
  float coefficient;
  
  while(startA<=finishA && startB<=finishB)
  {
   switch(COMPARE(terms[startA].expon,terms[startB].expon))
   {
    case 1 : attach(terms[startA].coeff,terms[startA].expon);
             startA++;
             break;
    case -1: attach(terms[startB].coeff,terms[startB].expon);
             startB++;
             break;
    case 0 : coefficient=terms[startA].coeff+terms[startB].coeff;
             if(coefficient)
             attach(coefficient,terms[startA].expon);
             startA++;
             startB++;
             break;
   }
  }
  for(;startA<=finishA;startA++)
   attach(terms[startA].coeff,terms[startA].expon);
  for(;startB<=finishB;startB++)
   attach(terms[startB].coeff,terms[startB].expon);
  
 }
 
 void input()
 {
  int n,i,exp;
  float coef;
  printf("Enter the no of terms\n");
  scanf("%d",&n);
  printf("Enter the coefficients and exponents\n");
  for(i=0;i<n;i++)
  {
   scanf("%f",&coef);
   scanf("%d",&exp);
   attach(coef,exp);
  }
 }
 
 void display(int f,int l)
 {
  int i;
  for(i=f;i<=l;i++)
  {
   if(i==l)
    printf("%.1fx^%d ",terms[i].coeff,terms[i].expon);
   else
    printf("%.1fx^%d + ",terms[i].coeff,terms[i].expon);
   }
   
  printf("\n");
 }
void main()
 {
  int startA,finishA,startB,finishB,startD,finishD;
  int i;
  printf("1st polynomial:\n");
  startA=avail;
  input();
  finishA=avail-1;
  
  printf("2nd polynomial:\n");
  startB=avail;
  input();
  finishB=avail-1;
  
  startD=avail;
  padd(startA,finishA,startB,finishB,startD,finishD);
  finishD=avail-1;
  
  printf("1st polynomial:\n");
    display(startA,finishA);
    
    printf("2nd polynomial:\n");
    display(startB,finishB);
   
   printf("SUM:\n");
    display(startD,finishD);
 }
               
