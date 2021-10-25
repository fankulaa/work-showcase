/*
Elektros kaina : 0.11

    Pocesorius
greitis
kaina
architektura ( string tipo: amd ,apple,intel, )
Branduoliu kiekis
Elektros suvartojimas metinis
metine kaina elektros (isskaiciuoti konstruktoriuje)


    Vaizdo plokste
pavadinimas
greitis
kaina
architektura ( string tipo: amd ,apple,intel, )
Branduoliu kiekis
HashRate
Ram kiekis
metine kaina elektros (isskaiciuoti konstruktoriuje)


    Kompiuteris
pavadinimas
susideda is cpu+GPU
Paskaiciuoti suvartojima metine elektros kaina
Galutine kaina

    Parduotuve
Gali sukurti kompiuteri
prideti CPU
Prideti GpU

    Meniu
1. prideti CPU
2. Prideti GpU
3. Atspausdinti visus CPU
4. Atspausdinti visus GpU
5. Sukurti kompiuteri
6. Atspausdinti kompiuterius ( cpu name gpu name kainaBendra )
*/

#include <iostream>
#include <vector>

using namespace std;


/*
    Pocesorius
greitis
kaina
architektura ( string tipo: amd ,apple,intel, )
Branduoliu kiekis
Elektros suvartojimas metinis
metine kaina elektros (isskaiciuoti konstruktoriuje)
*/
class Procesorius {
    double proc_greitis;
    double proc_kaina;
    string proc_architektura;
    int proc_branduoliu_kiekis;
    double proc_elektros_suvartijomas_metinis;
    double proc_metine_kaina_elektros;
public:
    Procesorius() {
        proc_greitis = 0;
        proc_kaina = 0;
        proc_architektura = "";
        proc_branduoliu_kiekis = 0;
        proc_elektros_suvartijomas_metinis = 0;
        proc_metine_kaina_elektros = 0;
    }
    Procesorius(double greitis, double kaina, string architektura, int branduoliu_kiekis, double elektros_suvartijomas_metinis) {
        setProc_greitis(greitis);
        setProc_kaina(kaina);
        setProc_architektura(architektura);
        setProc_branduoliu_kiekis(branduoliu_kiekis);
        setProc_elektros_suvartijomas_metinis(elektros_suvartijomas_metinis);
        calc_Proc_metine_kaina_elektros(proc_elektros_suvartijomas_metinis);
    }

    //setter
    void setProc_greitis(double a) {
        proc_greitis = a;
    }
    void setProc_kaina(double a) {
        proc_kaina = a;
    }
    void setProc_architektura(string a) {
        proc_architektura = a;
    }
    void setProc_branduoliu_kiekis(int a) {
        proc_branduoliu_kiekis = a;
    }
    void setProc_elektros_suvartijomas_metinis(double a) {
        proc_elektros_suvartijomas_metinis = a;
    }

    //getter
    double getProc_greitis() {
        return proc_greitis;
    }
    double getProc_kaina() {
        return proc_kaina;
    }
    string getProc_architektura() {
        return proc_architektura;
    }
    int getProc_branduoliu_kiekis() {
        return proc_branduoliu_kiekis;
    }
    double getProc_elektros_suvartijomas_metinis() {
        return proc_elektros_suvartijomas_metinis;
    }
    double getProc_metine_kaina_elektros() {
        return proc_metine_kaina_elektros;
    }

    //functions
    void calc_Proc_metine_kaina_elektros(double elektros_suvartijomas_metinis) {
        
        proc_metine_kaina_elektros = elektros_suvartijomas_metinis * 0.11;
   
    }
    void proc_PrintAll() {
        cout << "----------------------------------------- " << endl;
        cout << "greitis: " << getProc_greitis() << endl;
        cout << "kaina: " << getProc_kaina() << endl;
        cout << "architektura: " << getProc_architektura() << endl;
        cout << "branduoliu_kiekis: " << getProc_branduoliu_kiekis() << endl;
        cout << "elektros_suvartijomas_metinis: " << getProc_elektros_suvartijomas_metinis() << endl;
        cout << "metine_kaina_elektros: " << getProc_metine_kaina_elektros() << endl;
        cout << "----------------------------------------- " << endl;

    }
};


