#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
class Procesorius {
private:
    double greitis;
    string architektura;
    double kaina;
    double Cores;
    double elektrosSuvartojimas;
public:
    double metineKaina;
    Procesorius() {
        greitis = 0;
        architektura = "";
        kaina = 0;
        Cores = 0;
        elektrosSuvartojimas = 0;
        metineKaina = 0;
    }

    Procesorius(double a, string b, double c, double d, double e) {
        greitis = a;
        architektura = b;
        kaina = c;
        Cores = d;
        elektrosSuvartojimas = e;
        metineKaina = e * 0.11;
    }

    void setGreitis(double a) {
        greitis = a;
    }
    double getGreitis() {
        return greitis;
    }
    void setArchitektura(string a) {
        architektura = a;
    }
    string getArchitektura() {
        return architektura;
    }
    void setKaina(double a) {
        kaina = a;
    }
    double getKaina() {
        return kaina;
    }
    void setCores(double a) {
        Cores = a;
    }
    double getCores() {
        return Cores;
    }
    void setElektrosSuvartojimas(double a) {
        elektrosSuvartojimas = a;
    }
    double getElektrosSuvartojimas() {
        return elektrosSuvartojimas;
    }
    void setMetineKaina(double a) {
        metineKaina = a;
    }
    double getMetineKaina() {
        return metineKaina;
    }
};

class VaizdoPlokste {
private:
    string pavadinimas;
    double greitis;
    double kaina;
    string architektura;
    double Cores;
    double hashRate;
    double ramKiekis;
    double elektrosSuvartojimas;
public:
    double metineKaina;
    VaizdoPlokste() {
        pavadinimas = "";
        greitis = 0;
        kaina = 0;
        architektura = "";
        Cores = 0;
        hashRate = 0;
        ramKiekis = 0;
        elektrosSuvartojimas = 0;
        metineKaina = 0;
    }

    VaizdoPlokste(string a, double b, double c, string d, double e, double f, double g, double h) {
        pavadinimas = a;
        greitis = b;
        kaina = c;
        architektura = d;
        Cores = e;
        hashRate = f;
        ramKiekis = g;
        elektrosSuvartojimas = h;
        metineKaina = h * 0.11;
    }
    void setPavadinimas(string a) {
        pavadinimas = a;
    }
    string getPavadinimas() {
        return pavadinimas;
    }
    void setVGreitis(double a) {
        greitis = a;
    }
    double getVGreitis() {
        return greitis;
    }
    void setVArchitektura(string a) {
        architektura = a;
    }
    string getVArchitektura() {
        return architektura;
    }
    void setVKaina(double a) {
        kaina = a;
    }
    double getVKaina() {
        return kaina;
    }
    void setVCores(double a) {
        Cores = a;
    }
    double getVCores() {
        return Cores;
    }
    void setHashRate(double a) {
        hashRate = a;
    }
    double getHashRate() {
        return hashRate;
    }
    void setRamKiekis(double a) {
        ramKiekis = a;
    }
    double getRamKiekis() {
        return ramKiekis;
    }
    void setVelektrosSuvartojimas(double a) {
        elektrosSuvartojimas = a;
    }
    double getVelektrosSuvartojimas() {
        return elektrosSuvartojimas;
    }
    void setVMetineKaina(double a) {
        metineKaina = a;
    }
    double getVMetineKaina() {
        return metineKaina;
    }

};

class Kompiuteris {
private:
    Procesorius pro;
    VaizdoPlokste vaiz;
    string pavad;
public:
    Kompiuteris() {
    }

    Kompiuteris(Procesorius a, VaizdoPlokste b, string c) {
        pro = a;
        vaiz = b;
        pavad = c;
    }

