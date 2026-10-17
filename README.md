flowchart TD

A([Start Program]) --> B[Main Menu]

B -->|Register| C[Register User]
B -->|Login| D[Login User]
B -->|Admin Panel| E[Admin Authentication]
B -->|Exit| Z([End Program])

C --> B

E --> F{Correct Admin Password?}

F -->|Yes| G[Display Registered Users]
F -->|No| H[Access Denied]

G --> B
H --> B

D --> I{Valid Username & Password?}

I -->|No| B
I -->|Yes| J[User Dashboard]

J --> K{Select Option}

K -->|1| L[Daily Decision Maker]
K -->|2| M[Priority Calculator]
K -->|3| N[Time Allocation]
K -->|4| O[Budget Decision]
K -->|5| P[Task Prioritization]
K -->|6| Q[Study Planner]
K -->|7| R[Habit Decision]
K -->|8| S[Compare Options]
K -->|9| T[Problem Solver]
K -->|10| U[Decision History]
K -->|11| V[Reports]
K -->|12| W[Control Panel]
K -->|13| X[Logout]

L --> Y[Log Activity]
M --> Y
N --> Y
O --> Y
P --> Y
Q --> Y
R --> Y
S --> Y
T --> Y

Y --> J

U --> J
V --> J
W --> J

X --> B
