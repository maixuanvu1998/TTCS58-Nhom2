#include <iostream> 
#include <excpt.h>   // exception  

using namespace std; 

#define MAXDIGITS 10000 
#define PLUS     +1 
#define MINUS    -1 
#define COSO     10 

class bignum { 
  private :       
    int  digits[MAXDIGITS];   // Array int  
    int  sign;                // Sign bignum    
    int  lastdigits;          // Length bignum  
   
  public : 
    // function constructor 
    /*bignum() { 
         memset (this->digits, 0, MAXDIGITS * sizeof (this->digits[0]));     
    } */

    // function operator >> (input) 
    friend istream& operator >> (istream& cin, bignum& a) { 
         string line;    // string bignum 
         getline(cin, line);  
         a = line; 
         return cin;   
    } 
     
    // function operator << (output)  
    friend ostream& operator << (ostream& cout, const bignum& a) { 
        int i;          // counter 
         
        if (a.sign == MINUS) cout << "-";    
        for (i = a.lastdigits; i >=0; i --) cout << a.digits[i]; 
        cout << endl; 
         
        return cout;    
    } 
     
    // operator bignum = string (line) 
    void operator = (const string& lineinput) { 
        int i, j = 0;   // counter 
        string line;     
         
        string signbignum = string(lineinput.begin() + 0, lineinput.begin() + 1); 
         if (signbignum == "+") { 
             this->sign = PLUS;           
             line = string(lineinput.begin() + 1, lineinput.end());         
         } 
         else if (signbignum == "-") { 
             this->sign = MINUS;  
             line = string(lineinput.begin() + 1, lineinput.end());    
         } 
         else { 
             this->sign = PLUS;   
             line = lineinput; 
         } 
          
        this->lastdigits = line.size() - 1;    
        for (i = line.size() - 1; i >=0; i --) this->digits[j ++] = line[i] - '0';            
    } 
     
    // operator == (between two bignum) 
    bool operator == (const bignum& b) { 
        int i;    // counter 
         
        if (this->sign != b.sign) return false; 
        if (this->lastdigits != b.lastdigits) return false; 
        for (i = this->lastdigits; i >= 0; i --) { 
            if (this->digits[i] != b.digits[i]) return false; 
        } 
         
        return true; 
    } 
     
    // operator != (between two bignum) 
    bool operator != (const bignum& b) { 
        static bignum a = *this; 
        if (a == b) return false; 
         
        return true;  
    } 
     
    // operator = (between two bignum) 
    bignum& operator = (const bignum& b) { 
        int i;    // counter 
         
        this->sign = b.sign; 
        this->lastdigits = b.lastdigits; 
        for (i = b.lastdigits; i >=0; i --) this->digits[i] = b.digits[i]; 
         
        return *this;   
    } 
     
    // function Remove zero in bignum 
    bignum removezero(const bignum& b) { 
        bignum a = b;   
        while ( (a.lastdigits > 0) && (a.digits[a.lastdigits] == 0)) a.lastdigits --; 
        // - 0 = 0 
        if ( (a.lastdigits == 0) && (a.digits[0] == 0)) a.sign = PLUS; 
        return a; 
    } 
     
    // oprerator + (between two bignum) 
     bignum operator + (const bignum& y) { 
       bignum a = *this, c, b = y;     
       int carry = 0, i;    // carry and counter 
        
       // sign of bignum  == sign of bignum b (PLUS, MINUS) 
       if (a.sign == b.sign) c.sign = a.sign; 
       else {  
           // sign of bignum *this is MINUS and sign of bignum b is PLUS 
           if (a.sign == MINUS) { 
               a.sign = PLUS; 
               c = b - a; 
               a.sign = MINUS;       
           } else { 
               b.sign = PLUS; 
               c = a - b; 
               b.sign = MINUS;      
           } 
           return c; 
       } 
       // length of bignum 
       c.lastdigits = max(a.lastdigits, b.lastdigits) + 1; 
       for (i = 0; i <= c.lastdigits; i ++) { 
           c.digits[i] = (carry + a.digits[i] + b.digits[i]) % COSO; 
           carry = (carry + a.digits[i] + b.digits[i]) / COSO; 
       } 
       c = removezero(c); 
       return c; 
    }  
     
    // operator += (with a bignum) 
    bignum operator += (const bignum& b) { 
         
        return (*this = *this + b);  
    } 
     
