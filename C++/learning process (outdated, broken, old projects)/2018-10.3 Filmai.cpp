#include <iostream>
#include <stdlib.h>

using namespace std;

/* TEST DATA:

6
1000000 8.6
120000 8.5
20000000 8.6
200000000 5.8
200000000 8.6
120000 7.7

*/

//structure
struct Movie {
public:
    long int budget;
    double rating;

    struct Movie* next;
};

//imput n (Movie count)
int imputN() {
loop:
    int n;
    cout << "Imput number of movies (1-100): ";
    cin >> n;

    //Fool proof (0 < n <= 100)
    if (n > 100 || n < 0) {
        cout << "Wrong number, imput anew. " << endl;
        goto loop;
    }
    return n;
}

//push list
void addToFirst(struct Movie** head, long int node_data, double node_data2) {

    struct Movie* newMovie = new Movie;
    newMovie->budget = node_data;
    newMovie->rating = node_data2;
    newMovie->next = (*head);
    (*head) = newMovie;
}

//display all list from front to back
void displayList(struct Movie* node) {
    cout << "Dynamic list: ";
    if (node == NULL) {
        cout << "null";
        return;
    }
    while (node != NULL)
    {
        cout << node->budget << " ";
        cout << node->rating << " ";
        cout << "--> ";
        node = node->next;
    }

    if (node == NULL)
        cout << "null" << endl;
}

//return smallest budget index or data
int searchForSmallestBudget(struct Movie** head){
    
    struct Movie* curr = *head;

    int currentPlace=0;
    int current_place_stamp = 0;

    long int data=curr->next->budget;

    data = curr->budget;
    //cout << "data: " << curr->budget<< endl;
    curr = curr->next;
    //cout << "data: " << curr->budget << endl;
    currentPlace++;

    while (curr->budget != NULL) {
        

        if (curr->budget < data) {
            
            //cout << "pre stamp: " << currentPlace << endl;
            current_place_stamp = currentPlace;
            //cout <<"current place stamp: "<< current_place_stamp;
            data = curr->budget;
        }

        //cout << "current place:" << currentPlace;
        currentPlace++;

        if (curr->next == NULL) {
            //cout << endl;
            //cout << "data: " << data << endl;
            //cout << "current place stamp: " <<current_place_stamp<< endl;

            //return data;
            cout << endl;
            return current_place_stamp;
        }
        curr = curr->next;

    }

    
}

//return biggest rating
int searchForBiggestRating(struct Movie** head) {

    struct Movie* curr = *head;

    int currentPlace = 0;
    int current_place_stamp = 0;

    double data = curr->next->rating;

    data = curr->rating;
    //cout << "data: " << curr->budget<< endl;
    curr = curr->next;
    //cout << "data: " << curr->budget << endl;
    currentPlace++;

    while (curr->rating != NULL) {




        //move +1


        if (curr->rating >= data) {

            //cout << "pre stamp: " << currentPlace << endl;
            current_place_stamp = currentPlace;
            //cout <<"current place stamp: "<< current_place_stamp;
            data = curr->rating;
            //cout <<"Current data: "<< data<<endl;
        }

        //cout << "current place:" << currentPlace;
        currentPlace++;

        if (curr->next == NULL) {
            //cout << endl;
            //cout << "data: " << data << endl;
            //cout << "current place stamp: " <<current_place_stamp<< endl;

            //return data;
            cout << endl;
            return current_place_stamp;
        }

        curr = curr->next;

    }
}

//searcthing for budget and rating specific
void searchForBudgedAndRating(struct Movie** head, long int budgetGoal, double ratingGoal, int n) {

    cout << "MOVIES WITH BUDGET LESS THAN 100 000 000$ AND RATING OF MORE THAN 8.5: ";

    struct Movie* curr = *head;

    int currentPlace = 0;
    int current_place_stamp = 0;

    while (curr->budget != NULL) {

        if (curr->budget < budgetGoal && curr->rating > ratingGoal) {

            cout << n-currentPlace << " ";
            current_place_stamp = currentPlace;
        }

        currentPlace++;

        if (curr->next == NULL) {
            cout << endl;
            cout << endl;
            return;
        }
        curr = curr->next;
    }
}

int main()
{
    struct Movie* head = NULL;
    int n=imputN();

    //cin n movies
    cout << "Movies: " << endl;
    for (int i = 0; i < n; i++) {
        long int biudzetas;
        double reitingas;
        cin >> biudzetas >> reitingas;
        addToFirst(&head, biudzetas, reitingas);
    }
    cout << endl;

    //cout n movies
    displayList(head);

    //searching biggest rating index
    cout << "BIGGEST RATING: " << n - searchForBiggestRating(&head);

    //searching smallest budget index
    cout << "SMALLEST BUDGET: " << n - searchForSmallestBudget(&head) << endl;
    
    //Searching for budget less than X $ and rating more than X;
    searchForBudgedAndRating(&head, 100000000, 8.5, n);
}