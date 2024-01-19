#include<iostream>
#include<string>
using namespace std;

class oprema{
    public:
    string ime;
    string graficka;
    bool porta;
    int cena;
    oprema()=default;
    oprema(string ime, string graficka, bool porta, int cena) {
        this->ime=move(ime);
        this->graficka=move(graficka);
        this->porta=porta;
        this->cena=cena;
    }
    ~oprema()=default;

    int sporedi(int cena1, int cena2) {
        if(cena1<cena2) {
            return cena1;
        }
        else if(cena1>cena2) {
            return cena2;
        }
        else {
            cout<<"Dvete ceni se isti nema poeftina"<<endl;
        }
    }
    //set
    string setIme() {
        this->ime=move(ime);
    }
    string setGraficka() {
        this->graficka=move(graficka);
    }
    bool setPorta() {
        this->porta=porta;
    }
    int setCena() {
        this->cena=cena;
    }
    //get
    string getIme() {
        return ime;
    }
    string getGraficka() {
        return graficka;
    }
    bool getPorta() {
        return porta;
    }
    int getCena() {
        return cena;
    }
}

class laptop:public oprema {
    public:
    bool dopolnitelna;
    int dopCena;
    laptop()=default;
    laptop(string ime, string graficka, bool porta, int cena, bool dopolnitelna, int dopCena)
    :oprema(ime, graficka, porta, cena) {
        this->dopolnitelna=dopolnitelna;
        this->dopCena=dopCena;
    }
    ~laptop()=default;
    //set
    bool setDopolnitelna() {
        this->dopolnitelna=dopolnitelna;
    }
    int setdopCena() {
        this->dopCena=dopCena;
    }
    //get
    bool getDopolnitelna() {
        return dopolnitelna;
    }
    int getdopCena() {
        return dopCena;
    }
    
    void printLaptop() {
        cout<<"Ime: "<<this->ime<<endl;
        cout<<"Graficka: "<<this->graficka<<endl;
        if(this->porta) cout<<"Mrezna porta: ima"<<endl;
        else cout<<"Mrezna porta: nema"<<endl;
        cout<<"Cena bez dopolnitelna graficka: "<<this->cena<<endl;
        if(this->dopolnitelna) {
            cout<<"Dopolnitelna graficka ima"<<endl;
            cout<<"Cena so doplata: "<<this->cena+this->dopCena<<endl;
        }
        else {
            cout<<"Nema dopolnitelna graficka, cenata ostanuva ista"<<endl;
        }
    }
}

class pc:public oprema{
    public:
    float cenaDop;
    float popust;
    pc()=default;
    pc(string ime, string graficka, bool porta, int cena, float cenaDop, float popust) 
    :oprema(ime, graficka, porta, cena) {
        this->cenaDop=cenaDop;
        this->popust=popust;
        porta=true;
    }
    ~pc()=default;
    // set
    float setcenaDop() {
        this->cenaDop=cenaDop;
    }
    float setPopust() {
        this->popust=popust;
    }
    // get
    float getcenaDop() {
        return cenaDop;
    }
    float getPopust() {
        return popust;
    }
    void printPc() {
        cout<<"Ime: "<<this->ime<<endl;
        cout<<"Graficka: "<<this->graficka<<endl;
        cout<<"Mrezna porta: ima"<<endl;
        cout<<"Cena: "<<this->cena<<endl;
        cout<<"Cena so popust: "<<this->cena-(this->cena*this->popust)<<endl;
        cout<<"Krajna cena: "<<this->getCena()<<endl;
    }
}
int main() {

    return 0;
}