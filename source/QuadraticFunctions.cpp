/*
 * QuadraticFunctions.cpp
 *
 *  Created on: Sep. 2017
 *      Author: NizyBoxer03
 */

//I'm really sorry for the excessive comments, but I must admit that the rubber duck method actually works.
//Since I don't have a rubber duck, I just write everything down.
//Sorry!
//Yes, I talk a lot.

#include <iostream>
#include <cmath>

class QuadFunc //Class for converting the Quadratic Functions between Forms.
{
	public:
		void stoi(float a, float b, float c) //Standard to Intercept conversion.
		{
			n = true;
			x1 = bhsk(a, b, c, n);
			n = false;
			x2 = bhsk(a, b, c, n);
			std::cout << "The Intercept Form is:\n";
			std::cout << a << "(x+" << x1 << ")" << "(x+" << x2 << ")" <<"\n";
		}

		void stov(float a, float b, float c) //Stardard to Vertex conversion.
		{
			xv = xvs(a, b);
			yv = yvs(a, b, c, xv);
			std::cout << "The Vertex Form is:\n";
			std::cout << a << "(x-" << xv << ")^2+" << yv <<"\n";
		}

		float itos(float a, float x1, float x2) //Intercept to Standard conversion.
		{
			float b = 0, c = 0;
			b = ((x1*a)+(x2*a));
			c = ((a*x1)*x2);
			std::cout <<"The Standard Form is:\n";
			std::cout << a <<"x^2+"<< b << "x+" << c <<"\n";
			return 0;
		}

		float itov(float a, float x1, float x2) //Intercept to Vertex conversion.
		{
			xv = xvi(x1, x2);
			yv = yvi(a, x1, x2, xv);
			std::cout << "The Vertex Form is:\n";
			std::cout << a << "(x-" << xv << ")^2+" << yv <<"\n";
			return 0;
		}

		float vtos(/*float a, float x1, float x2*/) //Vertex to Standard conversion.
				{
					std::cout << "WIP\n";
					return 0;
				}

		float vtoi(/*float a, float x1, float x2*/) //Vertex to Intercept conversion.
				{
					std::cout << "WIP\n";
					return 0;
				}


		void sel() //Function in charge of receiving input and executing other functions. Fancy wording for a menu.
			{
				std::cout << "Select an option:\n1.Standard to Intercept.\n2.Standard to Vertex.\n3.Intercept to Standard.\n4.Intercept to Vertex.\n5.Vertex to Standard.\n6.Vertex to Intercept.\n"; //Print out the menu choices.
				std::cin >> opt; //Receive input and make a choice.
				switch(opt)
				{
					case 1:
						std::cout << "Enter the value of \"a\":\n";
						std::cin >> a;
						std::cout << "Enter the value of \"b\":\n";
						std::cin >> b;
						std::cout << "Enter the value of \"c\":\n";
						std::cin >> c;
						stoi(a, b, c); //Call corresponding function using input received as arguments.
						break;

					case 2:
						std::cout << "Enter the value of \"a\":\n";
						std::cin >> a;
						std::cout << "Enter the value of \"b\":\n";
						std::cin >> b;
						std::cout << "Enter the value of \"c\":\n";
						std::cin >> c;
						stov(a, b, c); //Call corresponding function using input received as arguments.
						break;

					case 3:
						std::cout << "Enter the value of \"a\":\n";
						std::cin >> a;
						std::cout << "Enter the value of \"x1\":\n";
						std::cin >> x1;
						std::cout << "Enter the value of \"x2\":\n";
						std::cin >> x2;
						itos(a, x1, x2); //Call corresponding function using input received as arguments.
						break;

					case 4:
						std::cout << "Enter the value of \"a\":\n";
						std::cin >> a;
						std::cout << "Enter the value of \"x1\":\n";
						std::cin >> x1;
						std::cout << "Enter the value of \"x2\":\n";
						std::cin >> x2;
						itov(a, x1, x2);
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
		float a = 0, b = 0, c = 0, x1 = 0, x2 = 0, xv = 0, yv = 0; //All the variables needed for the actual calculations.
		int opt; //Initial menu selection is stored here.
		bool n; //Selector for the Bhaskara Function. If true, x1 is returned. If false, x2 is returned.
		float bhsk(float a, float b, float c, bool n) //Function that performs a semi-linear version of the Bhaskara Formula. Needs <cmath> to work.
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

		float xvs(float a, float b) //Calculates the X position of the Vertex from the Standard Form values.
		{
			float x = 0; //Temporary variable needed just to return the value.
			x = (-b/(2*a)); //Actual calculation.
			return x; //Returns the above calculation
		}

		float xvi(float x1, float x2) //Calculates the X position of the Vertex from the Intercept Form values.
		{
			float x = 0;
			x = ((x1+x2)/2);
			return x;
		}

		float yvs(float a, float b, float c, float xv)  //Calculates the Y position of the Vertex from the Standard Form values.
		{
			float x = 0, pxv = pow(xv, 2), apxv = (a*pxv), bxv = (b*xv); //Variables needed for this cheap and dirty, but somehow effective approach.
			x = (apxv+bxv+c); //Adds everything.
			return x; //Returns the addition done above.
		}

		float yvi(float a, float x1, float x2, float xv)  //Calculates the Y position of the Vertex from the Intercept Form values.
		{
			float x = 0;
			std::cout << "DEBUG: " << a << " " << x1 << " " << x2 << " " << xv << "\n";
			x = (a*(xv-x1)*(xv-x2));
			return x;
		}
};

int main(int argc, char **argv) //Program Entry Point
{
	QuadFunc cf; //New object of class QuadFunc.
	cf.sel(); //Starts the program via the sel() function in class QuadFunc.
	return 0; //Ends program execution
}
