#include "Polynomial.h"
//INTEGRANTES:
//SERGIO CORDOBA
//SEBASTIAN ARIAS
//https://replit.com/@SebastianArias6/Practica2#main.cpp
int main()
{
	int size;
	cout<<"***************************************************"<<endl;
	cout<<"First Polynomial"<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"Grade of the Polynomial ";
	cin>>size;

	Polynomial A(size);
	A.generatePolynomial();

	cout<<"***************************************************"<<endl;
	cout<<"Second Polynomial"<<endl;
	cout<<"***************************************************"<<endl;
	cout<<"Grade of the Polynomial ";
	cin>>size;
	
	Polynomial B(size);
	B.generatePolynomial();

	
		//Overloading +=
		cout<<endl<<"***************************************************"<<endl;
		cout<<"Overloading +="<<endl;
		cout<<"***************************************************"<<endl;
		
		cout<<"A= ";
		A.printPolynomial();

		cout<<"B= ";
		B.printPolynomial();

		B+=A;
		cout<<"B+=A ";
		B.printPolynomial();


		cout<<endl<<"***************************************************"<<endl;
		cout<<"Overloading + and ="<<endl;
		cout<<"***************************************************"<<endl;
		
		Polynomial *C;	

		cout<<"A= ";
		A.printPolynomial();

		cout<<"B= ";
		B.printPolynomial();

		C=A+B;
		
		cout<<"Result C=A + B ";
		C->printPolynomial();

		cout<<"A= ";
		A.printPolynomial();

		cout<<"B= ";
		B.printPolynomial();

		cout<<endl<<"***************************************************"<<endl;
		cout<<"Overloading * and ="<<endl;
		cout<<"***************************************************"<<endl;


		cout<<"A= ";
		A.printPolynomial();

		cout<<"B= ";
		B.printPolynomial();

		C=A*B;
		
		cout<<"Result C=A * B ";
		C->printPolynomial();

		cout<<"A= ";
		A.printPolynomial();

		cout<<"B= ";
		B.printPolynomial();



		cout<<endl<<"***************************************************"<<endl;
		cout<<"Overloading ="<<endl;
		cout<<"***************************************************"<<endl;
		
		B=A;
		cout<<"A= ";
		A.printPolynomial();
		cout<<"B= ";
		B.printPolynomial();

		//Overloading *=
		cout<<endl<<"***************************************************"<<endl;
		cout<<"Overloading *="<<endl;
		cout<<"***************************************************"<<endl;
		
		cout<<"A= ";
		A.printPolynomial();

		cout<<"B= ";
		B.printPolynomial();

		B*=A;
		cout<<"B*=A ";
		B.printPolynomial();		


		//Overloading *=
		cout<<endl<<"***************************************************"<<endl;
		cout<<"Overloading A*=c"<<endl;
		cout<<"***************************************************"<<endl;
		
		cout<<"A= ";
		A.printPolynomial();

		cout<<"c= 10"<<endl;
		int c=10;

		A*=c;
		cout<<"A*=c ";
		A.printPolynomial();	
	
		

	return 0;
}
