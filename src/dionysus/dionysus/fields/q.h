#ifndef DIONYSUS_Q_H
#define DIONYSUS_Q_H

#include <iostream>

// TODO: eventually need to be able to adaptively switch to arbitrary precision arithmetic

namespace dionysus
{

template<typename Element_ = long>
class Q
{
    public:
        // typedef stuff. Renames Element_ to BaseElement
        using           BaseElement = Element_;
        // Elements of the field Q should have a numerator and denominator. Equality should be determined by the relationship {ac ~ bd} given elements {a,b} and {c,d}
        struct Element
        {
            // An element of this field should have a numerator and a denominator. This field is the field of rational numbers. 
            BaseElement numerator, denominator;
            // Redefine the equals operator for elements. numerators for each should be equal and denominators should be equal?
            bool        operator==(Element o) const                     { return numerator == o.numerator && denominator == o.denominator; }
            // Ask Dave
            bool        operator!=(Element o) const                     { return !((*this) == o); }
            // ask Dave
            friend
            std::ostream&   operator<<(std::ostream& out, Element e)    { out << e.numerator << '/' << e.denominator; return out; }
        };
        // identity is 1/1, zero is 0/1, given a long we make denominator 0 
        Element         id()  const                         { return { 1,1 }; }
        Element         zero()  const                       { return { 0,1 }; }
        Element         init(BaseElement a) const           { return { a,1 }; }
        
        Element         neg(Element a) const                { return { -a.numerator, a.denominator }; }
        Element         add(Element a, Element b) const     { Element x { a.numerator*b.denominator + b.numerator*a.denominator, a.denominator*b.denominator }; normalize(x); return x; }

        Element         inv(Element a) const                { return { a.denominator, a.numerator }; }
        Element         mul(Element a, Element b) const     { Element x { a.numerator*b.numerator, a.denominator*b.denominator }; normalize(x); return x; }
        Element         div(Element a, Element b) const     { return mul(a, inv(b)); }

        bool            is_zero(Element a) const            { return a.numerator == 0; }

        BaseElement     numerator(const Element& x) const   { return x.numerator; }
        BaseElement     denominator(const Element& x) const { return x.denominator; }

        static void     normalize(Element& x)
        {
            BaseElement q = gcd(abs(x.numerator), abs(x.denominator));
            x.numerator /= q;
            x.denominator /= q;
            if (x.denominator < 0)
            {
                x.numerator   = -x.numerator;
                x.denominator = -x.denominator;
            }
        }

        static BaseElement  abs(BaseElement x)              { if (x < 0) return -x; return x; }
        static BaseElement  gcd(BaseElement a, BaseElement b)   { 
            if (b < a) 
                return gcd(b,a); 
            while (a != 0) { 
                b %= a; std::swap(a,b); 
            } 
            return b; 
        }

        static bool     is_prime(BaseElement x)             { return false; }       // Ok, since is_prime is only used as a shortcut
};

}

#endif
