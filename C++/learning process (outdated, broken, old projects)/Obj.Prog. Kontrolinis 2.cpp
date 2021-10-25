// Obj.Prog. Kontrolinis 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class Kelnes {
    string kelnes_pavadinimas;
    string kelnes_tipas;
    double kelnes_kaina;
    int kelnes_dydis;
    int kelnes_sudetingumas;
    double kelnes_galutine_kaina;
public:
    Kelnes() {
        kelnes_pavadinimas = "";
        kelnes_tipas = "";
        kelnes_kaina = 0;
        kelnes_dydis = 0;
        kelnes_sudetingumas = 0;
        kelnes_galutine_kaina = 0;
    }
    Kelnes(string pavadinimas, string tipas, double kaina, int dydis, int sudetingumas) {
        setKelnes_pavadinimas(pavadinimas);
        setKelnes_tipas(tipas);
        setKelnes_kaina(kaina);
        setKelnes_dydis(dydis);
        setKelnes_sudetingumas(sudetingumas);
        kelnes_galutine_kaina = calcGalutine_kaina(dydis, sudetingumas);
    }

    //setter
    void setKelnes_pavadinimas(string a) {
        kelnes_pavadinimas = a;
    }
    void setKelnes_tipas(string a) {
        kelnes_tipas = a;
    }
    void setKelnes_kaina(double a) {
        kelnes_kaina = a;
    }
    void setKelnes_dydis(int a) {
        kelnes_dydis = a;
    }
    void setKelnes_sudetingumas(int a) {
        kelnes_sudetingumas = a;
    }

    //getter
    string getKelnes_pavadinimas() {
        return kelnes_pavadinimas;
    }

    string getKelnes_tipas() {
        return kelnes_tipas;
    }
    double getKelnes_kaina() {
        return kelnes_kaina;
    }
    int getKelnes_dydis() {
        return kelnes_dydis;
    }
    int getKelnes_sudetingumas() {
        return kelnes_sudetingumas;
    }
    double getKlenes_galutine_kaina() {
        return kelnes_galutine_kaina;
    }
    //functions
    
    //kam tada kaina jai mes jos nenaudojam (pagal uzduoti) sitame skaiciavime?
    double calcGalutine_kaina(int dydis, int sudetingumas) {
        double galutine_kaina;
        galutine_kaina = dydis * sudetingumas;
        return galutine_kaina;
    }
    void kelnes_printAll() {
        cout << "----------------------------------------- " << endl;
        cout << "Kelnes: " << endl;
        cout << "kelnes pavadinimas: " << getKelnes_pavadinimas() << endl;
        cout << "kelnes tipas: " << getKelnes_tipas() << endl;
        cout << "kelnes kaina: " << getKelnes_kaina() << endl;
        cout << "kelnes dydis: " << getKelnes_dydis() << endl;
        cout << "kelnes sudetingumas: " << getKelnes_sudetingumas() << endl;
        cout << "kelnes galutine_kaina: " << kelnes_getGalutineKaina() << endl;
        cout << "----------------------------------------- " << endl;
    }
    double kelnes_getGalutineKaina() {
        return kelnes_galutine_kaina;
    }
};

class Virsus {
    string virsus_pavadinimas;
    string virsus_tipas;
    double virsus_kaina;
    int virsus_dydis;
    int virsus_sudetingumas;
    double virsus_galutine_kaina;
public:
    Virsus() {
        virsus_pavadinimas = "";
        virsus_tipas = " ";
        virsus_kaina = 0;
        virsus_dydis = 0;
        virsus_sudetingumas = 0;
        virsus_galutine_kaina = 0;
    }
    Virsus(string pavadinimas, string tipas, double kaina, int dydis, int sudetingumas) {
        setVirsus_pavadinimas(pavadinimas);
        setVirsus_tipas(tipas);
        setVirsus_kaina(kaina);
        setVirsus_dydis(dydis);
        setVirsus_sudetingumas(sudetingumas);
        virsus_galutine_kaina = calcGalutine_kaina(dydis, sudetingumas);
    }

    //setteriai
    void setVirsus_pavadinimas(string a) {
        virsus_pavadinimas = a;
    }
    void setVirsus_tipas(string a) {
        virsus_tipas = a;
    }
    void setVirsus_kaina(double a) {
        virsus_kaina = a;
    }
    void setVirsus_dydis(int a) {
        virsus_dydis = a;
    }
    void setVirsus_sudetingumas(int a) {
        virsus_sudetingumas = a;
    }

