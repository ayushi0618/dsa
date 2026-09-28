class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        auto isLeapYear = [](int y) {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        };

        int totalDays = 0;

        // Count days for previous years starting from 1971
        for (int y = 1971; y < year; ++y) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }

        // Count days for previous months in the current year
        for (int m = 1; m < month; ++m) {
            if (m == 2 && isLeapYear(year)) {
                totalDays += 29;
            } else {
                totalDays += daysInMonths[m - 1];
            }
        }

        // Add current days (minus 1 since Jan 1, 1971 is counted as 0 offset)
        totalDays += (day - 1);

        // January 1, 1971 was a Friday (index 5)
        return days[(totalDays + 5) % 7];
    }
};