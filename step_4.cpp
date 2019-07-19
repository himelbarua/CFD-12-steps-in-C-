//step 3
//1D Burgers equations
//ut+uux=m*uxx

#include <iostream>
#include <fstream>
#include<cmath>

int main()
{
	int i, j, k, t;
	double mu = 0.3;
	double pi = 3.1416;
	double xlength = 2 * pi;
	using namespace std;
	double dx = 0.1;
	int const Nx = 63,Nt = 5000;
	double dt = 0.0001;
	double un[Nx + 1], u[Nx + 1], x[Nx + 1],phi[Nx+1],dphi[Nx+1];
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
		phi[i] = exp(-0.25*pow(x[i], 2) / mu) + exp(-0.25*(2*pi-pow(x[i],2))/mu);
		dphi[i]= (-0.5*x[i] / mu) * exp(-0.25*(pow(x[i], 2)) / mu) + ((0.5*(2 * pi) - x[i]) / mu)*exp(-0.25*((2 * pi) - pow(x[i], 2)) / mu);
		u[i] = (-2 * mu*(dphi[i] / phi[i])) + 4;
	}
	
	/*for (int i = 0; i <= Nx; i++)
	{
		if ((x[i] >= Nx * dx*0.3) && (x[i] <= Nx * dx*0.6))
		{
			u[i] = 2;
		}
		else
		{
			u[i] = 1;
		}
	}*/

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
			un[i] = u[i]-(dt/dx)*u[i]*(u[i]-u[i-1])+ sigma * (u[i + 1] - 2 * u[i] + u[i - 1]);
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
		std::cout << "unable to open";
	}
}