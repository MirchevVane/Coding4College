#include<iostream>
#include<string>
using namespace std;
enum{neutralen=0,zalog,vlog}

struct nalog{
char *klient;
klient=new char[strlen(klient)+1];
int nalog;
int suma;
float kamata;
};

class zalozna{
    private:
    string ime;
    string adresa;
    int kapital;
    int vraboteni;
    struct nalog *nalozi;
    int kolku;
    public:
    zalozna()=default;
    zalozna(string ime, string adresa, int kapital, int vraboteni, struct nalog nalozi[], int kolku) {
        this->ime=move(ime);
        this->adresa=move(adresa);
        this->kapital=kapital;
        this->vraboteni=vraboteni;
        this->kolku=kolku;
        nalozi=new struct nalog[kolku];
        for(int i=0;i<kolku;i++) {
            this->nalozi[i]=nalozi[i];
        }
    }
    ~zalozna() {
        delete nalozi;
    }
    //set
    void setIme(string ImePrateno) {
        this->ime=ImePrateno;
    }
    void setAdresa(string AdresaPratena) {
        this->adresa=AdresaPratena;
    }
    void setKapital(int PratenKapital) {
        this->kapital=PratenKapital;
    }
    void setVraboteni(int VraboteniSent) {
        this->vraboteni=VraboteniSent;
    }
    //get
    string getIme() {
        return ime;
    }
    string getAdresa() {
        return adresa;
    }
    int getKapital() {
        return kapital;
    }
    int getVraboteni() {
        return vraboteni;
    }
    bool sostojba() {
        int sumaVlog=0;
        int sumaNeutral=0;
        int sumaZalog=0;
        for(int i=0;i<kolku;i++) {
            if(nalozi[i].nalog==vlog) {
                sumaVlog+=nalozi[i].suma;
            }
            if(nalozi[i].nalog==neutralen) {
                sumaNeutral+=nalozi[i].suma;
            }
            if(nalozi[i].nalog==zalog) {
                sumaZalog+=nalozi[i].suma;
            }
        }
        if(sumaVlog+sumaNeutral-sumaZalog>kapital) {
            return true;
        }
        else {
            return false;
        }
    }
    
    int vrati(int a) {
        int sum=0;
        for(int i=0;i<kolku;i++) { 
        if(a==vlog) {
            sum+=nalozi[i].suma;
        }
        else if (a==neutralen) {
            sum+=nalozi[i].suma;
        }
        else if(a==zalog) {
            sum+=nalozi[i].suma;
        }
    }
    return sum;
    }
};

void pecati(class zalozna z[], int n) {
    int zalozeni=0;
    for(int i=0;i<n;i++) {
        if(strcmp(z[i].getAdresa(),'Skopje')) {
            zalozeni++;
        }
    }
    cout<<"Vkupno zalozeni vo Skopje ima: "<<zalozeni<<endl;
}

int main() {


    return 0;
}