#include<iostream>
#include<string>
using namespace std;
class korisnik{
    protected:
    string ime;
    string prezime;
    int plata;
    int tarifa; //1-10
    int dolg;
    bool status; //0-aktivna, 1-neaktivna
    int neplateni;
    public:
    korisnik()=default;
    korisnik(string ime, string prezime, int plata, int tarifa, int dolg, bool status, int neplateni) {
        this->ime=move(ime);
        this->prezime=move(prezime);
        this->plata=plata;
        this->tarifa=tarifa;
        this->dolg=dolg;
        this->status=status;
        this->neplateni=neplateni;
    }
    ~korisnik()=default;
    //set
    string setIme(string pime) {
        this->ime=move(pime);
    }
    string setPrezime(string pprezime) {
        this->prezime=move(pprezime);
    }
    int setPlata(int pplata) {
        this->plata=pplata;
    }
    int setTarifa(int ptarifa) {
        this->tarifa=ptarifa;
    }
    int setDolg(int pdolg) {
        this->dolg=pdolg;
    }
    bool setStatus(bool pstatus) {
        this->status=status;
    }
    int setNeplateni(int pneplateni) {
        this->neplateni=pneplateni;
    }
    //get
    string getIme() {
        return ime;
    }
    string getPrezime() {
        return prezime;
    }
    int getPlata() {
        return plata;
    }
    int getTarifa() {
        return tarifa;
    }
    int getDolg() {
        return dolg;
    }
    bool getStatus() {
        return status;
    }
    int getNeplateni() {
        return neplateni;
    }

    int retDolg() {
        return this->dolg;
    }
    void zatvori() {
        if(!dolg) {
            status=true;
        }
        else {
            cout<<"Korisnikot gi nema podmireno site dolgovi"<<endl;
        }
    }
    void sporedi(korisnik *pratenKorisnik) {
        this->dolg+=pratenKorisnik->dolg;
        pratenKorisnik->status=false;
    }
    void printKorisnik() {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Plata: "<<plata<<endl;
        cout<<"Tarifa: "<<tarifa<<endl;
        cout<<"Dolg: "<<dolg<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Neplateni smetki: "<<neplateni<<endl;
    }
}
class firma:public korisnik {
    protected:
    int kolkuBr;
    int kolkuDolzi[3];
    public:
    firma()=default;
    firma(string ime, string prezime, int plata, int tarifa, int dolg, bool status,int neplateni, int kolkuBr, int kolkuDolzi[])
    :korisnik(move(ime),move(prezime),plata,tarifa,dolg,status,neplateni) {
        this->name=name;
        this->prezime=prezime;
        this->plata=plata;
        this->tarifa=tarifa;
        this->dolg=dolg;
        this->status=status;
        this->kolkuBr=kolkuBr;
        this->neplateni=neplateni;
        for(int i=0;i<3;i++) {
            this->kolkuDozi[i]=kolkuDolzi[i];
            this->dolg+=kolkuDolzi[i];
        }
    }
    ~firma()=default;
    //set
    int setkolkuBr(int kolkuBrp) {
        this->kolkuBr=kolkuBrp;
    }
    int setkolkuDolzi(int kolkuDolzip[3]) {
        for(int i=0;i<3;i++) {
            this->kolkuDolzi[i]=kolkuDolzip[i];
        }
    }
    //get
    int getkolkuBr() {
        return this->kolkuBr;
    }
    int getkolkuDolzi() {
        for(int i=0;i<3;i++) {
            return this->kolkuDolzi[i];
        }
    }
    void printFirma() {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Plata: "<<plata<<endl;
        cout<<"Tarifa: "<<tarifa<<endl;
        cout<<"Dolzi: "<<dolg<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Neplateni smetki: "<<neplateni<<endl;
        cout<<"Korisnici: "<<kolkuBr<<endl;
        for(int i=0;i<kolkuBr;i++) {
            cout<<"Kolku dolzi korisnikot "<<i+1<<":"<<kolkuDolzi[i]<<endl;
        }
    }
}

class kombo:public korisnik {
    protected:
    bool tv;
    int dolgTv;
    bool digitalna;
    public:
    kombo(string ime, string prezime, int plata, int tarifa, int dolg, bool status, int neplateni, bool tv, int dolgTv, bool digitalna)
    :korisnik(move(ime), move(prezime), plata, tarifa, dolg, status, neplateni) {
        this->ime=ime;
        this->prezime=prezime;
        this->plata=plata;
        this->tarifa=tarifa;
        this->dolg=dolg;
        this->status=status;
        this->neplateni=neplateni;
        this->tv=tv;
        this->dolgTv=dolgTv;
        if(digitalna) {
            this->dolgTv+1000;
        }
        this->dolgTv+=dolgTv;
    }
    ~kombo()=default;
    
    void printKombo() {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Plata: "<<plata<<endl;
        cout<<"Tarifa: "<<tarifa<<endl;
        cout<<"Dolg: "<<dolg<<endl;
        cout<<"Status: "<<status<<endl;
        cout<<"Neplateni: "<<neplateni<<endl;
        if(tv) {
            cout<<"Televizija: ima"<<endl;
            cout<<"Dolg za televizija: "<<dolgTv<<endl;

        }
        if(digitalna) { 
        cout<<"Digitalna: ima"<<endl;
        cout<<"Dolg za digitalna: "<<dolgTv<<endl;
        }
    }
}
int main() {


    return 0;
}