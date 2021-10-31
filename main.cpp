#include <iostream>
using namespace std;

const int month = 12;
const int date = 31;

struct userid
{
    string name;
    string username;
    string email;
    string password;
    int account_no;
};

struct step_count
{
    int step_num[month][date];
    int weight[month][date];
    double calories[month][date];
    double distance[month][date];
};

struct sleep_track
{
    int sleep_hour[month][date];
    int sleep_minute[month][date];
    string feeling[month][date];
};

struct bmi_count
{
    double weight[month][date];
    double height[month][date];
    char gender[month][date];
    double bmiscore[month][date];
};

userid user_info;
step_count step;
sleep_track sleep;
bmi_count bmi;

void bmi_info (bmi_count &bmi)
{
    string key;
    int i,j;
    double bmiscore;
    char gen;
    cout << "\nBMI (Body Mass Index) Info \n" << "------------------\n\n";
    cout << "Please Select The Month (1-12): ";
    cin >> j;
    cout << "Please Select The Date (1-31): ";
    cin >> i;
    
    if (i<1||i>31||j<1||j>12)
    {
        cout << "Invalid Month or Date! \n\n";
        return bmi_info(bmi);
    }
    
    i-=1;j-=1;
    bmi.bmiscore[j][i]=bmi.weight[j][i]/(bmi.height[j][i]*bmi.height[j][i]);
    gen=bmi.gender[j][i];
    bmiscore=bmi.bmiscore[j][i];
    cout << endl;
    cout << "User Weight: " << bmi.weight[j][i] << " kg\n";
    cout << "User Height: " << bmi.height[j][i] << " cm\n";
    if (gen=='F'||gen=='f')
    {
        cout << "User Gender: Female\n";
    }
    else if (gen=='M'||gen=='m') 
    {
        cout << "User Gender: Male\n";
    }
    else 
    {
        cout << "Unknown\n";
    }
    cout << "User BMI: " << bmiscore << endl;
    if (bmiscore >= 0.0018 && bmiscore <= 0.0025)
            {
              cout << "BMI Category : Normal" << endl;
              cout << "Recommendation : Stay Fit and Healthy." << endl;
            }
          else if (bmiscore >= 0.0025 && bmiscore <= 0.0030)
            {
              cout << "BMI Category : Overweight" << endl;
              cout << "Recommendation : Increase Your Protein Consumption To Help Build Muscle." << endl;
            }
          else if (bmiscore > 0.0030)
            {
              cout << "BMI Category : Obesity" << endl;
              cout << "Recommendation : Eat More Vegetables and Fruits, Also Add More Grain." << endl;
            }
          else if (bmiscore < 0.0018)
            {
              cout << "BMI Category : Underweight" << endl;
              cout << "Recommendation : Increase Your Carbs and Protein Consumption." << endl;
            }
    
    
    cout << "\n\nEnter any key(s) to exit: ";
    cin >> key;
}

void bmi_calculate(bmi_count &bmi)
{
    string key;
    int i,j;
    char gen;
    cout << "\nBody Data Input\n" << "-------------------\n\n";
    cout << "Please Select The Month (1-12): ";
    cin >> j;
    cout << "Please Select The Date (1-31): ";
    cin >> i;
    if (i<1||i>31||j<1||j>12)
    {
        cout << "Invalid Month or Date! \n\n";
        return bmi_calculate(bmi);
    }
    
    i-=1;j-=1;
    
    cout << "\nPlease Enter The Following Info: \n\n";
    cout << "Input Weight (kg) : ";
    cin >> bmi.weight[j][i];
    cout << "Input Height (cm) : ";
    cin >> bmi.height[j][i];
    cout << "Input Gender (M/F): ";
    cin >> gen;
    gen=bmi.gender[j][i];
    cout << "Enter any key(s) to exit: ";
    cin >> key;
}


void bmi_menu(bmi_count &bmi)
{
    char choice_3;
    string key;
    
    cout << "\nBMI (Body Mass Index)\n";
    cout << "==================\n\n";
    cout << "1. Enter Body Data\n" << "2. BMI Info\n" << "3. Return to Main Menu\n";
    cout << "Please Choose The Option (1-3): ";
    cin >> choice_3;
    
    switch (choice_3)
    {
        case '1':
            bmi_calculate(bmi);
            bmi_menu(bmi);
            break;
        case '2':
            bmi_info(bmi);
            bmi_menu(bmi);
            break;
        case '3':
            return;
        default:
            cout << "Invalid input! " << endl;
            bmi_menu(bmi);
    }
}


