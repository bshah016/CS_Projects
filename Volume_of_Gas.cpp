#include <iostream>
using namespace std;

const double GAS_CONST = 8.3144621;

double ComputeGasVolume(double pressure, double temperature, double moles) {
    double volume = 0;
    volume = (moles * temperature * 8.3144621) / pressure;
    return volume;
}

int main() {
    double gasPressure;
    double gasMoles;
    double gasTemperature;
    double gasVolume;
    cout << "What is the pressure of the gas (in Pascals)?" << endl << "Pressure: ";
    cin >> gasPressure;
    cout << endl;
    cout << "What is the massof the gas (in Moles)?" << endl << "Moles: ";
    cin >> gasMoles;
    cout << endl;
    cout << "What is the temperature of the gas(in Kelvin)?" << endl << "Temperature: ";
    cin >> gasTemperature;
    cout << endl;

    gasVolume = ComputeGasVolume(gasPressure, gasTemperature, gasMoles);
    cout << "Gas Volume = " << gasVolume << " cubic meters!!" << endl;

    return 0;
}