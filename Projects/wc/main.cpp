#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: ccwc <flag> <filename>\n";
        return 1;
    }

    string flag;
    string filename;

    if (argc == 2) {
        // No flag, just filename
        filename = argv[1];
        flag = "all";
    } else {
        // Flag + filename
        flag = argv[1];
        filename = argv[2];
    }

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Cannot open file " << filename << "\n";
        return 1;
    }

    size_t lines = 0, words = 0, chars = 0;
    string line, word;

    while (getline(file, line)) {
        lines++;
        chars += line.size() + 1; // +1 for newline
        istringstream iss(line);
        while (iss >> word) {
            words++;
        }
    }

    if (flag == "-c") {
        cout << chars << " " << filename << "\n";
    } else if (flag == "-w") {
        cout << words << " " << filename << "\n";
    } else if (flag == "-l") {
        cout << lines << " " << filename << "\n";
    } else if (flag == "all") {
        cout << lines << " " << words << " " << chars << " " << filename << "\n";
    } else {
        cerr << "Unknown flag: " << flag << "\n";
    }

    return 0;
}