void sleep_tracker(sleep_track &sleep)
{
    string key;
    int i,j,k;
    cout << "\nSleep Tracker Input\n" << "-------------------\n\n";
    cout << "Please Select The Month (1-12): ";
    cin >> j;
    cout << "Please Select The Date (1-31): ";
    cin >> i;
    if (i<1||i>31||j<1||j>12)
    {
        cout << "Invalid Month or Date! \n\n";
        return sleep_tracker(sleep);
    }
    
    i-=1;j-=1;
    
    string feelings[4]={"Restful","Neutral","Restless","Irritated"};
    
    cout << "\nPlease Enter The Following Info: \n\n";
    cout << "Input Hour of Sleep Time (0-24): ";
    cin >> sleep.sleep_hour[j][i];
    cout << "Input Minute of Sleep Time (0-59): ";
    cin >> sleep.sleep_minute[j][i];
    if (sleep.sleep_hour[j][i]<0||sleep.sleep_hour[j][i]>24||sleep.sleep_minute[j][i]>59)
    {
        cout<<"The Entered Value is Invalid, Please Try Again! \n";
        sleep_tracker(sleep);
    }
    cout << "What Do You Feel That Night? (1. Restful 2. Neutral 3. Restless 4. Irritated): ";
    cin >> k;
    if (k<=0||k>4)
    {
        cout << "The Entered Value is Invalid, Please Try Again! \n";
        sleep_tracker(sleep);
    }
    sleep.feeling[j][i]=feelings[k-1];
    cout << "Enter any key(s) to exit: ";
    cin >> key;
}
    
void sleep_info (sleep_track &sleep)
{
    string key;
    int i,j,sleep_point=100,minute;
    cout << "\nSleep Tracker Info Info \n" << "---------------------\n\n";
    cout << "Please Select The Month (1-12): ";
    cin >> j;
    cout << "Please Select The Date (1-31): ";
    cin >> i;
    
    if (i<1||i>31||j<1||j>12)
    {
        cout << "Invalid Month or Date! \n\n";
        return sleep_info(sleep);
    }
    
    i-=1;j-=1;
    cout << endl;
    cout << "I Slept For " << sleep.sleep_hour[j][i] << " Hours and "
    <<sleep.sleep_minute[j][i] << " Minutes" << endl;
    cout << "While Asleep, I Feel " << sleep.feeling[j][i] << endl;
    minute=(sleep.sleep_hour[j][i]*60)+sleep.sleep_minute[j][i];
    if (minute<480&&minute>0)
        sleep_point=100*minute/480;
    cout << "Sleeping Points: " << sleep_point << endl;
    if (minute>=480)
        cout << "You Sleep Adequately :), Please Mantain Your Sleeping Habbit ";
    else if (minute<480&&minute>=360)
        cout << "You Are Slightly Lacking Sleep, Please Try to Aim For 8 Hours";
    else
        cout << "You Are Sleep Deprived :(, Please Add Your Sleep Yime Immediately and Aim For 8 Hours";
    cout << "\n\nEnter any key(s) to exit: ";
    cin >> key; 
}

void sleep_tracker_menu(sleep_track &sleep)
{
    char choice_2;
    string key;
    
    cout << "\nSLEEP TRACKER\n";
    cout << "==============\n\n";
    cout << "1. Enter Sleep Time\n" << "2. Sleep Info\n" << "3. Return to Main Menu\n";
    cout << "Please Choose The Option (1-3): ";
    cin >> choice_2;
    
    switch (choice_2)
    {
        case '1':
            sleep_tracker(sleep);
            sleep_tracker_menu(sleep);
            break;
        case '2':
            sleep_info(sleep);
            sleep_tracker_menu(sleep);
            break;
        case '3':
            return;
        default:
            cout << "Invalid input! " << endl;
            sleep_tracker_menu(sleep);
    }
}

void step_counter(step_count & step)
{
    string key;
    int i,j;
    cout << "\nStep Counter Input\n" << "-------------------\n\n";
    cout << "Please Choose The Month (1-12): ";
    cin >> j;
    cout << "Please Choose The Date (1-31): ";
    cin >> i;
    
    if (i<1||i>31||j<1||j>12)
    {
        cout << "Invalid Month or Date! \n\n";
        return step_counter(step);
    }
    
    i-=1;j-=1;
    cout << "\nPlease Enter The Following Info: \n\n";
    cout << "Number of Step: ";
    cin >> step.step_num[j][i];
    cout << "Body Weight (kg): ";
    cin >> step.weight[j][i];
    step.calories[j][i]=step.step_num[j][i]*step.weight[j][i]/72.6*0.04;
    step.distance[j][i]=step.step_num[j][i]*0.001524;
    cout << "Enter any key(s) to exit: ";
    cin >> key;
}

void step_counter_info(step_count &step)
{
    string key;
    int i,j;
    cout << "\nStep Counter Info \n"<<"------------------\n\n";
    cout << "Please Select The Month (1-12): ";
    cin >> j;
    cout << "Please Select The Date (1-31): ";
    cin >> i;
    
    if (i<1||i>31||j<1||j>12)
    {
        cout << "Invalid Month or Date! \n\n";
        return step_counter_info(step);
    }
    
    i-=1;j-=1;
    cout << endl;
    cout << "Number of Steps: " << step.step_num[j][i] << endl;
    cout << "User Body Weight: " << step.weight[j][i] << " kg" << endl;
    cout << "Calories Burned: " << step.calories[j][i] << endl;
    cout << "Distance Travelled: " << step.distance[j][i] << " km" << endl;
    cout << "Enter any key(s) to exit: ";
    cin >> key;
}