    // operator - (between two bignum) 
    bignum operator - (const bignum& y) { 
       bignum a = *this, c, b = removezero(y), so0; 
       so0 = "0"; 
       int borrow = 0, div, i;    // counter 
       // bignum b == 0 
       if (b == so0) return a; 
        
       // bignum a == 0 
       if (a == so0) {    
          if (b < so0) { 
            b.sign = PLUS;     
            return b; 
          } 
          else if (b > so0) { 
              b.sign = MINUS; 
              return b;  
          } 
          else return so0; 
       } 
        
       //sign of bignum a == sign of bignum b 
       if (a.sign == b.sign) { 
             c.sign = a.sign;      
       } else { 
           // sign of bignum *this is MINUS and sing of bignum b is PLUS 
           if (a.sign == MINUS) { 
               a.sign = PLUS; 
               c = a + b; 
               c.sign = MINUS; a.sign = MINUS;       
               return c; 
           } else { 
               b.sign = PLUS; 
               c = a + b; 
               c.sign = PLUS;  b.sign = MINUS;      
               return c; 
           } 
       } 
       if (a.sign == PLUS)  
       { 
           if (a >= b) { 
               c.sign = PLUS;   
                
               c.lastdigits = max(a.lastdigits, b.lastdigits); 
                
               for (i = 0; i <= c.lastdigits; i ++) { 
                   div = a.digits[i] - borrow - b.digits[i]; 
                   if (a.digits[i] > 0) borrow = 0; 
                   if (div < 0) { 
                       div += COSO; borrow = 1;  
                   }  
                   c.digits[i] = div % COSO; 
               } 
           } else { 
               c.sign = MINUS; 
               c.lastdigits = max(a.lastdigits, b.lastdigits); 
               for (i = 0; i <= c.lastdigits; i ++) { 
                   div = b.digits[i] - borrow - a.digits[i]; 
                   if (b.digits[i] > 0) borrow = 0; 
                   if (div < 0) { 
                       div += COSO; borrow = 1;  
                   }  
                   c.digits[i] = div % COSO; 
               }    
           } 
       } else { 
            a.sign = PLUS; 
            b.sign = PLUS; 
            c = b - a;   
            if (a < b) c.sign = PLUS; 
            else c.sign = MINUS; 
       } 
       c = removezero(c); 
       return c; 
    }  
      
    // operator -= (with a bignum) 
    bignum operator -= (const bignum& b) { 
         
        return (*this = *this - b); 
    }   
     
    // operator shift left bit (b is number) 
    const bignum operator <<= (int b) { 
       int i, n;        // counter 
       bignum so0;    // bignum 0   
        
       // if bignum is 0 then return 0 (do nothing) 
       so0 = "0"; 
       if ((this->lastdigits) == 0 && (this->digits[0] == 0)) return so0; 
       n = this->lastdigits + 1; 
       memmove(this->digits + b, this->digits, n * sizeof (this->digits[0])); 
       //memset(this->digits, 0, b * sizeof (this->digits[0])); 
       /* 
       for (i = lastdigits; i >=0; i --) this->digits[i + b] = this->digits[i]; 
       for (i = 0; i < b; i ++) this->digits[i] = 0; 
       */ 
       this->lastdigits += b; 
        
       return *this; 
    } 
     
    // operator * (between two bignum 
    bignum operator * (const bignum& b) { 
        bignum c, a = b, sonhan = *this, tong; 
        int i, j; 
        c = "0"; 
     
        for (i = 0; i <= a.lastdigits; i ++) { 
            for (j = 1; j <= a.digits[i]; j ++) { 
                tong = sonhan + c; 
                c = tong;     
            } 
            sonhan <<= 1; 
        } 
         // sign 
        c.sign = (this->sign) * (a.sign); 

        return c;   
    } 
     
    // operator *= (with a bignum) 
    bignum operator *= (const bignum& b) { 
        
       return (*this = *this * b);  
    } 
     
