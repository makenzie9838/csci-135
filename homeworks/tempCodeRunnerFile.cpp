#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    vector<int> result = a;

    for (int i = 0; i < b.size(); i++) {
        result.push_back(b[i]);
    }
    
    return result;
}

int main() {
    vector<int> a = {1, 4, 9, 16};
    vector<int> b = {9, 7, 4, 9, 11};

    vector<int> result = append(a, b);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}