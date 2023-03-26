#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int> &height) {
    stack<int> s;
    height.push_back(0);
    int n = height.size();
    int max_area = 0;
    for (int i = 0; i < n;) {
        if (s.empty() || height[s.top()] <= height[i]) {
            s.push(i++);
        } else {
            int t = s.top();
            s.pop();
            max_area = max(max_area, height[t] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    return max_area;
}

int largestBlackSubRectangle(vector<vector<bool>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> height(n);
    int max_area = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]) {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        max_area = max(max_area, largestRectangleArea(height));
    }
    return max_area;
}

int main() {
    int n,m;
    cin >> n >> m;
    int k;
    vector<vector<bool>> matrix;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin >> k;
            if(k==1)matrix[i].push_back(true);
            else matrix[i].push_back(false);
        }
    }
    cout << largestBlackSubRectangle(matrix) << endl;
    return 0;
}
