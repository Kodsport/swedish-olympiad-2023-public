#include <stdio.h>

int main() {
	int n,nt,nm,t,m,i;
	scanf("%d %d", &t, &m);
	nt=nm=0;
	n=40;
	for(i=0;n>0;i++) {
		if(i%t==0) {nt++; n--;}
		if(i%m==0) {nm++; n--;}
	}
	printf("%d %d", nt, nm);
	return 0;
}
