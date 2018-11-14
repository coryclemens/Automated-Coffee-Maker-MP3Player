#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>     
#include <unistd.h>
#include <wiringPi.h>
#include <string.h>

int monday();
int tuesday();
int wednesday();
int thursday();
int friday();
int coffeeOn();
int alarmClock();
#define COFFEE 21  //defines the wiringPi pin 21 to coffee


int alarmClock()  //plays an mp3 using system()
{
char playmusic[50];  //used to load command line command into system()

printf("Song:Disciples----Artist:Tame Impala\n\n\n");
printf("Press 'q' to SNOOZE\n\n\n");
strcpy(playmusic, "omxplayer /home/pi/Music/disciples.mp3"); //loads text into string
system(playmusic);  //grabs and plays mp3 from command line
printf("\n\n\n");

return 0;  //returns to main
}


int monday()  //code is same for wednesday() and friday()
{
   int clockMin, clockHour, clockSec; //clock values
   struct tm *local;   //struct to grab elements
   time_t t;

    printf("It is Monday\n\n\n");
    printf("Coffee maker will power on at 8:00:00 AM\n\n\n");
    printf("Current Time of Day:\n\n");
    for(;;)
{                       //infinite loop starts clock
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if(clockHour==8)                    //when time is 8, will break
        break;
        
}
sleep(5);       //small delay
coffeeOn(NULL); //executes to turn coffee maker on
    
    return 0;

}

int tuesday() //does the same as MonWedFri functions, but an hour earlier at 7, same for thurs
{
    int clockMin, clockHour, clockSec;
   struct tm *local;
   time_t t;
   
    printf("It is Tuesday\n\n\n");
    printf("Coffee maker will power on at 7:00:00 AM\n\n\n");
    printf("Current Time of Day:\n\n");
    for(;;)
{
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if(clockHour==7)           //stops clock at 7
        break;           
}
sleep(5);
coffeeOn(NULL);


    return 0;
}

int wednesday()
{
   int clockMin, clockHour, clockSec;
   struct tm *local;
   time_t t;
   

    printf("It is Wednesday\n\n\n");
    printf("Coffee maker will power on at 8:00:00 AM\n\n\n");
    printf("Current Time of Day:\n\n");
    for(;;)
{
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if(clockHour==8)
        break;
}
sleep(5);
coffeeOn(NULL);

    return 0;
}

int thursday()
{
   int clockMin, clockHour, clockSec;
   struct tm *local;
   time_t t;
   
   
    printf("It is Thursday\n\n\n\n");
    printf("Coffee maker will power on at 7:00:00 AM\n\n\n");
    printf("Current Time of Day:\n\n");
    for(;;)
{
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if(clockHour==7)
        break;
}
sleep(5);
coffeeOn(NULL);
    return 0;
}

int friday()
{
    int clockMin, clockHour, clockSec;
   struct tm *local;
   time_t t;

    printf("It is Friday!\n");
    printf("Coffee maker will power on at 8:00:00 AM\n");
    printf("Current Time of Day:\n");
    for(;;)
{
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if(clockHour==8)
        break;
}
sleep(5);
coffeeOn(NULL);

    return 0;
}

int coffeeOn()  //turns coffee on, used in all day functions
{
	int clockMin, clockHour, clockSec;
   struct tm *local;
   time_t t;
   
 
	wiringPiSetup();       //from wiringPi.h, initializes GPIO pins
	pinMode(COFFEE, OUTPUT);  //COFFEE defined as wiringPi 21, makes GPIO 29 output
	digitalWrite(COFFEE, HIGH);  //sends output into pin, turning coffee maker on
	printf("\n\n\nThe pot is now hot\n");
	printf("\n\nThe Coffee Maker will power off in 30 minutes.\n");

	    for(;;) //infinite loop creates a clock which will turn the coffee maker off 
{
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if(clockMin==30) //when 30 mins have passed, break loop
		break;
}
digitalWrite(COFFEE, LOW);   //turns coffee maker off 
printf("\nThe Coffee maker has powered off\n\n");
return 0;  //returns to main
}


int main(void)
{
   int clockMin, clockHour, clockSec;  //stores clock vals from struct
   struct tm *local;      //struct tm *local, stores system time elements
   time_t t;            //type time_t stores 
   int weekDayNum;          //stores day of week #


for(;;){
	
    printf("Hello Cory!\n\n\n");
    
    t=time(NULL);  //gets systems time elements into t
    local = localtime(&t);  //loads t into struct tm *local
    weekDayNum=local->tm_wday; //access element of struct
    
    if((weekDayNum==1)||(weekDayNum==3)||(weekDayNum==5)){ //if mon wed fri, alarm at 730
		printf("Alarm sounding at 7:30 AM\n\n\n");
		for(;;)
{
	t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;  //accesses 3 elements of struct for clock

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b"); //prints a clock until 730
    if((clockHour==7)&&(clockMin==30))
        break;                  //breaks from for, exectues alarmClock()
        
}
alarmClock();

}

else{
	printf("Alarm sounding at 6:30 AM\n\n\n"); //same as above, except 630 on tues thurs
		for(;;)
{
    t=time(NULL);
    local = localtime(&t);
    clockHour=local->tm_hour;
    clockMin=local->tm_min;
    clockSec=local->tm_sec;

    fprintf(stdout, "%2d:%2d:%2d", clockHour, clockMin, clockSec);
    fflush(stdout);
    sleep(1);
    fprintf(stdout, "\b\b\b\b\b\b\b\b");
    if((clockHour==6)&&(clockMin==30)) //clock runs until 630, breaks
        break;
        
}
alarmClock(); //executes after break

}
	

printf("Week Day Number: %d\n\n\n", local->tm_wday); //after alarmclock
weekDayNum=local->tm_wday;  //accesses day #

   
   
   switch(weekDayNum){   //depending on which day 1-5, executes a case and executes a day function
        case 1:
            monday(NULL);
            break;
        case 2:
            tuesday(NULL);
            break;
        case 3:
            wednesday(NULL);
            break;
        case 4:
            thursday(NULL);
            break;
        case 5:
            friday(NULL);
            break;

}
printf("\n\nProgram restarting.....\n\n");  //reches this point after coffeeOn()
sleep(10); //added come delay
}


//loop above wil restart and make program start again

return 0;
}

