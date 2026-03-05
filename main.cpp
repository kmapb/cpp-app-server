#include <cstdio>
#include <unordered_map>
#include <string>
#include <cstdlib>
#include <iostream>
#include <format>

#include "shared.hpp"

using namespace std;

const Schema kSchema = {
  { "ts", { INT } },
  { "req", { INT } },
  { "svc", { STR } },
  { "ev", { STR } },
  { "downstream", { STR, true } },
};


struct StaticEvent {
    int64_t ts;
    int64_t req;
    string svc;
    string ev;
    string* downstream = nullptr;
};

int main(int argc, char** argv) {
    printf("Hello, world!\n");
    string line;
    while (getline(cin, line)) {
        dprintf("you said: {}\n", line);
        auto v = parse_line(kSchema, line);
    }
    return 0;
}
