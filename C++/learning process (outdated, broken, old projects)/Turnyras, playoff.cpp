#include <iostream>
#include <math.h>

using namespace std;

class Treneris {
    string vardas, pavarde;
public:
    Treneris(string a, string b) {
        vardas = a;
        pavarde = b;
    }

Treneris() {


}

void atspaudinti() {
    cout << vardas << " " << pavarde << endl;
}
// funkcijoms vieta


};

class Komanda {
    string pavadinimas;
    Treneris treneris;
    int kiekL = 0;
    int kiekP = 0;
    int pelnyti = 0;
    int praleista = 0;

public:

    Komanda(string a, string b, string c) {
        pavadinimas = c;
        treneris = Treneris(a, b);

    }

    Komanda() {

    }

    int getKiekL() {
        int a;
        a = kiekL;
        return a;
    }
    void atspausdinti() {
        cout << pavadinimas << " - Treneris: ";
        treneris.atspaudinti();
    }

    void atspausdintiL() {
        cout << pavadinimas << " " << kiekL << " " << kiekP << " " << kiekL + kiekP << " " << pelnyti - praleista << endl;
    }



    void laimejo(int a, int b) {
        kiekL++;
        pelnyti = pelnyti + a;
        praleista = praleista + b;
        cout << endl;
        cout << "Laimejo : " << pavadinimas << endl;
        cout << endl;
    }

    void pralaimejo(int a, int b) {
        kiekP++;
        pelnyti = pelnyti + a;
        praleista = praleista + b;
    }
    int getPelnyti() {
        int a;
        a = pelnyti;
        return a;
    }


};

class Turnyras {

    Komanda komandos[16];
    int kiekK = 0;
    string turnyroTipas;
    int scoreBoard = 0;

public:
    Turnyras(string a) {
        turnyroTipas = a;
    }

    void pridetiKomanda(string a, string b, string c) {
        komandos[kiekK] = Komanda(a, b, c);
        kiekK++;

    }

    void atspausdinti() {
        for (int i = 0; i < kiekK; i++) {
            

        }

    }

    void atspausdintiLaimetoja(int i) {
        cout <<"LAIMEJO: "<< i + 1 << " komanda - "; komandos[i].atspausdinti();
    }
    
    int kasLaimejo(int a, int b) {

        
        
        if (komandos[a - 1].getKiekL() > komandos[b - 1].getKiekL()) {
            return a;
        }
        else {
            return b;
        }
        
    }
    

    void zaistiRungtynes(int a, int b, int tA, int tB) {
        if (tA > tB) {
            komandos[a - 1].laimejo(tA, tB);
            komandos[b - 1].pralaimejo(tB, tA);
        }
        else {
            komandos[a - 1].pralaimejo(tA, tB);
            komandos[b - 1].laimejo(tB, tA);

        }
    }

    void lentele() {
        cout << endl << endl;
        cout << "-------Spausdiname lentele-----------" << endl;
        cout << " Pavadinimas    Laimeta   Pralosta  Zaista   Balu_skirtumas  " << endl;
        for (int i = 0; i < kiekK; i++) {
            komandos[i].atspausdintiL();
        }


    }
    int komandaGetPelnyti(int a) {
        int b;
        b = komandos[a].getPelnyti();
        return b;
    }

    int ieskotiLaimetoju(int a) {



        for (int i = scoreBoard; i < kiekK; i++) {
            
            if (komandos[i].getKiekL() == a) {
                scoreBoard = i+1;
                return i;
            }

        }
    }
    void resetScoreBoard() {
        scoreBoard = 0;
    }
};