    void setPro(double a, string b, double c, double d, double e, double f) {
        pro.setGreitis(a);
        pro.setArchitektura(b);
        pro.setKaina(c);
        pro.setCores(d);
        pro.setElektrosSuvartojimas(e);
        pro.setMetineKaina(f);
    }
    double getProGreitis() {
        return pro.getGreitis();
    }
    string getArchitektura() {
        return pro.getArchitektura();
    }
    double getKaina() {
        return pro.getKaina();
    }
    double getCores() {
        return pro.getCores();
    }
    double getElektrosSuvartojimas() {
        return pro.getElektrosSuvartojimas();
    }
    double getMetineKaina() {
        return pro.metineKaina;
    }
    void setVaiz(string a, double b, double c, string d, double e, double f, double g, double h, double i) {
        vaiz.setPavadinimas(a);
        vaiz.setVGreitis(b);
        vaiz.setVKaina(c);
        vaiz.setVArchitektura(d);
        vaiz.setVCores(e);
        vaiz.setHashRate(f);
        vaiz.setRamKiekis(g);
        vaiz.setVelektrosSuvartojimas(h);
        vaiz.setVMetineKaina(i);
    }
    string getVaizPavadinimas() {
        return vaiz.getPavadinimas();
    }
    double getGreitis() {
        return vaiz.getVGreitis();
    }
    double getVaizKaina() {
        return vaiz.getVKaina();
    }
    string getVArchitektura() {
        return vaiz.getVArchitektura();
    }
    double getVCores() {
        return vaiz.getVCores();
    }
    double getHashRate() {
        return vaiz.getHashRate();
    }
    double getVelektrosSuvartojimas() {
        return vaiz.getVelektrosSuvartojimas();
    }
    double getVMetineKaina() {
        return vaiz.getVMetineKaina();
    }
    void setKompiuterioPavadinimas(string a) {
        pavad = a;
    }
    string getKompiuterioPavadinimas() {
        return pavad;
    }

};
class Parduotuve {
    vector <Procesorius> CPU;
    vector <VaizdoPlokste> GpuCard;
    vector <Kompiuteris> PC;

    int parinktiPro() {
        int choice;
        cout << "Procesoriu sarasas: " << endl;
        for (int i = 0; i < CPU.size(); i++) {
            cout << i + 1 << ". " << CPU[i].getArchitektura() << " " << CPU[i].getGreitis() << " " << CPU[i].getKaina() << endl;
        }
        cout << "Pasirinkite procika: " << endl;
        cin >> choice;
        system("CLS");
        return choice - 1;
    }

    int parinktiVaiz() {
        int choice;
        cout << "Vaizdo ploksciu sarasas: " << endl;
        for (int i = 0; i < GpuCard.size(); i++) {
            cout << i + 1 << ". " << GpuCard[i].getPavadinimas() << " " << GpuCard[i].getVGreitis() << GpuCard[i].getVKaina() << endl;
        }
        cout << "Pasirinkite GPU: " << endl;
        cin >> choice;
        system("CLS");
        return choice - 1;
    }

    string parinktiString() {
        string pavadinimas;
        cin >> pavadinimas;
        return pavadinimas;
    }

    void atspausdinti(string a) {
        cout << a << endl;
    }

    double parinktiFloat() {
        double a;
        cin >> a;
        return a;
    }

public:

    void addCPU(Procesorius a) {
        CPU.push_back(a);
    }

    void addGpuCard(VaizdoPlokste a) {
        GpuCard.push_back(a);
    }

    void addPC(Procesorius a, VaizdoPlokste b, string c) {
        PC.push_back(Kompiuteris(a, b, c));
        system("CLS");
        cout << "PC sukurtas" << endl;
    }

    void sukurtiKompiuteri() {
        int a = parinktiPro();
        int b = parinktiVaiz();
        atspausdinti("Pavadinimas?:");
        addPC(CPU[a], GpuCard[b], parinktiString());
    }

    void sukurtiPro() {
        atspausdinti("Iveskite Greiti: ");
        double a = parinktiFloat();
        atspausdinti("Iveskite architektura: ");
        string b = parinktiString();
        atspausdinti("Iveskite kaina: ");
        double c = parinktiFloat();
        atspausdinti("Iveskite branduoliu kieki: ");
        double d = parinktiFloat();
        atspausdinti("Iveksite el. suvartojima: ");
        double e = parinktiFloat();

        CPU.push_back(Procesorius(a, b, c, d, e));
    }

