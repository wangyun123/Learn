
__declspec(dllexport) int func(int a)
{
	return a;
}
__declspec(dllexport) int func(int a, int b)
{
	return a+b;
}
__declspec(dllexport) int func(int a, int b, int c)
{
	return a+b+c;
}