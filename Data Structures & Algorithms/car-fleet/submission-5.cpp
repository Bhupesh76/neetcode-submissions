class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int,double>> cars;
        for(int i=0; i<position.size(); i++)
        {
            double time = (double)(target-position[i])/speed[i];
            cars.push_back({position[i],time});
        }

        double maxtime = 0;
        int fleet = 0;

        sort(cars.rbegin(),cars.rend());

        for(auto car : cars)
        {
            double time = car.second;
            if(time > maxtime)
            {
                fleet++;
                maxtime = time;
            }
        }
        return fleet;
    }
};
