#include <iostream>
#include <list>

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
