#include <iostream>
#include <string>
using namespace std;

struct Lek{
    string ime;
    int mg{};
    float pH{};
    int dDoza{};

    void Zgolemi(int plusMg){
        mg+=plusMg;
    }
    bool static Kompatabilnost(float pH1,float pH2){
        if(pH1==pH2){
            return true;
        }return false;
    }
    void Pecati() const{
        cout<<"Ime na lekot : "<<ime<<endl;
        cout<<"Miligrami : "<<mg<<endl;
        cout<<"pH faktor : "<<pH<<endl;
        cout<<"Dnevna doza : "<<dDoza<<endl;
    }

};

class Apteka{
private:
    string ime;
    int brLekovi;
    struct Lek *lekovi;
public:
    Apteka(string ime,int brLekovi){
        this->ime=move(ime);
        this->brLekovi=brLekovi;
        lekovi=new Lek[brLekovi];
    }
    ~Apteka(){
        delete lekovi;
    };

    int setLek(struct Lek momentalenLek,int i){
        if(i>=brLekovi){
            return -1;
        }
        lekovi[i].ime=move(momentalenLek.ime);
        lekovi[i].mg=momentalenLek.mg;
        lekovi[i].dDoza=momentalenLek.dDoza;
        lekovi[i].pH=momentalenLek.pH;
        return 0;
    }

    int getBrLekovi() const{
        return brLekovi;
    }
    struct Lek getLek(int i){
        return lekovi[i];
    }

    void Dodadi(int nB){
        lekovi=new Lek[brLekovi+nB];
        for(int i=brLekovi;i<brLekovi+nB;i++){
            cout<<"Ime na lek : ";
            cin>>lekovi[i].ime;
            cout<<"Miligrami na lek : ";
            cin>>lekovi[i].mg;
            cout<<"pH faktor : ";
            cin>>lekovi[i].pH;
            cout<<"Dnevna doza : ";
            cin>>lekovi[i].dDoza;
        }
    }

    void Kompatabilnost(struct Lek const &pratenLek){
        for(int i=0;i<brLekovi;i++){
            if(lekovi[i].pH==pratenLek.pH){
                cout<<lekovi[i].ime<<" e kompatabilen so "<<pratenLek.ime<<endl;
            }
        }
    };

    void Kompatabilnost(string const &imeNaLek){
        struct Lek odredenLek;
        for(int i=0;i<brLekovi;i++){
            if(imeNaLek==lekovi[i].ime){
                odredenLek=lekovi[i];
                break;
            }
        }
        for(int i=0;i<brLekovi;i++){
            if(odredenLek.pH==lekovi[i].pH){
                cout<<lekovi[i].ime<<" e kompatabilen so "<<odredenLek.ime<<endl;
            }
        }
    };

    void Pecati() const{
        cout<<"Ime na apteka : "<<ime<<endl;
        cout<<"Lekovi vo apteka : "<<endl;
        for(int i=0;i<brLekovi;i++){
            cout<<lekovi[i].ime<<endl;
            cout<<"Miligrami : "<<lekovi[i].mg<<endl;
            cout<<"pH faktor : "<<lekovi[i].pH;
            cout<<"Dnevna doza : "<<lekovi[i].dDoza<<" mg/den"<<endl;
        }
    };
};


void kompatibilnost(class Apteka odredenaApteka,struct Lek const &odredenLek){
    struct Lek momentalenLek;
    for(int i=0;i<odredenaApteka.getBrLekovi();i++){
        momentalenLek=odredenaApteka.getLek(i);
        if(momentalenLek.pH==odredenLek.pH){
            cout<<momentalenLek.ime<<" e kompatabilen so "<<odredenLek.ime<<endl;
        }
    }
}

int main(){
    Apteka Zegin("Zegin",5);
    Apteka BellaFarm("BellaFarm",10);
    struct Lek momentalenLek;

    for(int i=0;i<Zegin.getBrLekovi();i++){
        cout<<"Ime na lek : ";
        cin>>momentalenLek.ime;
        cout<<"Miligrami : ";
        cin>>momentalenLek.mg;
        cout<<"pH faktor : ";
        cin>>momentalenLek.pH;
        cout<<"Dnevna doza : ";
        cin>>momentalenLek.dDoza;
        Zegin.setLek(momentalenLek,i);
    }
    momentalenLek.Pecati();
    Zegin.Pecati();

    for(int i=0;i<BellaFarm.getBrLekovi();i++){
        cout<<"Ime na lek : ";
        cin>>momentalenLek.ime;
        cout<<"Miligrami : ";
        cin>>momentalenLek.mg;
        cout<<"pH faktor : ";
        cin>>momentalenLek.pH;
        cout<<"Dnevna doza : ";
        cin>>momentalenLek.dDoza;
        BellaFarm.setLek(momentalenLek,i);
    }
    momentalenLek.Pecati();
    BellaFarm.Pecati();

    Zegin.Dodadi(3);
    BellaFarm.Dodadi(2);

    kompatibilnost(Zegin,momentalenLek);
    momentalenLek.Zgolemi(20);
    
    return 0;
}