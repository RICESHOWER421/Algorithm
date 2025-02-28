#include <bits/stdc++.h>
using namespace std;

class TextEditor {
public:
    TextEditor() {

    }

    void addText(string text) {
        a += text;
    }

    int deleteText(int k) {
        int cnt = 0;
        while (!a.empty() && k) {
            a.pop_back();
            --k;
            ++cnt;
        }
        return cnt;
    }

    string cursorLeft(int k) {
        while (!a.empty() && k) {
            b += a.back();
            a.pop_back();
            --k;
        }
        return a.size() <= 10 ? a : a.substr(a.size() - 10);
    }

    string cursorRight(int k) {
        while (!b.empty() && k) {
            a += b.back();
            b.pop_back();
            --k;
        }
        return a.size() <= 10 ? a : a.substr(a.size() - 10);
    }
private:
    string a, b;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

int main() {

    return 0;
}