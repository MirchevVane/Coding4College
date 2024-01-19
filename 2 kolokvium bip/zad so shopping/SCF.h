#include <cstring>

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

    bool voRok(struct datum today){
        if(today.year>=produced.year){
            if(today.month>produced.month){
                return true;
            }else if(today.month==produced.month){
                printf("Product expires this month\n");
                return true;
            }
        }
        return false;
    }

    void prodadi(){
        price=0.0;
    }

};

class ShoppingCenter{
private:
    char name[30];
    char street[15];
    struct proizvod items[100];
    int numOfItems;
    float newPrices[100];
public:
    ShoppingCenter(char *nameE,char *streetE,struct proizvod itemsE[100],int numOfItemsE,float newPricesE[100]);
    ~ShoppingCenter()=default;

    int proverka(struct datum today);

    float getNeto(char *typeE);
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

ShoppingCenter::ShoppingCenter(char *nameE, char *streetE, struct proizvod *itemsE, int numOfItemsE, float *newPricesE) {
    strcpy(name,nameE);
    strcpy(street,streetE);
    numOfItems=numOfItemsE;
    for(int i=0;i<numOfItemsE;i++) {
        items[i]=itemsE[i];
        newPrices[i]=newPricesE[i];
    }
}



