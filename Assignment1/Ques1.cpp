#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, pos, val, i, key;
    while (1) {
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                for (i = 0; i < n; i++) cin >> arr[i];
                break;
            case 2:
                for (i = 0; i < n; i++) cout << arr[i] << " ";
                cout << "\n";
                break;
            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                for (i = n; i > pos; i--) arr[i] = arr[i - 1];
                arr[pos] = val;
                n++;
                break;
            case 4:
                cout << "Enter position: ";
                cin >> pos;
                for (i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
                n--;
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> key;
                for (i = 0; i < n; i++) {
                    if (arr[i] == key) {
                        cout << "Found at position " << i << "\n";
                        break;
                    }
                }
                if (i == n) cout << "Not found\n";
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}
