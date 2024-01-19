#include<iostream>
#include<string>
using namespace std;
enum{aktiven=1,neaktiven,trener};
class participant{
    private:
    string ime;
    string prezime;
    int vozrast;
    int redenBroj;
    int tip;
    string poteklo;
    bool olimpijada;
    public:
    participant()=default;
    participant(string ime "", string prezime "", int vozrast=0, int redenBroj=0, int tip=0,string poteklo "", bool olimpijada=false) {
    this->ime=move(ime);
    this->prezime=move(prezime);
    this->vozrast=vozrast;
    this->redenBroj=redenBroj;
    this->tip=tip;
    this->poteklo=move(poteklo);
    this->olimpijada=olimpijada;
    }
    ~participant()=default;
    //set
    
    void setIme(string name) {
        this->ime=move(name);
    }
    void setPrezime(string surname) {
        this->prezime=move(surname);
    }
    void setVozrast (int age) {
        this->vozrast=age;
    }
    void setredenBroj (int num) {
        this->redenBroj=num;
    }
    void setTip(int type) {
        this->tip=type;
    }
    void setPoteklo (string origin) {
        this->poteklo=move(origin);
    }
    void setOlimpijada (bool olympics) {
        this->olimpijada=olympics;
    }
    //get
    string getIme() {
        return this->ime;
    }
    string getPrezime() {
        return this->prezime;
    }
    int getVozrast() {
        return this->vozrast;
    }
    int getredenBroj() {
        return this->redenBroj;
    }
    int getTip() {
        return this->tip;
    }
    string getPoteklo() {
        return this->poteklo;
    }
    bool getOlimpijada() {
        return this->olimpijada;
    }
    
    virtual void pecati() const {
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Vozrast: "<<vozrast<<endl;
        cout<<"Reden broj: "<<redenBroj<<endl;
        if(tip==aktiven) {
            cout<<"Tip na ucesnik: aktiven"<<endl;
        }
        else if(tip==neaktiven) {
            cout<<"Tip na ucesnik: neaktiven"<<endl;
        }
        else if(tip==trener) {
            cout<<"Tip na ucesnik: trener"<<endl;
        }
    }
    
}

class StandAlone:public participant {
    private:
    int preliminarni;
    int osvoeni;
    int sudija;
    public:
    StandAlone()=default;
    StandAlone(string ime "", string prezime "", int vozrast=0, int redenBroj=0, int tip=0,string poteklo "", bool olimpijada=false,
    int preliminarni=0, int osvoeni=0, int sudija=0):participant(ime,prezime,vozrast,redenBroj,poteklo,olimpijada) {
        this->preliminarni=preliminarni;
        this->osvoeni=osvoeni;
        this->sudija=sudija;
    }
    ~StandAlone()=default;
    //set
    void setPreliminarni (int before) {
        this->preliminarni=before;
    }
    void setOsvoeni (int after) {
        this->osvoeni=afer;
    }
    void setSudija (int judge) {
        this->sudija=judge;
    }
    //get
    int getPreliminarni() {
        return this->preliminarni;
    }
    int getOsvoeni() {
        return this->osvoeni;
    }
    int getSudija() {
        return this->sudija;
    }
    //funkcii
    int getPoeniSamostojni() {
        float vkupni=0.0;
        if(tip!=trener) {
            vkupni=vkupni+this->preliminarni + this->osvoeni + this->sudija;
            vkupni=vkupni/3;
        }
        return vkupni;
    }
    virtual void print() const override{
        cout<<"Ime: "<<ime<<endl;
        cout<<"Prezime: "<<prezime<<endl;
        cout<<"Vozrast: "<<vozrast<<endl;
        cout<<"Reden broj: "<<redenBroj<<endl;
        if(tip==aktiven) {
            cout<<"Tip na ucesnik: aktiven"<<endl;
        }
        else if(tip==neaktiven) {
            cout<<"Tip na ucesnik: neaktiven"<<endl;
        }
        else if(tip==trener) {
            cout<<"Tip na ucesnik: trener"<<endl;
            cout<<"Trenerite ne dobivaat poeni"<<endl;
            break;
        }
        cout<<"Preliminarni poeni: "<<preliminarni<<endl;
        cout<<"Osvoeni poeni: "<<osvoeni<<endl;
        cout<<"Poeni od sudiite: "<<sudija<<endl;
}

class Team:public participant {
    private:
    int soigraci[10];
    int kolkuSoigraci;
    float poeniSoigraci[10];
    public:
    Team()=default;
    Team(string ime "", string prezime "", int vozrast=0, int redenBroj=0, int tip=0, string poteklo "", bool olimpijada=false,
    int *soigraci, int kolkuSoigraci=0, float *poeniSoigraci) {
        this->kolkuSoigraci=kolkuSoigraci;
        for(int i=0;i<kolkuSoigraci;i++) {
            this->soigraci[i]=soigraci[i];
            this->poeniSoigrac[i]=poeniSoigraci[i];
        }
    }
    ~Team()=default;
    //set
    void setSoigraci(int teammates[], int n) {
        for(int i=0;i<n;i++) {
            this->soigraci[i]=teammates[i];
        }
    }
    void setpoeniSoigraci(float tp[], int n) {
        for(int i=0;i<n;i++) {
            this->poeniSoigraci[i]=tp[i];
        }
    }
    //get
    int getSoigraci() {
        for(int i=0;i<kolkuSoigraci;i++) {
            return this->soigraci[i];
        }
    }
    float getpoeniSoigraci() {
        for(int i=0;i<kolkuSoigraci;i++) {
            return this->poeniSoigraci[i];
        }
    } 
    //funkcii
    float getPoeniTimski() {
        float vk=0.0;
        if(tip!=3) {
            for(int i=0;i<kolkuSoigraci;i++) {
                vk+=poeniSoigraci[i];
            }
            for(int i=0;i<kolkuSoigraci;i++) {
                poeniSoigraci[i]=poeniSoigraci[i]+(vk/0.10);
            }
        }
        for(int i=0;i<kolkuSoigraci;i++) {
            cout<<"Igracot "<<i+1<<" ima osvoeno "<<poeniSoigraci[i]<<endl;
        }
    }


}
int main() {

    return 0;
}