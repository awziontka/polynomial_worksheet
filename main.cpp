#include "polynomial.h"
#include "fraction.h"
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;

int main() {
    //Polynomial p1({c0,c1,c2,c3});
    ofstream file;
    file.open("worksheet.txt");
    int count=1;
    unsigned seed;
    int frac;
    
    Fraction c0=0,c1=0,c2=0,c3=0;
    while(count<20){
        //string res="null",res1="null",res2="null",res3="null";
        if(count==1){
                cout<<"designate seed:";
                cin>>seed;
        }
        srand(seed);
//        cout<<"do you want the first term to be a fraction?(y/n)";
//        cin>> res;
        frac=rand()%2;
        if (frac==1){
            long n=rand()% 100+1;
            long d=rand()% 100+1;
            c0 = Fraction(n,d);
        }
        else
            c0 = rand()% 100;
//        cout<<"do you want the second term to be a fraction?(y/n)";
//        cin>>res1;
        frac = rand()%2;
        if(frac==1){
            long n=rand()%100+1;
            long d=rand()%100+1;
            c1 = Fraction(n,d);
        }
        else
            c1 = rand()%100;
//        cout<<"do you want the third term to be a fraction?(y/n)";
//        cin>>res2;
        frac = rand()%2;
        if(frac==1){
            long n=rand()%100+1;
            long d=rand()%100+1;
            c2 = Fraction(n,d);
        }
        else
            c2 = rand()%100;
//        cout<<"do you want the last term to be a fraction?(y/n)";
//        cin>>res3;
        frac = rand()%2;
        if(frac==1){
            long n=rand()%100+1;
            long d=rand()%100+1;
            c3 = Fraction(n,d);
        }
        else
            c3 = rand()%100;
        Polynomial p1({c0,c1,c2,c3});
        
        string ans = p1.poly_to_string();
        cout<<ans<<endl;
        file<<ans;
        file<<"\n";
        file<<"\n";
        count++;
        seed++;
    }
        file.close();
            
            
        
    /*cout << "p1 as string: " << p1.poly_to_string() << endl;
    cout << "p2 as string: " << p2.poly_to_string() << endl << endl;
  
    cout << "p1(1/2): " << p1.evaluate(Fraction(1, 2)) << endl << endl;

    auto deriv_p1 = p1.derivative();
    cout << "p1.derivative(): " << deriv_p1.poly_to_string() << endl;
    auto deriv_p2 = p2.derivative();
    cout << "p2.derivative(): " << deriv_p2.poly_to_string() << endl<<endl;

    auto indef_integral_p1 = p1.integral();
    cout << "p1.integral(): " << indef_integral_p1.poly_to_string() << endl;
    auto indef_integral_p2 = p2.integral();
    cout << "p2.integral(): " << indef_integral_p2.poly_to_string() << endl<<endl;

    auto def_integral = p1.integral(Fraction(3, 4), Fraction(7, 2));
    cout << "p1.integral(3/4, 7/2): " << def_integral << endl << endl;*/
}

/*int main(){
    Polynomial p1({0,2,0});
    cout<<"p1 as string: "<<p1.poly_to_string()<<endl;
    cout<<p1.evaluate(4);
}*/
