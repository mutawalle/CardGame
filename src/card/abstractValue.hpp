#ifndef ABSTRACTVALUE_HPP
#define ABSTRACTVALUE_HPP
// class abstrack memiliki value() virtual

class AbstractValue{
    public:
        virtual double value() const = 0;
        bool operator>(const AbstractValue& other){
            return this->value() > other.value();
        }
        bool operator<(const AbstractValue& other);
        bool operator==(const AbstractValue& other);
};



#endif 