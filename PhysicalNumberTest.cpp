
#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
  PhysicalNumber a(2, Unit::KM);
  PhysicalNumber b(300, Unit::M);
  PhysicalNumber c(2, Unit::HOUR);
  PhysicalNumber d(30, Unit::MIN);
 
  PhysicalNumber e(3.2,Unit::KM);
  PhysicalNumber f(80,Unit::M);
  PhysicalNumber g(20, Unit::CM);

  PhysicalNumber h(90, Unit::SEC);
  PhysicalNumber i(40, Unit::MIN);
  PhysicalNumber j(1, Unit::HOUR);

  PhysicalNumber k(100, Unit::G);
  PhysicalNumber l(5.3, Unit::KG);
  PhysicalNumber m(7, Unit::TON);
   
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

  .setname("Basic output- km,m,cm")
  .CHECK_OUTPUT(e, "3.2[km]")
  .CHECK_OUTPUT(f, "80[m]")
 
  .setname("Compatible dimensions- km,m,cm")
  .CHECK_OUTPUT(-e,"-3.2[km]")
  .CHECK_OUTPUT(-f, "-80[m]")
  .CHECK_OUTPUT(+e,"3.2[km]")
  .CHECK_OUTPUT(+f, "80[m]")
  .CHECK_OUTPUT(++e,"4.2[km]")
  .CHECK_OUTPUT(++f, "81[m]")
  .CHECK_OUTPUT(--e,"3.2[km]")
  .CHECK_OUTPUT(--f, "80[m]")

  .CHECK_OK(e++)
  .CHECK_OUTPUT(e,"4.2[km]")
  .CHECK_OK(f++)
  .CHECK_OUTPUT(f, "81[m]")
  .CHECK_OK(e--)
  .CHECK_OUTPUT(e,"3.2[km]")
  .CHECK_OK(f--)
  .CHECK_OUTPUT(f, "80[m]")

  .CHECK_OUTPUT((e+=f),"3.28[km]")  //--> e=3.28 km
  .CHECK_OUTPUT(e,"3.28[km]")
  .CHECK_OUTPUT(e+e,"6.56[km]")
  .CHECK_OUTPUT(f-f,"0[m]")
  .CHECK_EQUAL(f<e,true)

  


  .setname("Incompatible dimensions- km,m,cm -- (+,-,+=,-=,<,>,<=,>=)")
  .CHECK_THROWS(e+h) .CHECK_THROWS(e+i) .CHECK_THROWS(e+j) .CHECK_THROWS(e+k)
  .CHECK_THROWS(e+l) .CHECK_THROWS(e+m) .CHECK_THROWS(f+h) .CHECK_THROWS(f+i)
  .CHECK_THROWS(f+j) .CHECK_THROWS(f+k) .CHECK_THROWS(f+l) .CHECK_THROWS(f+m)
  
  .CHECK_THROWS(e+=h) .CHECK_THROWS(e+=i) .CHECK_THROWS(e+=j) .CHECK_THROWS(e+=k)
  .CHECK_THROWS(e+=l) .CHECK_THROWS(e+=m) .CHECK_THROWS(f+=h) .CHECK_THROWS(f+=i) 
  .CHECK_THROWS(f+=j) .CHECK_THROWS(f+=k) .CHECK_THROWS(f+=l) .CHECK_THROWS(f+=m)

  .CHECK_THROWS(e-h) .CHECK_THROWS(e-i) .CHECK_THROWS(e-j) .CHECK_THROWS(e-k)
  .CHECK_THROWS(e-l) .CHECK_THROWS(e-m) .CHECK_THROWS(f-h) .CHECK_THROWS(f-i) 
  .CHECK_THROWS(f-j) .CHECK_THROWS(f-k) .CHECK_THROWS(f-l) .CHECK_THROWS(f-m)

  .CHECK_THROWS(e-=h) .CHECK_THROWS(e-=i) .CHECK_THROWS(e-=j) .CHECK_THROWS(e-=k)
  .CHECK_THROWS(e-=l) .CHECK_THROWS(e-=m) .CHECK_THROWS(f-=h) .CHECK_THROWS(f-=i) 
  .CHECK_THROWS(f-=j) .CHECK_THROWS(f-=k) .CHECK_THROWS(f-=l) .CHECK_THROWS(f-=m)

  .CHECK_THROWS(e<h) .CHECK_THROWS(e<i) .CHECK_THROWS(e<j) .CHECK_THROWS(e<k)
  .CHECK_THROWS(e<l) .CHECK_THROWS(e<m) .CHECK_THROWS(f<h) .CHECK_THROWS(f<i)
  .CHECK_THROWS(f<j) .CHECK_THROWS(f<k) .CHECK_THROWS(f<l) .CHECK_THROWS(f<m)

  .CHECK_THROWS(e<=h) .CHECK_THROWS(e<=i) .CHECK_THROWS(e<=j) .CHECK_THROWS(e<=k)
  .CHECK_THROWS(e<=l) .CHECK_THROWS(e<=m) .CHECK_THROWS(f<=h) .CHECK_THROWS(f<=i)
  .CHECK_THROWS(f<=j) .CHECK_THROWS(f<=k) .CHECK_THROWS(f<=l) .CHECK_THROWS(f<=m)

  .CHECK_THROWS(e>h) .CHECK_THROWS(e>i) .CHECK_THROWS(e>j) .CHECK_THROWS(e>k)
  .CHECK_THROWS(e>l) .CHECK_THROWS(e>m) .CHECK_THROWS(f>h) .CHECK_THROWS(f>i)
  .CHECK_THROWS(f>j) .CHECK_THROWS(f>k) .CHECK_THROWS(f>l) .CHECK_THROWS(f>m)

  .CHECK_THROWS(e==h) .CHECK_THROWS(e==i) .CHECK_THROWS(e==j) .CHECK_THROWS(e==k)
  .CHECK_THROWS(e==l) .CHECK_THROWS(e==m) .CHECK_THROWS(f==h) .CHECK_THROWS(f==i)
  .CHECK_THROWS(f==j) .CHECK_THROWS(f==k) .CHECK_THROWS(f==l) .CHECK_THROWS(f==m)
  .CHECK_THROWS(g==h) .CHECK_THROWS(g==i) .CHECK_THROWS(g==j) .CHECK_THROWS(g==k) 
  .CHECK_THROWS(g==l) .CHECK_THROWS(g==m)

  .CHECK_THROWS(e!=h) .CHECK_THROWS(e!=i) .CHECK_THROWS(e!=j) .CHECK_THROWS(e!=k)
  .CHECK_THROWS(e!=l) .CHECK_THROWS(e!=m) .CHECK_THROWS(f!=h) .CHECK_THROWS(f!=i)
  .CHECK_THROWS(f!=j) .CHECK_THROWS(f!=k) .CHECK_THROWS(f!=l) .CHECK_THROWS(f!=m)


  .setname("Basic output- hour,min,sec")
  .CHECK_OUTPUT(h, "90[sec]")
  .CHECK_OUTPUT(i, "40[min]")
  .CHECK_OUTPUT(j, "1[hour]")

  .setname("Compatible dimensions- hour,min,sec")
  .CHECK_OUTPUT(-h, "-90[sec]")
  .CHECK_OUTPUT(-i, "-40[min]")
  .CHECK_OUTPUT(-j, "-1[hour]")
  .CHECK_OUTPUT(+h, "90[sec]")
  .CHECK_OUTPUT(+i, "40[min]")
  .CHECK_OUTPUT(+j, "1[hour]")

  .CHECK_OK(h++)
  .CHECK_OUTPUT(h, "91[sec]")
  .CHECK_OK(i++)
  .CHECK_OUTPUT(i, "41[min]")
  .CHECK_OK(j++)
  .CHECK_OUTPUT(j, "2[hour]")
  .CHECK_OK(h--)
  .CHECK_OUTPUT(h, "90[sec]")
  .CHECK_OK(i--)
  .CHECK_OUTPUT(i, "40[min]")
  .CHECK_OK(j--)
  .CHECK_OUTPUT(j, "1[hour]")

  .CHECK_OUTPUT((i+=j),"100[min]") // --> i=100 min
  .CHECK_OUTPUT(i,"100[min]")
  .CHECK_OUTPUT(i+i,"200[min]")
  .CHECK_OUTPUT((j-=h),"0.975[hour]")  //--> j=0.975 hour
  .CHECK_OUTPUT(j,"0.975[hour]")
  .CHECK_EQUAL(j<i,true)
  .CHECK_OUTPUT(j-j,"0[hour]")
  .CHECK_OUTPUT(i-j,"41.5[min]") 
  .CHECK_OUTPUT((h+=j),"3600[sec]")  //-->h=3600 sec
  .CHECK_OUTPUT(h,"3600[sec]") 
  .CHECK_EQUAL(h>j,true)
  .CHECK_EQUAL(i==PhysicalNumber(100, Unit::MIN),true)
  .CHECK_EQUAL(h<=i,true)
  .CHECK_EQUAL(i>=j,true)


  .setname("Incompatible dimensions- hour,min,sec -- (+,-,+=,-=,<,>,<=,>=)")
  .CHECK_THROWS(h+k) .CHECK_THROWS(h+l) .CHECK_THROWS(h+m)
  .CHECK_THROWS(i+k) .CHECK_THROWS(i+l) .CHECK_THROWS(i+m)
  .CHECK_THROWS(j+k) .CHECK_THROWS(j+l) .CHECK_THROWS(j+m)

  .CHECK_THROWS(h+=k) .CHECK_THROWS(h+=l) .CHECK_THROWS(h+=m)
  .CHECK_THROWS(i+=k) .CHECK_THROWS(i+=l) .CHECK_THROWS(i+=m)
  .CHECK_THROWS(j+=k) .CHECK_THROWS(j+=l) .CHECK_THROWS(j+=m)

  .CHECK_THROWS(h-k) .CHECK_THROWS(h-l) .CHECK_THROWS(h-m)
  .CHECK_THROWS(i-k) .CHECK_THROWS(i-l) .CHECK_THROWS(i-m)
  .CHECK_THROWS(j-k) .CHECK_THROWS(j-l) .CHECK_THROWS(j-m)

  .CHECK_THROWS(h-=k) .CHECK_THROWS(h-=l) .CHECK_THROWS(h-=m)
  .CHECK_THROWS(i-=k) .CHECK_THROWS(i-=l) .CHECK_THROWS(i-=m)
  .CHECK_THROWS(j-=k) .CHECK_THROWS(j-=l) .CHECK_THROWS(j-=m)

  .CHECK_THROWS(h<k) .CHECK_THROWS(h<l) .CHECK_THROWS(h<m)
  .CHECK_THROWS(i<k) .CHECK_THROWS(i<l) .CHECK_THROWS(i<m)
  .CHECK_THROWS(j<k) .CHECK_THROWS(j<l) .CHECK_THROWS(j<m)

  .CHECK_THROWS(h<=k) .CHECK_THROWS(h<=l) .CHECK_THROWS(h<=m)
  .CHECK_THROWS(i<=k) .CHECK_THROWS(i<=l) .CHECK_THROWS(i<=m)
  .CHECK_THROWS(j<=k) .CHECK_THROWS(j<=l) .CHECK_THROWS(j<=m)

  .CHECK_THROWS(h==k) .CHECK_THROWS(h==l) .CHECK_THROWS(h==m)
  .CHECK_THROWS(i==k) .CHECK_THROWS(i==l) .CHECK_THROWS(i==m)
  .CHECK_THROWS(j==k) .CHECK_THROWS(j==l) .CHECK_THROWS(j==m)

  .CHECK_THROWS(h!=k) .CHECK_THROWS(h!=l) .CHECK_THROWS(h!=m)
  .CHECK_THROWS(i!=k) .CHECK_THROWS(i!=l) .CHECK_THROWS(i!=m)
  .CHECK_THROWS(j!=k) .CHECK_THROWS(j!=l) .CHECK_THROWS(j!=m)



 .setname("Basic output-ton,kg,g")
  .CHECK_OUTPUT(k, "100[g]")
  .CHECK_OUTPUT(l, "5.3[kg]")
  .CHECK_OUTPUT(m, "7[ton]")

  .setname("Compatible dimensions-ton,kg,g")
  .CHECK_OUTPUT(-k, "-100[g]")
  .CHECK_OUTPUT(-l, "-5.3[kg]")
  .CHECK_OUTPUT(-m, "-7[ton]")
  .CHECK_OUTPUT(+k, "100[g]")
  .CHECK_OUTPUT(+l, "5.3[kg]")
  .CHECK_OUTPUT(+m, "7[ton]")
  .CHECK_OUTPUT(++k, "101[g]")
  .CHECK_OUTPUT(++l, "6.3[kg]")
  .CHECK_OUTPUT(++m, "8[ton]")
  .CHECK_OUTPUT(--k, "100[g]")
  .CHECK_OUTPUT(--l, "5.3[kg]")
  .CHECK_OUTPUT(--m, "7[ton]")

  .CHECK_OK(k++)
  .CHECK_OUTPUT(k, "101[g]")
  .CHECK_OK(l++)
  .CHECK_OUTPUT(l, "6.3[kg]")
  .CHECK_OK(m++)
  .CHECK_OUTPUT(m, "8[ton]")
  .CHECK_OK(k--)
  .CHECK_OUTPUT(k, "100[g]")
  .CHECK_OK(l--)
  .CHECK_OUTPUT(l, "5.3[kg]")
  .CHECK_OK(m--)
  .CHECK_OUTPUT(m, "7[ton]")

  


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
