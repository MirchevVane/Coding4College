#include<iostream>
#include<string>
using namespace std;
struct datum{
    int mesec;
    int godina;
}
struct proizvod{
    char ime[30];
    string tip;
    int cena;
    float gramaza;
    string poteklo;
    struct datum proizvedeno;

    bool voRok(datum d1, datum g1){
        if(proizvedeno.godina<d1.godina) {
            return false;
        }
        if(proizvedeno.godina==g1.godina) {
            if(proizvedeno.mesec==d1.mesec) {
                cout<<"Rokot istekuva ovoj mesec"<<endl;
            }
        }
        if(proizvedeno.godina>g1.godina) {
            return true;
        }
    }
    void prodadi() {
        cena=0;
    }
}

class trgovski {
    private:
    string ime;
    string adresa;
    struct proizvod *proizvodi;
    int kolku;
    int *novi_ceni;
    public:
    trgovski(string ime="", string adresa="", proizvod *proizvodi,int kolku=0, int *novi_ceni) {
        this->ime=move(ime);
        this->adresa=move(adresa);
        this->kolku=kolku;
        proizvodi=new proizvod[kolku];
        novi_ceni= new int[kolku];
    }
    ~trgovski() {
        delete [] novi_ceni;
        delete [] proizvodi;
    }
    bool proverka(int mesec, int godina) {
        int 
        for(int i=0;i<kolku;i++) {
            int isteceni=0;
            if(proizvodi[i].proizvedeno.godina<godina)
            {return true;}
            else if(proizvodi[i].proizvedeno.godina==godina) {
                if(proizvodi[i].proizvedeno.mesec<mesec) {
                    return true;
                }
                else if(proizvodi[i].proizvedeno.mesec>mesec) {
                    proizvodi[i].cena=0;
                    novi_ceni[i]=0;
                    isteceni++;
                }
            }
        }
        return isteceni;
    }

    int getNeto(string tip) {
        float vkupna=0.0;
        for(int i=0;i<kolku;i++) {
            if(strcmp(proizvodi[i].tip, string tip)) {
                vkupna=vkupna+proizvodi[i].gramaza;
                return vkupna;
            }
            else {
                vkupna=vkupna+proizvodi[i].gramaza;
                return vkupna;
            }
        }
    }
};
int main() {


    return 0;
}