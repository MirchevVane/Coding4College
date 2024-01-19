#include<iostream>
#include<string>
using namespace std;
enum{aktivna=0, neaktivna};
class kredit{
    private:
    string ime;
    string prezime;
    int visina;
    int kamata;
    int period;
    int status;
    int rata;
    public:
    kredit()=default;
    kredit(string ime="", string prezime="", int visina=0, int kamata=0, int period=0, int status=0, int rata=0) {
        this->ime=move(ime);
        this->prezime=move(prezime);
        this->visina=visina;
        this->kamata=kamata;
        this->period=period;
        this->status=status;
        this->rata=rata;
    }
    ~kredit()=default;
    //set
    void setIme(string name) {
        this->ime=move(name);
    }
    void setPrezime(string surname) {
        this->prezime=move(surname);
    }
    void setVisina(int height) {
        this->visina=height;
    }
    void setKamata(int kam) {
        this->kamata=kam;
    }
    void setPeriod(int time) {
        this->period=time;
    }
    void setStatus(int stat) {
        this->status=stat;
    }
    void setRata(int rat) {
        this->rata=rat;
    }
    //get
    string getIme() {
        return this->ime;
    }
    string getPrezime() {
        return this->prezime;
    }
    int getVisina() {
        return this->visina;
    }
    int getKamata() {
        return this->kamata;
    }
    int getPeriod() {
        return this->period;
    }
    int getStatus() {
        return this->status;
    }
    int getRata() {
        return this->rata;
    }
    //funkcii
    float retDolg() {
        return this->rata*this->period;
    }
    float zarabotka() {
        return this->retDolg()-this->visina;
    }

    virtual void print() const {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Visina na kredit: "<<visina<<endl;
        cout<<"Na kolku meseci e zemen: "<<period<<endl;
        if(status=aktivna) {
            cout<<"Status: aktiven"<<endl;
        }
        if(status=neaktivna) {
            cout<<"Status: neaktiven"<<endl;
        }
        cout<<"Rata: "<<rata<<endl;
        cout<<"Dolg: "<<retDolg()<<endl;
        cout<<"Zarabotka: "<<zarabotka()<<endl;
    }
};

class months:public kredit{
    private:
    float namaluva;
    int period=12;
    public:
    months(string ime="", string prezime="", int visina=0, int kamata=0, int period=12, int status=0, int rata=0, float namaluva=0.0, )
    : kredit(ime, prezime, visina, kamata, period, status, rata) {
        this->namaluva=namaluva;
        this->period=period;
    }
    ~months()=default;
    //set
    void setNamaluva(float lower) {
        this->namaluva=lower;
    }
    //get
    float getNamaluva() {
        return this->namaluva;
    }
    //funkcii

    float retDolgMeseci() {
        return this->period*this->rata/this->period;
    }
    float retZarabotkaMeseci() {
        return this->retDolgMeseci()-this->getVisina();
    }
    virtual void print() override{
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Visina na kredit: "<<visina<<endl;
        cout<<"Kreditot e zemen na 12 meseci, periodot ne se menuva"<<endl;
        if(status=aktivna) {
            cout<<"Status: aktiven"<<endl;
        }
        if(status=neaktivna) {
            cout<<"Status: neaktiven"<<endl;
        }
        cout<<"Namalena rata vo prvite 6 meseci: "<<namaluva<<endl;
        
    }
};

class fiksna:public kredit{
    private:
    static int kamata;
    float minimalec;
    public:
    fiksna()=default;
    fiksna(string ime="", string prezime="", int visina=0, int kamata=0, int period=0, int status=0, int rata=0
    static int kamata=0, float minimalec=0.0) : kredit(ime,prezime,visina,kamata, period, status, rata) {
        this->kamata=kamata;
        this->minimalec=minimalec;
    }
    ~fiksna()=default;
    //set
    static void setKamata(int kam) {
        this->kamata=kam;
    }
    void setMinimalec(float minim) {
        this->minimalec=minim;
    }
    //get
    static int getKamata() {
        return this->kamata;
    }
    float getMinimalec() {
        return this->minimalec;
    }
    //funkcii
    float mesecnaRata() {
        if(getVisina()<=this->minimalec) {
            static kamata=0;
            return this->getVisina()/this->getPeriod
        }
        else {
            return this->retDolg();
        }
    }
    float dolgFiksna() {
        float dolg=0.0
        if(getVisina()<=this->minimalec) {
            dolg=this->getVisina();
            return this->dolg;
        }
        else {
            return this->retDolg();
        }
    }
    virtual void print() override {
         cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Visina na kredit: "<<visina<<endl;
        cout<<"Period: "<<period<<endl;
        if(status=aktivna) {
            cout<<"Status: aktiven"<<endl;
        }
        if(status=neaktivna) {
            cout<<"Status: neaktiven"<<endl;
        }
        if(getVisina()<=this->minimalec) {
            cout<<"Visinata na kreditot e pod minimalnoto dolgot iznesuva:"<<this->dolg;
        }
        else if(getVisina()>this->minimalec) {
            cout<<"Kreditot e pogolem od minimalnoto, iznesuva: "<<this->retDolg(); 
        }
    }
};

int main() {

    return 0;
}