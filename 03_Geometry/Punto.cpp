typedef long double ld;
const ld PI = 2l * acosl(0);
const ld EPS = 1e-10;
 
struct Punto {
    ld x, y;
    Punto operator + (Punto aux) {
        return {x+aux.x,y+aux.y};
    }
    Punto operator - (Punto aux) {
        return {x-aux.x,y-aux.y};
    }
    ld operator ^ (Punto aux) {
        return x*aux.y - aux.x*y;   
    }
    ld mod() {return sqrtl(x*x + y*y);}
    ld arg() {
        ld angle =  atan2l(y,x);
        if(angle < -EPS) angle += PI * 2;
        return angle;
    }
}