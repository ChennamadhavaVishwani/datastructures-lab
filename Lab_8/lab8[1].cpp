#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n); 
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }

        int x = a[0]; 
        
        // Sort the array from the second element onwards
        sort(a.begin() + 1, a.end());

       
        for (int i = 1; i < n; i++) {
            if (a[i] > x) {
                int difference = a[i] - x;
                int moves = (difference + 1) / 2; 
                x = x + moves; 
            }
        }

        cout << x << endl; 
    }

    return 0;
}
