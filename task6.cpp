#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> wrapText(const string& text, int lineWidth) {
    istringstream words(text);
    string word;
    vector<string> lines;
    string currentLine;

    while (words >> word) {
        if (currentLine.length() + word.length() + 1 > lineWidth) {
            lines.push_back(currentLine);
            currentLine = word;
        } else {
            if (!currentLine.empty()) currentLine += " ";
            currentLine += word;
        }
    }

    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    return lines;
}

int main() {
    string text = "Mary loves to sing and perform tapdancing.";
    int lineWidth = 10;
    vector<string> wrappedText = wrapText(text, lineWidth);

    for (int i = 0; i < wrappedText.size(); i++) {
        cout << "Line " << i + 1 << ": " << wrappedText[i] << endl;
    }

    return 0;
}
