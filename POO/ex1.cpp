#include <iostream>
#include <list>

/* Dado uma sequência de texto de um chat, Lattes escreveu uma aplicação para mostrar uma bandeira relacionado ao idioma antes do texto.
 Ele utilizou herança nas suas classes, criando uma classe Base texto que armazena a mensagem, e duas classes derivadas que tem uma constante 
 da bandeira e o método getTexto para mostrar a bandeira e a mensagem. Lattes criou uma lista da classe Texto. Para 
cada entrada, ele alocava um objeto da classe derivada correspondente e adicionava na lista. Finamente, ele chama a função imprimir_
chat que recebe a lista, e seu desejo é imprimir o texto com a bandeira correta, chamando o método getTexto de cada entrada na lista.
 O problema é que Lattes não conseguiu escrever algumas linhas de código:
 Na função imprimir_chat ele não soube como iterar (percorrer cada elemento) da lista de texto.
 Na função imprimir_chat ele ainda precisa chamar o método getTexto e redirecioná-lo para std::cout.
 No final do main, ele não sabe como liberar a memória dos objetos alocados com delete.
 Ajude Lattes a terminar seu programa, lembre que você precisara declarar algumas funções como virtuais!
*/


class Texto {
    protected:
        std::string txt;
    public:
        Texto(std::string ptxt) : txt(ptxt) {}
        virtual ~Texto() {} 
        virtual std::string getTexto() const = 0; // Método virtual puro
};

class TextoPortugues : public Texto {
    // Código UTF-8 para bandeira
    std::string bandeira = u8"\360\237\207\247\360\237\207\267 ";
    public:
        using Texto::Texto; // Copiar Construtor de Texto
        std::string getTexto() const override {
            return(bandeira + txt + "\n");
        }
};

class TextoIngles : public Texto {
    // Código UTF-8 para bandeira
    std::string bandeira = u8"\360\237\207\272\360\237\207\270 ";
    public:
        using Texto::Texto; // Copiar Construtor de Texto
        std::string getTexto() const override {
            return(bandeira + txt + "\n");
        }
};

void imprimir_chat(std::list<Texto*> chat) {
    //for(tipo_lista elemento : lista)
    for(auto inicio = chat.begin(); inicio != chat.end(); ++inicio) {
        if(*inicio != nullptr) {
            std::cout << (*inicio)->getTexto(); 
        }
    }
}

int main() {
    std::list<Texto*> chat;
    chat.push_back(new TextoPortugues("Olá"));
    chat.push_back(new TextoIngles("Hello"));
    chat.push_back(new TextoIngles("How are you?"));
    chat.push_back(new TextoPortugues("Eu vou bem!"));
    
    imprimir_chat(chat);
    
    // Liberar a memória de todos os elementos
    for(auto inicio = chat.begin(); inicio != chat.end(); ++inicio) {
        delete *inicio;
    }
    chat.clear();
    
    // Asserções para garantir polimorfismo e abstratividade
    static_assert(std::is_polymorphic_v<Texto>);
    static_assert(std::is_abstract<Texto>(), "A classe texto não é abstrata");

    return 0;
}
