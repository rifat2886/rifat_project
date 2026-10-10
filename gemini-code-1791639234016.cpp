#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ডেটা মেমোরিতে ধরে রাখার স্ট্রাকচার
struct User {
    string username;
    string password;
};

struct HistoryRecord {
    string username;
    string activity;
};

// গ্লোবাল মেমোরি লিস্ট (অনলাইন কম্পাইলারে কাজ করার জন্য)
vector<User> registeredUsers;
vector<HistoryRecord> userHistory;

// --- AUTHENTICATION & ADMIN FUNCTIONS ---

void registerUser() {
    string u, p;
    cout << "\n=== REGISTRATION ===\n";
    cout << "Enter Username (single word): ";
    cin >> u;
    cout << "Enter Password (single word): ";
    cin >> p;

    // চেক করা ইউজার আগে থেকে আছে কি না
    for (const auto &user : registeredUsers) {
        if (user.username == u) {
            cout << ">> Error: Username already exists! Try another.\n";
            return;
        }
    }

    // মেমোরিতে সেভ করা
    registeredUsers.push_back({u, p});
    cout << ">> Registration Successful!\n";
    cout << ">> User registered: " << u << "\n";
}

bool loginUser(string &activeUser) {
    string u, p;
    cout << "\n=== LOGIN ===\n";
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    for (const auto &user : registeredUsers) {
        if (user.username == u && user.password == p) {
            activeUser = u;
            cout << ">> Login Successful! Welcome, " << activeUser << "!\n";
            return true;
        }
    }

    cout << ">> Invalid Username or Password!\n";
    return false;
}

void adminPanel() {
    string pass;
    cout << "\nEnter Admin Secret Password: ";
    cin >> pass;

    if (pass == "admin123") {
        cout << "\n=== ADMIN PANEL: REGISTERED USERS ===\n";
        if (registeredUsers.empty()) {
            cout << ">> No users registered yet!\n";
            return;
        }
        for (size_t i = 0; i < registeredUsers.size(); ++i) {
            cout << (i + 1) << ". User: " << registeredUsers[i].username << "\n";
        }
    } else {
        cout << ">> Wrong Admin Password!\n";
    }
}

void logHistory(const string &user, const string &act) {
    userHistory.push_back({user, act});
}

// --- ALL 13 MENU FUNCTIONS ---

// 1. Daily Decision Maker
void dailyDecisionMaker() {
    cout << "\n--- 1. Daily Decision Maker ---\n";
    int examDays, energyLevel;
    cout << "Days remaining until exam/deadline: ";
    cin >> examDays;
    cout << "Your current energy level (1-10): ";
    cin >> energyLevel;

    if (examDays <= 2 || energyLevel >= 7) {
        cout << ">> Decision: Focus on studying today!\n";
    } else {
        cout << ">> Decision: Take some time to rest and relax!\n";
    }
}

// 2. Priority Calculator
void priorityCalculator() {
    cout << "\n--- 2. Priority Calculator ---\n";
    string task;
    int urgency, importance;
    cout << "Enter task name: ";
    cin >> task;
    cout << "Urgency (1-10): ";
    cin >> urgency;
    cout << "Importance (1-10): ";
    cin >> importance;

    int score = urgency * importance;
    cout << ">> Task: " << task << "\n";
    cout << ">> Priority Score: " << score << "/100\n";
    if (score >= 60) cout << ">> Status: High Priority (Do it immediately!)\n";
    else if (score >= 30) cout << ">> Status: Medium Priority (Plan ahead)\n";
    else cout << ">> Status: Low Priority (Can be done later)\n";
}

// 3. Time Allocation
void timeAllocation() {
    cout << "\n--- 3. Time Allocation (24 Hours) ---\n";
    int study, sleep, chores;
    cout << "Planned study hours: ";
    cin >> study;
    cout << "Planned sleep hours: ";
    cin >> sleep;
    cout << "Planned chore hours: ";
    cin >> chores;

    int total = study + sleep + chores;
    if (total > 24) {
        cout << ">> Error: Total exceeds 24 hours by " << (total - 24) << " hours!\n";
    } else {
        cout << ">> Remaining Free Time: " << (24 - total) << " hours for leisure.\n";
    }
}

// 4. Budget Decision
void budgetDecision() {
    cout << "\n--- 4. Budget Decision ---\n";
    double budget, cost;
    cout << "Enter total monthly budget (Tk): ";
    cin >> budget;
    cout << "Enter cost of the item to buy (Tk): ";
    cin >> cost;

    if (cost > budget * 0.40) {
        cout << ">> Advice: Cost is more than 40% of budget. Postpone purchasing!\n";
    } else {
        cout << ">> Advice: Safe to buy. Remaining savings: " << (budget - cost) << " Tk.\n";
    }
}

// 5. Task Prioritization
void taskPrioritization() {
    cout << "\n--- 5. Task Prioritization ---\n";
    string t1, t2;
    int p1, p2;
    cout << "Task 1 Name: ";
    cin >> t1;
    cout << "Task 1 Priority (1-100): ";
    cin >> p1;
    cout << "Task 2 Name: ";
    cin >> t2;
    cout << "Task 2 Priority (1-100): ";
    cin >> p2;

    cout << "\n>> Prioritized Order:\n";
    if (p1 >= p2) {
        cout << "1. " << t1 << " (Score: " << p1 << ")\n";
        cout << "2. " << t2 << " (Score: " << p2 << ")\n";
    } else {
        cout << "1. " << t2 << " (Score: " << p2 << ")\n";
        cout << "2. " << t1 << " (Score: " << p1 << ")\n";
    }
}

