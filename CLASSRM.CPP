void initClassRooms(){
	ifstream classFile ("c:\\ttbl\\classes.dat");
	for(int i=0; i<MAX_CLASSES; i++) {
		classFile >> classRoom[i].classCd;
		classFile >> classRoom[i].className;
	}
    classFile.close();
}
//Pass Class Code when Class Name is supplied, 99 if none
int findClass(char clName[5] ) {
	for(int i=0; i<MAX_CLASSES; i++)
		if(strcmp(classRoom[i].className, clName)==0) {
			return classRoom[i].classCd;
		}
	return 99;
}

void readClassRooms() {
	char sub[5];
	int tchCd=-1;

	ifstream classFile ("c:\\ttbl\\classrm.dat");

	//Read Time Table from File
	for(int dow=0; dow<MAX_DAYS; dow++)
	  for(int pd=0; pd<MAX_PERIODS;pd++)
		for(int classCd=0; classCd<MAX_CLASSES; classCd++) {
		  classFile >> sub; //timeTable[classCd][dow][pd].subject;
		  //cout << sub << endl;
		  classRoom[classCd].timeTable[dow][pd].initTimeTable(
				  classCd,
				  tchCd,
				  sub,
				  ' '
		  );
		  //teacher[tchCd].timeTable[dow][pd]=classRoom[classCd].timeTable[dow][pd];
		}
	classFile.close();
}
