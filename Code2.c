#include <stdio.h>
/*This is the initial include statement with necessary dependencies*/
float celsius_to_fahrenheit(float celsius) {
    float fahrenheit;
    return fahrenheit = (celsius * (9.0 / 5) + 32);
}
/*This method converts celsius to fahrenheit*/
float fahrenheit_to_celsius(float fahrenheit) {
    float celsius;
    return celsius = ((5.0 / 9) * (fahrenheit - 32));
}
/*This method converts fahrenheit to celsius*/
float celsius_to_kelvin(float celsius) {
    float kelvin;
    return kelvin = celsius + 273.15;
}
/*This method converts celsius to kelvin*/
float kelvin_to_celsius(float kelvin) {
    float celsius;
    return celsius = kelvin - 273.15;
}
/*This method converts kelvin to celsius*/
float fahrenheit_to_kelvin(float fahrenheit) {
    float kelvin;
    return kelvin = (fahrenheit - 32) * (5.0/9) + 273.15;
}
/*This method converts fahrenheit to kelvin*/
float kelvin_to_fahrenheit(float kelvin) {
    float fahrenheit;
    return fahrenheit = (kelvin - 273.15) * (9.0/5) + 32;
}
/*This method converts kelvin to fahrenheit*/
void categorize_temperature(float celsius) {
    if (celsius <= 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather Advisory: Bundle up!\n");
    }
    else if (celsius > 0 && celsius <= 10) {
        printf("Temperature category: Cold\n");
        printf("Weather Advisory: Wear a jacket!\n");
    }
    else if (celsius > 10 && celsius <= 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather Advisory: This is perfect weather!\n");
    }
    else if (celsius > 25 && celsius <= 35) {
        printf("Temperature category: Hot\n");
        printf("Weather Advisory: Bring your water!\n");
    }
    else if (celsius < 35) {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather Advisory: Find some shade!\n");
    }
}
/*This method checks the temperature in celsius and then runs that celsius through nested if else loops until it finds the range that satisfies it. It then prints the statements under that range*/
int main() {
    float temp;
    int temp_scale;
    int target;
    float con_temp;
/*These are the initially declared variables*/
    printf("Enter a temperature: ");
    scanf("%f", &temp);
    printf("Choose the current scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
    scanf("%d", &temp_scale);
    printf("Convert to (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
    scanf("%d", &target);
/*This asks the user for their input and assigns that input to the values above*/
    while ((temp_scale == target) || (temp_scale == 3 && temp <= 0)){
        printf("Invalid Input. Try Again.\n");
        printf("Enter a temperature: ");
        scanf("%f", &temp);
        printf("Choose the current scale (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
        scanf("%d", &temp_scale);
        printf("Convert to (1)Celsius, (2)Fahrenheit, (3)Kelvin: ");
        scanf("%d", &target);
    }
/*If the user inputs a negative Kelvin value or makes the conversion choices the same, this code will make the user input another set of values*/
    if (target == 1) {
        if (temp_scale == 2) {
            con_temp = fahrenheit_to_celsius(temp);
        } 
        else if (temp_scale == 3) {
            con_temp = kelvin_to_celsius(temp);
        }
    }
    else if (target == 2) {
        if (temp_scale == 1) {
            con_temp = celsius_to_fahrenheit(temp);
        }
        else if (temp_scale == 3) {
            con_temp = kelvin_to_fahrenheit(temp);
        }
    }
    else if (target == 3) {
        if (temp_scale == 1) {
            con_temp = celsius_to_kelvin(temp);
        }
        else if (temp_scale == 2) {
            con_temp = fahrenheit_to_kelvin(temp);
        }
    }
/*This code will check what the target value is, what the initial conversion was, and then call the respective function to make the conversion*/
    if (target == 1) {
        printf("Converted temperature: %fC\n", con_temp);
    }
    else if (target == 2) {
        printf("Converted temperature: %fF\n", con_temp);
    }
    else if (target == 3) {
        printf("Converted temperature: %fK\n", con_temp);
    }
/*This code checks the what the target conversion was before printing out that conversion to the user*/
    if (temp_scale == 1) {
        categorize_temperature(temp);
    }
    else if (temp_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(temp));
    }
    else if (temp_scale == 3) {
        categorize_temperature(kelvin_to_celsius(temp));
    }
/*This code converts the intial conversion to celsius if it isn't celsius and calls categorize_temperature() with celsius as the one parameter*/
    return 0;
/*This is what is returned by main*/
}