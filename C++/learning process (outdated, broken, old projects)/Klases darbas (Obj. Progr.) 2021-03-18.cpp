#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Varikliai {

    string kuras;
    double kaina, litraza;

public:
    Varikliai() {
        litraza = 0;    
        kuras = "";
        kaina = 0;
    }
    Varikliai(double a, string b, double c) {
        litraza = a;
        kuras = b;
        kaina = c;
    }

    double getVariklisLitraza() {
        double a = litraza;
        return a;
    }
    double getVariklisKaina() {
        double a = kaina;
        return a;
    }
    string getVariklisKuras(){
        string a = kuras;
        return a;
    }
    
    void coutVariklisData() {
        cout << "litraza: " << litraza <<"L, kaina: "<<kaina<< ", kuras: " << kuras << endl;
    }
 
};
struct Kebulai {
private:
    string pavadinimas;
    double kaina;
public:
    Kebulai() {
        pavadinimas = "";
        kaina = 0;
    }
    Kebulai(string a, double b) {
        pavadinimas = a;
        kaina = b;
    }

    string getKebulasPavadiniams() {
        string a = pavadinimas;
        return a;
    }
    double getKebulasKaina() {
        double a = kaina;
        return a;
    }

    void coutKebulasData() {
        cout << "pavadinimas: " << pavadinimas << ", kaina: " << kaina << endl;
    }
};

//REEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
struct Automobiliai:public Varikliai, public Kebulai {
private:
    Varikliai variklis; //ask 
    Kebulai kebulas; //ask
    double kaina;
    string pavadinimas;
public:
    Automobiliai() {
        kaina = paskaicuoti();
    }
    Automobiliai(Varikliai a, Kebulai b,string c) { //ask
        variklis = a; //ask
        kebulas = b; //ask
        pavadinimas = c; //ask
        kaina = paskaicuoti();
    }

    double paskaicuoti() {
        double a;
        a = getVariklisKaina() + getKebulasKaina();
        return a;
    }
    double getKaina() {
        double a = kaina;
        return a;
    }

    void setPavadinimas(string a) {
        pavadinimas = a;
    }
    string getPavadiniams() {
        string a = pavadinimas;
        return a;
    }

    void getVariklis() {
        coutVariklisData();
    }
    void getKebulas() {
        coutKebulasData();
    }
}; 
struct Parduotuve {
private:
    vector <Varikliai> variklis;
    vector <Kebulai> kebulas;
    vector <Automobiliai> automobilis;
public:
    Parduotuve() {
    }

    void sukurti() {
        int a = pasirinktiVarikli();
        int b = pasiriktiKebula();
        atspausdinti("Koks bus pavadinimas?");
        string c = pariktiString();

        system("cls");
        cout << "Automobilis: " << c << endl;
        cout << endl;
        cout << "Variklis: " << variklis[a].getVariklisKuras() << " " << variklis[a].getVariklisLitraza() << "L " << variklis[a].getVariklisKaina() << "$" << endl;
        cout << "Kebulas: " << kebulas[b].getKebulasPavadiniams() << " " << kebulas[b].getKebulasKaina() << "$" << endl;
        if (patvirtinti() > 0) {
            addAutomobilis(variklis[a], kebulas[b], c);
            cout << "Automobilis sukurtas" << endl;
        }
        else {
            cout << "Sukurimas atsauktas" << endl;
        }

    }
    bool patvirtinti() {
        string a;
        cout << endl;
        cout << "Kad patvirtinti parasykyte 'taip' : " << endl;
        cin >> a;

        if (a == "taip") {
            return true;
        }
        else {
            return false;
        }
    }

