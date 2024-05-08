#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string survive_game(int t) {
    string results;

    for (int i = 0; i < t; ++i) {
        int n, k;
        cin >> n >> k;

        int max_damage = 0;
        int closest_monster = INT_MAX;

        for (int j = 0; j < n; ++j) {
            int health;
            cin >> health;
            if (j < k) {
                max_damage += health;
            }
        }

        for (int j = 0; j < n; ++j) {
            int position;
            cin >> position;
            closest_monster = max(closest_monster, abs(position));
        }
        
        if (closest_monster <= max_damage) {
            results += "YES\n";
        } else {
            results += "NO\n";
        }
    }

    return results;
}

int main() {
    int t;
    cin >> t;

    string results = survive_game(t);

    cout << results;

    return 0;
}
