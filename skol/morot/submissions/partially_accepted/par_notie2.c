#include <stdio.h>

int main() {
	int n,nt,nm,t,m,i;
	scanf("%d %d", &t, &m);
	nt=nm=1;
	n=38;
	for(i=1;n>0;i++) {
		if(i%t==0) {nt++; n--;}
        else if(i%m==0) {nm++; n--;}
	}
	printf("%d %d", nt, nm);
	return 0;
}
