#include <iostream>
#include <stdlib.h>


using namespace std;

struct Ben { //Audi fan
private:
    double price;
public:
    
    void setPrice(double a) {

        price = a;
    }
    double getPrice() {
        double a;
        a = price;
        return a;
    }
};

struct Tom { //BMW fan
private:
    double price;
public:

    void setPrice(double a) {

        price = a;
    }
    double getPrice() {
        double a;
        a = price;
        return a;
    }

};

struct Cars {
private:
    Ben ben;//Audi fan
    Tom tom;//BMW fan

    string mark;
    string name;
    double price;
public:
    void setMark(string a) {
        mark = a;
    }
    void setName(string a) {
        name = a;
    }
    void setPrice(double a) {
        price = a;
    }

    string getMark() {
        string a;
        a = mark;
        return a;
    }
    string getName() {
        string a;
        a = name;
        return a;
    }
    double getPrice() {
        double a;
        a = price;
        return a;
    }
    
    /*
    void distributeCars() {

        if (mark == "Audi") { //ben
            ben.setName(name);
            ben.setPrice(price);

        }
        else if (mark == "BMW") { //tom
            tom.setName(name);
            tom.setPrice(price);

        }
        else {
            return;
        }
    }
    */

    void printBen(){ //audi
        double price;
        string name;
        
        price = ben.getPrice();

        cout << "Audi " << name << " " << price << endl;
    }
    void printTom() { //bmw
        double price;
        string name;

        price = tom.getPrice();

        cout << "BMW " << name << " " << price << endl;
    }

    double tomPrice() { //bmw
        double price;
        price = tom.getPrice();
        
        return price;
    }
    double benPrice() { //bmw
        double price;
        price = ben.getPrice();

        return price;
    }

    void tomSetPrice(double a) {
        tom.setPrice(a);
    }
    void benSetPrice(double a) {
        ben.setPrice(a);
    }
};

int main()
{
    

    int n;
    cout << "Car amount: ";
    cin >> n;
    cout << endl;
    
    Cars car[8];

    cout << "Car list:\n";
    
    for (int i = 0; i < n; i++) { //setting car values
        string mark, name;
        double price;

        cin >> mark >> name >> price;
        car[i].setMark(mark);
        car[i].setName(name);
        car[i].setPrice(price);
    
    }
    cout << endl;


    int benListLenght = -1, tomListLenght = -1;
    for (int i = 0; i < n; i++) { // addint car values to Ben's + Tom's list

        double price;

        price = car[i].getPrice();

        if (car[i].getMark() == "Audi") { //ben
            car[benListLenght+1].benSetPrice(price);
            benListLenght++;
        }
        else if (car[i].getMark() == "BMW") { //tom
            car[tomListLenght+1].tomSetPrice(price);
            tomListLenght++;
        }

    }


    cout << "Ben's list: " << endl;
    for (int i = 0; i < benListLenght; i++) { // testing 
        car[i].printBen();
    }
    cout << endl;
    cout << "Tom's list: " << endl;
    for (int i = 0; i < tomListLenght; i++) { // testing 
        car[i].printTom();
    }

    cout << endl;


    double tomCheapest = car[0].tomPrice() , tomMost_expensive = 0;
    double benCheapest = car[0].benPrice() , benMost_expensive = 0;
    for (int i = 0; i < tomListLenght; i++) { //tom database check 
        double price = 0;
        price = car[i].tomPrice();

        if (price < tomCheapest) {
            tomCheapest = price;
        }
        else if (price > tomMost_expensive) {
            tomMost_expensive = price;
        }
    }
    for (int i = 0; i < benListLenght; i++) { //ben database check
        double price;
        price = car[i].benPrice();

        if (price < benCheapest) {
            benCheapest = price;
        }
        else if (price > benMost_expensive) {
            benMost_expensive = price;
        }
    }

    cout << "Tom's cheapest: " << tomCheapest << endl;
    cout << "Tom's most expensive: " << tomMost_expensive << endl;
    cout << endl;
    cout << "Ben's cheapest: " << benCheapest << endl;
    cout << "Ben's most expensive: " << benMost_expensive << endl;

    cout << endl;
    cout << endl;

    int tomScore = 0, benScore = 0;
    if (benMost_expensive > tomMost_expensive) { //most expensive
        cout << "Most expensive : Ben, price - " << benMost_expensive << endl;
        benScore++;
    }
    else {
        cout << "Most expensive : Tom, price - " << tomMost_expensive << endl;
        tomScore++;
    }

    if (benCheapest > tomCheapest) { //cheapest
        cout << "Cheapest : Tom, price - " << tomCheapest << endl;
        tomScore++;
    }
    else {
        cout << "Cheapest : Ben, price - " << benCheapest << endl;
        benScore++;
    }
    cout << endl;


    if (tomScore > benScore) {
        cout << "Winner: Tom!" << endl;
    }
    else if (tomScore < benScore) {
        cout << "Winner: Ben!" << endl;
    }
    else if (tomScore == benScore){
        cout << "Draw!" << endl;
    }
    cout << endl; cout << endl; cout << endl;
}
