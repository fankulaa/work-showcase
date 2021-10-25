// Obj.Prog. Kontrolinis 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Kompiuteris {
protected:
    int ram_kiekis;
    int ssd_kiekis;
    string cpu_pavadiniams;
public:
    Kompiuteris() {
        ram_kiekis = 0;
        ssd_kiekis = 0;
        cpu_pavadiniams = " ";
    }
    Kompiuteris(int ram_k, int ssd_k, string cpu_pav) {
        ram_kiekis = ram_k;
        ssd_kiekis = ssd_k;
        cpu_pavadiniams = cpu_pav;
    }
    void kompiuterisPrintAll() {
        cout << "Kompiuteris: \n" << endl;
        cout << "ram_kiekis: "<<ram_kiekis << endl;
        cout << "ssd_kiekis: "<< ssd_kiekis << endl;
        cout <<"cpu_pavadiniams: "<< cpu_pavadiniams << endl;
    }
};

class Nesiojamas_Kompiuteris: public Kompiuteris {
    int baterijos_dydis;
    int svoris;
    int pakrovejo_galingumas;
public:
    Nesiojamas_Kompiuteris() {
        baterijos_dydis = 0;
        svoris = 0;
        pakrovejo_galingumas = 0;
        ram_kiekis = 0;
        ssd_kiekis = 0;
        cpu_pavadiniams = " ";
    }
    Nesiojamas_Kompiuteris(int ram_k, int ssd_k, string cpu_pav,int bat_d,int sv,int pakr_g) {
        ram_kiekis = ram_k;
        ssd_kiekis = ssd_k;
        cpu_pavadiniams = cpu_pav;
        baterijos_dydis = bat_d;
        svoris = sv;
        pakrovejo_galingumas = pakr_g;

    }
    void nesiojamas_kompiuterisPrintAll(){
        cout << "Nesiojamas kompiuteris: \n" << endl;
        cout << "baterijos_dydis: " << baterijos_dydis << endl;
        cout << "svoris: " << svoris << endl;
        cout << "pakrovejo_galingumas: " << pakrovejo_galingumas << endl;
        cout << endl;
        cout << endl;
        kompiuterisPrintAll();

    }
};

int main()
{
    Nesiojamas_Kompiuteris nesiojamas_kompiuteris(69, 70, "Epic cpu", 71, 72, 73);

    nesiojamas_kompiuteris.nesiojamas_kompiuterisPrintAll();
}