#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int num); 
      Rational(int num, int denom); 
      const Rational add(const Rational &c) const; 
      const Rational subtract(const Rational &c) const; 
      const Rational multiply(const Rational &c) const; 
      const Rational divide(const Rational &c) const;
      void simplify();
      void display() const;
   private:
      int gcd(int one, int two) const;
};

// Implement Rational class member functions here
Rational::Rational() { 
    this->denominator = 1; this->numerator = 0; 
}

Rational::Rational(int num, int denom)
{
    this->numerator = num;
    this->denominator = denom;
}


Rational::Rational(int num)
{
    this->numerator = num;
    this->denominator = 1;
}
const Rational Rational::add(const Rational& c) const
{
    Rational* add = new Rational();
    add->numerator = (this->numerator * c.denominator + this->denominator * c.numerator);
    add->denominator = (this->denominator * c.denominator);
    return *add;
}

const Rational Rational::subtract(const Rational& c) const
{
    Rational* sub = new Rational();
    sub->numerator = (this->numerator * c.denominator - this->denominator * c.numerator);
    sub->denominator = (this->denominator * c.denominator);
    return *sub;
}

const Rational Rational::multiply(const Rational& c) const
{
    Rational* mult = new Rational();
    mult->numerator = (this->numerator * c.numerator);
    mult->denominator = (this->denominator * c.denominator);
    return *mult;
}



const Rational Rational::divide(const Rational& c) const
{
    Rational* div = new Rational();
    div->numerator = (this->numerator * c.denominator);
    div->denominator = (this->denominator * c.numerator);
    return *div;
}
void Rational::display() const
{
    cout << this->numerator << " / " << this->denominator;
}
void Rational::simplify() {
    int hcf = gcd(numerator, denominator);
    numerator = numerator / hcf;
    denominator = denominator / hcf;
}
int Rational::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}





// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}

