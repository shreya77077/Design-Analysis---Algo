#include <iostream>
#include <string>
using namespace std;

bool isDivisibleBy8(string str) {
    int n = str.length();
    if (n < 3)
        return false;
    int last = str[n - 1] - '0';
    int second_last = str[n - 2] - '0';
    int third_last = str[n - 3] - '0';
    return ((third_last * 100 + second_last * 10 + last) % 8 == 0);
}

string changeToDivisibleBy8(string str) {
    if (isDivisibleBy8(str))
        return str;
    for (int i = 0; i < str.length(); i++) {
        char original = str[i];
        for (char c = '0'; c <= '9'; c++) {
            str[i] = c;
            if (isDivisibleBy8(str)) {
                return str;
            }
        }
        str[i] = original;
    }
    return "-1";
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string str;
        cin >> n >> str;
        cout << changeToDivisibleBy8(str) << endl;
    }
    return 0;
}
