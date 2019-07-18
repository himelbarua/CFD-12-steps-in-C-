#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int i, j, k;
	int nx = 500, nt = 1000;
	const int Nx = 500;
	double dx = 0.02;
	double dt = 0.001;
	int c = 1;
	double u[Nx+1], un[Nx+1],x[Nx+1];


	for (int i = 0; i <= nx; i++)
	{
		x[i] = (i - 1)*dx;
	}

	for (int i = 0; i <= nx; i++)
	{
		u[i] = 0;
		un[i] = 0;
	}

	for (int i = 0; i <= nx; i++)
	{
		if (x[i] >= nx*dx*0.4 && x[i] <= 0.6*nx*dx)
		{
			u[i] = 2;
			un[i] = 2;
		}
		else
		{
			u[i] = 1;
			un[i] = 1;
		}
	}

	ofstream myfile_1;
	myfile_1.open("initial.txt");

	if (myfile_1.is_open())
	{
		for (int i = 0; i <= nx; i++)
		{
			myfile_1 << "\n  " << x[i];
			myfile_1 << "  " << u[i];
		}
	}

	
	
	for (int t = 1; t <= nt; t++)
	{

		for (int i = 1; i <= nx; i++)
		{
			un[i] = u[i] - ((c*dt) / dx)*(u[i] - u[i - 1]);
			u[i] = un[i];
		}

	}
	for (i = 0; i <= nx; i++)
	{
		cout << "\n u[" << i << "] is " << u[i];
	}

	ofstream myfile;
	myfile.open("final.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i <= nx; i++)
		{
			myfile << "\n  " << x[i];
			myfile << "  " << u[i];

		}
		myfile.close();
	}
	else
	{
		cout << "unable to open the file";
	}


	return 0;
}

