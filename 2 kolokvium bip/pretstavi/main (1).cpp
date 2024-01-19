#include <cstdio>
#include "heder.h"
using namespace std;

int main() {
    int brPretstavi,i;
    float cena;
    char space[2];
    int den,mesec,godina;
    struct datumi denes;
    printf("Vnesi broj na pretstavi : ");
    scanf("%d",&brPretstavi);
    gets(space);
    for(i=0;i<brPretstavi;i++){
        printf("Ime na pretstava ");
        gets(pretstava[i].ime);
        printf("Pocnuva (yyyy/mm/dd/hh) ");
        scanf("%d %d %d %d",&pretstava[i].pocetok.godina,&pretstava[i].pocetok.mesec,&pretstava[i].pocetok.den,&pretstava[i].pocetok.saat);
        gets(space);
        pretstava[i].kraj.godina=pretstava[i].pocetok.godina;
        pretstava[i].kraj.mesec=pretstava[i].pocetok.mesec;
        pretstava[i].kraj.den=pretstava[i].pocetok.den+2;
        pretstava[i].kraj.saat=pretstava[i].pocetok.saat+4;
        printf("Cena na karta ");
        scanf("%f",&cena);
        scanf("%c");
        fillCards(pretstava[i],i,cena);
    }
    printf("Najdi pretstavi za odreden den (yyyy/mm/dd) ");
    scanf("%d %d %d",&godina,&mesec,&den);
    gets(space);
    denes.godina=godina;
    denes.mesec=mesec;
    denes.den=den;
    najdiPretstavi(denes,brPretstavi);
    return 0;
}
