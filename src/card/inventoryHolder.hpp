// class abstrak untuk diturunkan menjadi PlayerCard dan DeckCard
#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

class InventoryHolder {
    public:
        virtual InventoryHolder* operator+(const InventoryHolder& other) const = 0;
        virtual InventoryHolder* operator-(const InventoryHolder& other) const = 0;
};

#endif