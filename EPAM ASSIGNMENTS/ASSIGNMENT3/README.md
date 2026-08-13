Medium Level Problem Statements — Greedy & Dynamic Programming

This repository contains C++ solutions for two medium-level problems based on Greedy Algorithms and Dynamic Programming.

Problem 1: Scholarship Distribution
Problem Statement

A college has a limited scholarship budget. Each student has a minimum scholarship amount they are willing to accept.

The college wants to award scholarships to the maximum number of students without exceeding the available budget.

Each student can receive at most one scholarship.

Input Format
N B
a1 a2 a3 ... aN


Where:

N = number of students
B = total available budget
ai = minimum scholarship required by student i
Output Format

Print the maximum number of students who can receive scholarships.

Constraints
1 ≤ N ≤ 100000
1 ≤ B ≤ 10^9
1 ≤ Scholarship ≤ 10^6
Example
Input
5 20
4 8 2 6 5

Output
4

Explanation

Sort the scholarship requirements:

2 4 5 6 8


Select the smallest requirements first:

2 + 4 + 5 + 6 = 17


Adding the next student would require:

17 + 8 = 25


which exceeds the budget of 20.

Therefore, the maximum number of students is 4.

Algorithm
Read N and the total budget.
Store all scholarship requirements.
Sort the requirements in ascending order.
Select students starting from the smallest requirement.
Stop when adding another scholarship exceeds the budget.
Print the number of selected students.
Complexity
Time Complexity: O(N log N)
Space Complexity: O(N)
Problem 2: Maximum Learning Points
Problem Statement

A student is preparing for a programming contest. Every topic provides a certain number of learning points.

The student cannot select two consecutive topics because of fatigue.

Given the learning points of all topics in order, determine the maximum learning points the student can earn.

Input Format
N
p1 p2 p3 ... pN


Where:

N = number of topics
pi = learning points for topic i
Output Format

Print the maximum learning points.

Constraints
1 ≤ N ≤ 100000
1 ≤ Points ≤ 10000
Example
Input
6
5 1 2 10 6 2

Output
17

Explanation

One optimal selection is:

5 + 10 + 2 = 17


The selected topics are not consecutive, so the constraint is satisfied.

Therefore, the maximum learning points are 17.

Algorithm

Let:

dp[i] = maximum points obtainable from topics 0 through i


For every topic, there are two choices:

Skip the current topic:
dp[i - 1]

Select the current topic:
dp[i - 2] + points[i]


Therefore:

dp[i] = max(dp[i - 1], dp[i - 2] + points[i])


Base cases:

dp[0] = points[0]
dp[1] = max(points[0], points[1])

Complexity
Time Complexity: O(N)
Space Complexity: O(N)
Second Example
Input
5
3 2 7 10 12

Output
22


An optimal selection is:

3 + 7 + 12 = 22


No two selected topics are consecutive.

C++ Implementations
Scholarship Distribution
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, totalBudget;
    int currSpent = 0;
    int maxStudents = 0;

    cin >> n >> totalBudget;

    vector<int> requirements(n);

    for (int i = 0; i < n; i++) {
        cin >> requirements[i];
    }

    sort(requirements.begin(), requirements.end());

    for (int i = 0; i < n; i++) {
        if (requirements[i] + currSpent > totalBudget) {
            break;
        }

        currSpent += requirements[i];
        maxStudents++;
    }

    cout << maxStudents << endl;

    return 0;
}

Maximum Learning Points
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> points(n);
    vector<ll> dp(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    if (n == 1) {
        cout << points[0] << endl;
        return 0;
    }

    dp[0] = points[0];
    dp[1] = max(points[0], points[1]);

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
    }

    cout << dp[n - 1] << endl;

    return 0;
}

Concepts Covered
Problem	Technique	Time	Space
Scholarship Distribution	Greedy + Sorting	O(N log N)	O(N)
Maximum Learning Points	Dynamic Programming	O(N)	O(N)
Key Takeaways
Greedy: Sort the scholarship requirements and always choose the smallest available requirement first.
Dynamic Programming: At every topic, choose between taking the current topic or skipping it.
long long is used in the DP solution to safely store larger accumulated values.
