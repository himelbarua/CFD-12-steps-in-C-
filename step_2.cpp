// step 2
//Non linear advection

#include<iostream>
#include<fstream>

using namespace std;
int main()
{
	int i, j, k, t;
	double dx = 0.1, dt = 0.01;
	const int Nx = 100, Nt = 150;
	int c = 1;
	double u[Nx + 1], un[Nx + 1], x[Nx + 1];

	
	//Initialization

	for (int i = 0; i <= Nx; i++)
	{
		u[i] = 0;
		un[i] = 0;
		x[i] = 0;
	}

	
	//Mesh generation

	for (i = 1; i <= Nx - 1; i++)
	{
		x[i] = (i - 1)*dx;
	}

  

	//Initial condition

	for (int i = 0; i <= Nx; i++)
	{
		if (x[i] >= Nx * dx*0.3 && x[i] <= Nx * dx*0.6)
		{
			u[i] = 2;
			//un[i] = 2;
		}
		else
		{
			u[i] = 1;
			//un[i] = 1;
		}
	}

	//print initial condition

	ofstream myfile_1;
	myfile_1.open("initial.txt");
	if (myfile_1.is_open())
	{
		for (int i=0;i<=Nx;i++)
		{ 
			myfile_1 << "\n  " << x[i];
			myfile_1 << "  " << u[i];
		}
	myfile_1.close();
	}
	else
	{
		std::cout << "unable to open the file";
	}


	//main loop

	for (int t = 1; t <= Nt; t++)
	{
		for (int i = 1; i <= Nx; i++)
		{
			un[i] = u[i] - (dt / dx)*u[i]*(u[i] - u[i - 1]);
			u[i] = un[i];
		}
	}

	ofstream myfile;
	myfile.open("final.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i <= Nx; i++)
		{
			myfile << "\n  " << x[i];
			myfile << "  " << u[i];
		}
		myfile.close();
	}
	else
	{
		std::cout << "unable to open the file";
	}

}