// 6. Study Planner
void studyPlanner() {
    cout << "\n--- 6. Study Planner ---\n";
    int chapters, days;
    cout << "Total chapters to complete: ";
    cin >> chapters;
    cout << "Days remaining before exam: ";
    cin >> days;

    if (days <= 0) {
        cout << ">> Invalid days entered!\n";
    } else {
        double perDay = (double)chapters / days;
        cout << ">> Target: Study at least " << perDay << " chapters per day.\n";
    }
}

// 7. Habit Decision
void habitDecision() {
    cout << "\n--- 7. Habit Decision ---\n";
    int doneDays;
    cout << "How many days did you follow the habit this week (0-7)? ";
    cin >> doneDays;

    if (doneDays >= 5) {
        cout << ">> Outstanding! You are maintaining consistency.\n";
    } else {
        cout << ">> Needs improvement! Try taking small steps every day.\n";
    }
}

// 8. Compare Options
void compareOptions() {
    cout << "\n--- 8. Compare Options ---\n";
    string opt1, opt2;
    int s1, s2;
    cout << "Option 1 Name: ";
    cin >> opt1;
    cout << "Rating for " << opt1 << " (1-10): ";
    cin >> s1;
    cout << "Option 2 Name: ";
    cin >> opt2;
    cout << "Rating for " << opt2 << " (1-10): ";
    cin >> s2;

    if (s1 > s2) cout << ">> Recommendation: " << opt1 << " is better!\n";
    else if (s2 > s1) cout << ">> Recommendation: " << opt2 << " is better!\n";
    else cout << ">> Both options are equally good!\n";
}

// 9. Problem Solver
void problemSolver() {
    cout << "\n--- 9. Problem Solver ---\n";
    int control;
    cout << "Is the issue under your direct control? (1 for Yes, 0 for No): ";
    cin >> control;

    if (control == 1) {
        cout << ">> Action: Break the issue into 3 micro steps and execute step 1 right now.\n";
    } else {
        cout << ">> Action: It is beyond your control. Focus on accepting and staying calm.\n";
    }
}

// 10. Decision History
void decisionHistory(const string &user) {
    cout << "\n--- 10. Decision History (" << user << ") ---\n";
    bool found = false;
    for (const auto &rec : userHistory) {
        if (rec.username == user) {
            cout << "- " << rec.activity << "\n";
            found = true;
        }
    }
    if (!found) cout << ">> No previous activity logged yet.\n";
}

// 11. Reports
void showReports(const string &user) {
    cout << "\n--- 11. Reports ---\n";
    cout << ">> Active Account: " << user << "\n";
    cout << ">> Status: Online\n";
    cout << ">> Total Registered Users in System: " << registeredUsers.size() << "\n";
}

// 12. Control Panel
void controlPanel() {
    cout << "\n--- 12. Control Panel ---\n";
    cout << ">> System Version: 1.0 (Online/Mobile Ready)\n";
    cout << ">> Admin Passcode: admin123\n";
}

// 13. Exit
void exitProgram() {
    cout << "\n>> Logged out safely.\n";
}

// --- USER DASHBOARD ---

void userDashboard(const string &user) {
    int ch;
    do {
        cout << "\n==============================================\n";
        cout << " ===== PERSONAL DECISION & PROBLEM SOLVER =====\n";
        cout << " Active User: " << user << "\n";
        cout << "==============================================\n";
        cout << "1. Daily Decision Maker\n";
        cout << "2. Priority Calculator\n";
        cout << "3. Time Allocation\n";
        cout << "4. Budget Decision\n";
        cout << "5. Task Prioritization\n";
        cout << "6. Study Planner\n";
        cout << "7. Habit Decision\n";
        cout << "8. Compare Options\n";
        cout << "9. Problem Solver\n";
        cout << "10. Decision History\n";
        cout << "11. Reports\n";
        cout << "12. Control Panel\n";
        cout << "13. Exit\n";
        cout << "Choose an option (1-13): ";
        cin >> ch;

        switch (ch) {
            case 1: dailyDecisionMaker(); logHistory(user, "Used Daily Decision Maker"); break;
            case 2: priorityCalculator(); logHistory(user, "Used Priority Calculator"); break;
            case 3: timeAllocation(); logHistory(user, "Used Time Allocation"); break;
            case 4: budgetDecision(); logHistory(user, "Used Budget Decision"); break;
            case 5: taskPrioritization(); logHistory(user, "Used Task Prioritization"); break;
            case 6: studyPlanner(); logHistory(user, "Used Study Planner"); break;
            case 7: habitDecision(); logHistory(user, "Used Habit Decision"); break;
            case 8: compareOptions(); logHistory(user, "Used Compare Options"); break;
            case 9: problemSolver(); logHistory(user, "Used Problem Solver"); break;
            case 10: decisionHistory(user); break;
            case 11: showReports(user); break;
            case 12: controlPanel(); break;
            case 13: exitProgram(); break;
            default: cout << ">> Invalid option! Try again.\n";
        }
    } while (ch != 13);
}

// --- MAIN FUNCTION ---

int main() {
    int opt;
    string activeUser = "";
    do {
        cout << "\n===================================\n";
        cout << "  DECISION & PROBLEM SOLVER SUITE  \n";
        cout << "===================================\n";
        cout << "1. Login\n";
        cout << "2. Register\n";
        cout << "3. Admin Panel\n";
        cout << "4. Exit App\n";
        cout << "Enter your choice (1-4): ";
        cin >> opt;

        switch (opt) {
            case 1:
                if (loginUser(activeUser)) {
                    userDashboard(activeUser);
                }
                break;
            case 2:
                registerUser();
                break;
            case 3:
                adminPanel();
                break;
            case 4:
                cout << "\nProgram closed successfully.\n";
                break;
            default:
                cout << ">> Invalid choice!\n";
        }
    } while (opt != 4);

    return 0;
}