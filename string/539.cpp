#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    //!time limit exceeded
    int findMinDifference1(vector<string> &timePoints) {
        int min = 12 * 60;
        for (int i = 0; i < timePoints.size(); i++) {
            for (int j = i + 1; j < timePoints.size(); j++) {
                if (timePoints[i] == timePoints[j]) {
                    return 0;
                }
                int x1 = posTime(timePoints[i]);
                int y1 = negTime(timePoints[i]);
                int x2 = posTime(timePoints[j]);
                int y2 = negTime(timePoints[j]);
                int temp = minTime(x1, y1, x2, y2);
                if (temp < min) {
                    min = temp;
                }
            }
        }
        return min;
    }

private:
    int posTime(string &time) {
        regex time_reg("(\\d+):(\\d+)");
        smatch match_result;
        regex_match(time, match_result, time_reg);
        return stoi(match_result[1]) * 60 + stoi(match_result[2]);
    }
    int negTime(const string &time) {
        regex time_reg("(\\d+):(\\d+)");
        smatch match_result;
        regex_match(time, match_result, time_reg);
        return stoi(match_result[1]) * 60 + stoi(match_result[2]) - 24 * 60;
    }
    int minTime(int x1, int y1, int x2, int y2) {
        int temp1 = abs(x1 - x2);
        int temp2 = abs(y1 - y2);
        int temp3 = abs(x1 - y2);
        int temp4 = abs(y1 - x2);
        temp3 = temp3 > 24 * 60 ? 48 * 60 - temp3 : temp3;
        temp4 = temp4 > 24 * 60 ? 48 * 60 - temp4 : temp4;
        return min({temp1, temp2, temp3, temp4});
    }

public:
    int findMinDifference(vector<string> &timePoints) {
        bool time_seen[24 * 60] = {false};
        for (auto &time : timePoints) {
            int minutes = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
            if (time_seen[minutes]) {
                return 0;
            }
            time_seen[minutes] = true;
        }
        int i = 0;
        int first = 0;
        int last = 0;
        for (i = 0; i < 24 * 60; i++) {
            if (time_seen[i]) {
                first = i;
                last = i;
                break;
            }
        }
        int ret = 24 * 60;
        for (i++; i < 24 * 60; i++) {
            if (time_seen[i]) {
                ret = min(ret, i - last);
                last = i;
            }
        }
        return min(ret, first + 24 * 60 - last);
    }
};

int main() {
    Solution sol;
    vector<string> timePoints = {"00:00", "23:59", "00:00"};
    cout << sol.findMinDifference(timePoints) << endl;
    timePoints = {"23:47", "11:00"};
    cout << sol.findMinDifference(timePoints) << endl;
    timePoints = {"23:59", "00:00"};
    cout << sol.findMinDifference(timePoints) << endl;

    timePoints = {"00:17", "12:20", "17:42", "18:11", "00:53", "05:58", "22:43", "11:37", "21:47", "17:59", "08:47", "19:20", "23:37", "03:23", "09:51", "13:59", "13:36", "22:38", "17:17", "05:51", "12:31", "19:17", "08:35", "18:00", "06:45", "02:31", "07:02", "03:42", "01:06", "18:48", "10:48", "09:50", "17:35", "21:10", "06:40", "14:31", "23:05", "19:28", "08:39", "13:40", "04:17", "12:36", "17:39", "00:20", "13:42", "02:37", "10:58", "15:38", "01:56", "06:11"};
    cout << sol.findMinDifference(timePoints) << endl;

    return 0;
}