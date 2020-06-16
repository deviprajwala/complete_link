#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//the program deals with the hierarchical clustering with the help of bottom up approach.The clustering method used here is complete link

float matrix[100][100];
void distance(float x[100],float y[100],int n);
float min(float a,float b);
void print_matrix(int n);
void min_of_matrix(int n);
void reduce(int a,int b,int n);
void cluster(int n);

void distance(float x[100],float y[100],int n)
//this function builds the distance matrix by calculating the distance between the points
{
 int i,j;
 float a;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
    a=((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]));
    a=sqrt(a);
    matrix[i][j]=a;
  }
 }
}

float max(float a,float b)
//this function is used to calculate the maximum value among the two values given
{
 if(a>b)
 {
  return a;
 }
 else
 {
  return b;
 }
}


void print_matrix(int n)
//this function is used to print  the matrix given the dimension as an argument
{
 int i,j;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
    printf("%.2f ",matrix[i][j]);
  }
  printf("\n");
 }
}

void max_of_matrix(int n)
//This function is used to get the maximum distance from the distance matrix and then the two points with most distance is sent as an argument to the function named reduce.
{
 int i,j,max_i,max_j;
 float max;
 max=0.000;
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(matrix[i][j]<max && matrix[i][j]!=0)
   {
    max=matrix[i][j];
    //here we find the maximum value and assign thier values to the variables defined below which is futher needed for the calculation.
    max_i=i;
    max_j=j;
   }
  }
 }
 printf("\n\nThe rows %d %d  from above matrix are clustered\n",max_i,max_j);
 reduce(max_i,max_j,n);
}

void reduce(int a,int b,int n)
//here we reduce the dimention of the matrix by merging the values with least distance
{
  int i,j;
  for(i=1;i<=n;i++)
  {
  for(j=1;j<=n;j++)
   {
     if(i==a&&j==b||i==b&&j==a)
     {
       //the values are not changed for above condition
     }
     else if(i==a||i==b)
     {
       matrix[i][j]=max(matrix[a][j],matrix[b][j]);
     }
     else if(j==a||j==b)
     {
       matrix[i][j]=max(matrix[i][a],matrix[i][b]);
     }
   }
  }
}

void cluster(int n)
//this function we call recusively until the dimention of the matrix reduces to one
{
 if (n==1)
 {
  return;
 }
 else
 {
  min_of_matrix(n);
  //minimum distance of the matrix is calculated
  n--;
  //value of n is decremented
  print_matrix(n);
  //reduced matrix is printed
  cluster(n);
  //cluster function is called recusively
 }
}
int main()
{

int i,j,dim;
float x[100],y[100];
//declaring the variables required

//printf("Enter the number of data points:");
scanf("%d",&dim);

//printf("Enter the cordinates\n");

for(i=1;i<=dim;i++)
{
// printf("x:");
 scanf("%f",&x[i]);
// printf("y:");
 scanf("%f",&y[i]);
 //printf("hi");
}
//getting the input from the user for further calculation

distance(x,y,dim);
//the distance matrix is generated
printf("The distance matrix obtained is\n");
print_matrix(dim);
cluster(dim);
return 0;
}
