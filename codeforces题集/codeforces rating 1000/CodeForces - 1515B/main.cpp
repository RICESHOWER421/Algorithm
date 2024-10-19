#include <iostream>
using namespace std;

void Test() {
    int n = 0;
    cin >> n;

    if (n % 2) {
        cout << "NO" << "\n";
        return;
    }

    int ret_1 = n / 2;
    int begin = 1;
    while (begin * begin < ret_1) {
        begin++;
    }

    if (begin * begin == ret_1) {
        cout << "YES" << "\n";
        return;
    }

    if (n % 4) {
        cout << "NO" << "\n";
    }
    else {
        int ret_2 = n / 4;
        begin = 1;
        while (begin * begin < ret_2) {
            begin++;
        }

        if (begin * begin == ret_2) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}

int main() {
    Test();
	return 0;
}