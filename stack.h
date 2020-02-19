#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <string>

template <class T> class Node
{
public:
    T value;
    std::string rem;
    std::string estado;
    std::string palabra;
    std::string posicion;
    Node* next;

    void setDato(T n) { value = n;}
    T getDato(){ return value;}

    void setRem(std::string n) { rem = n;}
    std::string getRem(){ return rem;}

    void setEstado(std::string es) { estado = es;}
    std::string getEstado() {return estado;}

        Node(T Dato, std::string Rem)
        {
            value = Dato;
            rem = Rem;
            estado="";
            palabra="";
            posicion="";
            next=0;

        }
};

template <class T> class Stack  ////////////////////////// de la clase
{
public:
    Node<T>* top = 0;


    void show(){
        Node<T>* tmp = top;
        while (tmp != 0)
        {
            std::cout << tmp->value << " ";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }


    void push(T value,std::string rem){
        if (top == 0) top = new Node<T>(value, rem);
        else
        {
            Node<T>* tmp = top;
            top = new Node<T>(value, rem);
            top->next = tmp;
        }
    }





    void pop(){
        if (top != 0)
        {
            Node<T>* tmp = top;
            top = top->next;
            delete tmp;
        }
    }



  std::string  grafic(){

        std::string linea1=" digraph G {";
        std::string linea2="nodesep=.02;";
        std::string linea3="rankdir=LR;";
        std::string linea4="node [shape=record,width=.1,height=.1];";
        std::string linea5="node0 [label = \"<f0> ";
        std::string linea6="\",height=2.5];";
        std::string linea7="node [width =1.5];";
        int index=0;
        std::string nodos="";
        //sistema=self.items
        //sistema.reverse()

        Node<T> *tmp = top;
        char str;
        std::string conver("");

        std::string prueba="";
        Node<T>* tmp2 = top;
        while (tmp2 != 0)
        {
            prueba = prueba + tmp2->getDato() + "/n ";
            tmp2 = tmp2->next;
        }






        while(tmp!=0){



            nodos=nodos+"|<f"+"2"+">["+ tmp->getDato() +","+ tmp->getRem() +"]";
            index=index+1;
            tmp = tmp->next;
            conver="";
        }


        std::string lineafinal="}";
        std::string grafo= linea1+linea2+linea3+linea4+linea5+nodos+linea6+linea7+lineafinal;
        return grafo;








    };

void generar_txt(){
std::string texto= grafic();
std::ofstream archivo;
archivo.open("realizados.txt", std::ios:: out);

archivo<<texto;
archivo.close();

        std::string sentencia="dot -Tpng realizados.txt -o realizados.png";
        std::string sentencia2="start realizados.png";
        std::string salir="EXIT";
        system(sentencia.c_str());
        system(sentencia2.c_str());
        system(salir.c_str());


};






};


#endif // STACK_H_INCLUDED
