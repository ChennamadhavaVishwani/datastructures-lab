#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<string>> words(3, vector<string>(n));
    vector<string> allWords;  

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> words[i][j];
            allWords.push_back(words[i][j]);
        }
    }

    vector<int> scores(3, 0);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string word = words[i][j];
            int count = 0;

            for (string &w : allWords) {
                if (w == word) count++;
            }

            
            if (count == 1)
                scores[i] += 3;
            else if (count == 2)
                scores[i] += 1;
        }
    }

   
    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
