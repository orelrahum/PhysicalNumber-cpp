
#include <iostream>
#include <sstream>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace std;
using namespace ariel;

///////////////Constructor/////////////
PhysicalNumber::PhysicalNumber(double mynum, Unit myunit)
{
    num = mynum;
    unit = myunit;
}

//////////////// operations +, -, +=, -=, ==, !=/////////////

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &other) const
{
    double res = convert(*this, other); 
    return PhysicalNumber(this->num + res, this->unit);
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &other) const
{
    double res = convert(*this, other); 
    return PhysicalNumber(this->num - res, this->unit);
}


PhysicalNumber PhysicalNumber::operator-() const { return PhysicalNumber(-num, unit); }

PhysicalNumber PhysicalNumber::operator+() const { return PhysicalNumber(num, unit); }


 PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &other)
{
    double res = convert(*this, other); 
    this->num = this->num + res;
    return *this;
}

 PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &other)
{
    double res = convert(*this, other); 
    this->num = this->num - res;
    return *this;

}

bool PhysicalNumber::operator==(const PhysicalNumber &value) const
{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->num == number;
}

bool PhysicalNumber::operator!=(const PhysicalNumber &value) const
{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->num != number;
}

////////////////operations ++, -- ///////////////////

 PhysicalNumber &PhysicalNumber::operator++()
{
    num++;
    return *this;
}

 PhysicalNumber &PhysicalNumber::operator--()
{
    num--;
    return *this;
}

PhysicalNumber PhysicalNumber::operator++(int)
{
    PhysicalNumber temp(*this);
    num++;
    return temp;
}

PhysicalNumber PhysicalNumber::operator--(int)
{
    PhysicalNumber temp(*this);
    num--;
    return temp;
}



////////////  Function that converts units  /////////////////

double PhysicalNumber::convert(const PhysicalNumber &first, const PhysicalNumber &second) const
{
    Unit l_unit = first.unit;
    Unit r_unit = second.unit;
    
    double l_val = first.num;
    double r_val = second.num;

    double result = 0;

    switch (r_unit)
    {
    case Unit::KM:

        if (l_unit == Unit::M) { result = r_val * 1000; }

        else if (l_unit == Unit::CM) { result = r_val * 100000; }

        else if (l_unit == Unit::KM) { result = r_val * 1; }

        else { throw std::invalid_argument("can't convert");}

        break;

    case Unit::M:

        if (l_unit == Unit::CM) { result = r_val * 100; }

        else if (l_unit == Unit::KM) { result = r_val / 1000; }

        else if (l_unit == Unit::M) { result = r_val * 1; }

        else { throw std::invalid_argument("can't convert"); }

        break;

    case Unit::CM:

        if (l_unit == Unit::M) { result = r_val / 100; }

        else if (l_unit == Unit::KM) { result = r_val / 100000; }

        else if (l_unit == Unit::CM) { result = r_val * 1; }

        else { throw std::invalid_argument("can't convert"); }

	break;

    case Unit::HOUR:

        if (l_unit == Unit::MIN) { result = r_val * 60; }
        
        else if (l_unit == Unit::SEC) { result = r_val * 3600; }
        
        else if (l_unit == Unit::HOUR) { result = r_val * 1; }
        
        else { throw std::invalid_argument("can't convert"); }
        
        break;

    case Unit::MIN:

        if (l_unit == Unit::HOUR) { result = r_val / 60; }
        
        else if (l_unit == Unit::SEC) { result = r_val * 60; }
        
        else if (l_unit == Unit::MIN) { result = r_val * 1; }
        
        else { throw std::invalid_argument("can't convert"); }
        
        break;

    case Unit::SEC:

        if (l_unit == Unit::MIN) { result = r_val / 60; }
        
        else if (l_unit == Unit::HOUR) { result = r_val / 3600; }
        
        else if (l_unit == Unit::SEC) { result = r_val * 1; }
        
        else { throw std::invalid_argument("can't convert"); }
        
        break;

    case Unit::TON:

        if (l_unit == Unit::KG) { result = r_val * 1000; }
        
        else if (l_unit == Unit::G) { result = r_val * 1000000; }
        
        else if (l_unit == Unit::TON) { result = r_val * 1; }
        
        else { throw std::invalid_argument("can't convert"); }
        
        break;

    case Unit::KG:

        if (l_unit == Unit::G) { result = r_val * 1000; }
        
        else if (l_unit == Unit::TON) { result = r_val / 1000; }
        
        else if (l_unit == Unit::KG) { result = r_val * 1; }
        
        else { throw std::invalid_argument("can't convert"); }
        
        break;

    case Unit::G:

        if (l_unit == Unit::TON) { result = r_val / 1000000; }
        
        else if (l_unit == Unit::KG) { result = r_val / 1000; }
        
        else if (l_unit == Unit::G) { result = r_val * 1; }
        
        else { throw std::invalid_argument("can't convert"); }
        
        break;

    default:

        throw std::invalid_argument("can't convert");
    }

    return result;
}


/////////////// operations <, >, <=, >= ///////////////////////

bool PhysicalNumber::operator<(const PhysicalNumber &value) const
{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->num < number;
}

bool PhysicalNumber::operator>(const PhysicalNumber &value) const
{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->num > number;
}

bool PhysicalNumber::operator<=(const PhysicalNumber &value) const
{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->num <= number;
}

bool PhysicalNumber::operator>=(const PhysicalNumber &value) const
{
    double number = 0;
    try { number = convert(*this, value); }
    catch (string e) { cerr << "Exception: Error in convert" << endl; }
    return this->num >= number;
}


//cin stream operator

istream &ariel::operator>>(istream &istream, PhysicalNumber &phy)
{
    string s;
    istream >> s;
    int pos1 = 0;
    int pos2 = 0;

    string ustring;
    int temp;
    double value;
    string typeUnit[9] = {"km", "m", "cm", "hour", "min", "sec", "ton", "kg", "g"};
    pos1 = s.find('[');
    pos2 = s.find(']');

    if ((pos1 != string::npos) && (pos2 != string::npos)) {

        ustring = s.substr(pos1 + 1, pos2 - pos1 - 1);
        bool flag = true;
        for (int i = 0; i < 9; i++)
        {
            if ((typeUnit[i] == ustring) && flag)
            {
                temp = i;
                flag = false;
            }
        }
        string value_s = s.substr(0, pos1);

        if (!flag)
        {
            try { value = stod(value_s); }
            catch (exception &e) {
                auto errorState = istream.rdstate(); 
                return istream; }

            phy.num = value;
            phy.unit = (Unit)temp;
        }
        else { auto errorState = istream.rdstate(); }
    }
    else { auto errorState = istream.rdstate(); }

return istream;
}


//cout stream operator
ostream &ariel::operator<<(ostream &os, const PhysicalNumber &p)
{
    switch (p.unit)
    {
    case Unit::KM:
    {
        os << p.num << "[km]";
        break;
    }
    case Unit::M:
    {
        os << p.num << "[m]";
        break;
    }
    case Unit::CM:
    {
        os << p.num << "[cm]";
        break;
    }
    case Unit::HOUR:
    {
        os << p.num << "[hour]";
        break;
    }
    case Unit::MIN:
    {
        os << p.num << "[min]";
        break;
    }
    case Unit::SEC:
    {
        os << p.num << "[sec]";
        break;
    }
    case Unit::TON:
    {
        os << p.num << "[ton]";
        break;
    }
    case Unit::KG:
    {
        os << p.num << "[kg]";
        break;
    }
    case Unit::G:
    {
        os << p.num << "[g]";
        break;
    }
    }
    return os;
}