    void sukurtiVaiz() {
        atspausdinti("Iveskite pavadinima: ");
        string a = parinktiString();
        atspausdinti("Iveskite greiti: ");
        double b = parinktiFloat();
        atspausdinti("Iveskite kaina: ");
        double c = parinktiFloat();
        atspausdinti("Iveskite architektura: ");
        string d = parinktiString();
        atspausdinti("Iveksite branduoliu kieki: ");
        double e = parinktiFloat();
        atspausdinti("Iveskite HashRate: ");
        double f = parinktiFloat();
        atspausdinti("Iveskite Ram Kiekis: ");
        double g = parinktiFloat();
        atspausdinti("Iveksite el. suvartojima: ");
        double h = parinktiFloat();

        GpuCard.push_back(VaizdoPlokste(a, b, c, d, e, f, g, h));
    }

    void menu() {
        cout << "Pasirinkite veiksma" << endl;
        cout << "1. Naujas CPU" << endl;
        cout << "2. Nauja  GpuCard" << endl;
        cout << "3. Naujas PC" << endl;
        cout << "4. Perziureti sarasa cpu" << endl;
        cout << "5. Perziureti sarasa gpu" << endl;
        cout << "6. Spausdint PC " << endl;
        cout << "7. Iseiti" << endl;
    }
    void printProcesorius() {
        cout << "CPU sarasas" << endl;
        for (int i = 0; i < CPU.size(); i++) {
            cout << i + 1 << ". greitis:" << CPU[i].getGreitis() << " kaina:" << CPU[i].getKaina() << " archi/pav:"
                << CPU[i].getArchitektura() << " brand:" << CPU[i].getCores() << " elektrSuvart:"
                << CPU[i].getElektrosSuvartojimas() << " metinisSuvartojimasKaina:" << CPU[i].getMetineKaina() << endl;
        }
    }
    void printVaizdoPlokste() {
        cout << "GPU sarasas" << endl;
        for (int i = 0; i < GpuCard.size(); i++) {
            cout << i + 1 << ". Pav:" << GpuCard[i].getPavadinimas() << " greit:" << GpuCard[i].getVGreitis()
                << " kaina:" << GpuCard[i].getVKaina() << " arch:" << GpuCard[i].getVArchitektura() << " bran:"
                << GpuCard[i].getVCores() << " hashrate:" << GpuCard[i].getHashRate() << " ram:" << GpuCard[i].getRamKiekis() << " metinisSuvartojimasKaina:"
                << GpuCard[i].getVMetineKaina() << endl;
        }
    }
    void printKompiuteris() {
        cout << "PC sarasas" << endl;
        for (int i = 0; i < PC.size(); i++) {
            cout << i + 1 << ". " << PC[i].getKompiuterioPavadinimas() << " gpu:" << GpuCard[i].getPavadinimas() << "  cpu:" << CPU[i].getArchitektura()
                << " BendraKaina:" << GpuCard[i].getVKaina() + CPU[i].getKaina() << endl;
        }
    }
};

int main()
{
    Parduotuve AliExpress;

    int a = 0;
    do {
        AliExpress.menu();
        cin >> a;
        switch (a) {
        case 1:
            system("CLS");
            AliExpress.sukurtiPro();
            break;
        case 2:
            system("CLS");
            AliExpress.sukurtiVaiz();
            break;
        case 3:
            system("CLS");
            AliExpress.sukurtiKompiuteri();
            break;
        case 4:
            system("CLS");
            AliExpress.printProcesorius();
            break;
        case 5:
            system("CLS");
            AliExpress.printVaizdoPlokste();
            break;
        case 6:
            system("CLS");
            AliExpress.printKompiuteris();
            break;
        case 7:
            system("CLS");
            cout << "Exit";
            exit(0);
        }
    } while (a >= 1 && a <= 6);
    return 0;
}