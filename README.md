# EPAM-SYSTEM
# ASSIGNMENT 1
# A responsive web app for XYZ Bank's Diwali coupon promo. Users register, enter a customer ID, and validate it against records with real-time feedback. Once validated, they generate a unique coupon code. Built with clean HTML, CSS (mobile-responsive), and JS handling step-by-step logic and input state.

## Web Page Overview — with Technology Details

**Project Name:** XYZ Bank – Diwali Coupon Registration Portal

**Purpose:** A promotional customer-facing web page that lets bank customers verify their identity and claim a Diwali festival discount coupon through a guided, three-step interactive process — without needing a backend or page reload.

**Type:** Front-end only, single-page interactive form

| Aspect | Details |
|---|---|
| **Project Type** | Static, client-side web application (no backend/database) |
| **Target Users** | XYZ Bank customers accessing a seasonal promotional campaign |
| **Core Goal** | Validate a customer's identity and issue a unique coupon code |
| **File Structure** | `index.html` (markup), `style.css` (styling), `app.js` (logic) |
| **Design Approach** | Mobile-first, responsive layout using flexbox and media queries |
| **State Management** | Simple JS boolean flag (`isValidated`) to control access to coupon generation |
| **Data Source** | Hardcoded demo array (`knownCustomers`) simulating a customer database |
| **User Interaction Model** | Progressive disclosure — sections reveal only as the user completes each step |

## Technology Stack

| Layer | Technology | Version/Standard | Role in Project |
|---|---|---|---|
| Structure | HTML5 | Living Standard | Defines page content, form elements, semantic layout |
| Styling | CSS3 | Level 3/4 features (Flexbox, `clamp()`, media queries) | Handles visual design and responsive behavior |
| Logic/Interactivity | JavaScript (ES6+) | Vanilla JS, no framework | Handles DOM manipulation, event listeners, validation logic |
| Layout Engine | CSS Flexbox | `display: flex` | Powers the button row layout and responsive stacking |
| Responsive Technique | CSS Media Queries | `@media (max-width: 480px)` | Adapts layout for mobile screens |
| Fluid Typography | CSS `clamp()` | Native CSS function | Scales heading size smoothly across viewport widths |
| Pattern Matching | JavaScript Regular Expressions | `/^[A-Za-z0-9]{4,12}$/` | Validates customer ID format |
| Random Generation | JavaScript `Math.random()` | Native JS | Generates unique coupon codes |
| Browser APIs Used | DOM API | `document.getElementById`, `addEventListener`, `classList` | Element selection and event handling |
| Font | Georgia / Times New Roman (system serif) | Web-safe fonts | Typography, no external font loading required |

## Why This Stack Was Chosen

| Reason | Explanation |
|---|---|
| No dependencies | Pure HTML/CSS/JS means zero build tools, npm packages, or frameworks — loads instantly |
| Lightweight | Small file sizes make it fast on any connection, including mobile banking users |
| Framework-agnostic foundation | Easy to later migrate into React/Vue/Angular or integrate into an existing bank portal |
| Wide browser compatibility | Vanilla JS + standard CSS3 features work across all modern browsers without polyfills |
| Easy backend integration path | The `fetch()` API can be dropped into `app.js` later to replace the hardcoded array with a real REST API call |

# ASSIGNMENT 2
# Medium Level Problem Statements — Tree & Graph

# PROBLEM 1: TREE OF TRUSTED SERVERS

DESCRIPTION:
A multinational organization maintains its internal communication infrastructure as a tree, where:
- Each node represents a server.
- Each edge represents a communication link.
- Server 1 is the root (central authentication server).
- Every server holds a unique security key (integer value).

A server is considered trusted if the XOR of all security keys along the path from the root to that server is greater than or equal to a given threshold K. The root itself is included in the evaluation.

The task is to determine how many servers in the tree are trusted.

INPUT FORMAT:
Line 1: N K
Line 2: N integers (security keys)
Next N-1 lines: u v (tree edges)

OUTPUT FORMAT:
A single integer — the number of trusted servers.

