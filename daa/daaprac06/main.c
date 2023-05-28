#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int val;
    char dir;
};
int max(int a, int b);
void print_lcs(int n, char X[], struct node c[][n], int i, int j);
void lcs( char *X, char *Y, int m, int n )
{
struct node n1[m][n];
for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
       if (X[i]== 0 || Y[j] == 0){
        n1[i][j].val = 0;
        n1[i][j].dir = 'h';
       }
       else{
        if (X[i] !=Y[j]){
           n1[i][j].val = max(n1[i-1][j].val, n1[i][j-1].val);
           if(n1[i-1][j].val > n1[i][j-1].val)
              n1[i][j].dir = 'u';
           else
              n1[i][j].dir = 's';
        }
        else
         n1[i][j].val = n1[i-1][j-1].val + 1;
         n1[i][j].dir = 'd';
       }
    }
}
print_lcs(23,X,n1,m,n);

}
void print_lcs(int n, char X[], struct node c[][n], int i, int j){
  if( i == 0 || j == 0)
    return;
  if(c[i][j].dir == 'd'){
    print_lcs(n,X,c,i-1,j-1);
    printf("%c",X[i]);
  }
  else{
    if(c[i][j].dir == 'u')
    print_lcs(n,X,c,i-1,j);
    else
    print_lcs(n,X,c,i,j-1);
  }
  
}
int max(int a, int b)
{
	return (a > b)? a : b;
}

int main()
{
char X[] = "0AGCCCTAAGGGCTACCTAGCTT";
char Y[] = "0GACAGCCTACAAGCGTTAGCTTG";
int m = strlen(X);
int n = strlen(Y);
struct node *c;
printf("The first string is: %s\n",X);
printf("The second string is: %s\n",Y);
printf("The longest common subsequence is:\n");
lcs( X, Y, m, n );

return 0;
}

