#include <iostream>
#include <string>
using namespace std;

struct Time {
    int hour, minute;
    int second;

    Time(int secs = 0);
    Time(int hrs, int mins, int secs=0);

    string to_string() const;
    Time operator+(const Time&);


};

Time::Time(int hrs, int mins, int secs)
{
    hour = hrs;
    minute = mins;
    second = secs;

}
Time::Time(int secs)
{
    hour = int(secs / 3600.0);
    secs -= hour * 3600.0;
    minute = int(secs / 60.0);
    secs -= minute * 60;
    second = secs;
}

string Time::to_string() const
{
    string timestring;
    if (minute < 10 && second < 10){
        timestring = std::to_string(hour)+":"+"0"+std::to_string(minute)+":"+"0"+std::to_string(second);}
    else if (minute > 10 && second > 10){
        timestring = std::to_string(hour)+":"+std::to_string(minute)+":"+std::to_string(second);}
    else if (minute < 10 && second > 10){
        timestring = std::to_string(hour)+":"+"0"+std::to_string(minute)+":"+std::to_string(second);}
    else if (minute > 10 && second < 10){
        timestring = std::to_string(hour)+":"+std::to_string(minute)+":"+"0"+std::to_string(second);}
    return(timestring);
}
// the member being called to_string is problematic because it is a built-in
// function, requiring std to be called in the above function.

Time Time::operator+(const Time& othertime) {
    return Time(hour + othertime.hour, minute + othertime.minute, second + othertime.second);

}

ostream& operator<<(ostream& out, Time time) {
    out << time.to_string();
    return out;
} 

int main() {
    int a = 5;
    Time t(3600 * 4 + 60 * 11 + 22);
    cout << "Time t is: " << t << endl;
    // should print 4:11:22

    return 0;
}

