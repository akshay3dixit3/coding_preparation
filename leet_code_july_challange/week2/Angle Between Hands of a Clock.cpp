class Solution {
public:
    double angleClock(int hour, int minutes) {
	double minutesAngle = (360 / 60) * minutes;
	double hoursAngle = (360 / 12) * (hour % 12);
	hoursAngle += (360 / 12) * (minutes / 60.0); // minutes for adding to hours
	double angle = abs(minutesAngle - hoursAngle);
	return min(angle, 360 - angle);
}
};