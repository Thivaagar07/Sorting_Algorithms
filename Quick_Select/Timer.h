#ifndef TIMER_H
#define TIMER_H
/* timer.h: This file implements a high performance timer for measuring the
performance
* of your code. Currently it works only on the windows platform.
* Reference: http://www.geisswerks.com/ryan/FAQS/timing.html
*
* This file defines a set of preprocessor macros for measuring the time:
*
* TICK() - Start the timer
* TOCK() - Stop the timer
* TICK_ELAPSED() - Return number of clock ticks elapsed between TICK()
and TOCK()
* DURATION() - Return duration between TICK() and TOCK() in
seconds (double precision).
* SHOW_DURATION() - Macro to show the duration using cout.
* MEASURE(THIS) - Measure codes in THIS and show the duration
* MSHOW_DURATION(MESSAGE) - Same like SHOW_DURATION(), but show the duration
with MESSAGE
* MMEASURE(MESSAGE, THIS) - Same like MEASURE(THIS), but show the duration with
MESSAGE
*
* Reference: http://www.geisswerks.com/ryan/FAQS/timing.html
*/
/* Sample usage:
#include <iostream>
using namespace std;
#include "timer.h"
int main() {
TICK();
_sleep(2500);
TOCK();
double duration1 = DURATION();
TICK();
Sleep(2500);
TOCK();
double duration2 = DURATION();cout << "Duration 1 _sleep(2500) = " << duration1 << "s" << endl;
cout << "Duration 2 Sleep(2500) = " << duration2 << "s" << endl;
}
*/
#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;
LARGE_INTEGER _timer_start;
LARGE_INTEGER _timer_stop;
LARGE_INTEGER _timer_frequency;
bool _timer_init = QueryPerformanceFrequency(&_timer_frequency);
#define TICK() if( _timer_init == false ) { \
cout << "Failed to query the performance frequency." << endl; \
cout << "Please do not use timer.h" << endl; \
exit(1); \
} \
QueryPerformanceCounter(&_timer_start);
#define TOCK() QueryPerformanceCounter(&_timer_stop);
// How many counter count elapsed between TICK() and TOCK()
#define TICK_ELAPSED() (_timer_stop.QuadPart - _timer_start.QuadPart)
// Duration in seconds
#define DURATION() ( TICK_ELAPSED() / (double) _timer_frequency.QuadPart)
// A few more macro for quick and dirty measurements
#define SHOW_DURATION() cout << "Duration: " \
<< setprecision(20) << DURATION() << "s" << endl;
#define MEASURE(THIS) TICK(); THIS ; TOCK(); SHOW_DURATION();
// A few more macro for quick and dirty measurements, with message
#define MSHOW_DURATION(MESSAGE) cout << MESSAGE << endl \
<< " Duration: " << setprecision(20) \
<< DURATION() << "s" << endl;
#define MMEASURE(MESSAGE, THIS) TICK(); THIS ; TOCK(); MSHOW_DURATION(MESSAGE);
#endif
//------------------------------------------------------------------------------------------------------------------

