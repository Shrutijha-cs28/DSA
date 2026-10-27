
#include <vector>
#include <stack>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {
            bool alive = true;

            // Collision occurs only when the previous asteroid
            // moves right and the current asteroid moves left.
            while (alive && asteroid < 0 &&
                   !st.empty() && st.top() > 0) {

                // Previous asteroid is smaller: it explodes
                if (st.top() < abs(asteroid)) {
                    st.pop();
                }
                // Both asteroids have the same size
                else if (st.top() == abs(asteroid)) {
                    st.pop();
                    alive = false;
                }
                // Previous asteroid is larger
                else {
                    alive = false;
                }
            }

            // Add the asteroid if it survived all collisions
            if (alive) {
                st.push(asteroid);
            }
        }

        // Convert stack into the answer in original order
        vector<int> ans(st.size());

        for (int i = (int)st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