/*
    Vaizdo plokste
pavadinimas
greitis
kaina
architektura ( string tipo: amd ,apple,intel, )
Branduoliu kiekis
HashRate
Ram kiekis
metine kaina elektros (isskaiciuoti konstruktoriuje)
*/
class Vaizdo_plokste {
    string vaizd_pavadinimas;
    double vaizd_kaina;
    string vaizd_architektura;
    int vaizd_branduoliu_kiekis;
    double vaizd_hash_rate;
    int vaizd_ram;
    double vaizd_elektros_suvartijomas_metinis;
    double vaizd_metine_kaina_elektros;
public:
    //setter
    Vaizdo_plokste() {
        vaizd_pavadinimas = "";
        vaizd_kaina = 0;
        vaizd_architektura = "";
        vaizd_branduoliu_kiekis = 0;
        vaizd_hash_rate = 0;
        vaizd_ram = 0;
        vaizd_elektros_suvartijomas_metinis = 0;
        vaizd_metine_kaina_elektros = 0;
    }
    Vaizdo_plokste(string pavadinimas, double kaina, string architektura, int branduoliu_kiekis, double hash_rate, int ram, double elektros_suvartijomas_metinis) {
        set_Vaizd_pavadinimas(pavadinimas);
        set_Vaizd_kaina(kaina);
        set_Vaizd_architektura(architektura);
        set_Vaizd_branduoliu_kiekis(branduoliu_kiekis);
        set_Vaizd_hash_rate(hash_rate);
        set_Vaizd_ram(ram);
        set_Vaizd_elektros_suvartijomas_metinis(elektros_suvartijomas_metinis);
        calc_Vaizd_metine_kaina_elektros(vaizd_elektros_suvartijomas_metinis);
    }

    //setter
    void set_Vaizd_pavadinimas(string a) {
        vaizd_pavadinimas = a;
    }
    void set_Vaizd_kaina(double a) {
        vaizd_kaina = a;
    }
    void set_Vaizd_architektura(string a) {
        vaizd_architektura = a;
    }
    void set_Vaizd_branduoliu_kiekis(int a) {
        vaizd_branduoliu_kiekis = a;
    }
    void set_Vaizd_hash_rate(double a) {
        vaizd_hash_rate = a;
    }
    void set_Vaizd_ram(int a) {
        vaizd_ram = a;
    }
    void set_Vaizd_elektros_suvartijomas_metinis(double a) {
        vaizd_elektros_suvartijomas_metinis = a;
    }

    //getter
    string getVaizd_pavadinimas() {
        return vaizd_pavadinimas;
    }
    double getVaizd_kaina() {
        return vaizd_kaina;
    }
    string getVaizd_architektura() {
        return vaizd_architektura;
    }
    int getVaizd_branduoliu_kiekis() {
        return vaizd_branduoliu_kiekis;
    }
    double getVaizd_hash_rate() {
        return vaizd_hash_rate;
    }
    int getVaizd_ram() {
        return vaizd_ram;
    }
    double getVaizd_elektros_suvartijomas_metinis() {
        return vaizd_elektros_suvartijomas_metinis;
    }
    double getVaizd_metine_kaina_elektros() {
        return vaizd_metine_kaina_elektros;
    }

    //functions
    void calc_Vaizd_metine_kaina_elektros(double elektros_suvartijomas_metinis) {
        
        vaizd_metine_kaina_elektros = elektros_suvartijomas_metinis * 0.11;
        
    }
    void vaizd_PrintAll() {
        cout << "----------------------------------------- " << endl;
        cout << "pavadinimas: " << getVaizd_pavadinimas() << endl;
        cout << "kaina: " << getVaizd_kaina() << endl;
        cout << "architektura: " << getVaizd_architektura() << endl;
        cout << "branduoliu_kiekis: " << getVaizd_branduoliu_kiekis() << endl;
        cout << "hash_rate: " << getVaizd_hash_rate() << endl;
        cout << "ram: " << getVaizd_ram() << endl;
        cout << "elektros_suvartijomas_metinis: " << getVaizd_elektros_suvartijomas_metinis() << endl;
        cout << "metine_kaina_elektros: " << getVaizd_metine_kaina_elektros() << endl;
        cout << "----------------------------------------- " << endl;
    }
};

