void readTeachers() {
	int i, j;
	int  ctCnt, clCnt;
	char clName[5], sub[5];

	ifstream teacherFile("c:\\ttbl\\teachers.dat");

	//Read Teachers from File    // For each teacher in file
	for(i=0; i<MAX_TEACHERS; i++) {
	  teacherFile >> teacher[i].teacherCd >>
					 teacher[i].teacherName >>
					 teacher[i].mySubject >>
					 ctCnt >> clCnt;
	  for(j=0; j<ctCnt; j++) { // Class Teacher
		teacherFile >> clName;
		teacher[i].myClass=findClass(clName);
	  }
	  int ctr=0;
	  for(j=0; j<clCnt; j++) {  // Classes taught
		teacherFile >> clName;
		teacher[i].othClass[ctr++]=findClass(clName);
	  }

	  for(int k=0; k<MAX_DAYS; k++) { // Init Matrix
		teacher[i].load[k]=0;
		teacher[i].isAbsent[k] = 0; //Present
		for(int j=0; j<MAX_PERIODS; j++)
		  teacher[i].timeTable[k][j]=freeSlot;
	  }
	}

	teacherFile.close();
}

int findTeacher(int clCd, char sub[5]) {
	for(int i=0; i<MAX_TEACHERS;i++) {
		if(strcmp(sub, "EXAM")==0 && (teacher[i].myClass==clCd))
			return teacher[i].teacherCd;
		else
		  if(strcmp(sub, teacher[i].mySubject)==0 &&
			 (teacher[i].othClass[0]==clCd ||
			  teacher[i].othClass[1]==clCd ||
			  teacher[i].othClass[2]==clCd))
			  return teacher[i].teacherCd;
	}
	return -1;
}