    //getteriai
    string getVirsus_pavadinimas() {
        return virsus_pavadinimas;
    }
    string getVirsus_tipas() {
        return virsus_tipas;
    }
    double getVirsus_kaina() {
        return virsus_kaina;
    }
    int getVirsus_dydis() {
        return virsus_dydis;
    }
    int getVirsus_sudetingumas() {
        return virsus_sudetingumas;
    }
    double getVirsus_galutine_kaina() {
        return virsus_galutine_kaina;
    }


    //kam tada kaina jai mes jos nenaudojam (pagal uzduoti) sitame skaiciavime?
    double calcGalutine_kaina(int dydis, int sudetingumas) {
        double galutine_kaina;
        galutine_kaina = dydis * sudetingumas;
        return galutine_kaina;
    }
    void virsus_printAll() {
        cout << "----------------------------------------- " << endl;
        cout << "Virsus: " << endl;
        cout << "virsus pavadinimas: " << getVirsus_pavadinimas() << endl;
        cout << "virsus tipas: " << getVirsus_tipas() << endl;
        cout << "virsus kaina: " << getVirsus_kaina() << endl;
        cout << "virsus dydis: " << getVirsus_dydis() << endl;
        cout << "virsus sudetingumas: " << getVirsus_sudetingumas() << endl;
        cout << "virsus galutine_kaina: " << getVirsus_galutine_kaina() << endl;
        cout << "----------------------------------------- " << endl;
    }
    double virsus_getGalutineKaina() {
        return virsus_galutine_kaina;
    }
};

class Komplektas {
    Virsus virsus;
    Kelnes kelnes;
    double kaina;
    double akcija;
public:
    Komplektas() {
        kaina = 0;
        akcija = 0;
    }
    Komplektas(class Virsus a, class Kelnes b) {
        virsus = a;
        kelnes = b;
        apskaicuotiKaina();
    }
    void apskaicuotiKaina() {
        kaina = virsus.virsus_getGalutineKaina() + kelnes.kelnes_getGalutineKaina();
    }
    void komplektas_PrintAll(int akcija) {
        cout << "----------------------------------------- " << endl;
        cout << "Komplektas: " << endl;
        virsus.virsus_printAll();
        kelnes.kelnes_printAll();
        cout << "Komplekto kaina: " << kaina << endl;
        cout << "Akcija: " << akcija << endl;
        if (akcija == 0) {
            cout << "Kaina su akcija: " << kaina  << endl;
            cout << "----------------------------------------- " << endl;
            return;
        }
        cout << "Kaina su akcija: " << kaina - kaina * akcija/100 << endl;
        cout << "----------------------------------------- " << endl;
    }
};

class Parduotuve{
    vector <Kelnes> kelnes;
    vector <Virsus> virsus;
    vector <Komplektas> komplektas;
    int akcija;
public:
    Parduotuve() {
        akcija = 0;
    }

    void idetiKelnes(string pavadinimas, string tipas, double kaina, int dydis, int sudetingumas) {
        kelnes.push_back(Kelnes(pavadinimas, tipas, kaina, dydis, sudetingumas));
    }

    void idetiVirsus(string pavadinimas, string tipas, double kaina, int dydis, int sudetingumas) {
        virsus.push_back(Virsus(pavadinimas, tipas, kaina, dydis, sudetingumas));
    }

    void idetiKomplektas(class Virsus a, class Kelnes b) {
        komplektas.push_back(Komplektas(a, b));
    }

    void perziuretiKelnes(){
        kelnes[0].kelnes_printAll();
    }

    void perziuretiVirsus() {
        virsus[0].virsus_printAll();
    }

    void setAkcija(int a) {
        akcija = a;
    }

    void perziuretiKomplektas(int akcija) {
        komplektas[0].komplektas_PrintAll(akcija);
    }



    void start() {
        
        idetiKelnes("BlueJeans", "dzinsai", 70, 5, 84);
        perziuretiKelnes();
        idetiVirsus("RedJumper","megztinis", 70, 5, 84);
        perziuretiVirsus();
        idetiKomplektas(virsus[0],kelnes[0]);
        perziuretiKomplektas(akcija);
        setAkcija(50);
        perziuretiKomplektas(akcija);

    }
};

int main()
{
    Parduotuve maxima;

    maxima.start();
}