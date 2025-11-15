#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
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


TEST_CASE("Test can create and render Times") {
    Time t1;
    CHECK(t1.to_string() == "0:00:00");
    Time t2(7);
    CHECK(t2.to_string() == "0:00:07");
    Time t3(72);
    CHECK(t3.to_string() == "0:01:12");
    Time t4(7 * 3600 + 11 * 60 + 19);
    CHECK(t4.to_string() == "7:11:19");
}
TEST_CASE("Test hour-minute and hour-minute-second constructors") {
    Time t1(5, 37);
    CHECK(t1.to_string() == "5:37:00");
    Time t2(7, 2, 11);
    CHECK(t2.to_string() == "7:02:11");
}
TEST_CASE("Test can add two Times with + operator") {
    Time t1(25, 40);
    Time t2(17, 2, 42);
    Time t3 = t1 + t2;
    CHECK(t3.to_string() == "42:42:42");
}
