// AARON LUDWIG A. ALTAR 
// CPE2A 11-7-24
// TRAIN LAW MODIFIED WITH PHILHEALTH AND NET SALARY

#include <iostream>
#include <string>
using namespace std;

string payment1 = "Your tax to be paid is: ";
string payment2 = "Your PhilHealth contribution is: ";
string payment3 = "Your Net Salary is: ";
double monthlyIncome, annualIncome, tax;

void computeTax() {
    const int taxExemption = 250000; // Tax exemption threshold (annual)
    const double taxCase1 = 0.15; // 15% of the excess for income over 250,000
    const double taxCase2 = 0.20; // 22,500 + 20% of the excess for income over 400,000
    const double taxCase3 = 0.25; // 102,500 + 25% of the excess for income over 800,000
    const double taxCase4 = 0.30; // 402,500 + 30% of the excess for income over 2,000,000 
    const double taxCase5 = 0.35; // 2,202,500 + 35% of the excess for income over 8,000,000 

    // Calculate annual income
    annualIncome = monthlyIncome * 12;

    // Calculate the tax based on annual income
    if (annualIncome < 0) {
        cout << "Income cannot be negative!" << endl;
    } else if (annualIncome <= taxExemption) {
        tax = 0; // No tax for income below or equal to the exemption
    } else if (annualIncome <= 400000) {
        tax = (annualIncome - taxExemption) * taxCase1; // 15% of the excess over 250,000
    } else if (annualIncome <= 800000) {
        tax = 22500 + (annualIncome - 400000) * taxCase2; // 22,500 + 20% of the excess over 400,000
    } else if (annualIncome <= 2000000) {
        tax = 102500 + (annualIncome - 800000) * taxCase3; // 102,500 + 25% of the excess over 800,000
    } else if (annualIncome <= 8000000) {
        tax = 402500 + (annualIncome - 2000000) * taxCase4; // 402,500 + 30% of the excess over 2,000,000
    } else {
        tax = 2202500 + (annualIncome - 8000000) * taxCase5; // 2,202,500 + 35% of the excess over 8,000,000
    }

    // Output the monthly tax
    cout << payment1 << tax / 12 << endl; // Divide by 12 to get monthly tax
}

double computePhilHealthContribution() {
    double contribution;

    // Define PhilHealth contribution based on monthly income ranges
    if (monthlyIncome <= 10000) {
        contribution = 500; // Fixed amount for income up to 10,000
    } else if (monthlyIncome >=10000.01 && monthlyIncome <= 79999.99) {
        contribution = (monthlyIncome * 0.05); // 5% for income between 10,001 and 79,999
    } else {
        contribution = 5000; // for income above 80,000
    }

    return contribution / 2; // Assuming the employer pays half
}

double computeNetSalary() {
    double monthlyTax = tax / 12; // Monthly tax
    double philHealthContribution = computePhilHealthContribution(); // Get PhilHealth contribution
    return monthlyIncome - monthlyTax - philHealthContribution; // Calculate net salary after tax and PhilHealth deduction
}

int main() {
    // Ask the user for their monthly gross income
    cout << "Enter your gross monthly income (in PHP): ";
    cin >> monthlyIncome;

    // Call the function to compute the tax
    computeTax();

    // Compute PhilHealth contribution
    double philHealthContribution = computePhilHealthContribution();
    cout << payment2 << philHealthContribution << endl;

    // Compute Net Salary
    double netSalary = computeNetSalary();
    cout << payment3 << netSalary << endl;

    return 0;
}