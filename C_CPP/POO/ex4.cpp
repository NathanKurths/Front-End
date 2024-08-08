#include <iostream>
/*
Implemente a classe Complexo, lembre-se do exercício 2, onde o número complexo tem a parte real (a) e a parte imaginária (b) ambos do tipo float.

Implemente um construtor que recebe os dois atributos.

Considerando um número complexo a + bi, onde a parte real é a, e a parte imaginária é b, e outro número complexo c + di, onde a parte real é c, e a parte imaginária é d, sobrecarregue os seguintes operadores:

- Complexo - Complexo : Subtração complexa: (a + bi) - (c + di) = (a - c) + (b - d)i

- Complexo + Complexo : Soma complexa: (a + bi) + (c + di) = (a + c) + (b + d)i

- Complexo * Complexo : Multiplicação complexa: (a + bi) + (c + di) = (ac - bd) + (ad + bc)i

- Complexo / Complexo : Divisão complexa: (a + bi) + (c + di) = (ac + bd)/(c2 + d2) + (bc – ad)/(c2 + d2)i

- << Complexo : Escreve na stream: "Real:" << Complexo.a << " Imag:" << Complexo.b

O main já está implementado e irá testar todos os operadores.*/
class Complexo{
    float a,b;

    public:
    Complexo()
    {
        a = 0;
        b = 0;
    }

    Complexo(float pA, float pB){
        this->a = pA;
        this->b = pB;
    }

    Complexo operator-(Complexo u)
    {
        Complexo resultante;
        resultante.a = a - u.a;
        resultante.b = b - u.b;
        return resultante;
    }

    Complexo operator+(Complexo u)
    {
        Complexo resultante;
        resultante.a = a + u.a;
        resultante.b = b + u.b;
        return resultante;
    }

    Complexo operator*(Complexo u)
    {
        Complexo resultante;
        resultante.a = (a*u.a) + (u.b*b)*(-1);
        resultante.b = (a*u.b) + (b*u.a);
        return resultante;
    }

    Complexo operator/(Complexo u)
    {
        Complexo resultante;
        float denominador = (u.a*u.a) + ((u.b * (-1*u.b)*(-1)));
        resultante.a = ((a*u.a) + ((-1*u.b)*b)*(-1))/denominador;
        resultante.b = ((a*(-1*u.b)) + (b*u.a))/denominador;
        return resultante;
    }

    friend std::ostream& operator<<(std::ostream& os, const Complexo& c);
};

std::ostream& operator<<(std::ostream& os, const Complexo& c) {
    os << "Real:" << c.a << " Imag:" << c.b;
    return os;
}

int main()
{
    Complexo n1(6,-4);
    Complexo n2(4,2);

    Complexo c = n1-n2;
    std::cout<< c << std::endl;

    Complexo d = n1+n2;
    std::cout<< d << std::endl;

    Complexo e = n1*n2;
    std::cout<< e << std::endl;

    Complexo f = n1/n2;
    std::cout<< f << std::endl;
    
    return 0;
}