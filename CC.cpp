#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);

     }
   void CC::cleanUp() {
       freeMem(m_name); // frees memory for name 
       m_name = nullptr;  //prevents dangling pointer 
       m_cardNo = 0; // resets card number
       m_cvv = 0;  //reset cvv
       m_expMon = 0;  //reset expiry month 
       m_expYear = 0;  // reset expiry year 
   }

   
       
   
   bool CC::isEmpty() const {
       return m_name == nullptr; //checks if name is not null
   }

   void CC::set() {
       m_name = nullptr;  // sets to default state 
       m_cardNo = 0;
       m_cvv = 0;
       m_expMon = 0;
       m_expYear = 0;
   }

   
   void CC::set(const char* name, unsigned long long number, short cvv, short expMon, short expYear) {
       cleanUp(); // reset before assigning new values

       if (validate(name, number, cvv, expMon, expYear)) {
           alocpy(m_name, name); // copy name dynamically
           m_cardNo = number; // stores card number 
           m_cvv = cvv; // stores cvv
           m_expMon = expMon; // stores expiry month 
           m_expYear = expYear; // stores expiry year 
       }
   }

   void CC::display() const {
       if (isEmpty()) {
           cout << "Invalid Credit Card Record" << endl; // means therses no data 
       }
       else {
           this->display(m_name, m_cardNo, m_expYear, m_expMon, m_cvv); //if there is display details 
       }
   }
  //sets vvalidation condtion if it doesnt meet the requirement print error if it does return the details 
   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
       if (!name || strlen(name) < 3) return false;  //if name is less than 3 charaters invalid: names to short 
       if (cardNo < 4000000000000000ull || cardNo > 4099999999999999ull) return false; //invalid cc number
       if (cvv < 100 || cvv > 999) return false; //invalid cvv number 
       if (expMon < 1 || expMon > 12) return false; //onvalid month
       if (expYear < 24 || expYear > 32) return false; //invalis year 
       return true;
   }
   
   

   
   

}