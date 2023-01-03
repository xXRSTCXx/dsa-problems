#include <bits/stdc++.h>

using namespace std;

regex r ("[A-Za-z]");

bool checkAnagram(string s1, string s2) {
   unordered_map<char, uint64_t> characters;

    for(char &ch: s1) {
        string ch_string (1, ch);
        if (!regex_match(ch_string, r)) continue;
        characters[ch]++;
    }

    for(char &ch: s2) {
        string ch_string (1, ch);
        if (!regex_match(ch_string, r)) continue;
        characters[ch]--;
    }

    for(auto i = characters.begin(); i != characters.end(); i++) {
        if (i->second != 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    string word1;
    getline(cin, word1);

    string word2;
    getline(cin, word2);

    cout << checkAnagram(word1, word2);
    return 0;
}