void step_counter_menu(step_count &step)
{
    char choice;
    string key;
    
    cout << "\nSTEP COUNTER\n";
    cout << "============\n\n";
    cout << "1. Enter Step Count\n" << "2. Step Count Info\n" << "3. Return to Main Menu\n";
    cout << "Please Choose the Option (1-3): ";
    cin >> choice;
    
    switch (choice)
    {
        case '1':
            step_counter(step);
            step_counter_menu(step);
            break;
        case '2':
            step_counter_info(step);
            step_counter_menu(step);
            break;
        case '3':
            return;
        default:
            cout << "Invalid input! " << endl;
            step_counter_menu(step);
    }
}

void userprofile(userid user_info)
{
    string key;
    cout << "\nYour Profile \n-------------\n\n";
    cout << "Name: " << user_info.name<<endl;
    cout << "Username: " << user_info.username<<endl;
    cout << "Email: " << user_info.email<<endl;
    cout << "Password: " << user_info.password<<endl;
    cout << "Account Number: " << user_info.account_no<<endl;
    cout << "Enter any key(s) to exit: ";
    cin >> key;
    
}

void help_screen()
{
    char temp;
    cout<<"\nHelp Screen\n";
    cout<<"------------\n\n";
        cout << "A. Sign Up and Log In" << endl;
        cout << "1. Sign up to create your GamaFit Account by filling the required data." << endl;
        cout << "2. Log in to your GamaFit account by filling your Username / Email and Password." << endl;
        cout << endl;
        cout << "B. Main Menu" << endl;
        cout << "1. Your Profile: Displays Your Account Information." << endl;
        cout << "2. Step Counter: Displays Your Step Counts, Distance Travelled, and Calories Burned." << endl;
        cout << "3. Sleep Tracker: Displays Your Sleep Time, Sleep Points, Feelings, and Feedback." << endl;
        cout << "4. Body Mass Index: Displays Your Weight, Height, BMI Results and Category, also a Feedback." << endl;
        cout << "5. Log Out: Ends the Program." << endl;
        cout << endl;
    cout<<"Enter any key(s) to continue: ";
    cin>>temp;
}

int terminate_program()
{
    cout<<"Bye";
    return 0;
}

void mainscreen(userid &user_info, step_count &step, sleep_track &sleep, bmi_count &bmi)
{
        char option,option_quit;
        string EnterStr;
        cout << endl << "MAIN MENU\n";
        cout << "==========\n\n";
        cout << "1. Your Profile" << endl;
        cout << "2. Step Counter" << endl;
        cout << "3. Sleep Tracker" << endl;
        cout << "4. Body Mass Index" << endl;
        cout << "5. Help" << endl;
        cout << "6. Quit Program" << endl;
        cout << "\nSelect Options (1-5): ";
        cin >> option;
        
    switch (option)
    {
        case '1':
            userprofile(user_info);
            mainscreen(user_info, step, sleep, bmi);
            break;
        case '2':
            step_counter_menu(step);
            mainscreen(user_info, step, sleep, bmi);
            break;
        case '3':
            sleep_tracker_menu(sleep);
            mainscreen(user_info, step, sleep, bmi);
            break;
        case '4':
            bmi_menu(bmi);
            mainscreen(user_info, step, sleep, bmi);
            break;
        case '5':
            help_screen();
            mainscreen(user_info, step, sleep, bmi);
            break;
        case '6':
            cout << "\nAre you sure you want to quit this program? (´･_･`)\n";
            cout << "Press (y) to quit or press any key(s) to cancel: ";
            cin >> option_quit;
            if (option_quit=='y')
            {
                cout << endl;
                cout << "Thank You For Using Our Service, Stay Healthy and Stay Safe (^▽^)";
                break;
            }
            else
                mainscreen(user_info, step, sleep, bmi);
        default:
            cout << "Invalid Input" << endl;
            mainscreen(user_info, step, sleep, bmi);
            break;
    }
}

void login(userid &user_info)
{
    bool check=false;
    string username_input,pass_input;
    cout << "\nPlease Login \n";
    cout << "-------------\n\n";
    while (!check)
    {
        cout << "Username or Email: ";
        cin >> username_input;
        cout << "Password: ";
        cin >> pass_input;
        
    if((username_input==user_info.username||username_input==user_info.email)&&pass_input==user_info.password)
        check=true;
    else
    {
        cout << "Your Input of Username or Email or Password Is Wrong! \n\n";
        login(user_info);
    }
        break;
    }
}

void signup (userid &user_info)
{
    cout << "\nWelcome to GamaFit, Please Register to Enter \n";
    cout << "--------------------------------- \n\n";
    cout << "Enter Name: ";
    getline(cin,user_info.name);
    cout << "Enter Username: ";
    cin >> user_info.username;
    cout << "Enter Email: ";
    cin >> user_info.email;
    cout << "Enter Password: ";
    cin >> user_info.password;
   
    user_info.account_no=(rand()%90000000)+100000000;
    login(user_info);
}

int main()
{
    signup(user_info);
    mainscreen(user_info, step,sleep,bmi);
    return 0;
}

