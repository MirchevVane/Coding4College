#include<iostream>
#include<string>
using namespace std;

class lek {
    private:
    string ime;
    int mg;
    int ph;
    int doza;
    public:
    lek()=default;
    lek(string ime, int mg, int ph, int doza) {
        this->ime=move(ime);
        this->mg=mg;
        this->ph=ph;
        this->doza=doza;
    }
    ~lek()=default;
    void zgolemi() {
        if(mg<doza) {
            while(mg<=doza) {
                mg++;
            }
        }
    }
    bool kompatibilni(int ph1, int ph2) {
        if(ph1==ph2) {
            return true;
        }
        else {
            return false;
        }
        
    }
    void pecati() {
        cout<<"Ime: "<<ime<<endl;
        cout<<"mg: "<<mg<<endl;
        cout<<"pH vrednost: "<<ph<<endl;
        cout<<"Preporacana doza: "<<doza<<endl;
    }
}

class apteka {
    private:
    string name;
    int brLek;
    class lek *lekovi;
    public:
    apteka()=default;
    apteka(string name, int brLek) {
        this->name=move(name);
        this->brLek=brLek;
        lekovi=new lek[brLek];
    }
    ~apteka()={
        delete lekovi;
    }
    //set
    string setName(string name) {
        this->name=move(name);
    }
    int setbrLek(int brLek) {
        this->brLek=brLek;
    }
    //get
    string getName() {
        return name;
    }
    int getbrLek() {
        return brLek;
    }
    int setLek(class lek momentalen, int i) {
        if(i>=brLek) {
            break;
        }
        else {
            lekovi[i].ime=move(momentalen.ime);
            lekovi[i].mg=move(momentalen.mg);
            lekovi[i].ph=move(momentalen.ph);
            lekovi[i].doza=move(momentalen.doza);
        }
    }
    void dodadi(int plus) {
        lekovi=new Lek[brLek+plus];
        int i;
        for(i=0;i<brLek+plus;i++) {
            cout<<"Ime: "<<endl;
            cin>>lekovi[i].ime;
            cout<<"Mg: "<<endl;
            cin>>lekovi[i].mg;
            cout<<"pH: "<<endl;
            cin>>lekovi[i].ph;
            cout<<"Doza: "<<endl;
            cin>>lekovi[i].doza;
        }
    }
    void kompatibilnost(class lek const &sporedenLek) {
        int i;
        for(i=0;i<brLek;i++) {
            if(lekovi[i].ph==sporedenLek.ph) {
                cout<<"Lekovite se kompatibilni"<<endl;
            }
        }
    } 
    void KompPoIme(string const &imeLek) {
        int i;
        class lek odredenLek;
        for(i=0;i<brLek;i++) {
            if(imeLek==lekovi[i].ime) {
                odredenLek=lekovi[i];
                break;
            }
        }
        for(i=0;i<brLek;i++) {
            if(odredenLek.ph==lekovi[i].ph) {
                cout<<"Lekovite se kompatibilni"<<endl;
            }
        }
    }
    void pecati() {
        cout<<"Ime na apteka: "<<ime<<endl;
        cout<<"Koi lekovi se naogjaat vo aptekata ? "<<endl;
        for(int i=0;i<brLek;i++) {
            cout<<"Ime na lek: "<<lekovi[i].ime<<endl;
            cout<<"Mg: "<<lekovi[i].mg<<endl;
            cout<<"pH: "<<lekovi[i].ph<<endl;
            cout<<"Doza: "<<lekovi[i].doza<<endl;
        }
    }
}

void nadvoresna(class apteka A, class lek const &odredenLek) {
    class lek momentalen;
    int i;
    for(i=0;i<A.getbrLek();i++) {
        momentalen=A.setLek(i);
        if(momentalen.ph==odredenLek.ph) {
            cout<<"Lekovite se kompatibilni"<<endl;
        }
    }
}
int main() {

    return 0;
}