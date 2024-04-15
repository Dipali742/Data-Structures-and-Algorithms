class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        int cnt = 0;
        while(!que.empty()) {
            int current_node = que.front();
            que.pop();
            cnt++;
            for(auto it : adjList[current_node]) {
                inorder[it] -=1;
                if(inorder[it] == 0)
                    que.push(it);
            }
        }
        if(cnt == numCourses)
            return true;
        return false;
    }
};
