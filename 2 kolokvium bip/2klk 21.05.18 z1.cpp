#include<iostream>
#include<string>
using namespace std;
struct danocna{
    char *vraboten;
    string maticen;
    int bruto;
    int neto;
    int odbitoci;
    void allocIme(int brZ) {
        ime=new char[brZ];
    }
}

class firma {
    private:
    string ime;
    string adresa;
    int budzet;
    int dejnost; //1 2 ili 3
    danocna *danocni
    int kolku;
    public:
    firma()=default;
    firma(string ime, string adresa, int budzet, int dejnost, int kolku) {
        danocni=new danocna[kolku];
        this->ime=move(ime);
        this->adresa=move(adresa);
        this->budzet=budzet;
        this->dejnost=dejnost;
        this->kolku=kolku;
    }
    ~firma()=default;
    //set
    string setIme(string ime) {
        this->ime=move(ime);
    }
    string setAdresa(string adresa) {
        this->adresa=move(adresa);
    }
    int setBudzet(int budzet) {
        this->budzet=budzet;
    }
    int setDejnost(int dejnost) {
        this->dejnost=dejnost;
    }
    int setKolku(int kolku) {
        this->kolku=kolku;
    }
    //get
    string getIme() {
        return ime;
    }
    string getAdresa() {
        return adresa;
    }
    int getBudzet() {
        return budzet;
    }
    int getDejnost() {
        return dejnost;
    }
    int getKolku() {
        return kolku;
    }
    bool proverka() {
        int vkBruto=0;
        int vkOdbitoci=0;
        for(int i=0;i<kolku;i++) {
            vkBruto=vkBruto+danocni[i].bruto;
            vkOdbitoci=vkOdbitoci+danocni[i].odbitoci;
        }
        if(vkBruto-vkOdbitoci<budzet) {
            return true;
        }
        else if(vkBruto-vkOdbitoci==budzet) {
            cout<<"Rezultatot e ist"<<endl;
        }
        else {
            return false;
        }
    }
    int getNeto(long maticen) {
        for(int i=0;i<kolku;i++) {
            if(maticen==danocni[i].maticen) {
                return danocni[i].neto;
            }
        }
        return -1;
    }
    int getNeto(long maticen1, long maticen2a) {
        int poc, kraj, vkNeto=0;
        for(int i=0;i<kolku;i++) {
            if(maticen1==danocni[i].maticen) { 
            poc=i;
            }
            if(maticen2==danocni[i].maticen) {
                kraj=i;
            }
        }
        for(int i=poc;i<kraj;i++) {
            vkNeto=vkNeto+potvrdi[i].neto;
        }
        return vkNeto;
    }

}
int main() {

    return 0;
}