CONSTRAINTS:
1 ≤ N ≤ 10^5
0 ≤ K ≤ 10^9
0 ≤ Key ≤ 10^9
Input graph is guaranteed to be a valid tree

APPROACH:
1. Build an adjacency list representation of the tree from the given edges.
2. Perform a DFS (or BFS) starting from the root (Server 1).
3. Maintain a running XOR value while traversing from the root to each node:
   pathXOR(child) = pathXOR(parent) XOR key[child]
   pathXOR(root) = key[root]
4. At each visited node, compare pathXOR(node) with K.
5. Increment a counter whenever pathXOR(node) >= K.
6. After traversing all N nodes, output the counter.

COMPLEXITY:
Time: O(N)
Space: O(N)

SAMPLE INPUT:
7 5
3 6 2 7 1 4 5
1 2
1 3
2 4
2 5
3 6
3 7

SAMPLE OUTPUT:
4

EXPLANATION:
For each server, the path XOR is accumulated while performing DFS from the root, using the rule pathXOR(child) = pathXOR(parent) XOR key[child], with pathXOR(root) = key[root]. Once every server's path XOR is computed, each value is compared against the threshold K = 5. Servers whose path XOR is greater than or equal to K are counted as trusted. Applying this rule across the tree in the sample input yields 4 trusted servers.

ADDITIONAL EXAMPLE:
Input:
5 2
1 3 2 5 6
1 2
1 3
3 4
3 5

Output:
3

# PROBLEM 2: EMERGENCY ROUTE VALIDATION


DESCRIPTION:
A country's transportation network is modeled as a connected, undirected graph, where:
- Each vertex represents a city.
- Each edge represents a highway/road.
- City 1 is the capital.

During emergencies, rescue teams travel from the capital to other cities. A city is considered efficiently reachable if the shortest path (in number of roads) from City 1 to that city is less than or equal to D.

The task is to determine the total number of efficiently reachable cities, including the capital. Unreachable cities are not counted.

INPUT FORMAT:
Line 1: N M D
Next M lines: u v (roads)

OUTPUT FORMAT:
A single integer — the number of efficiently reachable cities.

CONSTRAINTS:
1 ≤ N ≤ 10^5
0 ≤ M ≤ 2×10^5
0 ≤ D ≤ N
No self-loops

APPROACH:
1. Build an adjacency list from the given roads.
2. Run a standard BFS starting from City 1, since BFS guarantees shortest paths in an unweighted graph.
3. Track the distance (dist[]) of every city from City 1, initialized to -1 (unvisited/unreachable).
4. During BFS, update dist[neighbor] = dist[current] + 1.
5. After BFS completes, count how many cities satisfy 0 <= dist[city] <= D (this naturally excludes unreachable cities, which remain at -1).
6. Output the count.

COMPLEXITY:
Time: O(N + M)
Space: O(N + M)

SAMPLE INPUT:
7 8 2
1 2
1 3
2 4
2 5
3 6
6 7
5 7
4 6

SAMPLE OUTPUT:
6

EXPLANATION:
Running BFS from City 1 gives the following shortest distances:
City 1 → 0
City 2 → 1
City 3 → 1
City 4 → 2
City 5 → 2
City 6 → 2
City 7 → 3

Cities with distance less than or equal to D = 2 are Cities 1, 2, 3, 4, 5, and 6. This gives a total of 6 efficiently reachable cities.

ADDITIONAL EXAMPLE:
Input:
6 5 1
1 2
2 3
1 4
4 5
5 6

Output:
3


KEY CONCEPTS USED


Concept                                    | Problem 1 | Problem 2
--------------------------------------------------------------
Tree/Graph Representation (Adjacency List) |    Yes    |    Yes
DFS Traversal                              |    Yes    |    No
BFS Traversal                              | Optional  |    Yes
Path Aggregation (XOR)                     |    Yes    |    No
Shortest Path (Unweighted Graph)           |    No     |    Yes
Threshold-based Counting                   |    Yes    |    Yes

 
