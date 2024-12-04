#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string line;
    std::vector<int> lista, listb;

    ifstream f ("data/day1.txt");

    if (f.is_open()) {
        while (getline(f, line)) {
            size_t delim = line.find(" ");
            size_t lastdelim = line.find_last_of(" ");
            int first = stoi(line.substr(0, delim));
            int last = stoi(line.substr(lastdelim+1, line.size()));
            lista.push_back(first);
            listb.push_back(last);
        }
    }
    sort(lista.begin(), lista.end());
    sort(listb.begin(), listb.end());

    long sum = 0;
    for (int i=0; i < lista.size(); i++) {
        cout << lista[i] << " " << listb[i] << "\n";
        sum += abs(lista[i] - listb[i]);
    }

    cout << "Sum is " << sum << "\n";
    return 0;
}
