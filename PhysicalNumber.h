 #include <iostream>
 #include "Unit.h"
using std::istream,std::ostream,std::istringstream;


 namespace ariel
 {
   class PhysicalNumber
   {
       private:

      Unit unit;
      double num;

       public:
    //constructors
    PhysicalNumber(double num,Unit unit);
    ~PhysicalNumber();
    double getNum();
    Unit getUnit();

// +,-,++,--,sign(+),sign(-),+=,-=,<<,>>,<,<=,>,>=,=

       PhysicalNumber operator+(const PhysicalNumber& other) const ;
       PhysicalNumber operator-(const PhysicalNumber& other) const ;

       
       PhysicalNumber operator-() const;
       PhysicalNumber operator+() const;

       //const PhysicalNumber& operator=(const PhysicalNumber& other); 
       const PhysicalNumber& operator+=(const PhysicalNumber& other);
       const PhysicalNumber& operator-=(const PhysicalNumber& other);

       const PhysicalNumber& operator++();
       const PhysicalNumber& operator--();

      PhysicalNumber operator++(int);
      PhysicalNumber operator--(int);


       bool operator ==(const  PhysicalNumber&  a)const;
       bool operator !=(const  PhysicalNumber&  a)const;
       bool operator <=(const  PhysicalNumber&  a)const;
       bool operator >=(const  PhysicalNumber&  a)const;  
       bool operator <(const  PhysicalNumber&  a)const;
       bool operator >(const  PhysicalNumber&  a)const;


       double convert(const PhysicalNumber &p1 , const PhysicalNumber &p2) const;


       friend ostream& operator<<(ostream& os, const PhysicalNumber& p);
       friend istream& operator>>(istream& is, PhysicalNumber& p);


   };


 };
