class Solution {
    class Car{
        public:
            int pos;
            int speed ;
            Car(int p ,  int s ):pos(p) , speed(s) {};
    };

    static bool mycmp(Car&a , Car&b){
        return a.pos < b.pos;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car>cars;
        for(int i =0 ; i < position.size() ;++i){
            Car car(position[i] , speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin() , cars.end() ,mycmp);

        stack<float>st;
        for(auto car:cars){
            float time = (target - car.pos)/((float)car.speed);
            while(!st.empty() && time >= st.top()){
                st.pop();

            }
            st.push(time);
        }
        return st.size();


        
    }
};






class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars;
        for (int i = 0; i < position.size(); ++i) {
            float time = (float)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end(), [](const pair<int, float>& a, const pair<int, float>& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        float currentFleetTime = 0;
        for (const auto& car : cars) {
            if (car.second > currentFleetTime) {
                currentFleetTime = car.second;
                fleets++;
            }
        }
        return fleets;
    }
};


// GitHub Copilot
// Time Complexity
// The time complexity of the carFleet function is O(n log n), where n is the number of cars. This is because the function sorts the cars based on their positions, which takes O(n log n) time. The subsequent operations (calculating times and processing the stack) take O(n) time.

// Space Complexity
// The space complexity of the carFleet function is O(n), where n is the number of cars. This is because the function uses a vector to store the cars and a stack to store the times.

// Optimization
// The current implementation is already efficient with O(n log n) time complexity and O(n) space complexity. However, we can make the code more readable by avoiding the custom Car class and directly working with pairs of positions and speeds.

// Here is the optimized version:

// Explanation
// Create a vector of pairs to store the position and time to reach the target for each car.
// Sort the cars based on their positions in descending order.
// Traverse the sorted cars:
// If the current car's time is greater than the current fleet time, it forms a new fleet.
// Update the current fleet time to the current car's time.
// Return the number of fleets.
// This approach maintains the time complexity of O(n log n) and space complexity of O(n), but it simplifies the code by avoiding the custom Car class and directly working with pairs of positions and times.



