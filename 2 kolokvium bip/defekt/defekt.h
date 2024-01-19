#ifndef ZADNEKOJA_DEFEKT_H
#define ZADNEKOJA_DEFEKT_H
#include <string>
using namespace std;
typedef struct{
    int den;
    int mesec;
    int godina;
}datum;

class defekt {
private:
    string opis;
    datum prijaven;
    datum popraven;
public:
    defekt() = default;
    defekt(string opis,datum prijaven,datum popraven);
    ~defekt() = default;
    //set
    void setOpis(string &opis);
    void setPrijaven(datum &prijaven);
    void setPopraven(datum &popraven);
    //get
    string getOpis() const;
    datum getPrijaven() const;
    datum getPopraven() const;
    //getinfo
    void getInfo() const;

};

#endif //ZADNEKOJA_DEFEKT_H
