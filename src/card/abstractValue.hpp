#ifndef ABSTRACTVALUE_HPP
#define ABSTRACTVALUE_HPP

class AbstractValue {
    public:
        virtual double getValue() const = 0;
        bool operator>(const AbstractValue& other) {
            return this->getValue() > other.getValue();
        }
        bool operator<(const AbstractValue& other) {
            return this->getValue() < other.getValue();
        }
        bool operator<=(const AbstractValue& other) {
            return this->getValue() <= other.getValue();
        }
        bool operator>=(const AbstractValue& other) {
            return this->getValue() >= other.getValue();
        }
        bool operator==(const AbstractValue& other) {
            return this->getValue() == other.getValue();
        }
};



#endif 