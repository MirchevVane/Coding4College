/*Да се напише класа Prostor од која ќе бидат изведени класи StanbenProstor и MaloprodazenProstor.
Во класата Prostor се чува локацијата (како динамичка низа од знаци), квадратурата на просторот
и основната цена по метар квадратен. За класата StanbenProstor се чува информација за бројот на
паркинг места кои сопственикот сака да ги купи. За класата MaloprodazenProstor се чува
информација за бројот на брендови кои ги носи групацијата што го изнајмува просторот.
За секоја од класите да се напише функција presmetaj_cena() која ја пресметува цената за
соодветниот простор. Вкупната основна цена на простор се пресметува како производ од
квадратурата на просторот и основната цена по метар квадратен. Цената на станбен простор се
пресметува на тој начин што на вкупната основна цена се додаваат 5000 за секое купено паркинг
место. Цената на малопродажен простор се пресметува на тој начин што вкупната основната цена
се намалува за онолку проценти колку што групацијата има брендови.
Дополнително, за класите да се напише функција pechati() која ги печати податоците за објект од
соодветната класа, да се напишат конструктори со default параметри, copy конструктор и да се
преоптовари операторот = за доделување.
Надвор од класите да се напише функција која како аргументи прима два парамтери: низа од
покажувачи кон простори независни од типот на просторот и бројот на простори, а истата го
наоѓа најефтиниот простор и за него ги печати сите информации.
Да се состави и главна функција во која треба да се тестира работата на функцијата.*/

class prostor
{
protected:
    char *lokacija;
    int kvadratura;
    int cena;
public:
    prostor(char *l=NULL, int k=0, int c=0)
    {
        lokacija=new char[strlen(l)+1];
        strcpy(lokacija,l);
        kvadratura=k;
        cena=c;
    }
    prostor(const prostor &p)
    {
        lokacija=new char[strlen(p.lokacija)+1];
        strcpy(lokacija,p.lokacija);
        kvadratura=p.kvadratura;
        cena=p.cena;
    }
    prostor & operator=(prostor &p)
    {
        delete []lokacija;
        lokacija=new char[strlen(p.lokacija)+1];
        strcpy(lokacija,p.lokacija);
        kvadratura=p.kvadratura;
        cena=p.cena;
        return *this;
    }
    virtual float presmetajcena() =0;
    virtual ~prostor()
    {
        delete []lokacija;
    }
    void pechati()
    {
        cout<<lokacija<<" "<<kvadratura<<" "<<cena<<endl;
    }
};
class stanbenprostor : public prostor
{   
    protected:
    int parkingmesta;
public:
    stanbenprostor(char *l=NULL,int k=0,int c=0,int p=0) :prostor(l,k,c),parkingmesta(p) {}
    stanbenprostor(prostor &pr,int p=0) :prostor(pr),parkingmesta(p) {}
    stanbenprostor(const stanbenprostor &sp) :prostor(sp),parkingmesta(sp.parkingmesta) {}
    float presmetajcena()
    {
        float vkupno=kvadratura*cena;
        vkupno+=5000*parkingmesta;
        return vkupno;
    }
    void pecati()
    {
        prostor::pechati();
        cout<<parkingmesta<<endl;
    }
};
class maloprodazenprostor : public prostor
{   
    protected:
    int brojbrendovi;
public:
    maloprodazenprostor(char *l=NULL,int k=0,int p=0, int bb=0) :prostor(l,k,p),brojbrendovi(bb) {}
    maloprodazenprostor(prostor &pr,int bb=0) :prostor(pr),brojbrendovi(bb){}
    maloprodazenprostor(const maloprodazenprostor &m) :prostor(m),brojbrendovi(m.brojbrendovi) {}
    float presmetajcena()
    {
        float vkupno=kvadratura*cena;
        vkupno-=(vkupno*this->brojbrendovi)/100;
        return vkupno;
    }
    void pecati()
    {
        prostor::pechati();
        cout<<brojbrendovi<<endl;
    }
};
bool sporedi(prostor *p1,prostor *p2)
{
    if(p1->presmetajcena() < p2->presmetajcena())
        return 1;
    else
        return 0;
}
void najeftin(prostor *p,int b)
{
    prostor *najmal;
    najmal=p[0];
    for(int i=0;i<b;i++)
    {
        if(sporedi(p[i],najmal))
            najmal=p[i];
    }
    najmal.pechati();
}
int main()
{
    prostor p[2];
    stanbenprostor sp("skopje",30,500,2);
    maloprodazenprostor m("kumanovo",20,200,5);
    p[0]=&sp;
    p[1]=&m;
    najeftin(p,2);
}