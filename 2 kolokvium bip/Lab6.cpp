#include<iostream>
#include<string>
using namespace std;
struct student {
    int indeks;
    int oceni[40];
    int brOceni;
    float prosek() {
        float avg=0;
        for(int i=0;i<brOceni;i++) {
            avg=avg+oceni[i];
        }
        return avg;
    }
    bool nagrada() {
        if(avg>9.0) {
            return true;
        }
        else {
            return false;
        }
    }
    void pecati() {
        cout<<"Indeks: "<<indeks<<endl;
        for(int i=0;i<brOceni;i++) {
            cout<<"Ocena po predmet: "<<i+1<<" "<<oceni[i]<<endl;
        }
        cout<<"Vkupno oceni: "<<brOceni<<endl;
    }
}

struct grupa{
    int indeksi[10];
}
struct laboratoriska{
        struct grupa group;
        struct student studenti[20];
        int brStudenti;
        int izraboteni[10];
        int izrabotil(int ind) {
        for(int i=0;i<brStudenti;i++) {
            if(ind==group.indeksi[i]) {
                cout<<"Studentot: "<<ind<<" pripagja na grupata"<<endl;
            }
            else {
                cout<<"Studentot ne pripagja na grupata"<<endl;
                return -1;
            }
        }
        }
        void potpis() {
            for(int i=0;i<brStudenti;i++) {
                if(izraboteni[i]>8) {
                    cout<<"Studentot so indeks "<<studenti[i].indeks<<" dobiva potpis"<<endl;
                }
                else {
                    cout<<"Studentot so indeks: "<<studenti[i].indeks<<" ne dobiva potpis"<<endl;
                }
            }
        }
    }

int main() {
    struct grupa g;
    struct laboratoriska lab;
    int i;
    bool proverka;
    int nagradeni=0;
    for(i=0;i<lab.brStudenti;i++) {
       cout<<"Vnesi podatoci za studentot: "<<i+1<<endl;
       cout<<"Indeks: "<<endl;
       cin>>lab.studenti[i].indeks;
       cout<<"Kolku oceni ima dobieno: "<<endl;
       cin>>lab.studenti[i].brOceni;
       for(int j=0;j<lab.studenti[i].brOceni;j++) {
           cout<<"Vnesi ja ocenkata: "<<j+1<<endl;
           cin>>lab.studenti[i].oceni[j];
       }
       cout<<"Kolku laboratoriski izrabotil ?"<<endl;
       cin>>lab.izraboteni[i];
        }
    for(i=0;i<lab.brStudenti;i++) {
        proverka=lab.studenti[i].prosek(); 
        if(proverka) {
            nagradeni++;
        }
    }
    cout<<"Ima vkupno "<<nagradeni<<"nagradeni studenti, koj saka neka cestita"<<endl;

    return 0;
}