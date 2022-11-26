#include "duration.h"

#include <assert.h>

// Constructor with no parameters, no alarm and time is 0
Duration::Duration() {
    time = 0;
    alarmHasBeenSet = false;
}
// Constructor with parameter, still no alarm and time is user defined
Duration::Duration(int t) {
    assert(t >= 0);
    time = t;
    alarmHasBeenSet = false;
}

// Returns the current time
int Duration::getDuration() { return time; }

// Ticking the clock, incrementing the time by 1. returning the check function
// To make sure we havent gone over the alarm
bool Duration::tick() {
    time++;
    return checkAndUpdateAlarm();
}

// Tick function with parameter, otherwise the same as tick w/ no parameter
bool Duration::tick(int dt) {
    assert(dt >= 0);
    time += dt;
    return checkAndUpdateAlarm();
}

// Setting the alarm value to the user defined input, and setting the alarm true
void Duration::setAlarm(int t) {
    if (t > time) {
        alarm = t;
        alarmHasBeenSet = true;
    }
}

// If the alarm is set and our time is larger than the alarm value, the function
// Resets the alarm and returns the true as the alarm "rings"
bool Duration::checkAndUpdateAlarm() {
    if (alarmHasBeenSet == true && time > alarm) {
        alarmHasBeenSet = false;
        return true;
    } else {
        return false;
    }
}

Duration::~Duration() {}