void drawLine(char c, int sz) {
	for(int i=0; i<sz; i++)
		cout << c;
}
void displayClassTable(int dow) {
	int i;
	drawLine(205, 79);
	cout << endl << "\t";
	for(i=0; i<MAX_PERIODS; i++)
		cout << "\t"<< i+1;
	cout << endl;
	drawLine(205, 79);

	for(i=0; i<MAX_CLASSES; i++) {
		cout << setw(10) << endl << classRoom[i].className;
		for(int pd=0; pd<MAX_PERIODS;pd++)
			cout << "\t" << classRoom[i].timeTable[dow][pd].subject;
	}
	cout << endl;
	drawLine(205, 79);
}
void displayTeacherTable(int dow) {
	int i;
	drawLine(205, 79);
	cout << endl << "\t";

	for(i=0; i<MAX_PERIODS; i++)
		cout << "\t"<< i+1;
	cout << endl;
	drawLine(205, 79);

	for(i=0; i<MAX_TEACHERS; i++) {
		cout << endl << teacher[i].teacherCd << ": " <<
				teacher[i].teacherName;
		for(int pd=0; pd<MAX_PERIODS;pd++)
		  if(teacher[i].isAbsent[dow])
			cout << "\t" << "ABSENT";
		  else if(teacher[i].timeTable[dow][pd].classCd<MAX_CLASSES)
				cout << "\t" <<
				 classRoom[teacher[i].timeTable[dow][pd].classCd].className <<
				 teacher[i].timeTable[dow][pd].subst;
		  else
			cout << "\t" << "" ; //"Free";
	}
	cout << endl;
	drawLine(205, 79);
}

