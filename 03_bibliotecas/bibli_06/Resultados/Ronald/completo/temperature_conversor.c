#include "./temperature_conversor.h"

float convert_celsius_to_kelvin(float temperature) {
    float kelvin = temperature + 273.15;
    return kelvin;
}

float convert_celsius_to_fahrenheit(float temperature) {
    float fahrenheit = (9*temperature)/5 + 32;
    return fahrenheit;
}

float convert_kelvin_to_celsius(float temperature) {
    float celsius = temperature - 273.15;
    return celsius;
}

float convert_kelvin_to_fahrenheit(float temperature) {
    float fahrenheit = ((temperature-273.15)/5)*9 + 32;
    return fahrenheit;
}

float convert_fahrenheit_to_celsius(float temperature) {
    float celsius = (temperature-32)/9 * 5;
    return celsius;
}

float convert_fahrenheit_to_kelvin(float temperature) {
    float kelvin = ((temperature-32)/9)*5 + 273.15;
    return kelvin;
}

float convert_temperature(float temperature, float convert_func(float temperature)) {
    float temp_convertida = convert_func(temperature);
    return temp_convertida;
}
