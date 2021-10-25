#include <iostream>
#include <vector>

using namespace std;

class Knyga {
    string autorius;
    string pavadinimas;
    string ISBN;
    string leidykla;
    int leidimo_metai = 0;
    int vienetu_kiekis = 0;
public:
    Knyga() {
        autorius = " ";
        pavadinimas = " ";
        ISBN = " ";
        leidykla = " ";
        leidimo_metai = 0;
        vienetu_kiekis = 0;
    }
    Knyga(string autorius, string pavadinimas, string ISBN, string leidykla, int leidimo_metai, int vienetu_kiekis) {
        knygaSetAll(autorius, pavadinimas, ISBN, leidykla, leidimo_metai, vienetu_kiekis);
    }



    void knygaSetAutorius(string a) {
        autorius = a;
    }
    string knygaGetAutorius() {
        return autorius;
    }

    void knygaSetPavadinimas(string a) {
        pavadinimas = a;
    }
    string knygaGetPavadinimas() {
        return pavadinimas;
    }

    void knygaSetISBN(string a) {
        ISBN = a;
    }
    string knygaGetISBN() {
        return ISBN;
    }

    void knygaSetLeidykla(string a) {
        leidykla = a;
    }
    string knygaGetLeidykla() {
        return leidykla;
    }

    void knygaSetLeidimo_metai(int a) {
        leidimo_metai = a;
    }
    int knygaGetLeidimo_metai() {
        return leidimo_metai;
    }

    void knygaSetVienetu_kiekis(int a) {
        vienetu_kiekis = a;
    }
    int knygaGetVienetu_kiekis() {
        return vienetu_kiekis;
    }

    //builder
    void knygaSetAll(string autorius,string pavadinimas,string ISBN,string leidykla,int leidimo_metai,int vienetu_kiekis) {

        knygaSetAutorius(autorius);
        knygaSetPavadinimas(pavadinimas);
        knygaSetISBN(ISBN);
        knygaSetLeidykla(leidykla);
        knygaSetLeidimo_metai(leidimo_metai);
        knygaSetVienetu_kiekis(vienetu_kiekis);
    }

    //printer
    void knygaPrintAll() {
        cout << "----------------------------------------------------------" << endl;
        cout <<"autorius: "<< autorius << endl;
        cout <<"pavadinimas: "<< pavadinimas << endl;
        cout <<"ISBN: "<< ISBN << endl;
        cout <<"leidykla: "<< leidykla << endl;
        cout << "leidimo metai: " << leidimo_metai << endl;
        cout <<"vienetukiekis: " <<vienetu_kiekis << endl;
        cout << "----------------------------------------------------------" << endl;
    }

    string cinString() {
        string a;
        cin >> a;
        return a;
    }

    int cinInt() {
        int a;
        cin >> a;
        return a;
    }
};

class Lentyna:public Knyga{
    string pozicija;
    int talpumas = 0;
    int aukstu_kiekis = 0;
    int vienetu_kiekis = 0;
    vector <Knyga> knyga;
public:
    Lentyna() {
        pozicija = " ";
        talpumas = 0;
        aukstu_kiekis = 0;
        vienetu_kiekis = 0;
    }
    Lentyna(string pozicija, int talpumas, int aukstu_kiekis, int vienetu_kiekis) {
        lentynaSetAll(pozicija, talpumas, aukstu_kiekis, vienetu_kiekis);
    }

    void lentynaSetPozicija(string a) {
        pozicija = a;
    }
    string lentynaGetPozicija() {
        return pozicija;
    }

    void lentynaSetTalpumas(int a) {
        talpumas = a;
    }
    int lentynaGetTalpumas() {
        return talpumas;
    }

    void lentynaSetAukstu_kiekis(int a) {
        aukstu_kiekis = a;
    }
    int lentynaGetAukstu_kiekis() {
        return aukstu_kiekis;
    }

    void lentynaSetVienetu_kiekis(int a) {
        vienetu_kiekis = a;
    }
    int lentynaGetVienetu_kiekis() {
        return vienetu_kiekis;
    }

    //pushback
    void idetiKyngaILentyna(string autorius, string pavadinimas, string ISBN, string leidykla, int leidimo_metai, int vienetu_kiekis) {
        knyga.push_back(Knyga(autorius, pavadinimas, ISBN, leidykla, leidimo_metai, vienetu_kiekis));
    }

    //builder
    void lentynaSetAll(string pozicija,int talpumas,int aukstu_kiekis,int vienetu_kiekis) {
        lentynaSetPozicija(pozicija);
        lentynaSetTalpumas(talpumas);
        lentynaSetAukstu_kiekis(aukstu_kiekis);
        lentynaSetVienetu_kiekis(vienetu_kiekis);
    }

    //printer
    void lentynaPrintAll() {
        cout << "----------------------------------------------------------" << endl;
        cout << "pozicija: " << pozicija << endl;
        cout << "talpumas: " << talpumas << endl;
        cout << "aukstu_kiekis: " << aukstu_kiekis << endl;
        cout << "vienetu_kiekis: " << vienetu_kiekis << endl;
        cout << "knygos: " << endl;
        knyga[0].knygaPrintAll();
        cout << "----------------------------------------------------------" << endl;
    }
};

class Biblioteka:public Lentyna{
    vector <Lentyna> lentyna;
public:
    void idetiLentynaIBiblioteka(string pozicija, int talpumas, int aukstu_kiekis, int vienetu_kiekis) {
        lentyna.push_back(Lentyna(pozicija, talpumas, aukstu_kiekis, vienetu_kiekis));
    }

    void start() {
        string pozicija;
        int talpumas=0; 
        int aukstu_kiekis=0;
        int vienetu_kiekis=0;

        cout << "----------------------------------------------------------" << endl;
        cout << "Lentynos sukurimas" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Pozicija: ";
        pozicija = cinString();
        cout << "\nTalpumas: ";
        talpumas = cinInt();
        cout << "\nAukstu Kiekis: ";
        aukstu_kiekis = cinInt();
        cout << "\nVienetu Kiekis: ";
        vienetu_kiekis = cinInt();

        idetiLentynaIBiblioteka(pozicija, talpumas, aukstu_kiekis, vienetu_kiekis);

        string autorius;
        string pavadinimas;
        string ISBN;
        string leidykla;
        int leidimo_metai=0;
        int vienetu_kiekis2=0;

        cout << "----------------------------------------------------------" << endl;
        cout << "Knygos sukurimas" << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "Autorius: ";
        autorius = cinString();
        cout << "\nPavadinimas: ";
        pavadinimas = cinString();
        cout << "\nISBN: ";
        ISBN = cinString();
        cout << "\nLeidykla: ";
        leidykla = cinString();
        cout << "\nLeidimo Metai: ";
        leidimo_metai = cinInt();
        cout << "\nVienetu kiekis: ";
        vienetu_kiekis2 = cinInt();

        idetiKyngaILentyna(autorius, pavadinimas, ISBN, leidykla, leidimo_metai, vienetu_kiekis2);  
    }
};


int main()
{
    Biblioteka biblioteka;

    biblioteka.start();
    biblioteka.lentynaPrintAll();
}