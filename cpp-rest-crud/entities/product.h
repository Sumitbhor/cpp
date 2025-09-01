#if !defined(ENTITY_PRODUCT_H)
#define ENTITY_PRODUCT_H

#include <string>

using namespace std;

class Product {
public:
    int id;
    string title;
    string description;
    string category;
    double price;

    Product(int id, string title, string description, string category, double price)
    {
        this->id=id;
        this->title=title;
        this->description=description;
        this->category=category;
        this->price=price;
        }
};

#endif // ENTITY_PRODUCT_H