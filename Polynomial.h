#include <iostream>


using namespace std;
class Polynomial{
public:
	
	Polynomial();				//Default constructpolyObj: it creates an Polynomial with grade 99
	Polynomial(int sz);			//Special constructpolyObj: it creates an Polynomial with grade sz
	Polynomial(Polynomial &polyObj);		//Copy ConstructpolyObj
	~Polynomial();				//DestructpolyObj: deallocate mempolyObjy
	void readPolynomial();		//readPolynomial Method: Reads all positions of the Polynomial
	void printPolynomial();		//printPolynomial Method: Prints all positions of the Polynomial
	int getGrade();			//getSize Method: return the Polynomial grade
	void generatePolynomial();   //generatePolynomial Method: generates random coeficients
	void operator+=(const Polynomial &polyObj); //Overload the operator += for Polynomials: A+=B defined as A[i]+=B[i]
	Polynomial *operator+(Polynomial &polyObj); //Overload the operator +  for using with Polynomial
	void operator=(const Polynomial &polyObj);  //Overload the assignment operator 
	void initPolynomial(int i); //delete the current polynomomial, and creates new one with grade i
	Polynomial *operator*(Polynomial &B); //Overloading * operator for Polynomials
	void operator*=(Polynomial &B);//Overloading *= operator for Polynomials
	void operator*=(int c);//Overloading *= operator for Polynomial*int


private:
	double *Coef;//Array for storing the coeficients
	int grade;//polynomial grade
};