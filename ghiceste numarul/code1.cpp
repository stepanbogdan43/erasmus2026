#include <iostream>
#include <cstdlib>
using namespace std;


int main() {
    int randomnumber, ghicire, incercari = 10;

    randomnumber =rand() % 101 ;

    cout << "=== Guess the Number ==="<<endl;
    cout << "Am ales un numar intre 1 si 100."<<endl;
    cout << "Ai 10 incercari"<<endl;
    do {

        cout << "Introdu un numar: "<<endl;
        cin >> ghicire;
        incercari--;


        if (ghicire > randomnumber) {

            cout << "Prea mare!"<<endl;
            cout << "Mai ai "<<incercari<<" incercari"<<endl;

        } else if (ghicire < randomnumber) {

            cout << "Prea mic!"<<endl;
            cout << "Mai ai "<<incercari<<" incercari"<<endl;

        } else {

            cout << "Felicitari! Ai ghicit numarul in " <<10-incercari << " incercari!"<<endl;
        }

    } 
    while (ghicire != randomnumber && incercari>0);
    cout<<"Numarul era "<< randomnumber<<endl;
    return 0;
}
 