//Given Class Time Table and Teacher assign teacher in ClassMatrix
void assignTeacher() {
	int tchCd;
	for(int dow=0; dow<MAX_DAYS; dow++)
	  for(int pd=0; pd<MAX_PERIODS;pd++)
		for(int classCd=0; classCd<MAX_CLASSES; classCd++) {
		  tchCd = findTeacher(classRoom[classCd].classCd,
			  classRoom[classCd].timeTable[dow][pd].subject);
		  classRoom[classCd].timeTable[dow][pd].teacherCd = tchCd;
		  teacher[tchCd].timeTable[dow][pd]=
			 classRoom[classCd].timeTable[dow][pd];
		  teacher[tchCd].load[dow]++;
		}
}
int exactSubs(TimeTable tt, int dow, int pd) {
	for(int i=0; i<MAX_TEACHERS; i++)
	  if(!teacher[i].isAbsent[dow] &&
		 teacher[i].isMySubject(tt.subject)  &&
		 teacher[i].timeTable[dow][pd].isFreeSlot() &&
		 teacher[i].load[dow]<6)
		 {
			tt.teacherCd = teacher[i].teacherCd;
			tt.subst='*';
			teacher[i].timeTable[dow][pd]=tt;
			teacher[i].load[dow]++;
			return 1;
		 }
	 return 0;
}
void genSubs(TimeTable tt, int dow, int pd) {
	for(int i=0; i<MAX_TEACHERS; i++)
	  if(tt.subst != '*' &&
		 !teacher[i].isAbsent[dow] &&
		 teacher[i].timeTable[dow][pd].isFreeSlot() &&
		 teacher[i].load[dow]<6)
		 {
			tt.teacherCd = teacher[i].teacherCd;
			tt.subst='*';
			teacher[i].timeTable[dow][pd]=tt;
			teacher[i].load[dow]++;
		 }
}
void reassignTeachers(int dow) {
	for(int i=0; i<MAX_TEACHERS; i++)
		if(teacher[i].isAbsent[dow])
		   for(int pd=0; pd<MAX_PERIODS; pd++)
			 if(!teacher[i].timeTable[dow][pd].isFreeSlot())
				if(!exactSubs(teacher[i].timeTable[dow][pd], dow, pd))
				  genSubs(teacher[i].timeTable[dow][pd], dow, pd);
}
