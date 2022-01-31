#include <c:\ttbl\datastr.cpp>
#include <c:\ttbl\classrm.cpp>
#include <c:\ttbl\teachers.cpp>
#include <c:\ttbl\assign.cpp>
#include <c:\ttbl\display.cpp>

int main()
{
	clrscr();

	freeSlot.initTimeTable(99,-1,"Free",' ');
	absentSlot.initTimeTable(99,-1,"Absent",' ');
	initClassRooms();

	readTeachers();
	readClassRooms();
	assignTeacher();

	int dow;
	cout << "Day Code List:" << endl;
	for(int i=0;i<MAX_DAYS;i++)
		cout << i << ": " << today[i] << endl;

	cout << "Enter Day Code from above for which Time Table is needed: ";
	cin >> dow;
	clrscr();

	cout << "\t\t\tClass Time Table for " << today[dow] << endl;
	displayClassTable(dow);

	cout << "\n\n\n\n\t\t\tTeacher Time Table for " << today[dow] << endl;
	displayTeacherTable(dow);

	cout << "\n\nEnter Absent Teacher's Codes, -1 to end: ";
	int tchCd;
	cin >> tchCd;
	while (tchCd >=0) {
	  teacher[tchCd].markAbsent(dow);
	  cin >> tchCd;
	};



	cout << "\n\t\t\tRevised Teacher Time Table for " << today[dow] << endl;
	reassignTeachers(dow);
	displayTeacherTable(dow);
    cout << endl << "Press any key to end . . .";

	getch();
	return 0;
}

