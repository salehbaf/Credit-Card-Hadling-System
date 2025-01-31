#ifndef SENECA_CC_H_
#define SENECA_CC_H_

#include <iostream>

namespace seneca {
   class CC {
   private:
       char* m_name = nullptr;  // holds credit card name 
       unsigned long long m_cardNo = 0;  //credit card number
       short m_expYear = 0;  //exp year
       short m_expMon = 0;   //exp month
       short m_cvv = 0;      //cvv

       
       bool validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const; //checks if cc is valid

       void prnNumber(unsigned long long no) const;// prints cc number and formats it 
       void display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const;// displays cc details 
      
      

   public:
       
       void cleanUp(); // clears memory and resets values
       bool isEmpty() const; // Checks if cc is empty
       void set(); // Resets the cc to an empty state
       void set(const char* name, unsigned long long number, short cvv, short expMon = 12, short expYear = 24); //sets cc info if valid
       void display() const; //shows cc details
   };
}

#endif // SENECA_CC_H_



