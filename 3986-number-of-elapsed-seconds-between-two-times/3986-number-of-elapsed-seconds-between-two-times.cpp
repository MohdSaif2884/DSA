 #include <string>
#include <cmath>

using namespace std;

class Solution { 
public: 
    int secondsBetweenTimes(string startTime, string endTime) { 
   
        int start_h = (startTime[0] - '0') * 10 + (startTime[1] - '0');
        int start_m = (startTime[3] - '0') * 10 + (startTime[4] - '0');
        int start_s = (startTime[6] - '0') * 10 + (startTime[7] - '0');
        
         int end_h = (endTime[0] - '0') * 10 + (endTime[1] - '0');
        int end_m = (endTime[3] - '0') * 10 + (endTime[4] - '0');
        int end_s = (endTime[6] - '0') * 10 + (endTime[7] - '0');
        
 
        int start_total_seconds = start_h * 3600 + start_m * 60 + start_s;
        int end_total_seconds = end_h * 3600 + end_m * 60 + end_s;
        
        
        return abs(end_total_seconds - start_total_seconds);
    } 
};
