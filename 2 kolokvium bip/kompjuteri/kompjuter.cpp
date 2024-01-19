//
// Created by marko on 5/14/2021.
//

#include "kompjuter.h"

kompjuter::kompjuter(string ime,string sopstvenik,int brDef){
    def = new defekt[brDef];
    this->ime=move(ime);
    this->sopstvenik=move(sopstvenik);
    this->brDef=brDef;
}

kompjuter::kompjuter(const kompjuter &praten){ // copy
    this->ime=praten.ime;
    this->sopstvenik=praten.sopstvenik;
    this->brDef=praten.brDef;
    if(!brDef) {
        for (int i = 0; i < brDef; i++) {
            this->def[i] = praten.def[i];
        }
    }
}

void kompjuter::setIme(const string &ime){
    this->ime=ime;
}
void kompjuter::setSopstvenik(const string &sopstvenik){
    this->sopstvenik=sopstvenik;
}
void kompjuter::addDef(const defekt &praten){
    brDef++;
    def=new defekt[brDef];
    def[brDef-1]=praten;
}
string kompjuter::getIme() const{
    return this->ime;
}
string kompjuter::getSopstvenik() const{
    return this->sopstvenik;
}
defekt kompjuter::getDefekt(int i) const{
    if(!brDef && i<=brDef){
        return this->def[i-1];
    }else return defekt();
}
int kompjuter::getBrDef() const{
    return this->brDef;
}
void kompjuter::getProblemi(datum pocetok,datum kraj) const{
    datum prijaven;
    for(int i=0;i<brDef;i++){
        prijaven=def[i].getPrijaven();
        if(pocetok.godina<=prijaven.godina && kraj.godina>=prijaven.godina){
            if(pocetok.mesec<=prijaven.mesec && kraj.mesec>=prijaven.mesec){
                if(pocetok.den<=prijaven.den && kraj.den>=prijaven.den){
                    def[i].getInfo();
                }
            }
        }
    }
};
