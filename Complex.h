#ifndef LR3_COMPLEX_H
#define LR3_COMPLEX_H

#include <iostream>
#include <cmath>

using namespace std;

class cmp{
private:
    size_t x;
    size_t y;
public:
    cmp(){
        x = y = 0;
    }

    cmp(size_t new_x, size_t new_y){
        x = new_x;
        y = new_y;
    }

    size_t GetX(){
        return x;
    }

    size_t GetY(){
        return y;
    }

    void SetX(size_t value){
        x = value;
    }

    void SetY(size_t value){
        y = value;
    }

    cmp& operator=(const cmp a){
        x = a.x;
        y = a.y;
        return (*this);
    }

    cmp& operator+=(cmp a){
        x += a.x;
        y += a.y;
        return(*this);
    }

    cmp operator+(const cmp a){
        return {x + a.x, y + a.y};
    }

    cmp operator-(const cmp a){
        return {x - a.x, y - a.y};
    }

    cmp operator*(const cmp a){
        return {x * a.x - y * a.y, x * a.y + y * a.x};
    }

    cmp operator/(const cmp a){
        cmp temp;
        double z = a.x * a.x + a.y * a.y;
        temp.x = (x * a.x + y * a.y) / z;
        temp.y = (y * a.x - x * a.y) / z;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream &out, const cmp a){
        return out << "(" << a.x << "+" << a.y << "i)" << endl;
    }

    friend std::istream& operator>>(std::istream &in, cmp &a){
        return in >> a.x >> a.y;
    }

    bool operator==(const cmp a) const{
        if((x == a.x) && (y == a.y)){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator>(const cmp a) const{
        if(sqrt(pow(x,2) + pow(y,2)) > sqrt(pow(a.x, 2) + pow(a.y, 2))){
            return true;
        }
        else{
            return false;
        }
    }

    bool operator<(const cmp a) const{
        if(sqrt(pow(x, 2) + pow(y, 2)) < sqrt(pow(a.x, 2) + pow(a.y, 2))){
            return true;
        }
        else{
            return false;
        }
    }

    ~cmp()= default;

};

#endif //LR3_COMPLEX_H
