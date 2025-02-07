#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int current_month = 0;
vector<vector<string>> tasks(days_in_month[current_month]);


void ADD(int day, const string& task) 
{
    tasks[day - 1].push_back(task);
}

void DUMP(int day) 
{
    int tasks_count =  tasks[day-1].size();
    cout << tasks_count;
    for (const string& task : tasks[day - 1])
    {
        cout << " " << task;
    }
    cout << endl;
}

void NEXT() {
    int next_month_days = days_in_month[(current_month + 1) % 12];
    if (next_month_days < tasks.size()) 
    {
        for (int i = next_month_days; i < tasks.size(); i++) 
        {
            tasks[next_month_days - 1].insert(end(tasks[next_month_days - 1]), begin(tasks[i]), end(tasks[i]));
        }
    }
    tasks.resize(next_month_days);
    current_month = (current_month + 1) % 12;
}

int main() 
{
    int q;
    cin >> q;

    string command;
    for (int i = 0; i < q; i++) 
    {
        cin >> command;
        if (command == "ADD") 
        {
            int day;
            string task;
            cin >> day >> task;
            ADD(day, task);
        }
        else if (command == "DUMP") 
        {
            int day;
            cin >> day;
            DUMP(day);
        }
        else if (command == "NEXT") 
        {
            NEXT();
        }
    }
    return 0;
}
