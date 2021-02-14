#include "polynomial.h"

int main()
{

	vector<Polynomial*> polynomials(3, nullptr);


	while (1)
	{

		for (int i = 0; i < 20; i++)
			cout << "- - -";
		cout << endl;

		cout << "Choose the option :" << endl;
		cout << "1. Read all three polynomials " << endl;
		cout << "2. Evaluate expresion " << endl;
		cout << "3. Exit" << endl;


		int option;
		cin >> option;

		switch (option)
		{

		case 1:
		{
			
			for (int i = 0; i < 3; i++)
			{
				cout << "Polynomial numebr " << i + 1 << endl;
				vector<double> vec;
				unsigned degree;
				cout << "Grade of the polynomial : ";
				cin >> degree;
				cout << "Coefficients of the polynomial : (a0 x^n + a1 x^n-1 + ...)";
				for (size_t i = 0; i < degree + 1; i++)
				{
					int temp;
					cin >> temp;
					vec.push_back(temp);
				}
				polynomials[i] = new Polynomial(vec);

			}

			break;
		}

		case 2:
		{
			cout << "The value of x :";
			double x;
			cin >> x;
			if (evaluate_expresion_v1(*polynomials[0], *polynomials[1], *polynomials[2], x) == evaluate_expresion_v2(*polynomials[0], *polynomials[1], *polynomials[2], x))
			{
				cout << "TRUE" << endl;
			}
			else
			{
				cout << "FALSE" << endl;
			}

			for (int i = 0; i < 3; i++)
			{
				delete polynomials[i];
			}

			break;
		}

		case 3:
		{
			return 0;
		}

		}
	}


}