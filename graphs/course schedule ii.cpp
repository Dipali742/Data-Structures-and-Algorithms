class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjList(numCourses);
        vector<int>inorder(numCourses, 0);
        for(int i = 0; i<prerequisites.size();i++) {
            adjList[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inorder[prerequisites[i][1]]++;
        }

        queue<int>que;
        for(int i = 0; i<inorder.size();i++) {
            if(inorder[i] == 0)
                que.push(i);
        }

        vector<int>courses;
        while(!que.empty()) {
            int current_node = que.front();
            que.pop();
            courses.push_back(current_node);
            for(auto it : adjList[current_node]) {
                inorder[it] -=1;
                if(inorder[it] == 0)
                    que.push(it);
            }
        }
        reverse(courses.begin(), courses.end());
        if(courses.size() == numCourses)
            return courses;
        return {};
    }
};