/*

    Kompiuteris
pavadinimas
susideda is cpu+GPU
Paskaiciuoti suvartojima metine elektros kaina
Galutine kaina

*/
class Kompiuteris {
    string komp_pavadinimas;
    Vaizdo_plokste vaizdo_plokste;
    Procesorius procesorius;
    double komp_metine_elektros_kaina;
    double komp_galutine_kaina;
public:
    Kompiuteris() {
        komp_pavadinimas = "";
        komp_metine_elektros_kaina = 0;
        komp_galutine_kaina = 0;
    }
    Kompiuteris(class Vaizdo_plokste a, class Procesorius b, string pavadinimas) {
        setKomp_pavadinimas(pavadinimas);
        vaizdo_plokste = a; 
        procesorius = b;
        CalcKomp_galutine_kaina();
        CalcKomp_metine_elektros_kaina();
    }
    
    //setter
    void setKomp_pavadinimas(string a) {
        komp_pavadinimas = a;
    }

    //getter
    string getKomp_pavadinimas() {
        return komp_pavadinimas;
    }
    double getKomp_metine_elektros_kaina() {
        return komp_metine_elektros_kaina;
    }
    double getKomp_galutine_kaina() {
        return komp_galutine_kaina;
    }

    //functions
    void CalcKomp_metine_elektros_kaina() {
        komp_metine_elektros_kaina = procesorius.getProc_metine_kaina_elektros() + vaizdo_plokste.getVaizd_metine_kaina_elektros();
    }
    void CalcKomp_galutine_kaina() {
        komp_galutine_kaina = procesorius.getProc_kaina() + vaizdo_plokste.getVaizd_kaina();
    }
    void komp_PrintAll() {
        
        cout << "CPU: ";
        procesorius.proc_PrintAll();
        cout << "GPU: ";
        vaizdo_plokste.vaizd_PrintAll();

        cout << "komp_pavadinimas: "<< getKomp_pavadinimas() << endl;
        cout << "komp_metine_elektros_kaina: " << getKomp_metine_elektros_kaina() << endl;
        cout << "komp_galutine_kaina: " << getKomp_galutine_kaina() << endl;
        cout << "-------------------------------------------" << endl;
    }
};

/*
    Parduotuve
Gali sukurti kompiuteri
prideti CPU
Prideti GpU
*/
class Parduotuve {
    vector <Kompiuteris> kompiuteris;
    vector <Procesorius> cpu;
    vector <Vaizdo_plokste> gpu;
public:
    //functions
    int cinInt() {
        int a;
        cin >> a;
        return a;
    }
    double cinDouble() {
        double a;
        cin >> a;
        return a;
    }
    string cinString() {
        string a;
        cin >> a;
        return a;
    }

    //add
    void pridetiCpu(double greitis, double kaina, string architektura, int branduoliu_kiekis, double elektros_suvartijomas_metinis) {
        cpu.push_back(Procesorius(greitis, kaina, architektura, branduoliu_kiekis, elektros_suvartijomas_metinis));
    }
    void pridetiGpu(string pavadinimas, double kaina, string architektura, int branduoliu_kiekis, double hash_rate, int ram, double elektros_suvartijomas_metinis) {
        gpu.push_back(Vaizdo_plokste(pavadinimas, kaina, architektura, branduoliu_kiekis, hash_rate, ram, elektros_suvartijomas_metinis));
    }
    void pridetiKompiuteri(class Vaizdo_plokste a, class Procesorius b, string pavadinimas) {
        kompiuteris.push_back(Kompiuteris(a, b, pavadinimas));
    }

    //print

