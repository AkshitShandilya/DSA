#include <iostream>
#include <string>
using namespace std;

bool canSplit(string s) {
    int n = s.length();

    
    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i, j - i);
            string part3 = s.substr(j);

           
            if ((part1.find(part2) != string::npos && part3.find(part2) != string::npos) ||
                (part2.find(part1) != string::npos && part3.find(part1) != string::npos) ||
                (part1.find(part3) != string::npos && part2.find(part3) != string::npos)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    if (canSplit(s))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
