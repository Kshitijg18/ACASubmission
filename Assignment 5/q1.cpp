#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int calculateMaxSimultaneousTrains(vector<int> arrivalTimes, vector<int> departureTimes) {
    int maxTrains = 0;
    int currentTrains = 0;
    int numTrains = arrivalTimes.size();

    sort(arrivalTimes.begin(), arrivalTimes.end());
    sort(departureTimes.begin(), departureTimes.end());

    int arrivalIndex = 0;
    int departureIndex = 0;

    while (arrivalIndex < numTrains && departureIndex < numTrains) {
        if (arrivalTimes[arrivalIndex] <= departureTimes[departureIndex]) {
            currentTrains++;
            arrivalIndex++;
        }
        else {
            currentTrains--;
            departureIndex++;
        }
        maxTrains = max(maxTrains, currentTrains);
    }

    return maxTrains;
}

int main()
{
    int arrivalArray[] = {900, 940, 950, 1100, 1500, 1800};
    int departureArray[] = {910, 1200, 1120, 1130, 1900, 2000};
    vector<int> arrivals(arrivalArray, arrivalArray + sizeof(arrivalArray) / sizeof(arrivalArray[0]));
    vector<int> departures(departureArray, departureArray + sizeof(departureArray) / sizeof(departureArray[0]));
    cout << calculateMaxSimultaneousTrains(arrivals, departures);
    return 0;
}