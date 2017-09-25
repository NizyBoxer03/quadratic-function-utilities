/*
 * QuadraticFunctions.cpp
 *
 *  Created on: Sep. 2017
 *      Author: NizyBoxer03
 */

#include <iostream>
#include <cmath>

class ConvFunc
{
	public:
		float a = 0, b = 0, c = 0, x1 = 0, x2 = 0, xv = 0, yv = 0;
		void stoi(float a, float b, float c)
		{
			n = true;
			x1 = bhsk(a, b, c, n);
			n = false;
			x2 = bhsk(a, b, c, n);
			std::cout << "The Intercept Form is:\n";
			std::cout << a << "(x+" << x1 << ")" << "(x+" << x2 << ")" <<"\n";
		}

		void stov(float a, float b, float c)
		{
			xv = xvp(a, b);
			yv = yvp(a, b, c, xv);
			std::cout << "The Vertex Form is:\n";
			std::cout << a << "(x-" << xv << ")^2+" << yv <<"\n";
		}

		float itos(/*float a, float x1, float x2*/)
		{
			std::cout << "TEST\n";
			return 0;
		}

		float itov(/*float a, float x1, float x2*/)
		{
			std::cout << "TEST\n";
			return 0;
		}

		float vtos(/*float a, float x1, float x2*/)
				{
					std::cout << "TEST\n";
					return 0;
				}

		float vtoi(/*float a, float x1, float x2*/)
				{
					std::cout << "TEST\n";
					return 0;
				}


		void sel()
			{
				std::cout << "Select an option:\n1.Standard to Intercept.\n2.Standard to Vertex.\n3.Intercept to Standard.\n4.Intercept to Vertex.\n5.Vertex to Standard.\n6.Vertex to Intercept.\n";
				std::cin >> opt;
				switch(opt)
				{
					case 1:
						std::cout << "Enter the value of \"a\":\n";
						std::cin >> a;
						std::cout << "Enter the value of \"b\":\n";
						std::cin >> b;
						std::cout << "Enter the value of \"c\":\n";
						std::cin >> c;
						stoi(a, b, c);
						break;

					case 2:
						std::cout << "Enter the value of \"a\":\n";
						std::cin >> a;
						std::cout << "Enter the value of \"b\":\n";
						std::cin >> b;
						std::cout << "Enter the value of \"c\":\n";
						std::cin >> c;
						stov(a, b, c);
						break;

					case 3:
						itos();
						break;

					case 4:
						itov();
						break;

					case 5:
						vtos();
						break;

					case 6:
						vtoi();
						break;
				}
			}

	private:
		int opt;
		bool n;
		float bhsk(float a, float b, float c, bool n)
		{
			float x = 0;
			float a2 = (2*a) ;
			if(n == true)
			{
				x = (-b+sqrt(pow(b, 2)-4*a*c))/a2 ;
			}
			else
			{
				x = (-b-sqrt(pow(b, 2)-4*a*c))/a2;
			}
			return x;
		}

		float xvp(float a, float b)
		{
			float x = 0;
			x = (-b/(2*a));
			return x;
		}

		float xvf(/*float x1, float x2*/)
		{
			std::cout << "TEST\n";
			return 0;
		}

		float yvp(float a, float b, float c, float xv)
		{
			float x = 0, pxv = pow(xv, 2), apxv = (a*pxv), bxv = (b*xv);
			x = (apxv+bxv+c);
			return x;
		}

		float yvf(/*float a, float x1, float x2, float xv*/)
		{
			std::cout << "TEST\n";
			return 0;
		}
};

int main(int argc, char **argv)
{
	ConvFunc cf;
	cf.sel();
	return 0;
}




