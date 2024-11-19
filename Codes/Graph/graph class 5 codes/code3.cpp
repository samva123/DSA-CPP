// class Solution {
// public:

//     bool isSafe(int newX, int newY, int row, int col,vector<vector<int> >& diff, int currX, int currY ) {
//         if(newX >=0 && newY >=0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]) {
//             return true;
//         }
//         else {
//             return false;
//         }
//     }

//     int minimumEffortPath(vector<vector<int>>& heights) {
//         priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > mini;
//         int row = heights.size();
//         int col = heights[0].size();
//         vector<vector<int> > diff(row, vector<int>(col, INT_MAX));
//         int destX = row-1;
//         int destY = col-1;
//         //initial state
//         //set srcn ka distance 0
//         diff[0][0] = 0;
//         //min heap meentry for src push krdo
//         mini.push({0,{0,0}});

//         while(!mini.empty()) {
//             auto topPair = mini.top();
//             mini.pop();
//             int currDiff = topPair.first;
//             pair<int,int>  currNodeIndexPair = topPair.second;
//             int currX = currNodeIndexPair.first;
//             int currY = currNodeIndexPair.second;
//             //cout << "CurrDiff: " << currDiff << " currX " << currX <<" currY " << currY << endl;
            
//             //now we can travel to all nbr i.e. top, down, left, right
//             int dx[] = {-1,0,1,0};
//             int dy[] = {0,1,0,-1};
//             for(int i=0; i<4; i++) {
//                 //cout << "Inside for loop for currX " << currX << " currY " << currY  << endl;
//                 int newX = currX + dx[i];
//                 int newY = currY + dy[i];
//                 if(isSafe(newX, newY,row,col,diff,currX, currY)) {
//                     //cout << "Inside safe if condition with currX " << currX << " currY " << currY << endl;
//                     //cout << " newX " << newX << " newY " << newY << endl; 
//                     int maxDiff = max(currDiff, abs(heights[currX][currY]-heights[newX][newY]));
//                     //check can we update diff array
//                     diff[newX][newY] = min(diff[newX][newY], maxDiff);
//                     //cout << "diff updated " << diff[newX][newY] << endl;
//                     //entry create karo min Heap me
//                     if(newX != destX || newY != destY) {
//                         mini.push({diff[newX][newY], {newX, newY}});
//                         //cout << "new entry added " << endl;
//                     }
//                 }
//             }

//         }
//         return diff[destX][destY];
//     }
// };


class Solution {
public:

    bool isSafe(int newX, int newY, int row, int col) {
        if(newX >=0 && newY >=0 && newX < row && newY < col ) {
            return true;
        }
        else {
            return false;
        }
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int, pair<int,int> > , vector<pair<int,pair<int,int> > >, greater<pair<int,pair<int,int> > > > mini;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int> > diff(row, vector<int>(col, INT_MAX));
        int destX = row-1;
        int destY = col-1;
        //initial state
        //set srcn ka distance 0
        diff[0][0] = 0;
        //min heap meentry for src push krdo
        mini.push({0,{0,0}});

        while(!mini.empty()) {
            auto topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int,int>  currNodeIndexPair = topPair.second;
            int currX = currNodeIndexPair.first;
            int currY = currNodeIndexPair.second;
            //cout << "CurrDiff: " << currDiff << " currX " << currX <<" currY " << currY << endl;
            
            //now we can travel to all nbr i.e. top, down, left, right
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0; i<4; i++) {
                //cout << "Inside for loop for currX " << currX << " currY " << currY  << endl;
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if(isSafe(newX, newY,row,col)) {
                    //cout << "Inside safe if condition with currX " << currX << " currY " << currY << endl;
                    //cout << " newX " << newX << " newY " << newY << endl; 
                    int maxDiff = max(currDiff, abs(heights[currX][currY]-heights[newX][newY]));
                    //check can we update diff array
                    //diff[newX][newY] = min(diff[newX][newY], maxDiff);
                    //cout << "diff updated " << diff[newX][newY] << endl;
                    //entry create karo min Heap me
                    if(maxDiff < diff[newX][newY]) {
                        diff[newX][newY] = maxDiff;
                        mini.push({diff[newX][newY], {newX, newY}});
                        //cout << "new entry added " << endl;
                    }
                }
            }

        }
        return diff[destX][destY];
    }
};




// Summary


// Time Complexity
// The time complexity of the given code is (O((V + E) \log V)), where (V) is the number of vertices (nodes) and (E) is the number of edges in the graph. This is because:

// Initialization: Initializing the diff array takes (O(V)) time.
// Priority Queue Operations: Each insertion and deletion operation in the priority queue takes (O(\log V)) time.
// Processing Each Node: Each node is processed exactly once, and each edge is considered exactly once during the traversal, which takes (O(V + E)) time.
// Therefore, the overall time complexity is: [ O((V + E) \log V) ]

// Space Complexity
// The space complexity of the given code is (O(V + E)), where (V) is the number of vertices and (E) is the number of edges. This is because:

// Adjacency List: The adjacency list adj takes (O(E)) space.
// Diff Array: The diff array takes (O(V)) space.
// Priority Queue: The priority queue can hold up to (O(V)) nodes in the worst case.
// Therefore, the overall space complexity is: [ O(V + E) ]


// Time Complexity: (O((V + E) \log V))
// Space Complexity: (O(V + E))
// Explanation
// Time Complexity:

// Initialization: Initializing the diff array takes (O(V)) time.
// Node Processing: Each node is processed exactly once, leading to (O(V)) time.
// Edge Processing: Each edge is processed exactly once, leading to (O(E)) time.
// Priority Queue Operations: Each insertion and deletion operation in the priority queue takes (O(\log V)) time.
// Space Complexity:

// Adjacency List: Stores all edges, taking (O(E)) space.
// Diff Array: Stores the minimum difference for each node, taking (O(V)) space.
// Priority Queue: Can hold up to (O(V)) nodes in the worst case.