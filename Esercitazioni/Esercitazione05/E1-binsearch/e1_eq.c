#include "e1.h"

int binsearch(int *v, int n, int x) {
	int i = 0;		//int i=0, j=n;
	int j = n;
	int a = 1;
L:    	if(i >= j) goto E0;	//while (i<j) {
        int m = (i+j) >> 1;	//int m = (i+j)/2;
        if(v[m] == x) goto E1;	//if (v[m]==x) return 1;
        if(v[m] <= x) goto F;	//if (v[m]>x) j=m;
	j = m;
	goto L;
E0:	a = 0;
E1:	return a;
F:	i = m+1;
	goto L;			//else i=m+1;
 
    				//return 0;
}
