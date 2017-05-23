#include <stdio.h>

int div(int a, int b)
{
	if (b==0)
	{
		throw "1111111";
	}
	return a/b;
}

int main(int argc, char* argv[])
{
	printf("try catch ...\n");

	try{
		int res = div(10, 20);
	}catch (char* e){
		printf("%s\n", e);
	}

	getchar();
	return 0;
}