    //menu
    void iseiti() {
        cout << endl;
        cout << endl;
        system("pause");
    }
    void start() {
        int x = -1;
        do {
            menu();
            cin >> x;
            swichCases(x);
        } while (x != 0);
    }
    void menu() {
        system("cls");
        cout << "-------------------------------------------" << endl;
        cout << "                   MENIU" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "[1] - Sukurti CPU" << endl;
        cout << "[2] - Sukurti GPU" << endl;
        cout << "[3] - Sukurti kompiuteri" << endl;
        cout << "[4] - Perziureti kompiuterius" << endl;
        cout << "[5] - Perziureti CPU" << endl;
        cout << "[6] - Perziureti GPU" << endl;
        cout << "[0] - Iseiti" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "Pasirinkimas: ";
    }
    void swichCases(int x) {
        switch (x) {
        case 1: //Sukurti CPU
            system("cls");
            for (int i = 0; i < 1; i++) {
                double greitis, kaina, elektros_suvartijomas_metinis;
                string architektura;
                int branduoliu_kiekis;

                cout << "greitis: ";
                greitis = cinDouble();
                cout << "kaina: ";
                kaina = cinDouble();
                cout << "architektura: ";
                architektura = cinString();
                cout << "branduoliu_kiekis: ";
                branduoliu_kiekis = cinInt();
                cout << "elektros_suvartijomas_metinis: ";
                elektros_suvartijomas_metinis = cinDouble();

                pridetiCpu(greitis, kaina, architektura, branduoliu_kiekis, elektros_suvartijomas_metinis);
            }
            iseiti();
            break;
        case 2: //Sukurti GPU
            system("cls"); 
            for (int i = 0; i < 1; i++) {
                string pavadinimas, architektura;
                double kaina, hash_rate, elektros_suvartijomas_metinis;
                int ram, branduoliu_kiekis;

                cout << "pavadinimas: " ;
                pavadinimas = cinString();
                cout << "kaina: " ;
                kaina = cinDouble();
                cout << "architektura: " ;
                architektura = cinString();
                cout << "branduoliu_kiekis: ";
                branduoliu_kiekis = cinInt();
                cout << "hash_rate: ";
                hash_rate = cinDouble();
                cout << "ram: " ;
                ram = cinInt();
                cout << "elektros_suvartijomas_metinis: " ;
                elektros_suvartijomas_metinis = cinDouble();

                pridetiGpu(pavadinimas, kaina, architektura, branduoliu_kiekis, hash_rate, ram, elektros_suvartijomas_metinis);
            }
            iseiti();
            break;
        case 3: //Sukurti kompiuteri
            system("cls");
            for (int i = 0; i < 1; i++) {
                int cpu_nr, gpu_nr;
                string pavadinimas;

                cout << "Pasirinkite CPU:" << endl;
                for (int i = 0; i < cpu.size(); i++) {
                    cout << i+1 << ": ";
                    cpu[i].proc_PrintAll();
                }
                cout << "Pasirinkimas: ";
                cpu_nr = cinInt()-1;
                system("cls");

                cout << "Pasirinkite GPU:" << endl;
                for (int i = 0; i < gpu.size(); i++) {
                    cout << i + 1 << ": ";
                    gpu[i].vaizd_PrintAll();
                }
                cout << "Pasirinkimas: ";
                gpu_nr = cinInt() - 1;
                system("cls");

                cout << "Pavadinimas: ";
                pavadinimas = cinString();

                pridetiKompiuteri(gpu[gpu_nr], cpu[cpu_nr], pavadinimas);
            }
            iseiti();
            break;
        case 4: //Perziureti kompiuterius
            system("cls");
                for (int i = 0; i < 1; i++) {
                    cout << "Kompiuteriai:" << endl;
                    for (int i = 0; i < kompiuteris.size(); i++) {
                        cout << endl;
                        cout << i + 1 << ": " << endl;
                        kompiuteris[i].komp_PrintAll();
                        cout << endl;
                        cout << endl;
                    }
                }
            iseiti();
            break;
        case 5: //cpu
            system("cls");
            for (int i = 0; i < 1; i++) {
                cout << "CPU:" << endl;
                for (int i = 0; i < cpu.size(); i++) {
                    cout << endl;
                    cout << i + 1 << ": " << endl;
                    cpu[i].proc_PrintAll();
                    cout << endl;
                    cout << endl;
                }
            }
            iseiti();
            break;
        case 6: //gpu
            system("cls");
            for (int i = 0; i < 1; i++) {
                cout << "GPU:" << endl;
                for (int i = 0; i < gpu.size(); i++) {
                    cout << endl;
                    cout << i + 1 << ": " << endl;
                    gpu[i].vaizd_PrintAll();
                    cout << endl;
                    cout << endl;
                }
            }
            iseiti();
            break;
        case 0:
            cout << endl;
            cout << endl;
            return;
        default:
            system("cls");
            cout << "Wrong number, try again" << endl;
            iseiti();
        }
    }
};

//Elektros kaina : 0.11
int main()
{
    Parduotuve varle;
    varle.start();
}