#include <cstdio>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

constexpr unordered_map<string, Type> kSchema = {
  { "ts",  INT },
  { "req", STR },
};

int main(int argc, char** argv) {
    printf("Hello, world!\n");
    string line;
    while (getline(cin, line)) {
        cout << "you said: " << line << "\n";
    }
    return 0;
}
