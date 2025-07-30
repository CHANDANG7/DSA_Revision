You''re given numCourses labeled from 0 to numCourses - 1.

Some courses have prerequisites: prerequisites[i] = [a, b] means to take course a, you must first take course b.

You must determine if it is possible to finish all courses.



class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto& pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adj[prereq].push_back(course);  // b -> a
            indegree[course]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }

        int count = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for(int neighbor : adj[node]) {
                indegree[neighbor]--;
                if(indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        return count == numCourses;
    }
};
