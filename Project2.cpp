/*
Spencer Askine
CS-210
2/1/2023
*/

#include <iomanip>
#include<iostream>

using namespace std;

//Calculating yearly interest without monthly compounding monthly and without additional contributions 
double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {

//For loop to count out the years the user has specified and calculate interested earned and total balance 
  for(int i = 0; i < numberOfYears; i++){
    //Formula for calculating interested earned for the year
    double yearEndEarnedInterest = initialInvestment / (100/interestRate);
    //Formula for calculating total investment after interest
    double yearEndBalance = initialInvestment + yearEndEarnedInterest;
    
    
    //Output for the user to see total interested earned and their new balance every year
    cout << setw(10) << setfill(' ') << (i+1) << setw(20) << "$" << fixed << setprecision(2) << yearEndBalance << setw(30) << "$" << fixed << setprecision(2) << yearEndEarnedInterest << endl;

    initialInvestment = yearEndBalance;

  }


  return initialInvestment;

}

//Calculating interest that is compounded monthly and with additional monthly deposits 
double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears){

//define variables
double yearEndBalance;
yearEndBalance = initialInvestment;
//For loop to count out the years the user has specified and calculate interested earned and total balance 
for(int j = 0; j < numberOfYears; j++){
  double totalInterest = 0;
  //For loop to calculate the interest monthly within each year 
  for (int h = 0; h < 12; h++){

    //Formula for one months worth of interest
    double monthlyInterest = (yearEndBalance + monthlyDeposit) * ((interestRate / 100) /  12);

    //total interest for the year
    totalInterest += monthlyInterest;
    //total balance at the end of the year
    yearEndBalance =  yearEndBalance + monthlyDeposit + monthlyInterest;




  }

  //Output for the user to see total interested earned and their new balance every year
  cout << setw(10) << setfill(' ') << (j+1) << setw(20) << "$" << fixed << setprecision(2) << yearEndBalance << setw(30) << "$" << fixed << setprecision(2) << totalInterest << endl;
// return the ending balance
}
return initialInvestment;
}


//Main function
int main(){
    //define variables
    double initialInvestment, monthlyDeposit, interestRate, numMonths;
    int numberOfYears;

    //display menu screen for the user
    cout << "****************************************\n";
    cout << "************** Data Input **************\n";
    cout << "Initial Investment Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of years: \n";

    //Wait for user input to continue
    system("PAUSE");

    //Display menu again with symbols and collect user input
    cout << "****************************************\n";
    cout << "************** Data Input **************\n";
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << "Annual Interest: %";
    cin >> interestRate;
    cout << "Number of years: ";
    cin >> numberOfYears;

    //Wait for user input to continue
    system("PAUSE");

    //Print out a readable userfriendly table for interest and total balance when there are no monthly deposits and compounded yearly
    cout << endl;
    cout << setw(69) << "Balance and Interest Without Additional Monthly Deposits\n";
    cout << "================================================================================\n";
    cout << setw(10) << setfill(' ') << "Year" << setw(30) << setfill(' ') << "Year End Balance" << setw(40) << setfill(' ') << "Year End Earned Interest\n";
    cout << "--------------------------------------------------------------------------------" << endl;
    calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);

    //space between the tables
    cout << endl;
    cout << endl;

    //Print out a readable userfriendly table for interest and total balance when there are monthly deposits and compounded monthly
    cout << setw(69) << "Balance and Interest With Additional Monthly Deposits\n";
    cout << "================================================================================\n";
    cout << setw(10) << setfill(' ') << "Year" << setw(30) << setfill(' ') << "Year End Balance" << setw(40) << setfill(' ') << "Year End Earned Interest\n";
    cout << "--------------------------------------------------------------------------------" << endl;
    balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
}




