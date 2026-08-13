#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, totalBudget, currSpent=0, maxStudents=0;
    cin>>n>>totalBudget;
    vector<int> requirements(n);
    for(int i=0; i<n; i++) cin>>requirements[i];
    sort(requirements.begin(), requirements.end());
    for(int i=0; i<n; i++)
        {
        if(requirements[i]+currSpent > totalBudget) break;
        currSpent += requirements[i];
        maxStudents++;
        
    } cout << maxStudents << endl;
    return 0;
}
