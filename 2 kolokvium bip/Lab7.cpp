#include<iostream>
#include<string>
using namespace std;
struct datum{
    int mesec;
    int godina;
}
struct proizvod{
    string ime;
    string tip;
    int cena;
    int gramaza;
    string poteklo;
    struct datum proizvedeno;

    bool voRok(struct datum denes) {
        if(denes.godina>proizvedeno.godina) {
            return true;
        }
        else if(denes.godina==proizvedeno.godina) {
            if(denes.mesec<proizvedeno.mesec) {
                return true;
            }
            else if(denes.mesec==proizvedeno.mesec) {
                cout<<"Rokot istekuva ovoj mesec"<<endl;
            }
        }
        else {
            return false;
        }
    }
    void prodadi() {
        cena=0;
    }
}

class trgovski() {
private:
    string ime;
    string adresa;
    proizvod proizvodi[100];
    int kolku;
    int novaCena[100];
public:
trgovski()=default;
trgovski(string ime, string adresa, proizvod *proizvodi, int kolku, int *novaCena) {
    this->ime=move(ime);
    this->adresa=move(adresa);
    this->kolku=kolku;
    for(int i=0;i<kolku;i++) {
        this->proizvodi[i]=proizvodi[i];
        this->novaCena[i]=novaCena[i];
    }
}
~trgovski(){};
//set

void setIme(string ime) {
    this->ime=move(ime);
}
void setAdresa(string adresa) {
    this->adresa=move(adresa);
}

//get

string getIme() {
    return ime;
}
string getAdresa() {
    return adresa;
}
int getKolku() {
    return kolku;
}
void getProizvodi() {
    for(int i=0;i<kolku;i++) {
        cout<<proizvodi[i].ime;
        cout<<proizvodi[i].tip;
        cout<<proizvodi[i].cena;
        cout<<proizvodi[i].gramaza;
        cout<<proizvodi[i].proizvedeno.mesec;
        cout<<proizvodi[i].proizvedeno.godina;
    }
}
int proverka(struct datum denes) {
    int vkupno=0;
    for(int i=0;i<kolku;i++) 
    {
        if(proizvodi[i].proizvedeno.godina>denes.godina) {
            proizvodi[i].prodadi();
            novaCena[i]=0;
            vkupno++;
        }
        else if(proizvodi[i].proizvedeno.godina==denes.godina) {
            if(proizvodi[i].proizvedeno.mesec>denes.mesec) {
                proizvodi[i].prodadi();
                novaCena[i]=0;
                vkupno++:
            }
        }
    }
    return vkupno;
}

float getNeto(string tip) {
    int vkupno=0;
    if(!strcmp(tip,"")) {
        for(int i=0;i<kolku;i++) {
            if(strcmp(tip, proizvodi[i].tip)) {
                vkupno=vkupno+proizvodi[i].gramaza;
            }
        }
    }
    else {
        for(int i=0;i<kolku;i++) {
            vkupno=vkupno+proizvodi[i].gramaza;
        }
    }
    return vkupno;
}

}

int main() {
    struct proizvod pr[100];
    string ime;
    string adresa;
    int n;
    int novi_ceni[100];
    cout<<"Ime: "<<endl;
    cin>>ime;
    cout<<"Adresa: "<<endl;
    cin>>adresa;
    cout<<"Broj na proizvodi: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++) {
        cout<<"Vnesi ime na proizvodot "<<i+1<<endl;
        cin>>pr[i].ime;
        cout<<"Tip: "<<endl;
        cin>>pr[i].tip;
        cout<<"Cena: "<<endl;
        cin>>pr[i].cena;
        cout<<"Tezina: "<<endl;
        cin>>pr[i].gramaza;
        cout<<"Zemja na poteklo: "<<endl;
        cin>>pr[i].poteklo;
        cout<<"Data na proizvodstvo: (mesec/godina)"<<endl;
        cin>>pr[i].proizvedeno.mesec;
        cin>>pr[i].proizvedeno.godina;
        cout<<"Vnesi nova cena "<<endl;
        cin>>novi_ceni[i];

    }

    return 0;
}