#ifndef ZADNEKOJA_KOMPJUTER_H
#define ZADNEKOJA_KOMPJUTER_H
#include <string>
#include <iostream>
#include "defekt.h"
using namespace std;

class kompjuter {
private:
    string ime;
    string sopstvenik;
    int brDef;
    defekt *def;
public:
    kompjuter() = default;
    kompjuter(string ime,string sopstvenik,int brDef);
    kompjuter(const kompjuter &praten); // copy
    ~kompjuter(){
        delete def;
    };
    //set
    void setIme(const string &ime);
    void setSopstvenik(const string &sopstvenik);
    void addDef(const defekt &praten);
    //get
    string getIme() const;
    string getSopstvenik() const;
    defekt getDefekt(int i) const;
    int getBrDef() const;
    //funkcii
    void getProblemi(datum pocetok,datum kraj) const;
};


#endif //ZADNEKOJA_KOMPJUTER_H
