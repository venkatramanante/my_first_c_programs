#include <stdio.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
    #define sleep_ms(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define sleep_ms(ms) usleep((ms) * 1000)
#endif

int main() {
 
    printf("\033[?25l");

    while (1) {
        time_t raw_time = time(NULL);

        raw_time += (5 * 3600) + (30 * 60);

        struct tm *ist = gmtime(&raw_time);

        printf("\r[IST] %02d:%02d:%02d  (Date: %02d-%02d-%04d)",
               ist->tm_hour,
               ist->tm_min,
               ist->tm_sec,
               ist->tm_mday,
               ist->tm_mon + 1,
               ist->tm_year + 1900);

        fflush(stdout);
        sleep_ms(1000);
    }

    
    return 0;
}