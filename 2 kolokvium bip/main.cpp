/*Потребно е да се напише програма за работа со студенти и лабораториски вежби. За секој студент
треба да се креира структура каде се чуваат информации за број на индекс, листа од оцени (листа
од цели броеви најмногу 40) и број на оценки (должина на листата). Во рамки на структурата
треба да се напишат следниве функции:
Функција која го враќа просекот на студентот (просечна вредност од оцените).
 - Функција која враќа дали студентот има добиено награда (дали има просек над 9.0).
Печатање на податоците за студентот во произволен формат

Потоа, да се напише друга структура за опис на една лабораториска група. За секоја
лабораториска група се чуваат информации за листа од студенти (структури студент најмногу 20),
број на студенти и листа со број на лабораториски вежби кои ги има изработено секој од
студентите (поле со цели броеви од 0 до 10). За класата треба да се напишат следниве функции:

Функција која враќа колку вежби има одработено даден студент чиј индекс се праќа како
аргумент на функцијата. Доколку студентот не е во таа група, функцијата враќа -1
Функција која враќа колку студенти може да добијат потпис (имаат најмалку 8 вежби)
Функција која како аргументи ги добива сите податоци потребни за сместување
на информации во структурата Лабораториска Група.

Да се напише главна програма во која ќе се внесат податоци за една лабораториска група со N
студенти и да се отпечатат студентите од таа група кои што имаат просек над 9.0. и колку такви
студенти има.*/

#include <iostream>
using namespace std;

struct student {
    int indeks;
    int broceni;
    int ocena [40];

    static bool prosek(student s) {
        int i;
        float avg;
        for(i=0;i<s.broceni;i++) {
            avg=avg+s.ocena[i];
        }
        avg=avg/s.broceni;
        if(avg>9.0) {
            cout<<"Studentot so indeks br: "<<s.indeks<<" ima prosek nad 9.0"<<endl;
            return true;
        }
        return false;
    }

    static void printaj(student s) {
        cout<<"Br na indeks: "<<s.indeks<<endl;
        cout<<"Oceni"<<endl;
        for(int i=0;i<s.broceni;i++) {
            cout<<s.ocena[i]<<endl;
        }
    }
};


struct grupa {
    int indeksi[10];
};


struct laboratoriska{
    struct grupa group;
    struct student studenti[20];
    int brstud;
    int izraboteni[10];

    static bool izrabotil(struct student s,struct laboratoriska lab) {
        int i, j;
        int check;
        for (j = 0; j < lab.brstud; j++) {
            if (s.indeks == lab.group.indeksi[j]) {
                cout << "Studentot so broj na indeks " << lab.studenti[i].indeks << "pripagja na grupata" << endl;
                return true;
            }
        }
        return false;
    }

    static void potpis(struct laboratoriska l) {
        int i;
        for(i=0;i<l.brstud;i++) {
            if(l.izraboteni[i]>8) {
                cout << "Studentot so br. na indeks" << l.studenti[i].indeks << "dobiva potpis" << endl;
            }else{
                cout << "Studentot so br. na indeks" << l.studenti[i].indeks << "ne dobiva potpis" << endl;
            }
        }
    }
};
/*
 * Да се напише главна програма во која ќе се внесат податоци за една лабораториска група со N
студенти и да се отпечатат студентите од таа група кои што имаат просек над 9.0. и колку такви
студенти има.
 */
int main() {
    int N,i,j,s9=0;
    bool check;
    struct laboratoriska lab;

    cout<<"Vnesi broj na studenti"<<endl;
    cin>>N;
    lab.brstud=N;
    for(i=0;i<lab.brstud;i++){
        cout<<"Indeks na studnent"<<endl;
        cin>>lab.studenti[i].indeks;
        cout<<"Broj na ocenki"<<endl;
        cin>>lab.studenti[i].broceni;
        for(j=0;j<lab.studenti[i].broceni;j++){
            cout<<"Vnesi ocena"<<endl;
            cin>>lab.studenti[i].ocena[j];
        }
        cout<<"Izraboteni lab vezbi"<<endl;
        cin>>lab.izraboteni[i];
    }
    for(i=0;i<lab.brstud;i++){
        check = lab.studenti[i].prosek(lab.studenti[i]);
        if(check){
            s9++;
        }
    }
    cout<<s9<<" studenti imaat prosek nad 9.0"<<endl;

    return 0;
}
