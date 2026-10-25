#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Convert a "MM-DD" date string to the day of the year (1 to 365)
        auto convertToDays = [](const std::string& date) {
            std::vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int month = std::stoi(date.substr(0, 2));
            int day = std::stoi(date.substr(3, 2));
            int totalDays = day;
            for (int i = 0; i < month - 1; ++i) {
                totalDays += daysInMonths[i];
            }
            return totalDays;
        };

        int aliceArrival = convertToDays(arriveAlice);
        int aliceLeave = convertToDays(leaveAlice);
        int bobArrival = convertToDays(arriveBob);
        int bobLeave = convertToDays(leaveBob);

        // Find the latest arrival and earliest leave date
        int startOverlap = std::max(aliceArrival, bobArrival);
        int endOverlap = std::min(aliceLeave, bobLeave);

        // Calculate overlapping days
        if (startOverlap <= endOverlap) {
            return endOverlap - startOverlap + 1;
        }
        
        return 0;
    }
};