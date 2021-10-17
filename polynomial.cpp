#include "Polynomial.h"

//Default constructpolyObj: it creates a Polynomial with grade 99
Polynomial::Polynomial()
{
	Coef = new double[100];
	grade=99;
}

//Special constructpolyObj: it creates a polynomial with grade sz
Polynomial::Polynomial(int sz)
{
	Coef = new double[sz + 1];
	grade = sz;
}

//Copy ConstructpolyObj
Polynomial::Polynomial(Polynomial &polyObj)
{
	Coef = polyObj.Coef;
	grade = polyObj.grade;
}


//DestructpolyObj: deallocate mempolyObjy
Polynomial::~Polynomial()
{
	delete []Coef;
	Coef=0;
}

//readPolynomial Method: Reads all positions of the Polynomial
void Polynomial::readPolynomial()
{
	int i;
	for(i= 0; i<= grade; i++)
	{
		cout<<"Polynomial["<<i<<"]= ";
		cin>>Coef[i];
	}
}

//printPolynomial Method: Prints all positions of the Polynomial
void Polynomial::printPolynomial()
{
	int i;
	for(i= grade; i>0; i--)
	{
		cout<<Coef[i]<<"X^"<<i<<" + ";
	}
	cout<<Coef[0]<<endl;
}
//generatePolynomial method: generates random coeficients
void Polynomial::generatePolynomial()
{
	int i;
	for(i= 0; i<= grade; i++)
	{
		Coef[i]=rand()%10;
	}
	
}
//initPolynomial method: delete the current polynomomial, and creates new one with grade i
void Polynomial::initPolynomial(int i)
{
	delete []Coef;
	Coef=new double[i+1];
	grade = i;
	for(i=0; i<=grade;i++)
	{
		Coef[i]=0;
	}
}

//getgrade Method: return the Polynomial grade
int Polynomial::getGrade()
{
	return grade;
}

//Overloading += operator
//void operator+=(const Polynomial &polyObj);
//Método que sobrecarga el operador += y se encarga de 
//sumar dos polinomios y actualizar el valor del polinomio B.
void Polynomial::operator+=(const Polynomial &B)
{
	int grade_h,grade_l;
	grade_h = grade;
	grade_l = B.grade;
	Polynomial * res;
	res = new(Polynomial);
	if(B.grade > this->grade){
		grade_h = B.grade;
		grade_l = this ->grade;
	}
	res -> initPolynomial(grade_h);

		int i;
		for(i = 0; i<=grade_l;i++){
			res->Coef[i] = Coef[i]+B.Coef[i];
		}
		if(grade_l == grade){
			for(i = grade_l+1; i<=grade_h;i++)
				res->Coef[i]=B.Coef[i];
		}else{
			for(i=grade_l+1; i<=grade_h;i++){
				res->Coef[i] = Coef[i];
			}
		}
	delete []Coef;

	Coef=new double[grade_h+1];
	for(i=0;i<=grade_h;i++){
		Coef[i]=res->Coef[i];
	}
	grade = grade_h;
  delete res;
	res=0;

}

//Overloading + operator
//Polynomial *operator+(Polynomial &polyObj);
//Método que se encarga de sumar los polinomios segun su grado
//este método hace que los polinmios se sumen por sus la semejanza de sus grados.
Polynomial *Polynomial::operator+(Polynomial &B)
{
	Polynomial *res;
	int i;

	if (grade>=B.grade){
		res = new Polynomial(grade);
		for(i = 0; i <= grade;i++){
			if(i > B.grade){
				res ->Coef[i] =Coef[i];
			}else{
				res ->Coef[i] = Coef[i]+B.Coef[i];
			}
		}
	}else{
		res = new Polynomial(B.grade);
		for(i = 0;i<=B.grade;i++){
			if(i > grade){
				res ->Coef[i] = B.Coef[i];
			}else{
				res ->Coef[i] = Coef[i]+B.Coef[i];
			}
		}
	}
	return res;
		
}

//Overloading * operator for Polynomial*Polynomial
//Método que se encarga de sobrecargar el operador * el cual
//multiplica los coeficientes y suma los grados de cada uno para luego
//sumar los coeficientes con grados semehantes.
Polynomial *Polynomial::operator*(Polynomial &B)
{
	Polynomial *res;
  res = new Polynomial(grade + B.grade);
  int i;
  int j;
  for(i=0;i<=grade;i++){
    for(j=i;j <=B.grade+i;j++){
      res->Coef[j]= res->Coef[j] + (Coef[i]*B.Coef[j-i]);
    }
  } 
	return res;
}


//Overloading *= operatorfor Polynomial*Polynomial
//Método que sobrecarga el operador *= y se encarga de
//multiplicar dos polinomios. 
void Polynomial::operator*=(Polynomial &B)
{
  Polynomial *res;
  res = new Polynomial(grade + B.grade);
  int i;
  int j;
  for(i=0;i<=grade;i++){
    for(j=i;j <=B.grade+i;j++){
      res->Coef[j]= res->Coef[j] + (Coef[i]*B.Coef[j-i]);
    }
  } 
	operator=(*res);
}


//Overloading * operator for Polynomial*int
//Método que se encarga de multiplicar los coeficientes.
//de un polinomio por un valor entero dado.
void Polynomial::operator*=(int c)
{
  int i;
  for(i = 0; i <= grade; i++){
    Coef[i] = Coef[i]*c;
  } 
} 


//Overloading = operator
//Método que se encarga de igualar los polinomios.
//iguala el polinomio A con el polinomio B.
void Polynomial::operator=(const Polynomial &B)
{
  grade = B.grade;
  int i;
  for(i=0;i<=grade;i++){
    Coef[i] = B.Coef[i];
  }
}