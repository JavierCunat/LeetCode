class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //use a stack to grab from front and be able to tell if the next one in the array will collide with the previous one
        stack<int> stack;
        for(int asteroid : asteroids) {
            bool destroyed = false;
            

            while(!stack.empty() && (stack.top() > 0 && asteroid < 0) ) {
                int top = stack.top();
                if(abs(top) > abs(asteroid)) {
                    //top asteroid survives so we don't pop
                    destroyed = true;
                    break;
                } else if(abs(top) == abs(asteroid)) {
                    stack.pop();
                    destroyed = true;
                    break;
                }
                else {
                    //top asteroid is destroyed so we pop
                    stack.pop();
                }
            }

            if(!destroyed) {
                stack.push(asteroid);
            }

        }

        int size = stack.size();
        vector<int> res(size);

        for(int i = size-1; i >= 0; i--) {
            res[i] = stack.top();
            stack.pop();
        }

        return res;
    }
};