    void addAutomobilis(Varikliai a, Kebulai b, string c) {
        automobilis.push_back(Automobiliai(a,b,c));
    }
    void atspausdintiAutomobilius() {
        cout << "Automobilius sarasas: " << endl;
        cout << endl;
        for (int i = 0; i < automobilis.size(); i++) {
            cout << i + 1 <<endl; 
            cout<< "Pavadinimas: " << automobilis[i].getPavadiniams() << endl;
            cout << "Kaina: " << automobilis[i].getKaina() << "$" << endl;
            cout << "Variklis: ";
            automobilis[i].getVariklis();
            cout << "Kebulas: ";
            automobilis[i].getKebulas();
            cout << endl;
            
        }
    }

    int pasirinktiVarikli() {
        int x;
        atspausdintiVariklius();
        cout << "Pasirinkite varikli: ";
        cin >> x;
        cout << endl;
        return x - 1;
    }
    void atspausdintiVariklius() {
        cout << "Variklius sarasas: " << endl;
        cout << endl;
        for (int i = 0; i < variklis.size(); i++) {
            cout << i + 1 << " " << variklis[i].getVariklisKuras() << " " << variklis[i].getVariklisLitraza() << "L " << variklis[i].getVariklisKaina() << "$" << endl;
        }
    }
    void addVariklis(Varikliai a) {
        variklis.push_back(a);
    }

    int pasiriktiKebula() {
        int x;
        atspausdintiKebulus();
        cout << "Pasirinkite kebula: ";
        cin >> x;
        cout << endl;
        return x - 1;
    }
    void atspausdintiKebulus() {
        cout << "Kebulu sarasas: " << endl;
        cout << endl;
        for (int i = 0; i < kebulas.size(); i++) {
            cout << i + 1 <<" "<< kebulas[i].getKebulasPavadiniams() << " " << kebulas[i].getKebulasKaina() << "$" << endl;
        }
    }
    void addKebulas(Kebulai a) {
        kebulas.push_back(a);
    }

    double parinktiDouble() {
        double a;
        cin >> a;
        return a;
    }
    string pariktiString() {
        string name;
        cin >> name;
        return name;
    }
    void atspausdinti(string a) {
        cout << a << endl;
    }

    void iseiti() {
        cout << endl;
        cout << endl;
        system("pause");
    }
    void paleisti() {
        int x = -1;
        do {
            menu();
            cin >> x;
            swichCases(x);
        } while (x != 0);
    }
    void testDataInput() {
        Varikliai tfsi(2.0, "Dyzelis", 12000);
        Varikliai TDI(2.2, "Elektra", 6000);
        Kebulai k1("Sedanas", 20000);


        addVariklis(tfsi);
        addVariklis(TDI);
        addKebulas(k1);
        addAutomobilis(tfsi, k1, "audi");
    }

    void menu() {
        system("cls");
        cout << "-------------------------------------------" << endl;
        cout << "                   MENIU" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "[1] - Perziureti variklius" << endl; //works
        cout << "[2] - Perziureti kebulus" << endl; //works
        cout << "[3] - Perziureti automobilius" << endl; //works
        cout << "[4] - Sukurti automobili" << endl; //works
        cout << "[0] - Iseiti is programos" << endl; //works
        cout << "-------------------------------------------" << endl;
        cout << "Pasirinkimas: ";
    }
    void swichCases(int x){
        switch (x) {
        case 1:
            system("cls"); //atspausdinti variklius
            atspausdintiVariklius();
            iseiti();
            break;
        case 2: //atspausdinti kebulus
            system("cls"); 
            atspausdintiKebulus();
            iseiti();
            break;
        case 3: //perziureti automobilius
            system("cls");
            atspausdintiAutomobilius();
            iseiti();
            break;
        case 4: //sukurti automobili
            system("cls");
            sukurti();
            iseiti();
            break;

        case 0:
            cout << endl;
            cout << endl;
            return;
        default:
            cout << "Wrong number, try again" << endl;
        }
    }
};

int main()
{
    Parduotuve AudiCentras;

    AudiCentras.testDataInput();
    AudiCentras.paleisti();
};

