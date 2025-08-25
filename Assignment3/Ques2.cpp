#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string s) {
    stack<char> st;
    for (char c : s)
        st.push(c);
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}

int main() {
    string str;
    cout << "Enter string to reverse: ";
    getline(cin, str);
    string reversed = reverseString(str);
    cout << "Reversed string: " << reversed << "\n";
    return 0;
}
