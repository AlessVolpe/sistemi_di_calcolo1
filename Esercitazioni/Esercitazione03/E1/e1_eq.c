int fib(int n) {
    	int di = n;	//if (n<2) return 1;
	int a = 1;
	if(di<2) goto E;
	di--;
	a = fib(di);
	int b = a;
	di--;
	a = fib(di);
	a = a + b;
E:    	return a;//return fib(n-1)+fib(n-2);
}
