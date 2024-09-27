#include <stdio.h>

int main() {
	int t[102],i;
	char s[100];
	scanf("%s", s);
	t[0]=1;
	for(i=0;s[i];i++) {
		t[i+1]=s[i]=='0' ? 0 : t[i];
		if(i>0 && (s[i-1]=='1' || s[i-1]=='2')) t[i+1]+=t[i-1];
	}
	printf("%d\n",t[i]);
	return 0;
}
