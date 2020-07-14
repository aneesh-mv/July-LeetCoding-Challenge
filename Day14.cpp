/*
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.
Example 1:
Input: hour = 12, minutes = 30
Output: 165
*/
class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_angle = (hour % 12 ) * 30 + minutes * 0.5;
        double minute_angle = minutes * 6;
        double diff = abs(hour_angle - minute_angle);
        return min(diff, 360 - diff);
    }
};
