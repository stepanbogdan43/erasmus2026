#include <iostream>  // Pentru a putea folosi cout si cin
#include <string>    // Pentru a lucra cu siruri de caractere
#include <vector>    // Pentru a stoca lista de cuvinte
#include <algorithm> // Pentru a amesteca cuvintele
#include <ctime>     // Pentru a genera numere aleatoare
#include <random>    // Pentru shuffle modern

using namespace std; // Pentru a nu scrie std:: inainte de fiecare functie

// Functie pentru a desena spanzuratoarea in functie de numarul de greseli
void deseneazaSpanzuratoarea(int greseli) {
    cout << "  +---+" << endl;
    cout << "  |   |" << endl;
    if (greseli >= 1) cout << "  O   |" << endl; else cout << "      |" << endl;
    if (greseli >= 4) cout << " /|\\  |" << endl; else if (greseli >= 3) cout << " /|   |" << endl; else if (greseli >= 2) cout << "  |   |" << endl; else cout << "      |" << endl;
    if (greseli >= 6) cout << " / \\  |" << endl; else if (greseli >= 5) cout << " /    |" << endl; else cout << "      |" << endl;
    cout << "      |" << endl;
    cout << "=========" << endl;
}

int main() {
    // Initializam generatorul de numere aleatoare cu timpul curent
    srand(time(0));

    // Lista de cuvinte din care alegem unul random
    vector<string> cuvinte = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape","man","woman","bird","drawing"};

    // Amestecam cuvintele pentru a le face mai imprevizibile
    random_device rd;
    mt19937 g(rd());
    shuffle(cuvinte.begin(), cuvinte.end(), g);

    // Alegem primul cuvant din lista amestecata
    string cuvant = cuvinte[0];

    // Cream un sir pentru a arata progresul (cu _ pentru literele neincheiate)
    string progres = string(cuvant.length(), '_');

    // Numarul maxim de greseli permise
    int greseli_max = 6;
    int greseli = 0;

    // Un sir pentru a tine evidenta literelor ghicite
    string litere_ghicite = "";

    cout << "Welcome to the Hangman game!" << endl;
    deseneazaSpanzuratoarea(greseli);
    cout << "Guess the word: " << progres << endl;

    // Bucla principala a jocului
    while (greseli < greseli_max && progres != cuvant) {
        cout << "Enter a letter: ";
        char litera;
        cin >> litera;

        // Verificam daca litera a fost deja ghicita
        if (litere_ghicite.find(litera) != string::npos) {
            cout << "You already guessed this letter!" << endl;
            continue;
        }

        // Adaugam litera la lista celor ghicite
        litere_ghicite += litera;

        // Verificam daca litera este in cuvant
        bool gasita = false;
        for (size_t i = 0; i < cuvant.length(); ++i) {
            if (cuvant[i] == litera) {
                progres[i] = litera;
                gasita = true;
            }
        }

        if (gasita) {
            cout << "Great! The letter " << litera << " is in the word." << endl;
        } else {
            greseli++;
            cout << "The letter " << litera << " is not in the word. Mistakes: " << greseli << "/" << greseli_max << endl;
        }

        // Desenam spanzuratoarea
        deseneazaSpanzuratoarea(greseli);

        cout << "Word: " << progres << endl;
    }

    // Verificam daca jucatorul a castigat sau pierdut
    if (progres == cuvant) {
        cout << "Congratulations! You guessed the word: " << cuvant << endl;
    } else {
        cout << "You lost! The word was: " << cuvant << endl;
    }

    // Intrebam daca vrea sa joace din nou
    cout << "Do you want to play again? (yes/no): ";
    string raspuns;
    cin >> raspuns;

    if (raspuns == "yes") {
        // Repornim jocul prin recursie (nu cea mai buna metoda, dar simpla)
        main();
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}