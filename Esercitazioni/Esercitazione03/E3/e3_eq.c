#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n) {
	const void* si = src;
	int b = n;
	void* a = malloc(n);	//void* des = malloc(n);
	void* di = a;
    	if(di == 0) goto N;	//if (des==0) return 0;
    	memcpy(des, src, n);	//memcpy(des, src, n);
	int a = di;
	return a;		//return des;
N:	a = 0;
	return a;
}	
