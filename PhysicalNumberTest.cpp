
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
  .CHECK_OUTPUT(g, "20[cm]")
 
  .setname("Compatible dimensions- km,m,cm")
  .CHECK_OUTPUT(-e,"-3.2[km]")
  .CHECK_OUTPUT(-f, "-80[m]")
  .CHECK_OUTPUT(-g, "-20[cm]")
  .CHECK_OUTPUT(+e,"3.2[km]")
  .CHECK_OUTPUT(+f, "80[m]")
  .CHECK_OUTPUT(+g, "20[cm]")
  .CHECK_OUTPUT(++e,"4.2[km]")
  .CHECK_OUTPUT(++f, "81[m]")
  .CHECK_OUTPUT(++g, "21[cm]")
  .CHECK_OUTPUT(--e,"3.2[km]")
  .CHECK_OUTPUT(--f, "80[m]")
  .CHECK_OUTPUT(--g, "20[cm]")

  .CHECK_OK(e++)
  .CHECK_OUTPUT(e,"4.2[km]")
  .CHECK_OK(f++)
  .CHECK_OUTPUT(f, "81[m]")
  .CHECK_OK(g++)
  .CHECK_OUTPUT(g, "21[cm]")
  .CHECK_OK(e--)
  .CHECK_OUTPUT(e,"3.2[km]")
  .CHECK_OK(f--)
  .CHECK_OUTPUT(f, "80[m]")
  .CHECK_OK(g--)
  .CHECK_OUTPUT(g, "20[cm]")

  .CHECK_OUTPUT(f+g,"80.2[m]")
  .CHECK_OUTPUT(g+f,"8020[cm]")
  .CHECK_OUTPUT(e+f,"3.28[km]")
  .CHECK_OUTPUT(f+e,"3280[m]")
  .CHECK_OUTPUT(g+e,"320020[cm]")
  .CHECK_OUTPUT(e+g,"3.2002[km]")
  .CHECK_OUTPUT(f-g,"79.8[m]")
  .CHECK_OUTPUT(e-f,"3.12[km]")
  .CHECK_OUTPUT(g-f,"-7980[cm]")
  .CHECK_OUTPUT(f-e,"-3120[m]")
  .CHECK_OUTPUT(g-e,"-319980[cm]")
  .CHECK_OUTPUT(e-g,"3.1998[km]")

  .CHECK_OUTPUT((e+=f),"3.28[km]")  //--> e=3.28 km
  .CHECK_OUTPUT(e,"3.28[km]")
  .CHECK_OUTPUT(e+e,"6.56[km]")
  .CHECK_OUTPUT((f-=g),"79.8[m]")  //--> f=79.8 m
  .CHECK_OUTPUT(f,"79.8[m]")
  .CHECK_OUTPUT(f-f,"0[m]")
  .CHECK_EQUAL(f<e,true)
  .CHECK_OUTPUT((g+=f),"8000[cm]") //--> g = 8000 cm
  .CHECK_OUTPUT(g,"8000[cm]")
  .CHECK_EQUAL(f<=g,true)
  .CHECK_OUTPUT((g-=g),"0[cm]")
  .CHECK_OUTPUT(g,"0[cm]")  //--> g = 0 cm
  .CHECK_OUTPUT(--g, "-1[cm]")   //--> g = -1 cm
  .CHECK_OUTPUT(+g,"-1[cm]")   //--> g = -1 cm
  .CHECK_EQUAL(f>g,true)
  .CHECK_EQUAL(e>=g,true)
  .CHECK_EQUAL(g==PhysicalNumber(-1, Unit::CM),true)
  


  .setname("Incompatible dimensions- km,m,cm -- (+,-,+=,-=,<,>,<=,>=)")
  .CHECK_THROWS(e+h) .CHECK_THROWS(e+i) .CHECK_THROWS(e+j) .CHECK_THROWS(e+k)
  .CHECK_THROWS(e+l) .CHECK_THROWS(e+m) .CHECK_THROWS(f+h) .CHECK_THROWS(f+i)
  .CHECK_THROWS(f+j) .CHECK_THROWS(f+k) .CHECK_THROWS(f+l) .CHECK_THROWS(f+m)
  .CHECK_THROWS(g+h) .CHECK_THROWS(g+i) .CHECK_THROWS(g+j) .CHECK_THROWS(g+k) 
  .CHECK_THROWS(g+l) .CHECK_THROWS(g+m)
  
  .CHECK_THROWS(e+=h) .CHECK_THROWS(e+=i) .CHECK_THROWS(e+=j) .CHECK_THROWS(e+=k)
  .CHECK_THROWS(e+=l) .CHECK_THROWS(e+=m) .CHECK_THROWS(f+=h) .CHECK_THROWS(f+=i) 
  .CHECK_THROWS(f+=j) .CHECK_THROWS(f+=k) .CHECK_THROWS(f+=l) .CHECK_THROWS(f+=m)
  .CHECK_THROWS(g+=h) .CHECK_THROWS(g+=i) .CHECK_THROWS(g+=j) .CHECK_THROWS(g+=k)
  .CHECK_THROWS(g+=l) .CHECK_THROWS(g+=m)

  .CHECK_THROWS(e-h) .CHECK_THROWS(e-i) .CHECK_THROWS(e-j) .CHECK_THROWS(e-k)
  .CHECK_THROWS(e-l) .CHECK_THROWS(e-m) .CHECK_THROWS(f-h) .CHECK_THROWS(f-i) 
  .CHECK_THROWS(f-j) .CHECK_THROWS(f-k) .CHECK_THROWS(f-l) .CHECK_THROWS(f-m)
  .CHECK_THROWS(g-h) .CHECK_THROWS(g-i) .CHECK_THROWS(g-j) .CHECK_THROWS(g-k)
  .CHECK_THROWS(g-l) .CHECK_THROWS(g-m)

  .CHECK_THROWS(e-=h) .CHECK_THROWS(e-=i) .CHECK_THROWS(e-=j) .CHECK_THROWS(e-=k)
  .CHECK_THROWS(e-=l) .CHECK_THROWS(e-=m) .CHECK_THROWS(f-=h) .CHECK_THROWS(f-=i) 
  .CHECK_THROWS(f-=j) .CHECK_THROWS(f-=k) .CHECK_THROWS(f-=l) .CHECK_THROWS(f-=m)
  .CHECK_THROWS(g-=h) .CHECK_THROWS(g-=i) .CHECK_THROWS(g-=j) .CHECK_THROWS(g-=k)
  .CHECK_THROWS(g-=l) .CHECK_THROWS(g-=m)

  .CHECK_THROWS(e<h) .CHECK_THROWS(e<i) .CHECK_THROWS(e<j) .CHECK_THROWS(e<k)
  .CHECK_THROWS(e<l) .CHECK_THROWS(e<m) .CHECK_THROWS(f<h) .CHECK_THROWS(f<i)
  .CHECK_THROWS(f<j) .CHECK_THROWS(f<k) .CHECK_THROWS(f<l) .CHECK_THROWS(f<m)
  .CHECK_THROWS(g<h) .CHECK_THROWS(g<i) .CHECK_THROWS(g<j) .CHECK_THROWS(g<k) 
  .CHECK_THROWS(g<l) .CHECK_THROWS(g<m)

  .CHECK_THROWS(e<=h) .CHECK_THROWS(e<=i) .CHECK_THROWS(e<=j) .CHECK_THROWS(e<=k)
  .CHECK_THROWS(e<=l) .CHECK_THROWS(e<=m) .CHECK_THROWS(f<=h) .CHECK_THROWS(f<=i)
  .CHECK_THROWS(f<=j) .CHECK_THROWS(f<=k) .CHECK_THROWS(f<=l) .CHECK_THROWS(f<=m)
  .CHECK_THROWS(g<=h) .CHECK_THROWS(g<=i) .CHECK_THROWS(g<=j) .CHECK_THROWS(g<=k) 
  .CHECK_THROWS(g<=l) .CHECK_THROWS(g<=m)

  .CHECK_THROWS(e>=h) .CHECK_THROWS(e>=i) .CHECK_THROWS(e>=j) .CHECK_THROWS(e>=k)
  .CHECK_THROWS(e>=l) .CHECK_THROWS(e>=m) .CHECK_THROWS(f>=h) .CHECK_THROWS(f>=i)
  .CHECK_THROWS(f>=j) .CHECK_THROWS(f>=k) .CHECK_THROWS(f>=l) .CHECK_THROWS(f>=m)
  .CHECK_THROWS(g>=h) .CHECK_THROWS(g>=i) .CHECK_THROWS(g>=j) .CHECK_THROWS(g>=k) 
  .CHECK_THROWS(g>=l) .CHECK_THROWS(g>=m)

  .CHECK_THROWS(e>h) .CHECK_THROWS(e>i) .CHECK_THROWS(e>j) .CHECK_THROWS(e>k)
  .CHECK_THROWS(e>l) .CHECK_THROWS(e>m) .CHECK_THROWS(f>h) .CHECK_THROWS(f>i)
  .CHECK_THROWS(f>j) .CHECK_THROWS(f>k) .CHECK_THROWS(f>l) .CHECK_THROWS(f>m)
  .CHECK_THROWS(g>h) .CHECK_THROWS(g>i) .CHECK_THROWS(g>j) .CHECK_THROWS(g>k) 
  .CHECK_THROWS(g>l) .CHECK_THROWS(g>m)

  .CHECK_THROWS(e==h) .CHECK_THROWS(e==i) .CHECK_THROWS(e==j) .CHECK_THROWS(e==k)
  .CHECK_THROWS(e==l) .CHECK_THROWS(e==m) .CHECK_THROWS(f==h) .CHECK_THROWS(f==i)
  .CHECK_THROWS(f==j) .CHECK_THROWS(f==k) .CHECK_THROWS(f==l) .CHECK_THROWS(f==m)
  .CHECK_THROWS(g==h) .CHECK_THROWS(g==i) .CHECK_THROWS(g==j) .CHECK_THROWS(g==k) 
  .CHECK_THROWS(g==l) .CHECK_THROWS(g==m)

  .CHECK_THROWS(e!=h) .CHECK_THROWS(e!=i) .CHECK_THROWS(e!=j) .CHECK_THROWS(e!=k)
  .CHECK_THROWS(e!=l) .CHECK_THROWS(e!=m) .CHECK_THROWS(f!=h) .CHECK_THROWS(f!=i)
  .CHECK_THROWS(f!=j) .CHECK_THROWS(f!=k) .CHECK_THROWS(f!=l) .CHECK_THROWS(f!=m)
  .CHECK_THROWS(g!=h) .CHECK_THROWS(g!=i) .CHECK_THROWS(g!=j) .CHECK_THROWS(g!=k) 
  .CHECK_THROWS(g!=l) .CHECK_THROWS(g!=m)


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
  .CHECK_OUTPUT(++h, "91[sec]")
  .CHECK_OUTPUT(++i, "41[min]")
  .CHECK_OUTPUT(++j, "2[hour]")
  .CHECK_OUTPUT(--h, "90[sec]")
  .CHECK_OUTPUT(--i, "40[min]")
  .CHECK_OUTPUT(--j, "1[hour]")

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

  .CHECK_OUTPUT(h+i,"2490[sec]") 
  .CHECK_OUTPUT(i+h,"41.5[min]")
  .CHECK_OUTPUT(h+j,"3690[sec]") 
  .CHECK_OUTPUT(j+h,"1.02500[hour]")
  .CHECK_OUTPUT(i+j,"100[min]")
  .CHECK_OUTPUT(j+i,"1.66666667[hour]") 
  .CHECK_OUTPUT(i-h,"38.5[min]")
  .CHECK_OUTPUT(j-h,"0.975[hour]")

  .CHECK_OUTPUT(h-i,"-2310[sec]") 
  .CHECK_OUTPUT(h-j,"-3510[sec]") 
  .CHECK_OUTPUT(i-j,"-20[min]")
  .CHECK_OUTPUT(j-i,"0.333333333[hour]") 
 

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

  .CHECK_THROWS(h>k) .CHECK_THROWS(h>l) .CHECK_THROWS(h>m)
  .CHECK_THROWS(i>k) .CHECK_THROWS(i>l) .CHECK_THROWS(i>m)
  .CHECK_THROWS(j>k) .CHECK_THROWS(j>l) .CHECK_THROWS(j>m)

  .CHECK_THROWS(h>=k) .CHECK_THROWS(h>=l) .CHECK_THROWS(h>=m)
  .CHECK_THROWS(i>=k) .CHECK_THROWS(i>=l) .CHECK_THROWS(i>=m)
  .CHECK_THROWS(j>=k) .CHECK_THROWS(j>=l) .CHECK_THROWS(j>=m)

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

  .CHECK_OUTPUT(k+l,"5400[g]")
  .CHECK_OUTPUT(l+k,"5.4[kg]")
  .CHECK_OUTPUT(k+m,"7000100[g]")
  .CHECK_OUTPUT(m+k,"7.0001[ton]")
  .CHECK_OUTPUT(l+m,"7005.3[kg]")
  .CHECK_OUTPUT(m+l,"7.0053[ton]")
  .CHECK_OUTPUT(l-k,"5.2[kg]")
  .CHECK_OUTPUT(m-k,"6.9999[ton]")
  .CHECK_OUTPUT(k-l,"-5200[g]")
  .CHECK_OUTPUT(k-m,"-6999900[g]")
  .CHECK_OUTPUT(l-m,"-6994.7[kg]")
  .CHECK_OUTPUT(m-l,"6.9947[ton]")

  .CHECK_OUTPUT((l+=k),"5.4[kg]")  // --> l=5.4 kg
  .CHECK_OUTPUT(l,"5.4[kg]")
  .CHECK_OUTPUT(l+l,"10.8[kg]")
  .CHECK_EQUAL(l==PhysicalNumber(5.4, Unit::KG),true)
  .CHECK_OUTPUT((m-=k),"6.9999[ton]") //--> m=6.9999 ton
  .CHECK_OUTPUT(m,"6.9999[ton]")
  .CHECK_OUTPUT(m-m,"0[ton]")
  .CHECK_EQUAL(m>=l,true)
  .CHECK_OUTPUT((k+=m),"7000100[g]") //--> k=7000100 g
  .CHECK_OUTPUT(k,"7000100[g]")
  .CHECK_OUTPUT(k-k,"0[g]")
  .CHECK_EQUAL(k>l,true)
  .CHECK_EQUAL(m<=k,true)
  .CHECK_EQUAL(l<m,true)
  
  

  .setname("check input")
  .CHECK_OK(istringstream("2[min]") >> e)
  .CHECK_OUTPUT((e += PhysicalNumber(30, Unit::SEC)), "2.5[min]")
  
  .CHECK_OK(istringstream("30[kg]") >> l)
  .CHECK_OUTPUT((l += PhysicalNumber(50, Unit::G)), "30.05[kg]")
  
  .CHECK_OK(istringstream("5[m]") >> k)
  .CHECK_OUTPUT((k += PhysicalNumber(20, Unit::CM)), "5.2[m]")



  .setname("check conversions")       

  .CHECK_EQUAL((PhysicalNumber(1, Unit::HOUR))==(PhysicalNumber(60, Unit::MIN)),true)  
  .CHECK_EQUAL((PhysicalNumber(3600, Unit::SEC))==(PhysicalNumber(60, Unit::MIN)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::HOUR))==(PhysicalNumber(3600, Unit::SEC)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::MIN))==(PhysicalNumber(60, Unit::SEC)),true)

  .CHECK_EQUAL((PhysicalNumber(1, Unit::M))==(PhysicalNumber(100, Unit::CM)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::KM))==(PhysicalNumber(1000, Unit::M)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::KM))==(PhysicalNumber(100000, Unit::CM)),true)
  .CHECK_EQUAL((PhysicalNumber(1000, Unit::M))==(PhysicalNumber(100000, Unit::CM)),true)

  .CHECK_EQUAL((PhysicalNumber(1, Unit::KG))==(PhysicalNumber(1000, Unit::G)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::TON))==(PhysicalNumber(1000, Unit::KG)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::TON))==(PhysicalNumber(1000000, Unit::G)),true)
  .CHECK_EQUAL((PhysicalNumber(1000, Unit::KG))==(PhysicalNumber(1000000, Unit::G)),true)


  .CHECK_EQUAL((PhysicalNumber(1000, Unit::KG))!=(PhysicalNumber(100, Unit::G)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::HOUR))!=(PhysicalNumber(1, Unit::MIN)),true)
  .CHECK_EQUAL((PhysicalNumber(23, Unit::M))!=(PhysicalNumber(100000, Unit::CM)),true)
  .CHECK_EQUAL((PhysicalNumber(1, Unit::TON))!=(PhysicalNumber(60, Unit::G)),true)




      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
