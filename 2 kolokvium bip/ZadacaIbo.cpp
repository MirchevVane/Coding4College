#include<iostream>
#include<string>
using namespace std;
enum{medijapan=0,iverka};
class kujni{
    private:
    string proizveduva;
    int materijal;
    int trosok;
    int meseci;
    public:
    kujni(string ime="", int materijal=0, int trosok=0, int meseci=0) {
        this->ime=move(ime);
        this->materijal=materijal;
        this->trosok=trosok;
        this->meseci=meseci;
    }
    ~kujni()=default;
    float pocetnaCena() {
            float pocetok=0.0;
            if(materijal==medijapan) {
                pocetok=4000.00;
            }
            else if(materijal==iverka) {
                pocetok=2000.00;
            }
            return pocetok;
        }
    virtual void pecati() const{
        cout<<"Ime: "<<ime<<endl;
        if(materijal==medijapan) {
            cout<<"Materijal: medijapan"<<endl;
            cout<<"Pocetna cena: 4000"<<endl;
        }
       else if(materijal==iverka) {
            cout<<"Materijal: iverka"<<endl;
            cout<<"Pocetna cena: 2000"<<endl;
        }

    }

};
class masi:public kujni {
    public:
    float povrshina;
    int fioki;
    int zafatnina[10];
    masi(string ime="", int materijal=0, int trosok=0, int meseci=0, float povrshina=0, int fioki=0, int *zafatnina)
    : kujni(ime, materijal, trosok, meseci) {
        this->povrshina=povrshina;
        this->fioki=fioki;
        for(int i=0;i<fioki;i++) {
            this->zafatnina[i]=zafatnina[i];
        }
    }
    ~masi()=default;
    float CenaMasi() {
        float price=0.0;
        if(materijal) {
            price=4000.00;
        }
        else if(!materijal) {
            price=2000.00;
        }
    }
}
int main() {
    
    return 0;
}