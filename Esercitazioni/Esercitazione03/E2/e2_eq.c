int counteq(short* v1, short* v2, int n) {
	short* di = v1;
	short* si = v2;
	int d = n;
	int a = 0;		//int i, cnt = 0;
	d--;
L:    	if(d < 0) goto E;	//for (i=0; i<n; ++i) cnt += (v1[i]==v2[i]);
	short c = di[d];
	short b = si[d];
	char cl = c == b ? 1:0;
	int cc = (int) cl;
	a = a + cc;
	goto L;
E:	return a;
}    	
