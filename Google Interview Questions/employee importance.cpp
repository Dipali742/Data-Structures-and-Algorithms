/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>adjList;
        for(int i =0 ;i<employees.size();i++) {
            adjList.insert({employees[i]->id, employees[i]});
        }
        queue<int>que;
        que.push(id);
        int total_importance = 0;
        while(!que.empty()) {
            int current_id = que.front();
            vector<int> current_subordinates = adjList[current_id]->subordinates;
            que.pop();
            total_importance += adjList[current_id]->importance;
            for(auto adjId : current_subordinates) {
                que.push(adjId);
            }
        }
        return total_importance;
    }
};
