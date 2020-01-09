#include <iostream>
using namespace std;

double CelsiusToKelvin(double valueCelsius) {
    double valueKelvin;

    valueKelvin = valueCelsius + 273.15;

    return valueKelvin;
}

double KelvinToCelsius(double valueKelvin) {
    double valueCelsius;

    valueCelsius = valueKelvin - 273.15;

    return valueCelsius;
}

int main() {
    double valueC;
    double valueK;

    cout << "What degree in Celsius do you want to convert to Kelvin?" << endl << "Degrees Celsius: ";
    cin >> valueC;
    cout << endl;
    cout << valueC << " degrees Celsius is " << CelsiusToKelvin(valueC) << " Kelvin." << endl << endl;
    cout << "What degree in Kelvin do you want to convert to Celsius?" << endl << "Degrees Kelvin: ";
    cin >> valueK;
    cout << endl;
    cout << valueK << " Kelvin is " << KelvinToCelsius(valueK) << " degrees Celsius." << endl;

    return 0;
}