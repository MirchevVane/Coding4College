#include <cstdio>
#define brojKarti 100
using namespace std;


struct datumi{
    int den;
    int mesec;
    int godina;
    int saat;
};

struct karti {
    struct datumi datum;
    int sediste;
    float cena;
    bool rezervirana;

    bool validnost(struct datumi momentalen) {
        if(datum.godina>momentalen.godina){
            if(datum.mesec>momentalen.godina){
                if(datum.den>momentalen.den){
                    if(datum.saat>momentalen.saat){
                        return true;
                    }
                }
            }
        }
        return false;
    }

};

struct pretstavi{
    char ime[50];
    struct karti karta[150];
    struct datumi pocetok;
    struct datumi kraj;

    void slobodniKarti(){
        int check=0;
        for(int i=0;i<brojKarti;i++){
            if(!karta[i].rezervirana){
                check++;
            }
        }
        if(!check){
            printf("Nema slobodni karti\n");
        }else{
            printf("Ima %d slobodni karti\n",check);
        }
    }
}pretstava[69];

void najdiPretstavi(struct datumi denes,int brojPretstavi){
    for(int i=0;i<brojPretstavi;i++){
        if(denes.godina== pretstava[i].pocetok.godina){
            if(denes.mesec==pretstava[i].pocetok.mesec){
                if(denes.den==pretstava[i].pocetok.den){
                    printf("%s  - 1vi den %d casot %.2f denari karta\n",pretstava[i].ime,pretstava[i].pocetok.saat,pretstava[i].karta[0].cena);
                }else if(denes.den==pretstava[i].pocetok.den+1){
                    printf("%s  - 2ri den %d casot %.2f denari karta\n",pretstava[i].ime,pretstava[i].pocetok.saat,pretstava[i].karta[0].cena);
                }else if(denes.den==pretstava[i].pocetok.den+2){
                    printf("%s  - 3ti den %d casot %.2f denari karta\n",pretstava[i].ime,pretstava[i].pocetok.saat,pretstava[i].karta[0].cena);
                }
            }
        }
    }
}

void fillCards(struct pretstavi momentalna, int index,float cena){
    int i;
    for(i=0;i<50;i++){
        pretstava[index].karta[i].sediste=i+1;
        pretstava[index].karta[i].rezervirana=false;
        pretstava[index].karta[i].cena=cena;
        pretstava[index].karta[i].datum.godina=momentalna.pocetok.godina;
        pretstava[index].karta[i].datum.mesec=momentalna.pocetok.mesec;
        pretstava[index].karta[i].datum.den=momentalna.pocetok.den;
        pretstava[index].karta[i].datum.saat=momentalna.pocetok.saat;

        pretstava[index].karta[i+50].sediste=i+1;
        pretstava[index].karta[i+50].rezervirana=false;
        pretstava[index].karta[i+50].cena=cena;
        pretstava[index].karta[i+50].datum.godina=momentalna.pocetok.godina;
        pretstava[index].karta[i+50].datum.mesec=momentalna.pocetok.mesec;
        pretstava[index].karta[i+50].datum.den=momentalna.pocetok.den+1;
        pretstava[index].karta[i+50].datum.saat=momentalna.pocetok.saat;

        pretstava[index].karta[i+100].sediste=i+1;
        pretstava[index].karta[i+100].rezervirana=false;
        pretstava[index].karta[i+100].cena=cena;
        pretstava[index].karta[i+100].datum.godina=momentalna.pocetok.godina;
        pretstava[index].karta[i+100].datum.mesec=momentalna.pocetok.mesec;
        pretstava[index].karta[i+100].datum.den=momentalna.pocetok.den+2;
        pretstava[index].karta[i+100].datum.saat=momentalna.pocetok.saat;
    }
    printf("\n");
}
