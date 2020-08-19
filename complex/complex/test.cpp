#include<iostream>
#include<complex>
#include<Windows.h>

using namespace std;

complex<double> MultiComplex(complex<double> &c, complex<double> &d)
{
	double a1 = c.real();
	double a2 = c.imag();
	double b1 = d.real();
	double b2 = d.imag();

	complex<double> e = complex<double>((a1*b1 - a2*b2), (a1*b2 + a2*b1));

	return e;
}

complex<double> DivisionComplex(complex<double> &c, complex<double> &d)
{
	double a1 = c.real();
	double a2 = c.imag();
	double b1 = d.real();
	double b2 = d.imag();

	double b1b2 = b1*b1 + b2*b2;

	complex<double> e = complex<double>((a1*b1 + a2*b2)/b1b2, (-a1*b2 + a2*b1)/b1b2);

	return e;
}


int main()
{
	LARGE_INTEGER nFreq,nBeginTime,nEndTime;
	double time;
	complex<double> d1(0,0),d2(0,0),a(3,4),b(2,3);

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);

	for (int i = 0; i < 10000;i++)
	{
		d1 = d1 + a*b;
		d2 = d2 + a/b;
	}
	cout << d1 << endl;
	cout << d2 << endl;

	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	printf("Cal-Prefit thickness costing time is %lfms\n",time*1000);

	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	d1 = 0;
	d2 = 0;
	for (int i = 0; i < 10000;i++)
	{
		d1 = d1 + MultiComplex(a,b);
		d2 = d2 + DivisionComplex(a,b);
	}
	cout << d1 << endl;
	cout << d2 << endl;

	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	printf("Cal-Prefit thickness costing time is %lfms\n",time*1000);




	return 0;
}