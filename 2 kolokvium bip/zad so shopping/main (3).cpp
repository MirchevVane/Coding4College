#include <cstdio>
#include "SCF.h"
using namespace std;

int main() {
    struct proizvod proizvodi[100];
    char ime[30],ulica[20],enter[40];
    int brP,total=0;
    int noviCeni[100];

    printf("Vnesi ime na shoping centar : ");
    gets(ime);
    printf("Vnesi ulica :");
    gets(ulica);
    printf("Vnesi broj na proizvodi : ");
    scanf("%d",&brP);
    gets(enter);
    for(int i=0;i<brP;i++){
        printf("Vnesi ime na proizvod : ");
        gets(proizvodi[i].name);
        printf("Vnesi tip na proizvod : ");
        gets(proizvodi[i].type);
        printf("Vnesi cena : ");
        scanf("%d",&proizvodi[i].price);
        printf("Vnesi gramaza : ");
        scanf("%f",&proizvodi[i].size);
        gets(enter);
        printf("Vnesi zemja na poteklo : ");
        gets(proizvodi[i].countryOfOrigin);
        printf("Vnesi mesec i godina na proizvodstvo : ");
        scanf("%d %d",&proizvodi[i].produced.month,&proizvodi[i].produced.year);
        printf("Vnesi nova cena na proizvod : ");
        scanf("%d",&noviCeni[i]);
        gets(enter);
    }
    ShoppingCenter VaneMall(ime,ulica,proizvodi,brP,noviCeni);

    for(int i=0;i<VaneMall.getNumOfItems();i++){
        total+=VaneMall.razlika(i);
    }
    printf("Totalna razlika na starite i novite ceni : %d",total);
    return 0;
}