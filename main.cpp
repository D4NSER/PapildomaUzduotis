#include "funkcijos.h"
vector <string> urls;
map <string, vector<int>> sarasas;


int main() {

    string fileChoice = getFileChoice();

    while (!canOpen(fileChoice)) {
        cout << "Nurodyto failo nepavyko atidaryti. Bandykite atidaryti kita faila." << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Iveskite naujo failo pavadinima: " << endl;
        cin >> fileChoice;
        if (fileChoice.size() < 4 || fileChoice.substr(fileChoice.size() - 4) != ".txt")
            fileChoice += ".txt";
    }
    cout << "\nPalaukite kol failas bus nuskaitytas..." << endl;
    readFile(fileChoice, sarasas, urls);
    cout << "\nFailas nuskaitytas. Rezultatus rasite faile " << "rezultatai.txt" << endl;
    output (sarasas, urls);

}