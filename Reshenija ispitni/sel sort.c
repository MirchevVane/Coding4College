#include <stdio.h>
void printarray(int *pInt, int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d ", *(pInt+i));
  }
}

void swap(int *a, int *b) {
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}

void selectionSort(int *niza, int n){
int i, j;
for(i=0;i<n;i++){ //go shifta pocetokot na sekoja podniza
  int min=niza[i];
  int minIndex=i;
  for(j=i+1;j<n;j++) {
    if(niza[j]<min) {
      min=niza[j];
      minIndex=j;
    }
    swap(niza+i, niza+minIndex);
  } //j=i+1 oti go razgleduva sekoj sleden element primer 1 3 9 2 8 6 kecot razgledan pa ide na 3kata itn itn.
  }
}

int main() {
int niza[]={2, 3, 1, 4, 7, 12, -5, 5, 6,  8, 9};
selectionSort(niza, 11);
printarray(niza, 11);

  return 0;
}