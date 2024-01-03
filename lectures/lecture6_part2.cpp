#include<iostream>
#include<string>
using namespace std;

enum class TrafficLightState {
    Red, 
    Yellow,
    Green
};

string getTrafficLightStateName(TrafficLightState state) {
    switch (state) {
        case TrafficLightState::Red:
            return "Red";
        case TrafficLightState::Green:
            return "Green";
        case TrafficLightState::Yellow:
            return "Yellow";
        default:
            return "Other";
    }
}


int main() {
    TrafficLightState state = TrafficLightState::Red;
    cout << "Current State is " << getTrafficLightStateName(state) << endl;
    return 0;
}