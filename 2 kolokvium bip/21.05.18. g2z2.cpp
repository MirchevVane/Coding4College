#include<iostream>
#include<string>
using namespace std;
class bilet{
    private:
    string patuvac;
    int pasosh[10];
    int cena;
    float popust;
    string poagja;
    string pristignuva;
    public:
    bilet()=default;
    bilet(string patuvac="", int *pasosh, int cena=0, float popust=0.0, string poagja="", string pristignuva="") {
        this->patuvac=move(patuvac);
        for(int i=0;i<10;i++) {
            this->pasosh[i]=pasosh[i];
        }
        this->cena=cena;
        this->popust=popust;
        this->poagja=move(poagja);
        this->pristignuva=move(pristignuva);
    }
    ~bilet()=default;
    //set
    void setPatuvac(string passenger) {
        this->patuvac=passenger;
    }
    void setPasosh(int passport[]) {
        for(int i=0;i<10;i++) {
            this->pasosh[i]=passport[i];
        }
    }
    void setCena(int price) {
        this->cena=price;
    }
    void setPopust(float discount) {
        this->popust=discount;
    }
    void setPoagja(string departure) {
        this->poagja=move(departure);
    }
    void setPristignuva(string arrival) {
        this->pristignuva=move(arrival);
    }
    //get
    string getPatuvac() {
        return patuvac;
    }
    int getPasosh() {
        for(int i=0;i<10;i++) {
            return pasosh[i];
        }
    }
    int getCena() {
        return cena;
    }
    float getPopust() {
        return popust;
    }
    string getPoagja() {
        return poagja;
    }
    string getPristignuva() {
        return pristignuva;
    }
    //funkcii

    virtual float getSuma() {
        return this->cena-(this->cena*this->popust);
    }
    void ponishti() {
        this->poagja=this->pristignuva;
    }
    void familyPonuda(bilet *praten) {
        this->cena+=praten->cena;
        praten->pristignuva=praten->poagja;
        this->popust=0.0;
    }
    bool checkFamily() {
        if(this->popust==0.0) {
            return true;
        }
        else {
            return false;
        }
    }
    virtual void pecati() const{
        cout<<"Ime: "<<patuvac<<endl;
        cout<<"Pasosh: "<<endl;
        for(int i=0;i<10;i++) {
            cout<<pasosh[i]<<endl;
        }
        cout<<"Cena: "<<cena<<endl;
        cout<<"Popust: "<<popust<<endl;
        cout<<"Poagja od: "<<poagja<<endl;
        cout<<"Pristignuva vo: "<<pristignuva<<endl;

    }
}

class itni:public bilet {
    private:
    int dopolnitelno;
    int torbi[3];
    int kolku;
    public:
    itni(string patuvac="", int *pasosh, int cena=0, float popust=0.0, string poagja="", string pristignuva="",
    int dopolnitelno=0, int torbi*, int kolku=0) : bilet(patuvac,pasosh,cena,popust,poagja,pristignuva) {
        this->dopolnitelno=dopolnitelno;
        this->kolku=kolku;
        if(kolku==1) {
            this->torbi[0]=torbi[0];
            this->torbi[1]=0;
            this->torbi[2]=0;
        }
        else if(kolku==2) {
            this->torbi[0]=torbi[0];
            this->torbi[1]=torbi[1];
            this->torbi[2]=0;
        }
         else if(kolku==3) {
            this->torbi[0]=torbi[0];
            this->torbi[1]=torbi[1];
            this->torbi[2]=torbi[2];
        }
    }
    ~itni()=default;
    //set
    void setDopolnitelno(int dop) {
        this->dopolnitelno=dop;
    }
    void setBagaz(int kolku, int torbi[]) {
        if(kolku<=3 && kolku>=0) {
            this->kolku=kolku;
            for(int i=0;i<kolku;i++) {
                this->torbi[i]=torbi[i];
            }
        }
        else if(kolku>3) {
            this->kolku=3;
            for(int i=0;i<3;i++) {
                this->torbi[i]=torbi[i];
            }
        }
        else if(!kolku) {
            this->kolku=0;
            for(int i=0;i<3;i++) {
                this->torbi[i]=0;
            }
        }
    }
    //get
    int getDopolnitelno() {
        return this->dopolnitelno;
    }
    int getKolku() {
        return this->kolku;
    }
    //funkcii
    float getSuma() override {
        float vkupno= this->cena+this->dopolnitelno;
        for(int i=0;i<kolku;i++) {
            if(this->torbi[i]>=10) {
                vk+=100*this->torbi[i];
            }
        }
        return vkupno;
    }
    void pecati() override{
        cout<<"Ime: "<<patuvac<<endl;
        cout<<"Pasosh: "<<endl;
        for(int i=0;i<10;i++) {
            cout<<pasosh[i];
        }
        cout<<"Cena: "<<cena<<endl;
        cout<<"Popust: "<<popust<<endl;
        cout<<"Poagja od: "<<poagja<<endl;
        cout<<"Pristignuva vo: "<<pristignuva<<endl;
        cout<<"Dopolnitelen bagaz: "<<kolku<<endl;
        cout<<"Doplata: "<<dopolnitelno<<endl;
    }
}

