#include <iostream>

template <typename T>
class Matrix{
    T* dados;
    int nlin;
    int ncol;
  public:
    // Construtor normal para alocar o espaço nlin * ncol para a Matrix
    Matrix(int nlin, int ncol) : nlin(nlin), ncol(ncol){
        dados = new T[nlin * ncol]();
    }
    // Este construtor permite inicializar a matrix com a sintaxe:
    // Matrix a = {{elemento1, elemento2}, {elemento3, elemento 4}}
    // C++ considera {elemento1, elemento2} como um objeto do tipo std::initializer_list
    Matrix(std::initializer_list<std::initializer_list<T>> linhas){
        nlin = linhas.size();
        ncol = linhas.begin()->size();
        dados = new T[nlin * ncol]();
        for(int i=0; i<nlin; i++){
            std::initializer_list<T> linha = *(linhas.begin() + i);
            std::copy(linha.begin(), linha.end(), dados + i*ncol);
        }
    }
    // Quando é feito Matrix a = b, o construtor de cópia padrão vai simplemente copiar o ponteiro de
    // dados, se b for destruído, o ponteiro de dados de a ficara inválido.
    // Neste caso, é necessário alocar dados para a e copiar o conteúdo b.dados para a.dados
    Matrix(const Matrix& other){
        this->nlin = other.nlin;
        this->ncol = other.ncol;
        this->dados = new T[nlin * ncol]();
        std::copy(other.dados, other.dados + nlin * ncol, this->dados);
    }
    // Quando é feito a = b, onde a e b são matrizes já inicializadas, o operador = padrão vai copiar
    // o ponteiro de dados de b para a. Isso é inválido, já que a tem seu próprio espaço de memória.
    // A solução é pedir para copiar b.dados para a.dados.
    // Lembre que como a e b já estão inicializados não é necessario alocar um novo espaço para a.
    void operator=(const Matrix& other){
        delete[] this->dados;
        this->nlin = other.nlin;
        this->ncol = other.ncol;
        this->dados = new T[nlin * ncol]();
        std::copy(other.dados, other.dados + nlin * ncol, this->dados);
    }
    // Destrutor normal de dados
    ~Matrix(){
        delete[] dados;
    }

    // Declare operadores aqui

    T operator [](int indice)
    {
        return dados[indice];
    }
    Matrix operator +(Matrix b)
    {
        Matrix resultante(this->nlin, this->ncol);
        for(int i=0; i<(nlin*ncol);i++)
        {
            resultante.dados[i] = dados[i] + b.dados[i];
        }
        return resultante;
    }
    Matrix operator -(Matrix b)
    {
        Matrix resultante(this->nlin, this->ncol);
        for(int i=0; i<(nlin*ncol);i++)
        {
            resultante.dados[i] = dados[i] - b.dados[i];
        }
        return resultante;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& m);

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& m) {
    for (int i = 0; i < m.nlin; ++i) {
        for (int j = 0; j < m.ncol; ++j) {
            os << m.dados[i * m.ncol + j] << ' ';
        }
        os << '\n';
    }
    return os;
}


int main(){
    Matrix<float> m1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<float> m2 = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    Matrix<float> m3 = {{2, 3}, {7, 8}, {9, 0}};
    std::cout << m1 + m2;
    // std::cout << m1 - m2;
    // std::cout << m1 * m2;
    // std::cout << m1 * m3;
    // std::cout << (m2 ^ 5);
}
