class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) 
    {
        vector<int> s; // use vector to simulate stack.
        for (int i : a) 
        {
            while (!s.empty() && s.back() > 0 && s.back() < -i)// this is cheking if the asteroid at the top is kamzor then negative velocity waala
                s.pop_back();
            if (s.empty() || i > 0 || s.back() < 0)// yadi top waala hi less than zero h toh collision ka koi chance nai h simply push it in the stack
                s.push_back(i);
            else if (i < 0 && s.back() == -i)// yadi equal waala case usko alag se deal kiya jaa raha h yahan pe
                s.pop_back();
        }
        return s;
    }
};
