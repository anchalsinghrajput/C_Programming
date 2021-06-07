#include <stdio.h>
	int fn(int* x, int n)
	{
		*x= n;
		return (n+100);
	}
	void main()
	{
		int x, y;
		y = fn(&x,250);
		printf("OUTPUT:X=%d,Y=%d"+3, x, y);
	}

/*output:
PUT:X=250,Y=350*/
  
  
  #include <stdio.h>
	#define ADD_FN(X,Y) X+Y
	int fn_A(int x, int y)
	{
	return (x+y);
	}
	int fn_A1(int x, int y)
	{
	return (x-y);
	}
	int fn(int x, int y)
	{
	return (x/y);
	}
	void main(){
		int x, y, w, z;
		x=20;
		y=30;
		z = fn(x,y);
		w =ADD_FN(x,y)*ADD_FN(z, x);
                printf("X=%d,Y=%d, Z=%d,W=%d", x, y, z, w);
	}

/*Output:
X=20,Y=30, Z=0,W=40*/

#include <stdio.h>

	int* fn(int*y)
	{
		int x= 27;
		*y=x*4;
		return &x;
	}
	void main()
	{
		int* pA;
		int x, z, y=25;
		z = y;
		pA = fn(&y);
		printf(“X=%d,Y=%d,Z=%d”, *pA, y, z);
	}

 	//The output of the program is X=27,Y=108 Z=25


