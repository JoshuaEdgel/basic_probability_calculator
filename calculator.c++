#include <iostream>
#include <cmath>

using namespace std;

void Calc();

double factorial(double n){
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

double Choose(double n, double r){
    double fact1 = factorial(n);
    double fact2 = factorial(r);
    double fact3 = factorial(n-r);
    double ans;
    ans = fact1 / (fact2 * fact3);
    return ans;
}

void Coin(double num, double head){
    double cho = Choose(num,head);
    double pows = pow(2,num);
    double ans = cho / pows;
    cout<<"The answer for " << head <<" heads in "<< num <<" tosses is "<< ans << " or " << ans*100 << "%" <<"\n";
}

double BiPDF(double num, double des, double prob){
    double cho = Choose(num, des);
    double pro = 1-prob;
    double ans = cho*(pow(prob,des))*(pow((pro),(num-des)));
    return ans;
}

double BiCDF(double num, double des, double prob){
    double ans;
    for(int i = 0; i < des; i ++) {
        ans += BiPDF(num, i, prob);
    }
    return ans;
}

double NBiCDF(double num, double des, double prob){
    double ans;
    for(int i = 0; i < des; i ++) {
        ans += BiPDF(num, i, prob);
    }
    ans = 1 - ans;
    return ans;
}

bool isValid(double one, double two){
    if(one < 0 || two < 0 || one < two){
        return false;
    }
    return true;
}

bool isValid(double one, double two, double three){
    if(one < 0 || two < 0 || one < two || three > 1 || three <= 0){
        return false;
    }
    return true;
}

void Restart(){
    cout<<"\n";
    cout<<"\n";
    cout<<"I am sorry you inputed something that is incorrect \n";
    cout<<"You are now being put back to the beginning of the program \n";
    Calc();
}

void Continue(){
    cout<<"\n";
    cout<<"Would you like to use the calculator again?\n";
    cout<<"1: YES                                0: NO\n";
    int con;
    cin >> con;

    if(con == 1) {
        Calc();
    }

}

void DisFact(){
    cout<<"\n";
    cout<<"n! = n * (n-1) * (n-2) * ... * 1\n";
    cout<<"n = a number (ex. 3! = 6). \n";
}

void DisCoin(){
    cout<<"\n";
    cout<<"      (n)      \n";
    cout<<"      (k)      \n";
    cout<<"   ---------   \n";
    cout<<"      2^n      \n";
    cout<<"n = desired amount \n";
    cout<<"k = total tries \n";
}

void DisBiCo(){
    cout<<"\n";
    cout<<" (n) =        n!        \n";
    cout<<" (k)    ----------------\n";
    cout<<"           k! * (n-k)!  \n";
    cout<<"n = desired amount \n";
    cout<<"k = total tries \n";
}

void DisBiPDF(){
    cout<<"\n";
    cout<<"(n) * x^(k) * a^(n-k)\n";
    cout<<"(k)                  \n";
    cout<<"n = desired amount \n";
    cout<<"k = total tries \n";
    cout<<"x = probability of success (ex. 0.6)\n";
    cout<<"a = probability of failure (ex. 0.4)\n";
}

void DisBiCDF(){
    cout<<"\n";
    cout<<"SUM(n to k)(n) * x^(k) * a^(n-k)\n";
    cout<<"           (k)                  \n";
    cout<<"n = desired amount \n";
    cout<<"k = total tries \n";
    cout<<"x = probability of success (ex. 0.6)\n";
    cout<<"a = probability of failure (ex. 0.4)\n";
}

void DisNBiCDF(){
    cout<<"\n";
    cout<<"(1 - SUM(n to k)(n) * x^(k) * a^(n-k))\n";
    cout<<"                (k)                  \n";
    cout<<"n = desired amount \n";
    cout<<"k = total tries \n";
    cout<<"x = probability of success (ex. 0.6)\n";
    cout<<"a = probability of failure (ex. 0.4)\n";
}

void Explanation(){
    cout<<"\n";
    cout<<"The purpose of this program is to help people understand and solve basic probability/statics problems. \n";
    cout<<"1: solves a basic coin flip problem. \n";
    cout<<"2: will do a basic choose problem. (ex. n choose k)";
    cout<<"3: solves a binomial (two option) probability, \n";
    cout<<"that the probabilty can be altered on (ex. 5 successes in 10 trys, with 0.6 chance of winning)\n";
    cout<<"4: solves a binomial probability for a sum of successes (ex. X>=x, 5-10 successes in 10 trys, with 0.6) \n";
    cout<<"5: solves a binomial probability for a sum of successes (ex. X<=x, 1-5 successes in 10 trys, with 0.6) \n";
    cout<<"6-11: Will display the specified formula. \n";
    cout<<"12: Brings you to this menu!\n";
    Continue();
}




void Calc(){
    cout<<"\n";
    cout<<"Welcome to my Probability Calculator \n";
    cout<<"Select which formula you want to use: \n";
    cout<<"1: Probability of exact Heads with X coins: \n";
    cout<<"2: Binomial coefficient function: \n";
    cout<<"3: Exact Binomail PDF P(X=x): \n";
    cout<<"4: At Most Binomial CDF P(X>=x): \n";
    cout<<"5: At Least Binomial CDF P(X<=x): \n";
    cout<<"6: Displays factorial formula: \n";
    cout<<"7: Displays coin formula: \n";
    cout<<"8: Displays binomial coeficient formula: \n";
    cout<<"9: Displays binomial PDF: \n";
    cout<<"10: Displays binomial CDF P(X<=x): \n";
    cout<<"11: Displays Binomial CDF P(X>=x): \n";
    cout<<"12: Help menu: \n";
    cout<<"\n";


    int ans;
    cin >> ans;
    if(ans == 1){
        cout<<"How many coins are being tossed? \n";
        double num;
        cin >> num;
        cout<<"How many Heads are desired? \n";
        double head;
        cin >> head;
        if(isValid(num, head)) {
            Coin(num, head);
            Continue();
        }
        else{
            Restart();
        }

    }
    else if(ans == 2){
        cout<<"How many are we choosing from: \n";
        double num1;
        cin >> num1;
        cout<<"How many successes do you want? \n";
        double num2;
        cin >> num2;
        if(isValid(num1, num2)){
            double sol = Choose(num1,num2);
            cout<<"Out of " << num1 << " we want " << num2 << " the answer is " << sol <<"\n";
            Continue();
        }
        else{
            Restart();
        }
    }
    else if(ans == 3){
        cout<<"How many are we choosing from: \n";
        double num1;
        cin >> num1;
        cout<<"How many successes do you want? \n";
        double num2;
        cin >> num2;
        cout<<"What is the probability of success? \n";
        double num3;
        cin >> num3;
        if(isValid(num1, num2, num3)){
            double ans = BiPDF(num1, num2, num3);
            cout<<"The answer for " << num1 <<" choose "<< num2 <<" with probability "<< num3 << " is " << ans  << " or " << ans*100 << "%" <<"\n";
            Continue();
        }
        else{
            Restart();
        }
    }
    else if(ans == 4){
        cout<<"How many are we choosing from: \n";
        double num1;
        cin >> num1;
        cout<<"How many successes do you want? \n";
        double num2;
        cin >> num2;
        cout<<"What is the probability of success? \n";
        double num3;
        cin >> num3;
        if(isValid(num1, num2, num3)){
            double ans = BiCDF(num1, num2, num3);
            cout<<"The answer for " << num1 <<" choose "<< num2 <<" with probability "<< num3 << " is " << ans  << " or " << ans*100 << "%" <<"\n";
            Continue();
        }
        else{
            Restart();
        }
    }
    else if(ans == 5){
        cout<<"How many are we choosing from: \n";
        double num1;
        cin >> num1;
        cout<<"How many successes do you want? \n";
        double num2;
        cin >> num2;
        cout<<"What is the probability of success? \n";
        double num3;
        cin >> num3;
        if(isValid(num1, num2, num3)){
            double ans = NBiCDF(num1, num2, num3);
            cout<<"The answer for " << num1 <<" choose "<< num2 <<" with probability "<< num3 << " is " << ans  << " or " << ans*100 << "%" <<"\n";
            Continue();
        }
        else{
            Restart();
        }
    }
    else if(ans == 6){
        DisFact();
        Continue();
    }
    else if(ans == 7){
        DisCoin();
        Continue();
    }
    else if(ans == 8){
        DisBiCo();
        Continue();
    }
    else if(ans == 9){
        DisBiPDF();
        Continue();
    }
    else if(ans == 10){
        DisBiCDF();
        Continue();
    }
    else if(ans == 11){
        DisNBiCDF();
        Continue();
    }
    else if(ans == 12){
        Explanation();
        Continue();
    }
    else{
        cout<<"\n";
        cout<<"Incorrect input";
        Continue();
    }
}

int main()
{
    Calc();

    return 0;
}