int main()
{
    Turnyras lkl("Sezonas");//4layeriai


    //daryta max komandos

    int tipas, kiekKomandu;

    cout << "Season(1) or playoff(2): ";
    cin >> tipas;
    cout << endl;



    if (tipas == 2) {

        cout << "Kiek komandu 2-16: ";
        cin >> kiekKomandu;
        cout << endl;

        for (int i = 0; i < kiekKomandu; i=i+2) { //vardas, pav, komandos pav.

            for (int j = 0; j < 2; j++) { //vardas, pav, komandos pav.

                string one, two, three;
                //cout << "Trenerio vardas ir pavarde, komandos pavadinimas" << endl;
                cin >> one >> two >> three;
                lkl.pridetiKomanda(one, two, three);
            }
            
            int t1, t2;
            //cout << "Pirmos bei antros komandos taskai" << endl;
            cin >> t1 >> t2;
            lkl.zaistiRungtynes(i+1,i+2,t1, t2); //komandos skaicius, komandos skaicius, score(team1), score(team2).
            
            
        }
        lkl.atspausdinti(); //playoff naudoti
        lkl.lentele();//naudoti sezone
        
        /*
        //pelnyti get test
        for (int i = 0; i < kiekKomandu; i++) {
            cout <<i+1<<" "<< lkl.komandaGetPelnyti(i) << endl;
        }
        

        
        //if using turn on kaslaimejo
        for (int i = 0; i < kiekKomandu/2; i=i+4) { //galima padaryti kad trackintu laimejimus ir is ju darytu 1vs1
            
            int pirmas, antras, trecias, ketvirtas; //eiliskumas del kas laimejo funkcijos;
            pirmas = i + 1;
            antras = i + 2;
            trecias = i + 3;
            ketvirtas = i + 4;

            int laimetojas1, laimetojas2;

            laimetojas1 = lkl.kasLaimejo(pirmas, antras);
            laimetojas2 = lkl.kasLaimejo(trecias, ketvirtas);
            
            lkl.zaistiRungtynes(laimetojas1, laimetojas2, lkl.komandaGetPelnyti(laimetojas1), lkl.komandaGetPelnyti(laimetojas2));
            lkl.lentele();//naudoti sezone
        }
        */

        //galima padaryti kad trackintu laimejimus ir is ju darytu 1vs1

        
        //dabar kur yra scoreboard'e, kiekviena karta kai gauna 2 pakeisti i paskutni liesta skaiciu +1;

        for (int i = 0; i < sqrt(kiekKomandu); i++) { //isimimas laimetoju

            int pirmas = 0, antras = 0;
            
            pirmas = lkl.ieskotiLaimetoju(1)+1;
            antras = lkl.ieskotiLaimetoju(1)+1;

            lkl.zaistiRungtynes(pirmas, antras, lkl.komandaGetPelnyti(pirmas), lkl.komandaGetPelnyti(antras));

            cout << "pirmas, antras: " << pirmas << " " << antras << endl;

        }

        lkl.lentele();//naudoti sezone
        lkl.resetScoreBoard();

        for (int i = 0; i < sqrt(kiekKomandu)/2; i++) { //isimimas laimetoju

            int pirmas = 0, antras = 0;

            pirmas = lkl.ieskotiLaimetoju(2) + 1;
            antras = lkl.ieskotiLaimetoju(2) + 1;

            lkl.zaistiRungtynes(pirmas, antras, lkl.komandaGetPelnyti(pirmas), lkl.komandaGetPelnyti(antras));

            cout << "pirmas, antras: " << pirmas << " " << antras << endl;

        }
        
        lkl.lentele();//naudoti sezone
        lkl.resetScoreBoard();

        for (int i = 0; i < (sqrt(kiekKomandu) / 2)/2; i++) { //isimimas laimetoju

            int pirmas = 0, antras = 0;

            pirmas = lkl.ieskotiLaimetoju(3) + 1;
            antras = lkl.ieskotiLaimetoju(3) + 1;

            lkl.zaistiRungtynes(pirmas, antras, lkl.komandaGetPelnyti(pirmas), lkl.komandaGetPelnyti(antras));

            cout << "pirmas, antras: " << pirmas << " " << antras << endl;
        }

        lkl.lentele();//naudoti sezone
        lkl.resetScoreBoard();
        cout << endl;
        cout << endl;

        for (int i = 0; i < ((sqrt(kiekKomandu) / 2) / 2) / 2; i++) { //isimimas laimetoju

            int pirmas = 0, antras = 0;

            pirmas = lkl.ieskotiLaimetoju(4) + 1;
            
            lkl.atspausdintiLaimetoja(pirmas-1);
        }
        


    }
    else if (tipas == 1) {
        cout << "Kiek komandu 2-16: ";
        cin >> kiekKomandu;
        cout << endl;

        for (int i = 0; i < kiekKomandu; i = i + 2) { //vardas, pav, komandos pav.

            for (int j = 0; j < 2; j++) { //vardas, pav, komandos pav.

                string one, two, three;
                //cout << "Trenerio vardas ir pavarde, komandos pavadinimas" << endl;
                cin >> one >> two >> three;
                lkl.pridetiKomanda(one, two, three);
            }

            int t1, t2;
            //cout << "Pirmos bei antros komandos taskai" << endl;
            cin >> t1 >> t2;
            lkl.zaistiRungtynes(i + 1, i + 2, t1, t2); //komandos skaicius, komandos skaicius, score(team1), score(team2).


        }
        lkl.atspausdinti(); //playoff naudoti
        lkl.lentele();//naudoti sezone
    }
    else {
        cout << "Wrong numbers." << endl;
    }

    


    
    /* 
    destytojo nurodytas
    
    lkl.pridetiKomanda("antanas", "Sireika", "Zalgiris");
    lkl.pridetiKomanda("Dainius", "Adomaitis", "Rytas");
    lkl.atspausdinti();
    lkl.zaistiRungtynes(100, 98); //komandos skaicius, komandos skaicius, score(team1), score(team2).
    lkl.lentele();//naudoti sezone
    */
}
