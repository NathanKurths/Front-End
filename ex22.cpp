#include <iostream>
#include <list>

using namespace std;

class Figura{
    public:
    virtual float calcularArea() = 0;
    virtual ~Figura(){}
};

class Triangulo : public Figura
{
    float base, altura;
    public:
    Triangulo(float pbase, float paltura)
    {
        this->base = pbase;
        this->altura = paltura;
    }

    float calcularArea() override
    {
        return 0.5 * base * altura;
    }
};

class Quadrado : public Figura
{
    float lado;
    public:
    Quadrado(float plado){
        this->lado = plado;
    }
    float calcularArea()
    {
        return lado*lado;
    }
};

class Circulo : public Figura
{
    float raio;
    public:
    Circulo(float praio)
    {
        this->raio = praio;
    }
    float calcularArea()
    {
        return raio*raio*(3.14159265358979323846);
    }
};

void imprime_area_total(std::list<Figura*> x){
    float total = 0;
    for(Figura* i : x){
        total += i->calcularArea();
    }
    std::cout<<total<<std::endl;
}

int main()
{
    Figura *a = new Triangulo(2.0, 3.0);
    std::list<Figura*> figuras;
    figuras.push_back(new Quadrado(3.0));
    figuras.push_back(a);


    imprime_area_total(figuras);


    return 0;
}
