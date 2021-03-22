#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    bool done=false;
    bool skipRepeated;
    int count, toAdd, countsDone;
    int attempts = 1;
    string test, toBrute, empty, temp;
    vector <string> x{ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", " " };
    vector <string> used{};

    cout << "String to brute force: ";
    cin >> toBrute;

    cout << "Skip repeated strings [Y/N]: ";
    cin >> temp;

    skipRepeated = temp == "Y" || temp == "y";
    

    while (done == false) {
        

        countsDone = 0;
        count = rand() % (toBrute.size() + 5);
        test = "";
        
        while (countsDone < count) {
            toAdd = rand() % x.size();
            test += x[toAdd];
            countsDone++;
        }

        if (skipRepeated == true && std::find(used.begin(), used.end(), test) != used.end()) {
            attempts++;
            cout << "Skipped [Attempt " << attempts << "]" << endl;
        };

        attempts++;
        cout << test << " [Attempt " << attempts << "]" << endl;
        used.push_back(test);
        
        done = test == toBrute;
    }

    cout << "done. press enter to exit";
    cin >> empty;
}