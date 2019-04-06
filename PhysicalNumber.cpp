
 # include <iostream>
 # include "PhysicalNumber.h"
 # include "Unit.h"



 using namespace std;
 using namespace ariel;

 PhysicalNumber::PhysicalNumber(double _num,Unit _unit)
 {
     num=_num;
     unit=_unit;
 }
 PhysicalNumber::~PhysicalNumber()
 {

 }
    double PhysicalNumber::getNum()
    {
        return num;
    }
    Unit PhysicalNumber::getUnit()
    {
        return unit;
    } 

       PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other) const 
       {
           return other;
       }
       PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other) const 
       {
           return other;
       }

       
       PhysicalNumber PhysicalNumber::operator-() const
       {
           return PhysicalNumber(-num,unit);
       }
       PhysicalNumber PhysicalNumber::operator+() const
       {
           return PhysicalNumber(num,unit);
       }

    //    const PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other) 
    //    {
    //        //add delete to .cpp
    //        return other;
    //    }

    
       const PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
       {
           return other;
       }
       const PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
       {
           return other;
       }

       const PhysicalNumber& PhysicalNumber::operator++()
       {
           num++;
           return *this;
       }
       const PhysicalNumber& PhysicalNumber::operator--()
       {
           num--;
           return *this;
       }

      PhysicalNumber PhysicalNumber::operator++(int)
      {
        //    PhysicalNumber temp(*this);
        //   num++;
        //   return temp;
          return *this;
      }
      PhysicalNumber PhysicalNumber::operator--(int)
      {
        //   PhysicalNumber temp(*this);
        //   num--;
        //   return temp;
        return *this;
      }

     

       bool PhysicalNumber::operator ==(const  PhysicalNumber&  a)const 
       {
           return true;
       }
       bool PhysicalNumber::operator !=(const  PhysicalNumber&  a)const
       {
           return true;
       }
       bool PhysicalNumber::operator <=(const  PhysicalNumber&  a)const 
       {
           return true;
       }
       bool PhysicalNumber::operator >=(const  PhysicalNumber&  a)const
       {
           return true;
       }
       bool PhysicalNumber::operator <(const  PhysicalNumber&  a)const 
       {
           return true;
       }
       bool PhysicalNumber::operator >(const  PhysicalNumber&  a)const
       {
           return true;
       }


    double PhysicalNumber::convert(const PhysicalNumber p1, const PhysicalNumber p2)
{
    double res = 0;
    double left_value = p2.num;
    double right_value = p1.num;

    Unit left_unit = p2.unit;
    Unit right_unit = p1.unit;

    switch (right_unit)
    {
    case Unit::KM:

        if (left_unit == Unit::M) // km to m
        {
            res = right_value / 1000;
        }
        else if (left_unit == Unit::CM) //km to cm
        {
            res = right_value / 100000;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::M:

        if (left_unit == Unit::CM) //m to cm
        {
            res = right_value / 100;
        }
        else if (left_unit == Unit::KM) //m to km
        {
            res = right_value * 1000;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::CM:

        if (left_unit == Unit::M) // cm to m
        {
            res = right_value * 100;
        }
        else if (left_unit == Unit::KM) // cm to km
        {
            res = right_value * 100000;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::HOUR:

        if (left_unit == Unit::MIN) // hour to min
        {
            res = right_value / 60;
        }
        else if (left_unit == Unit::SEC) // hour to sec
        {
            res = right_value / 3600;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::MIN:

        if (left_unit == Unit::HOUR) // min to hour
        {
            res = right_value * 60;
        }
        else if (left_unit == Unit::SEC) //min to sec
        {
            res = right_value / 60;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::SEC:

        if (left_unit == Unit::MIN) // sec to min
        {
            res = right_value * 60;
        }
        else if (left_unit == Unit::HOUR) // sec to hour
        {
            res = right_value * 3600;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::TON:

        if (left_unit == Unit::KG) //ton to kg
        {
            res = right_value / 1000;
        }
        else if (left_unit == Unit::G) //ton to g
        {
            res = right_value / 1000000;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::KG:

        if (left_unit == Unit::G) // kg to g
        {
            res = right_value / 1000;
        }
        else if (left_unit == Unit::TON) //kg to ton
        {
            res = right_value * 1000;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;
    case Unit::G:

        if (left_unit == Unit::TON) // g to ton
        {
            res = right_value * 1000000;
        }
        else if (left_unit == Unit::KG) // g to kg
        {
            res = right_value * 1000;
        }
        else
        {
            throw std::invalid_argument("can't convert");
        }
        break;

    default:

        throw std::invalid_argument("can't convert");
    }

    return res;
}


     ostream& ariel::operator<<(ostream& os, const PhysicalNumber& p)
       {
           return os;
       }
        istream& ariel::operator>>(istream& is, PhysicalNumber& p)
       {
           return is;
       }

      
