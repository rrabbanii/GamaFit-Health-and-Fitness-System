/* 
Programming Lab 2021 Group Project CSB

Izaaz Rahman Akbar  | 21/472855/PA/20348
Rabbani Nur Kumoro  | 21/472599/PA/20310
Ramzy Izza Wardhana | 21/472698/PA/20322

GAMAFIT (Consist of 3 Subprogram)
1. Program to Compute BMI.
2. Program to Recommend the Ideal Weight based on the Gender, Height and Weight.
3. Program to Recommend the Ideal Daily Water Consumption based on the Weight. 

*/

#include <iostream>
using namespace std;

// Function for number 1 (Computing the BMI)
// Equation for BMI = kg/cm^2
double BMI (double kg, double cm) //both cm and kg as 2 parameters for this function
{
  double bmiscore = kg / (cm * cm);
  return bmiscore;
}

// Function number 2 for Male (Ideal Body Weight)
// Equation for Ideal Body Weight MALE = ((Height - 100) - ((10/100) * (Height-100))));
double BBIL (double cm) //cm as parameter
{
  double st = cm - 100;
  double pr = 0.1;
  double bbil = st - (st * pr);	
  return bbil; //return Ideal Body Weight
}

// Function number 2 for Female (Ideal Body Weight)
// Equation for Ideal Body Weight FEMALE = ((Height - 100) - ((15/100) * (Height-100))))
double BBIP (double cm) //cm as parameter
{
  double st = cm - 100;
  double pr = 0.15;
  double bbip = st - (st * pr);	
  return bbip;
}

// Function for number 3 (Daily Water Requirement)
// Equation for Daily Water Requirement = (Body Weight * 30ml)
// Equation to convert from Ml to L = Ml / 1000
double water (double kg) //kg as parameter
{
  double ml = 30;
  double waterperday = kg * ml;
  return waterperday;
}

int main ()
{
  int ans = 0; //variable to determine the subprogram
  double kg, cm; //variable to calculate the subprogram
  char choice; //variable to determine true or false value (Y or N)
  char gen; //variable to determine the gender for function 2
  
do
    {
      cout << endl;
      cout << "==========================================" << endl;
      cout << endl;
      cout << "         || WELCOME TO GAMAFIT || " << endl;
      cout << endl;
      cout << "==========================================" << endl;
      cout << "Services" << endl;
      cout << "1. BMI (Body Mass Index)" << endl;
      cout << "2. Ideal Body Weight" << endl;
      cout << "3. Daily Water Requirement" << endl;
      cout << endl << "Choose between 1-3: ";
      cin >> ans;

    if (ans > 3 || ans <= 0) //program will only receive number between 1-3
    { 
      cout << "Please Input the correct value between 1-3!" << endl;
    }

    //subprogram for Computing the BMI
    if (ans == 1)
    {
	  cout << endl << "Let's Check your BMI" << endl;
    cout << endl;
	  cout << "Input Weight (kg) : ";
	  cin >> kg;
	  cout << "Input Height (cm) : ";
	  cin >> cm;
    cout << endl;

	  // calculating BMI

	  double bmiscore = BMI (kg, cm); //recall the previous function
	  cout << "BMI Results : " << bmiscore * 10000 << endl; 

	  // BMI Category
	  if (bmiscore >= 0.0018 && bmiscore <= 0.0025)
	    {
	      cout << "BMI Category : Normal" << endl;
	      cout << "Recommendation : Stay Fit and Healthy." << endl;
	    }
	  else if (bmiscore >= 0.0025 && bmiscore <= 0.0030)
	    {
	      cout << "BMI Category : Overweight" << endl;
	      cout << "Recommendation : Increase Your Protein Consumption to Help Build Muscle." << endl;
	    }
	  else if (bmiscore > 0.0030)
	    {
	      cout << "BMI Category : Obesity" << endl;
	      cout << "Recommendation : Eat More Vegetables and Fruits, Also Add More Grain to Your Consumption." << endl;
	    }
	  else if (bmiscore < 0.0018)
	    {
	      cout << "BMI Category : Underweight" << endl;
	      cout << "Recommendation : Increase Your Carbs and Protein Consumption." << endl;
	    }
	} 
	//subprogram for Computing the Ideal Weight 
	else if (ans == 2)
	{
         cout << "Input Weight (kg) : ";
         cin >> kg;
         cout << "Input Height (cm) : ";
         cin >> cm;
         cout << "Gender (M/F) : ";
         cin >> gen; //detemine The Gender
         double bbil = BBIL (cm); //recall the function for Male
         double bbip = BBIP (cm); //recall the function for Female

      // Determining if Male or Female

			if (gen == 'M' || gen == 'm') //could receive upper or lowercase M
			{
			cout << "Your Ideal Weight : " << bbil << endl;
			}
			else if (gen == 'F' || gen == 'f') //could receive upper or lowercase F
			{
			cout << "Your Ideal Weight : " << bbip << endl;
			}

  // Determining if ideal or not

			if (bbip == kg || bbil == kg)
			{
			cout << "IDEAL!" << endl;}
			else
			{
			cout << "Not Ideal Yet. For Diet Recommendations Pick Service No.1" << endl;
			}
    } 
    //subprogram to Compute the Daily Water Requirement
    else if (ans == 3) 
    {
      // Daily Water Intake Check
      cout << "Input Weight (kg) : ";
			cin >> kg;
			double waterprs = water (kg); //recall the previous function
			cout << "Your Daily Water Intake is : " << waterprs << " ml" << endl;
			cout << "Would You like to know in Liters ? " << endl; //optional choice
			cout << " Y (Yes) / N (No) : "; 
			cin >> choice;
			
      // Option to Convert ml to liters
			if (choice == 'Y' || choice == 'y') //could receive both upper or lowercase of Y
			{
			double finalwater = waterprs * 0.001; //Formula to convert Ml to L = Ml/1000
			cout << "Your Daily Water Intake in Liters : " << finalwater << " l" << endl;
      }
			else if (choice == 'N' || choice == 'n')
			{
			double finalwater = waterprs * 0.001;
			cout << "Thank You for using the Daily Water Requirement Services!" << endl;
			}
    }
    
// Choosing other Services
			cout << endl <<
			"Would you like to use another service?" << endl;
			cout << "(Y) for yes / (N) for no : "; cin >> choice;
 } 
 //loops to itterate as long as the condition is true,
 // if condition == Y, break the program. 
 while (choice == 'Y' || choice == 'y');
  cout << "=================================";
	cout << endl << "Thank You for using GAMAFIT";
  cout << endl << "Stay Safe, Stay Healthy, Stay Fit !"; 
  return 0;
}