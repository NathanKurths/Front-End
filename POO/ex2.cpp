#include <iostream>
#include <list>

/*
Considere uma figura que é formada por formas geométricas do tipo quadrado, triângulo, círculo e que não se intersectam.

Implemente uma classe Figura que armazene estas formas geométricas e implemente um método calcula_area() que retorna o somatório de todas as areas das formas geométricas.

- Utilize uma classe abstrata e polimorfismo para as formas geométricas.

Implemente o main que leia a seguinte estrutura:

- Primeira linha contém n, o número de formas geométricas da figura.

- Seguido por n linhas começando com uma string da forma geométrica, podendo ser "quadrado", "triangulo", ou "circulo".

  - No caso de quadrado, a linha contêm um float que representa o lado do quadrado.

  - No caso de triângulo, a linha contêm dois floats que representam a altura e a largura do triângulo.

  - No caso de círculo, a linha contêm um float que representa o raio do círculo.
  
  Exemplo de entradas:
    quadrado 5
    triangulo 2 3
    circulo 10
    quadrado 2
    triangulo 5 5

   Saída:
    358.5*/
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
