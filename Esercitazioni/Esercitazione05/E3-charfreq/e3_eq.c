#include <string.h>
#include "e3.h"

char charfreq(const char* s) {
    	unsigned freq[256];
	memset(freq, 0, 256*sizeof(unsigned));
L1:	char c = *s;
	if(c == 0) goto F;
	freq[c]++;
	s++;
	goto L1;
F:	unsigned maxi = 0;
	unsigned maxf = freq[0];
	int i = 1;
L2:	if(i >= 256) goto E;
	if(freq[i]>maxf) maxi = i;
	if(freq[i]>maxf) maxf = freq[i];
	++i;
	goto L2;
E:	return maxi;	
}
// Scrivere il C equivalente qui...
