#include <cstring>
#include <string>
using namespace std;

struct datum{
    int month;
    int year;
};

struct proizvod{
    char name[30];
    char type[10];
    int price;
    float size;
    char countryOfOrigin[20];
    struct datum produced;

    bool voRok(struct datum today) const{
        if(today.year==produced.year){
            if(today.month<produced.month){
                return true;
            }else if(today.month==produced.month){
                printf("Product expires this month\n");
                return true;
            }
        }else if(today.year<produced.year){
            return true;
        }
        return false;
    }

    void prodadi(){
        price=0;
    }

};

class ShoppingCenter{
private:
    string name;
    string street;
    struct proizvod items[100]{};
    int numOfItems;
    int newPrices[100]{};
public:
    //default constructor
    ShoppingCenter(string nameE,string streetE,struct proizvod itemsE[100],int numOfItemsE,int newPricesE[100]);
    ~ShoppingCenter() {};

    //functions
    int proverka(struct datum today);
    float getNeto(char *typeE);
    int razlika(int I){
        return abs(items[I].price-newPrices[I]);
    };

    //getters
    const string& getName() const{
        return name;
    }
    const string& getStreet() const{
        return street;
    }
    const int& getNumOfItems() const{
        return numOfItems;
    }
    void GetProducts() const{
        for(int i=0;i<numOfItems;i++){
            printf("%s %s %d %s %d/%d",items[i].name,items[i].type,items[i].price,items[i].countryOfOrigin,
                   items[i].produced.month,items[i].produced.year);
        }
    }

    //setters
    void setName(const string& newName){
        name=newName;
    }
    void setStreet(const string& newStreet){
        street=newStreet;
    }

};

int ShoppingCenter::proverka(struct datum today) {
    int total=0;
    for(int i=0;i<numOfItems;i++){
        if(items[i].produced.year>today.year){
            items[i].prodadi();
            newPrices[i]=0.0;
            total++;
        }else if(items[i].produced.year==today.year){
            if(items[i].produced.month>today.month){
                items[i].prodadi();
                newPrices[i]=0.0;
                total++;
            }
        }
    }
    return total;
}

float ShoppingCenter::getNeto(char *typeE) {
    float total=0.0;
    for(int i=0;i<numOfItems;i++){
        if(!strcmp(items[i].type,typeE)){
            return items[i].size;
        }
    }
    for(int i=0;i<numOfItems;i++){
        total+=items[i].size;
    }
    return total;
}

ShoppingCenter::ShoppingCenter(string nameE,string streetE,struct proizvod itemsE[100],int numOfItemsE,int newPricesE[100]) {
    name=move(nameE);
    street=move(streetE);
    numOfItems=numOfItemsE;
    for(int i=0;i<numOfItemsE;i++) {
        items[i]=itemsE[i];
        newPrices[i]=newPricesE[i];
    }
}