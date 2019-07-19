//step 3
//1D Diffusion

#include <iostream>
#include <fstream>
#include<cmath>

int main()
{
	int i, j, k, t;
	double mu = 0.3;
	using namespace std;
	int const Nx = 10, Nt =500;
	double dx = 0.1;
	double dt = 0.0001;
	double un[Nx+1], u[Nx+1], x[Nx+1];
	double sigma;
		
	sigma = ((mu*dt) / pow(dx, 2));
	std::cout << "sigma is " << sigma;
	
	//Initialization

	for (int i = 0; i <= Nx; i++)
	{
		x[i] = 0;
		u[i] = 0;
		un[i] = 0;
	}

	//Mesh genration

	for (int i = 1; i <= Nx; i++)
	{
		x[i] = (i - 1)*dx;
	}

	//Initial condition

	for (int i = 0; i <= Nx; i++)
	{
		if ((x[i] >= Nx*dx*0.3) && (x[i] <= Nx*dx*0.6))
		{
			u[i] = 2;
		}
		else
		{
			u[i] = 1;
		}
	}

	//initial distributuon 

	ofstream myfile_1;
	myfile_1.open("initial.txt");

	if (myfile_1.is_open())
	{
		for (i = 0; i <= Nx; i++)
		{
			myfile_1 << "\n  " << x[i];
			myfile_1 << "  " << u[i];
		}
		myfile_1.close();
	}

	else
	{
		std::cout << "unable to print";
	}

	//main loop
	for (int t = 1; t <= Nt; t++)// time loop
	{
		
		for (int i = 1; i <= Nx - 1; i++)//space loop
		{
			un[i] = u[i] + sigma * (u[i + 1] - 2 * u[i] + u[i - 1]);

		}
		for (int i = 1; i <= Nx - 1; i++)//updating 
		{
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
			myfile << "  " <<  u[i];
		}
		myfile.close();
	}
	else
	{
		std::cout << "unable to open";
	}
}