#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>

#include <iomanip.h>
#include <conio.h>

#define MAX_CLASSES 6
#define MAX_DAYS 5
#define MAX_PERIODS 8
#define MAX_TEACHERS 10

char today[5][5] = { "Mon", "Tue", "Wed", "Thu", "Fri"};

class TimeTable {
	public:
	char subject[5], subst;
	int classCd, teacherCd;
	void initTimeTable(int clCd, int tchCd, char* sub, char substChr)
	{
		classCd=clCd;
		teacherCd=tchCd;
		strcpy(subject, sub);
		subst = substChr;
	}
	int isFreeSlot() {
	  if (classCd==99) // class code 99 indicates free period for tch
		return 1;
	  else
	    return 0;
	}
};

class Teacher {
	public:
	int teacherCd;
	char teacherName[10];
	int isAbsent[MAX_DAYS], load[MAX_DAYS], myClass, othClass[3];
	char mySubject[5];
	TimeTable timeTable[MAX_DAYS][MAX_PERIODS];

	void markAbsent(int dow) { isAbsent[dow] = 1; }
	int isMySubject(char* sub) {
		if(strcmp(mySubject, sub) == 0)
		  return 1;
		else
		  return 0;
    }
} teacher[MAX_TEACHERS];

class ClassRoom {
	public:
	int classCd;
	char className[5];
	TimeTable timeTable[MAX_DAYS][MAX_PERIODS];
} classRoom[MAX_CLASSES];

TimeTable freeSlot, absentSlot;

