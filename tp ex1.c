#include <stdio.h>
int main(){
int n,i,j,t;
int m[100][100];
printf("donner n");
scanf("%d",&n);
for(i=0;i<n;i++){
for(j=0;i<n;i++){
scanf("%d",&m[i][j]);}
}
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
t=m[i][j];
m[i][j]=m[j][i];
m[j][i]=t;}
}
for(i=0;i<n;i++){
for(j=0;j<n;j++){
printf("%4d",m[i][j])
  printf("/n");}
}
return 0;}
