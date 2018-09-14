#ifndef STRING_H
#define STRING_H
 
#include<cassert>
#include<iostream>
 
class myString
{
private:
    char *m_data;
    int m_length;
 
public:
    myString(int length = 0): m_length(length)
    {
        assert(length>=0);
 
        m_data = new char[m_length];
    }
 
 
    myString(const char *p) // if parameter is string literal
    {
        int i = 0;
    
        while(p[i] != '\0') // for calculating the length of string literal.
        {
            i++;
        }
        
        m_length = i;
    
        m_data = new char[m_length];
 
        i=0;
 
        while(p[i] != '\0') // copy indually char by char 
        {            //since "m_data = p" wont work(const char* to char* warning )
 
            m_data[i] = p[i];
            
            i++;
        }
    }
    
 
    ~myString()
    {
        delete[] m_data;
    }
 
 
    char& operator[](int index)
    {
                assert(index >= 0 && index < m_length);    
 
        return m_data[index];
    }
 
 
    friend myString operator+(myString &s1, myString &s2) // combining two strings.
    {
        int j=0;
        
        myString str(s1.getLength() + s2.getLength());  // create new object with combined length.
 
        for(int i = 0; i < s1.m_length; i++ ) 
        {
            str.m_data[j++] = s1.m_data[i];   // could have used str[j++] = s1[i] also 
        }                      // but it would have called operator[] on every iteration    
        
        for(int i = 0; i < s2.m_length; i++ )
        {
            str.m_data[j++] = s2.m_data[i];
        }
 
        return str;
        
    }
 
 
    myString& operator=(myString &s1) // deep copying
    {
        if(this == &s1)
        {
            return *this;
        }
 
        this->erase();
 
        m_length = s1.m_length;
 
        if(s1.m_data)
        {
            m_data = new char[m_length];
            
            for(int i=0; i < m_length; i++)
            {
                m_data[i] = s1.m_data[i];
            }
        }
        else
        {
            m_data = nullptr;
        }
    return *this;            
    }
 
    
    friend bool operator==(myString &s1,myString &s2) // compare 2 strings
    {
        if(s1.m_length != s2. m_length) // if length not equal exit early.
        {
            return false;
        }
        else
        {
            int count = 0;
 
            int length = s1.m_length;
 
            while(length--)
            {
                if(s1.m_data[count] == s2.m_data[count]) // if all elements same then 
                {                     //while loop will complete
                    count++;
                }
                else                     // else will exit early
                {
                    return false;
                }
            }
 
            return true;
        }
    }    
 
 
    int getLength() {return m_length;}
 
 
    void erase()
    {
        delete[] m_data;
 
        m_data = nullptr; 
        m_length = 0;
    }
 
 
    void uppercase() 
    {
 
        for(int i=0; i < m_length; i++)
        {
            if(m_data[i] < 97 ) // if already uppercase then continue.
            {
                continue;
            }    
 
            m_data[i] -= 32;  
        }
    }
 
    void lowercase()
    {
        
        for(int i=0; i < m_length; i++)
        {
            if(m_data[i] >= 97 ) // if already lowercase then continue.
            {
                continue;
            }    
 
            m_data[i] += 32;  
        }
    }
 
    
    friend std::ostream& operator<<(std::ostream &out, myString &s)
    {
        std::cout<<s.m_data;
 
    return out;
    }
 
    
    friend std::istream& operator>>(std::istream &in, myString &s)
    {
        int i = 0;
 
        std::cin>>s.m_data;
                        
        while(s.m_data[i] != '\0')// when we instantiate object like this myString s;    
        {           // and then if we execute cin the m_length would still be zero.            
            i++;
        }
 
        s.m_length = i;        
        
    return in;
    }
    
};
 
 
#endif
