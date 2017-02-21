#include <cmath>
#include <vector>
using std::vector;
#include <string>
using std::string;
using std::ostringstream;
using std::istringstream;
#include <sstream>
#include <ostream>
#include <iostream>
using std::cout;
#include <set>
#include <iterator>
#include <algorithm>
using std::reverse;
#include "polynomial.h"
#include "fraction.h"


Polynomial::Polynomial(const vector<Fraction>& cfs){
    /*This function initializes the polynomial by assigning th members of the
     vector argument by imputting the into coefs.*/
    coefs=cfs;
}

string Polynomial::poly_to_string()const{
    /*This function takes the size of the polynomial to determine the power x
     will be raised to. It finds x power by subtracting 1 form the size.
     It first checks for the first term and then solves the rest of the terms.*/
    ostringstream oss; int count=0;
    bool zero=false;
    vector<Fraction> v=coefs;
    reverse(v.begin(), v.end());
    count=v.size();
    count-=1;int start=count; //Count subtracts by 1 to put powers in descending
    for(Fraction i:v){        //order.
        if(count==start){
            if(i==0)
                zero=true;
            
                if(count==0){
                    if(i>0)
                        oss<<i<<" ";
                    else if(i<0)
                        oss<<"-"<<abs(i)<<" ";
                    else if(i==0&&v.size()==1)
                        oss<<i;
                }
                else if(count==1){
                    if(abs(i)==1){
                        if(i<0)
                            oss<<"-x ";
                        else
                            oss<<"x ";
                    }
                    else if(i<0)
                        oss<<"-"<<abs(i)<<"x ";
                    else if(i==0&&v.size()==1)
                        oss<<i;
                    else if(i>1)               //Checks to prevent leading zeros
                        oss<<i<<"x ";
                    else if(abs(i)<1&&i!=0)
                        oss<<abs(i)<<"x ";
                }
                else if(count>=2){
                    if(abs(i)==1){
                        if(i<0)
                            oss<<"-x^"<<count<<" ";
                        else
                            oss<<"x^"<<count<<" ";
                    }
                    else if(i<0)
                        oss<<"-"<<abs(i)<<"x^"<<count<<" ";
                    else if(i>1)
                        oss<<i<<"x^"<<count<<" ";
                    else if(abs(i)<1&&i!=0)
                        oss<<abs(i)<<"x^"<<count<<" ";
                }
            count-=1;
            continue;
        }
        if (i==0){
            count-=1;
            continue;
        }
        if(count==0){
            if(i>0){
                if(zero==true){ //Prevents excess + or - signs.
                    zero=false; //turns off zero since it is only needed once.
                    oss<<i<<" ";
                }
                else
                    oss<<"+ "<<i<<" ";
            }
            else{
                if(zero==true){
                    zero==false;
                    oss<<"-"<<abs(i)<<" ";
                }
                else
                    oss<<"- "<<abs(i)<<" ";
            }
        }
        else if(count==1){
            if(i<0){
                if(zero==true){
                    zero==false;
                    oss<<"-";
                }
                else
                    oss<<"- ";
            }
            else if(i>0){
                if(zero==true)
                    zero==false;
                else
                    oss<<"+ ";
            }
            if(abs(i)==1)
                oss<<"x ";
            else if(abs(i)>1||abs(i)<1)
                oss<<abs(i)<<"x ";
        }
        else if(count>=2){
            if(i<0){
                if(zero==true){
                    zero==false;
                    oss<<"-";
                }
                else
                    oss<<"- ";
            }
            else if(i>0){
                if(zero==true)
                    zero=false;
                else
                    oss<<"+ ";
            }
            if(abs(i)==1)
                oss<<"x^"<<count<<" ";
            else if(abs(i)>1||abs(i)<1)
                oss<<abs(i)<<"x^"<<count<<" ";
        }
        count-=1;
    }
    return oss.str();
}

Fraction xpower(Fraction x, int power){
    /*This function determines the value of x when it is raised to a certain 
     power for a certain value of x. It will return this value to be used in
     evaluate.*/
    Fraction x1=x;
    if(power==0)
        return 1;
    else if(power==1)
        return x;
    else
        for(int i=2;i<=power;i++){
                x1*=x;
        }
        return x1;
}

Fraction Polynomial::evaluate(Fraction x)const{
    /*This function iterates through the coefficients of the polynomial and
     solves them, substituting x for whatever value is in the argument.*/
    Fraction result=0, x1;
    int count=0;
    for(Fraction i:coefs){
        x1=xpower(x,count);//Separate function called to solve for x when raised
        result+=(i*x1);
        count+=1;
    }
    return result;
}

Polynomial Polynomial::derivative()const{
    /*This function creates a new vector. The counter ensures that there is one
     less element so that the indexes are correct for the powers of x when
     printed.*/
    vector<Fraction> result;
    int count=0;
    for(Fraction i:coefs){
        if(count==0){
            count+=1;
            continue;
        }
        else if(count>=1)
            i*=count;
        count+=1;
        result.push_back(i);
    }
    return result;
}

Polynomial Polynomial::integral()const{
    /*This function creates a new vector as in Derivative. An extra 0 element is
     added, which will realign the coefficients with their correct indexes for
     the integral.*/
    vector<Fraction> result;
    result.push_back(0);//Pushback for the constant(defaulted to 0).
    Fraction count=1;//Count starts at 1 to compensate with pushback.
    for(Fraction i:coefs){
        if(i==0){
            count+=1;
        }
        else{
            i/=count;
            count+=1;
        }
        result.push_back(i);
    }
    return result;
}

Fraction Polynomial::integral(Fraction lower, Fraction upper)const{
    /*This function solves for the integral of a polynomial between a lower and
     upper bound by calling first the integral function followed by solving that
     new polynomial for the upper and lower bound by calling the evaluate
     function for each bound and then subtracting the lower value from the
     upper one.*/
    Fraction result=0,frac_low, frac_upp;
    Polynomial ind_poly=coefs;
    Polynomial i=ind_poly.integral();
    frac_low=i.evaluate(lower);
    frac_upp=i.evaluate(upper);
    result=frac_upp-frac_low;
    return result;
}