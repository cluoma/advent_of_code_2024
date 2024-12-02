#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <variant>

using namespace std;

void trim(string & str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    if (first == variant_npos)
        first = 0;
    if (last == variant_npos)
        last = str.length();

    str = str.substr(first, last - first + 1);
}

vector<string> split(string & input, const char * delim)
{
    vector<string> tokens;
    string remainingString = input;
    size_t loc;
    while ( (loc = remainingString.find_first_of(delim)) != variant_npos )
    {
        tokens.push_back(remainingString.substr(0, loc));
        remainingString = remainingString.substr(loc+1);
    }
    tokens.push_back(remainingString);

    return tokens;
}

bool check_report(vector<int> & r) {
    bool is_safe = true;
    bool increasing;
    int diff = r[1] - r[0];
    if (diff > 0)
        increasing = true;
    else
        increasing = false;
    if (abs(diff) < 1 || abs(diff) > 3)
        return false;

    for (int j = 2; j < r.size(); j++) {
        diff = r[j] - r[j-1];

        if ( (diff > 0 && !increasing) || (diff < 0 && increasing) ||
             abs(diff) < 1 || abs(diff) > 3) {
            is_safe = false;
            break;
        }
    }

    if (is_safe)
        return true;
    else
        return false;
}

int main() {
    FILE * f = fopen("day02/day02_data.txt", "r");

    vector<vector<int>> reports;

    char * line = nullptr;
    size_t len;
    uint32_t size = 0;

    while (getline(&line, &len, f) != -1) {
        std::string strLine = std::string(line);

        vector<string> level_str = split(strLine, " ");
        vector<int> level_int;
        for (int i = 0; i < level_str.size(); i++) {
            level_int.push_back(atoi(level_str[i].c_str()));
        }
        reports.push_back(level_int);
    }

    // Part 1
    uint64_t safe = 0;
    for (int i = 0; i < reports.size(); i++) {
        if (check_report(reports[i]))
            safe++;
    }
    printf("Safe count: %lu\n", safe);


    // Part 2
    uint64_t safe2 = 0;
    for (int i = 0; i < reports.size(); i++) {
        if (check_report(reports[i]))
            safe2++;
        else {
            for (int j = 0; j < reports[i].size(); j++) {
                vector<int> r_removed = reports[i];
                r_removed.erase(r_removed.begin()+j);
                if (check_report(r_removed)) {
                    safe2++;
                    break;
                }
            }
        }
    }
    printf("Safe2 count: %lu\n", safe2);
}
