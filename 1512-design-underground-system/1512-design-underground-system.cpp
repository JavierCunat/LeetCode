#include <utility> 

class UndergroundSystem {
private:
        unordered_map<int, std::pair<string, int>> checkIns;
        unordered_map<string, std::pair<double, int>> travelTimes;
public:

    void checkIn(int id, string stationName, int t) {
        checkIns[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
       std::pair curr = checkIns[id];
       string route = curr.first + "->" + stationName;
       travelTimes[route].first += t - curr.second;
       travelTimes[route].second += 1;
       checkIns.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        std::pair route = travelTimes[startStation + "->" + endStation];
        return route.first / route.second;
    }

};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */