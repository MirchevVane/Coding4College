/*Потребно е да се напише програма за работа со фирми и даночни потврди. Вашата задача се состои од
следното:
 Конципирање на структурата со соодветните елементи и функции,
 Имплементација на програмските барања и функции
 Целата програма да се концепира во една датотека (не во повеќе)
Класа Фирма ги содржи следниве информации:
 Име на фирмата (низа од најмногу 30 знаци)
 Адреса (низа од најмногу 40 знаци)
 Буџет на фирмата (цел број)
 Дејност (број 1, 2 или 3)
 Листа од даночни потврди (динамично алоцирана листа од структури од тип даночна потврд) 
 Колку даночни потврди има поднесено
Структура Даночна потврда ги содржи следниве информации:
 Име на вработениот за кој се поднела даночната потврда(динамично алоцирана листа од знаци)
 Матичен број (низа од 13 броеви)
 Колку е платено бруто износ (цел број)
 Колку е платено нето износ (цел број) 
 Колку се одбитоците (цел број) 
За класата, да се напишат потребните конструктори/дестркутори/функции/SET/GET функции. Исто така да се
напишат и следниве функции:
- Функција proverka која што проверува дали вкупното бруто од сите поднесени даночни потврди минус
вкупните одбитоци од даночните потврди е поголемо од буџетот на фирмата. Доколку е, тогаш враќа
неточно, инаку враќа точно.
- Функција getNeto која како аргумент добива матичен број на вработениот за кој е поднесена даночна
пријава и за таа даночна пријава го враќа нетото што е платено. Доколку функцијата се повика со два
броеви, тогаш враќа вкупно нето на вработените од позицијата на првиот број до позицијата на вториот
број. Доколку функцијата се повика со празни загради, тогаш го враќа вкупното нето на целата листа. 
Во главната програма да се дефинира една фирма со три даночни потврди и да се отпечати матичниот број на
вработениот кој што има најголема вредност за нето.*/

#include<iostream>
using namespace std;
#include<string>
struct danocna{
    char *vraboten;
    string maticen;
    int bruto;
    int neto;
    int odbitok;
    vraboten=new char[30];
}
class firma{
    private:
    string ime;
    string adresa;
    int budzet;
    int dejnost;
    struct danocna *danocni;
    int kolku;
    public:
    firma(string ime, string adresa, int budzet, int dejnost, struct danocna *danocni, int odbitoci) {
        this->ime=move(ime);
        this->adresa=move(adresa);
        this->budzet=budzet;
        this->dejnost=dejnost;
        this->danocni=new struct danocna[kolku];
        this->odbitoci=odbitoci;
    }
    ~firma()=default;
    //set
    void setIme(string ime) {
        this->ime=move(ime);
    }
    void setAdresa(string adresa) {
        this->adresa=move(adresa);
    }
    void setBudzet(int budzet) {
        this->budzet=budzet;
    }
    void setDejnost(int dejnost) {
        this->dejnost=dejnost;
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

    //- Функција proverka која што проверува дали вкупното бруто од сите поднесени даночни потврди минус
//вкупните одбитоци од даночните потврди е поголемо од буџетот на фирмата. Доколку е, тогаш враќа
//неточно, инаку враќа точно.
    bool proverka() {
        int vkBruto=0;
        int vkOdbitoci=0;
        for(int i=0;i<kolku;i++) {
            vkBruto=vkBruto+danocni[i].bruto;
            vkOdbitoci=vkOdbitoci+danocni[i].odbitok;
        }
        if(vkBruto-vkOdbitoci<budzet) {
            return true;
        }
        else if(vkBruto-vkOdbitoci==budzet) {
            cout<<"Brutoto minus odbitocite se isti so budzetot"<<endl;
        }
        else {
            return false;
        }
    }

    /*Функција getNeto која како аргумент добива матичен број на вработениот за кој е поднесена даночна
пријава и за таа даночна пријава го враќа нетото што е платено. Доколку функцијата се повика со два
броеви, тогаш враќа вкупно нето на вработените од позицијата на првиот број до позицијата на вториот
број. Доколку функцијата се повика со празни загради, тогаш го враќа вкупното нето на целата листа. 
Во главната програма да се дефинира една фирма со три даночни потврди и да се отпечати матичниот број на
вработениот кој што има најголема вредност за нето.*/

int getNeto(string maticen) {
    for(int i=0;i<kolku;i++) {
        if(danocni[i].maticen==maticen) {
            return danocni[i].neto;
        }
    }
}
int getNeto(string maticen1, string maticen2) {
    int vkupno=0;
    for(int i=0;i<kolku;i++) {
        if(maticen1==danocni[i].maticen)
        for(int j=i;j<kolku;j++) {
            vkupno+=danocni[i].neto;
            if(maticen2==danocni[j].maticen) {
                return vkupno;
            }
        }
    }
}
int getNeto() {
    int vkupno=0;
    for(int i=0;i<kolku;i++) {
        vkupno=vkupno+danocni[i].neto;
    }
    return vkupno;
}
}
int main() {


    return 0;
}