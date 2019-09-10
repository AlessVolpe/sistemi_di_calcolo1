#include "e2.h"

int lcm(int x, int y) {
	int si = x;
	int di = y;
	int c = di;		//int greater = y;
    	if(si <= di)
		c = si;
	int a;			//if (x > y)
L:      a = c;			//greater = x;
	int d = a % si;
	char bl = d == 0;
	a = c;
	d = a % di;
	char bh = d == 0;
    	bl = bl & bh;		//while (1) {
        if(bl == 0) goto F;	//if ((greater % x == 0) && (greater % y == 0))
	a = c;
	return a;		//return greater;
F:	c++;
	goto L;		        //greater++;
    
}	// Scrivere il C equivalente qui...