class biznis:public bilet {
    private:
    bool rucek;
    int cenaBiznis;
    bool bagazDop;
    int cenaBD;
    public:
    biznis(string patuvac="", int *pasosh, int cena=0, float popust=0.0, string poagja="", string pristignuva=""
    bool rucek=false, int cenaBiznis=0, bool bagazDop=false, int cenaBD=0) 
    : bilet(patuvac,pasosh,cena,popust,poagja,pristignuva) {
        this->rucek=rucek;
        this->cenBiznis=cenaBiznis;
        this->bagazDop=bagazDop;
        this->cenaBD=cenaBD;
    }
    ~biznis()=default;
    //set
    void setRucek(bool lunch) {
        this->rucek=lunch;
    }
    void setcenaBiznis(int priceB) {
        this->cenaBinzis=priceB;
    }
    void setbagazDop(bool AddLuggage) {
        this->bagazDop=AddLuggage;
    }
    void setcenaBD(int priceBC) {
        this->cenaBD=priceBC;
    }
    //get
    bool getRucek() {
        return this->rucek;
    }
    int getcenaBiznis() {
        return this->cenaBiznis;
    }
    bool getbagazDop() {
        return this->bagazDop;
    }
    int getcenaBD() {
        return this->cenaBD;
    }
    // funkcii
    float getSuma() override {
        if(rucek && bagazDop) return this->cena + this->cenaBiznis - (this->cena+this->popust) + 1000.00 + this->cenaBD;
        if(!rucek && bagazDop) return this->cena + this->cenaBiznis - (this->cena+this->popust) + this->cenaBD;
        if(rucek && !bagazDop) return this->cena + this->cenaBiznis - (this->cena+this->popust) + 1000.00;
        if(!rucek && !bagazDop) return this->cena + this->cenaBiznis - (this->cena+this->popust);
    }
    void pecati() const override {
        cout<<"Ime: "<<patuvac<<endl;
        cout<<"Pasosh: "<<endl;
        for(int i=0;i<10;i++) {
            cout<<pasosh[i];
        }
        cout<<"Cena: "<<cena<<endl;
        cout<<"Popust: "<<popust<<endl;
        cout<<"Poagja od: "<<poagja<<endl;
        cout<<"Pristignuva vo: "<<pristignuva<<endl;
        if(rucek) {
            cout<<"Rucek: ima"<<endl;
        }
        else cout<<"Rucek: nema"<<endl;
    }
    if(bagazDop) {
        cout<<"Dopolnitelen bagaz: ima"<<endl;
        cout<<"Cena za dopolnitelen bagaz: "<<cenaBD<<endl;
    }
    else {
        cout<<"Dopolnitelen bagaz: nema"<<endl;
    }
}
int main() {

    return 0;
}