//
// Created by marko on 5/14/2021.
//

#include "defekt.h"
#include <iostream>
defekt::defekt(string opis,datum prijaven,datum popraven){
    this->opis=move(opis);
    this->prijaven=prijaven;
    this->popraven=popraven;
}

void defekt::setOpis(string &opis) {
    this->opis = move(opis);
}
void defekt::setPrijaven(datum &prijaven){
    this->prijaven=prijaven;
}
void defekt::setPopraven(datum &popraven){
    this->popraven=popraven;
}
string defekt::getOpis() const{
    return this->opis;
}
datum defekt::getPrijaven() const{
    return this->prijaven;
}
datum defekt::getPopraven() const{
    return this->popraven;
}
void defekt::getInfo() const{
    cout<<opis<<endl;
    cout<<prijaven.den<<"/"<<prijaven.mesec<<"/"<<prijaven.godina<<endl;
    cout<<popraven.den<<"/"<<popraven.mesec<<"/"<<popraven.godina<<endl;
}