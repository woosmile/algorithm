#include <iostream>
#include <cstring>

using namespace std;

int alpha[26];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    for (int i = 0; i < s.length(); i++)
    {
        alpha[s.at(i) - 'a'] = alpha[s.at(i) - 'a'] + 1;
    }
    
    for (int i = 0; i < 26; i++)
    {
        cout << alpha[i] << ' ';
    }
    return (0);
}