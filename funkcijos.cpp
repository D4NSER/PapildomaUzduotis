#include "mylib.h"

string getFileChoice() {
    cout << "\nGalimi failai:" << endl;
    string dirPath = "./";
    for (const auto& i : fs::directory_iterator(dirPath)) {
        if (i.is_regular_file() && i.path().extension() == ".txt") {
            cout << i.path().filename() << endl;
        }
    }
    string fileChoice;
    cout << "\nIveskite failo, kuri norite nuskaityti, pavadinima: "<< endl;
    cin >> fileChoice; 

    if (fileChoice.size() < 4 || fileChoice.substr(fileChoice.size() - 4) != ".txt")
        fileChoice += ".txt";

    return fileChoice.empty() ? "text.txt" : fileChoice;
}

bool canOpen (const string& fileChoice) {
    ifstream in(fileChoice);
    return in.good();
}

bool isURL (const string& zodis) {
    regex urlRegex("(((http|https)://)?www\\.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
    return regex_match(zodis, urlRegex);
}

string fixWords(const string& zodis) {
    regex notFixedRegex("[^\\w]+");
    string fixedRegex = regex_replace(zodis, notFixedRegex, "");
    transform(fixedRegex.begin(), fixedRegex.end(), fixedRegex.begin(), ::tolower);
    return fixedRegex;
}

void addToTheList(const string& zodis, map<string, vector<int>>& sarasas, int eilutesNumeris) {
    if (zodis.empty()) 
        return;

    auto it = sarasas.find(zodis);

    if (it == sarasas.end()) {
        vector<int> eiluciuNr;
        eiluciuNr.push_back(eilutesNumeris);
        sarasas[zodis] = eiluciuNr;
    }
    else {
        vector<int>& eiluciuNr = it->second;
        if (eilutesNumeris != eiluciuNr.back()) {
            eiluciuNr.push_back(eilutesNumeris);
        }
    }
}

void readFile(const string& fileChoice,  map<string, vector<int>>& sarasas, vector<string>& urls) {
    ifstream failas;
    failas.open(fileChoice);
    stringstream tekstas;
    tekstas << failas.rdbuf();
    failas.close();

    string eilute;
    int eilutesNumeris = 0;
    while(getline(tekstas, eilute)) {
        eilutesNumeris++;
        string zodis;
        istringstream in(eilute);
        while( in >> zodis) {
            bool isNumber = false; 
            for (char c : zodis) {
                if (isdigit(c)) {
                    isNumber = true;
                    break;
                }
            }
            if(isURL(zodis)) {
                urls.push_back(zodis);
            }
            else if (!isNumber) {
                zodis = fixWords(zodis);
                addToTheList(zodis, sarasas,eilutesNumeris);
            }
        }
    }
}

void output ( map<string, vector<int>>& sarasas,vector<string> urls) {
    ofstream out("rezultatai.txt");
    if (!out.good()) {
        cout << "Failo nepavyko sukurti." << endl;
        return;
    }

    out << "URL count: " << urls.size() << "." << endl;
    for (const auto& url : urls)
        out << url << endl;

    out << endl;

   if (!sarasas.empty()) {
        out << left << setw(30) << "ZODIS" << setw(10) << "KIEKIS" << "EILUCIU NR." << endl;

        for (const auto& i : sarasas) {
            if (i.second.size() > 1){
                out << left << setw(30) << i.first << setw(10) << i.second.size();

                for (int j : i.second) {
                    out << setw(4) << j;
                }

            out << endl;
            }
        }
    }

    out.close();
}
  