    // operator < (with a bignum) 
    bool operator < (const bignum& b) { 
          bignum a = *this,c = b, so0; so0 ="0";  
          int i;    // counter 
           
          // bignum b == 0 
          if (c == so0) { 
               if (this->sign > 0) return false; 
               else return true;  
          } 
          // check ==  
          if (a == b) return false; 
          // check sign 
          if (a.sign < b.sign) return true; 
          else if (a.sign > b.sign) return false; 
          else { 
               // + 
              if ((a.sign == PLUS) && (b.sign == PLUS)) { 
                   if (a.lastdigits > b.lastdigits) return false; 
                   if (a.lastdigits < b.lastdigits) return true; 
                   for (i = a.lastdigits; i >=0; i --) { 
                       if (a.digits[i] < b.digits[i]) return true; 
                       if (a.digits[i] > b.digits[i]) return false; 
                   }  
                   return false;        
              } 
              // - 
              if ((a.sign == MINUS) && (b.sign == MINUS)) { 
                   if (a.lastdigits > b.lastdigits) return true; 
                   if (a.lastdigits < b.lastdigits) return false; 
                   for (i = a.lastdigits; i >=0; i --) { 
                       if (a.digits[i] < b.digits[i]) return false; 
                       if (a.digits[i] > b.digits[i]) return true; 
                   } 
                   return false;        
              } 
          } 
      } 
       
    // operator > (with a bignum) 
    bool operator > (const bignum& b) { 
        bignum a = *this; 
        if (a < b) return false; 
        if (a == b) return false; 
         
        return true;  
    } 
     
    // operator >= (with a bignum) 
    bool operator >= (const bignum& b) { 
        bignum a = *this; 
        if (a < b) return false; 
         
        return true;  
    }  
     
    // operator <= (with a bignum) 
     bool operator <= (const bignum& b) { 
         bignum a = *this;  
         if (a > b) return false; 
          
         return true;  
     }  
       
    // operator / (between two bignum)  
    bignum operator / (const bignum& y) { 
        bignum c, a = *this, b = removezero(y), sochia, so0, so1; 
        int asign, bsign;  // sign  
        int i;             // counter 
         
        try { 
            // bignum b == 0 
            if (b == so0) {  
                  cout << "Could not divide zero !" << endl; 
            } 
            // sign 
            c.sign = (a.sign) * (b.sign); 
            asign = a.sign; bsign = b.sign; 
             
            sochia = "0"; so0 = "0", so1 = "1"; 
            a.sign = PLUS; 
            b.sign = PLUS; 
            // bignum b == 1 
            if(b == so1) return *this; 
            // bignum a == bignum b 
            if (a == b) return so1; 
            if (a < b)  return so0;           
            else {   
                c.lastdigits = a.lastdigits; 
                for (i = c.lastdigits; i >= 0; i --) { 
                    sochia <<= 1; 
                    sochia.digits[0] = a.digits[i]; 
                    c.digits[i] = 0;      
                    while (true) { 
                             if (sochia < b) break; 
                             c.digits[i] ++; 
                             sochia -= b; 
                    }   
                } 
                a.sign = asign;  
                b.sign = bsign; 
            } 
        } catch (exception &e) { 
                cout << "Error !" << endl;   
        } 
        c = removezero(c); 
        return c;           
    } 
     
    // operator /= (with a bignum) 
    bignum operator /= (const bignum& b) { 
        
       return (*this = *this / b);  
    } 
     
    // operator -() 
    bignum operator -() {        
       bignum so0; so0 = "0";  
        
       return (so0 - *this); 
    } 
     
    // operator get abs() (absolute) 
     bignum abs() { 
        bignum so0; so0 = "0";   
         
        if (*this < so0) return (so0 - *this);   
        else return *this; 
    } 
     
    // operator % (with a bignum) 
    bignum operator % (const bignum& c) { 
            
        bignum a = *this, b = c, d, so0;   
        so0 = "0"; int dsign; 
        if (a > b) { 
           if (a.sign == b.sign) { 
                if (a.sign == PLUS) dsign = PLUS; 
                else dsign = MINUS;       
           } else { 
                  dsign = PLUS; 
           } 
           a.sign = PLUS; 
           b.sign = PLUS; 
           d = a - (a / b) * b; 
           d.sign = dsign; 
            
           d = removezero(d); 
           return d;   
        } else if (a < b) { 
           d.sign = a.sign;     
           d = removezero(a); 
           return d;     
        } 
        else return so0; 
    } 
     
    // operator % (with a bignum) 
    bignum operator %= (const bignum& b) { 
        
       return (*this = *this % b);  
    } 
};  
