#include <iostream>
#include<string.h>
#include<fstream>
#include <PDCurses-3.9/curses.h>

#include<stdio.h>
#include<windows.h>


#include "listadoble.h"
#include "stack.h"
using namespace std;













void repintar_p2(WINDOW * w, int y, int x){
    //refresh();
     //wclear(w);
     char termi[1];
        initscr(); // initialize Ncurses

      w = newwin( 28, 80, 1, 1); // create a new window yf , xf, yi, xi
                            box( w, 0, 0 ); // establece bordes predeterminados para la ventana

                            mvwprintw(w, 27, 2, "%s", " ^W Buscar y Reemplazar ");
                            mvwprintw(w, 27, 28, "%s", " ^C Reportes ");
                            mvwprintw(w, 27, 43, "%s", " ^G Guardar ");
                            mvwprintw(w, 27, 43, "%s", " ESC Salir ");
                            mvwprintw(w, 27, 57, "%s", " ^D Nuevo Documento ");

                        //noecho(); // deshabilitar el eco de caracteres en la pantalla
                           // keypad( w, TRUE ); // habilitar la entrada de teclado para la ventana.
                            //curs_set( 1 ); // Ocultar el cursor de pantalla predeterminado.



                            //wattron( w, A_STANDOUT );

                            wrefresh( w ); // actualiza



};


void repintar(WINDOW *w){
    char list[13][26] = {"Universidad de San Carlos","Facultad de Ingenieria","Estructuras de Datos","Practica 1","Sergio Ariel Ramirez", "201020252"," "," " , "Menu", "1.Crear_Archivo", "2.Abrir_Archivo", "3.Archivos_Recientes", "4.Salir  Ctl+X" };
    char item[12];
    int ch, i = 0;

    initscr(); // initialize Ncurses
    w = newwin( 28, 80, 1, 1); // create a new window yf , xf, yi, xi
    box( w, 0, 0 ); // establece bordes predeterminados para la ventana

    // ahora imprima todos los elementos del menú y resalte el primero
    for( i=0; i<13; i++ ) {
        if( i == 8 )
            wattron( w, A_STANDOUT ); //  Destaca el primer ítem.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
      wmove(w , 2, 3);

    wrefresh( w ); // actualizar la pantalla del terminal

}

void repinto_texto(WINDOW *w,ListaDoble* texto){
 int ys=2, xs=3;
 int tam =texto->getSize();

 char list[tam][1];
     int n1 = 1;
    char char_a[n1];
    string a;


 char term[12];

 if (tam>0){
        for(int k=0;k<tam;k++){
        a=texto->get_element_at(k);
        strcpy(char_a, a.c_str());
        list[k][0]=char_a[0];

        sprintf(term, "%s", list[k] ); fflush(stdin);
        mvwprintw( w, ys, xs, "%s", term ); fflush(stdin);


        if(xs==76){ys++; xs=3;}else{
         xs++;}

        }

        //wmove(w , 2, 3);

 }

 wmove(w , ys, xs);
 wrefresh( w ); // actualizar la pantalla del terminal




};






void pedir_palabra(WINDOW * w, int x, int y,ListaDoble* texto,Stack<string> *realizados,Stack<string> *revertidos){
    string cadena_remplazo;
    //refresh();
    int chr;
    int xr=36,yr=2;
     wclear(w);
      wrefresh( w ); // actualiza
     char termi[1];
        initscr(); // initialize Ncurses

      w = newwin( 28, 80, 1, 1); // create a new window yf , xf, yi, xi
                            box( w, 0, 0 ); // establece bordes predeterminados para la ventana

                            mvwprintw(w, 2, 2, "%s", "Ingresar la palabra a sustituir: ");

                            noecho(); // deshabilitar el eco de caracteres en la pantalla
                            keypad( w, TRUE ); // habilitar la entrada de teclado para la ventana.
                            curs_set( 1 ); // Ocultar el cursor de pantalla predeterminado.
                           wmove(w , yr, xr);
                           wrefresh( w ); // actualiza

while(( chr = wgetch(w)) != 0xa){   //presione Enter  para salir del programa


              // use una variable para incrementar o disminuir el valor basado en la entrada.
            switch( chr ) {
                case KEY_UP:

                            break;
                case KEY_DOWN:
                            break;

                default:



                    char p = putchar(chr);
                            mvwprintw(w, yr, xr, "%c", chr); //Asi Obtento el Caracter de la tecla pulsada
                            //mvwprintw(z, y, x, "%#02x", ch); //Asi imprimo el codigo hex de la tecla pulsada
                            //mvwprintw(z, 12, 43, "%c", put); // Asi imprimo un texto
                            xr++;

                            // ingreso a texto cada caracter leido
                            std::string u(1,p);
                            cadena_remplazo= cadena_remplazo + u;


            }

            }

ListaDoble *comodin= new ListaDoble();

char separador = ';'; //aqui vas a introducir el separador -en mi caso es un espacio-
std::string sentencia=cadena_remplazo; //aqui pones la oracion.
for(size_t p=0, q=0; p!=sentencia.npos; p=q){
cout << sentencia.substr(p+(p!=0),(q=sentencia.find(separador, p+1))-p-(p!=0))<<endl;
comodin->add_last(sentencia.substr(p+(p!=0),(q=sentencia.find(separador, p+1))-p-(p!=0)));
}


          bool lala=   texto->existe_palabra(comodin->get_element_at(0), comodin->get_element_at(1));

          if (lala==true){
            realizados->push(comodin->get_element_at(0),comodin->get_element_at(1));
          }





};






void reportes(WINDOW *w, ListaDoble* texto,Stack<string>* realizados,Stack<string>* revertidos){
refresh();
    WINDOW *tu;
    int ch_tu, i = 0;
    initscr(); // initialize Ncurses
    tu = newwin( 28, 80, 1, 1); // create a new window yf , xf, yi, xi
    box( tu, 0, 0 ); // establece bordes predeterminados para la ventana

    string cadena_remplazo;
    //
    int xr=18,yr=7;
    // wclear(tu);
    box( tu, 0, 0 ); // establece bordes predeterminados para la ventana

     char termi[1];
                            mvwprintw(tu, 2, 2, "%s", "1. Reporte 1 ListaDoblemente enlazada ");
                            mvwprintw(tu, 3, 2, "%s", "2. Reporte pila de palabras buscadas  ");

                            mvwprintw(tu, 4, 2, "%s", "3. Reporte pila de revertidos ");
                              mvwprintw(tu, 5, 2, "%s", "4. Reporte de palabras ordenadas ");
                              mvwprintw(tu, 7, 2, "%s", "Ingresar Numero: " );

                            //noecho(); // deshabilitar el eco de caracteres en la pantalla
                            keypad( tu, TRUE ); // habilitar la entrada de teclado para la ventana.
                            curs_set( 1 ); // Ocultar el cursor de pantalla predeterminado.
                           wmove(tu , yr, xr);
                           wrefresh( tu ); // actualiza

while(( ch_tu = wgetch(tu)) != 0xa){   //presione Enter  para salir del programa


              // use una variable para incrementar o disminuir el valor basado en la entrada.
            switch( ch_tu ) {
                case 49: // numero 1
                       mvwprintw(tu, yr, xr, "%c", ch_tu); //Asi Obtento el Caracter de la tecla pulsada
                       texto->generar_txt();
                            break;
                case 50: //numero 2
                       mvwprintw(tu, yr, xr, "%c", ch_tu); //Asi Obtento el Caracter de la tecla pulsada
                       realizados->generar_txt();
                            break;
                case 51:  //numero 3
                       mvwprintw(tu, yr, xr, "%c", ch_tu); //Asi Obtento el Caracter de la tecla pulsada
                            revertidos->generar_txt();
                            break;
                case 52:
                       mvwprintw(tu, yr, xr, "%c", ch_tu); //Asi Obtento el Caracter de la tecla pulsada
                            break;
                default:
                    mvwprintw(tu, yr, xr, "%s", "                             "); //Asi Obtento el Caracter de la tecla pulsada
                    break;

            }

            }

           wrefresh(tu);



    delwin( tu );
    endwin();


    repintar(w);





};



















int main() {
    ListaDoble *texto= new ListaDoble();
    Stack<string>* realizados = new Stack<string>();
    Stack<string>* revertidos = new Stack<string>();
    std::string palabra="";


    WINDOW *w;
    char list[13][26] = {"Universidad de San Carlos","Facultad de Ingenieria","Estructuras de Datos","Practica 1","Sergio Ariel Ramirez", "201020252"," "," " , "Menu", "1.Crear_Archivo", "2.Abrir_Archivo", "3.Archivos_Recientes", "4.Salir  Ctl+X" };
    char item[12];
    char te[1];
    int ch, i = 0;
    initscr(); // initialize Ncurses
    w = newwin( 28, 80, 1, 1); // create a new window yf , xf, yi, xi
    box( w, 0, 0 ); // establece bordes predeterminados para la ventana

    // ahora imprima todos los elementos del menú y resalte el primero
    for( i=0; i<13; i++ ) {
        if( i == 8 )
            wattron( w, A_STANDOUT ); //  Destaca el primer ítem.
        else
            wattroff( w, A_STANDOUT );
        sprintf(item, "%-7s",  list[i]);
        mvwprintw( w, i+1, 2, "%s", item );
    }
    wrefresh( w ); // actualizar la pantalla del terminal

    i = 8;
    noecho(); // deshabilitar el eco de caracteres en la pantalla
    keypad( w, TRUE ); // habilitar la entrada de teclado para la ventana.
    curs_set( 0 ); // Ocultar el cursor de pantalla predeterminado.

    //int caracteres =0;
    int x=3,y=2;




       // obtener la entrada
    while(( ch = wgetch(w)) != 24){   //presione control + X para salir del programa

                // pad derecho con espacios para hacer que los elementos aparezcan con un ancho uniforme.
            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item );
              // use una variable para incrementar o disminuir el valor basado en la entrada.
            switch( ch ) {
                case KEY_UP:
                            i--;
                            i = ( i<8 ) ? 12 : i;
                            break;
                case KEY_DOWN:
                            i++;
                            i = ( i>12 ) ? 8 : i;
                            break;
                case 0xa:  // detecta un enter
                     //wrefresh(w);
                     //wclear(w);
                     if( i == 9 ){ ////opcion 1 del menu  /////////////////////////////////////////////////////////////

                            //mvwprintw(w, y, x, "%s", "");
                            wrefresh(w);
                            // REPINTO LA PANTALLA 2
                            repintar_p2(w,y,x);
                            // Repinto el texto ya lleno
                            repinto_texto(w,texto); fflush(stdin);
                            wmove(w , y, x);
                            getyx( w, y, x);
                            mvwprintw(w, y, x, "%s", "");




                            keypad( w, TRUE ); // habilitar la entrada de teclado para la ventana.
                            curs_set( 1 ); // Ocultar el cursor de pantalla predeterminado.



                            // obtener la entrada
                            while(( ch = wgetch(w)) != 27){                              // Presione la tecla ESC para Salir
                               repinto_texto(w,texto);
                               wrefresh(w);

                            // Capto las entradas en este switch
                            switch( ch ) {

                            case 03:      // control c para generar el reporte

                             reportes(w, texto,realizados,revertidos);
                             wrefresh(w);

                            break;
                            case 04:      // control D reseteo los valores para nuevo proyecto

                             texto=new ListaDoble();
                             refresh(); x=3; y=2;
                            repintar_p2(w,y,x);
                            repinto_texto(w,texto); fflush(stdin);
                            wmove(w , y, x);
                            getyx( w, y, x);
                            mvwprintw(w, y, x, "%s", "");


                             wrefresh(w);

                            break;

                            case 23:   //control + w para recibir palabra a sustituir



                            pedir_palabra(w, x , y, texto, realizados ,revertidos);

                             //mvwprintw(w, y, x, "%s", "");
                            //wrefresh(w);
                            // REPINTO LA PANTALLA 2
                            repintar_p2(w,y,x);
                            // Repinto el texto ya lleno
                            repinto_texto(w,texto);

                            break;




                            default:

                            //mvwprintw(w, 27, 65, "%#02x", "          ");
                            //mvwprintw(w, 27, 65, "%#02x", ch);



                            if(ch==0xa){
                            texto->add_last(" ");
                            getyx( w, y, x);
                           // mvwprintw(w, y, x, "%s", " ");
                            //x=3;
                             y++;
                             x=3;

                           mvwprintw(w, y, 3, "%s", ""); fflush(stdin);
                           //wmove(w,y,x);


                           //refresh();

                           break;


                            }else if(ch>31 && ch <127){
                                wrefresh(w);
                                getyx( w, y, x);

                            char put = putchar(ch);
                            // mvwprintw(w, y, x, "%c", ch); //Asi Obtento el Caracter de la tecla pulsada
                            //mvwprintw(z, y, x, "%#02x", ch); //Asi imprimo el codigo hex de la tecla pulsada
                            //mvwprintw(z, 12, 43, "%c", put); // Asi imprimo un texto
                            x++;
                            if(x==76){x=3; y++;  texto->add_last(" ");  }
                            // ingreso a texto cada caracter leido
                            std::string s(1,put);  fflush(stdin);
                            texto->add_last(s);  fflush(stdin);


                             ;
                            wrefresh(w);
                            // REPINTO LA PANTALLA 2
                            //repintar_p2(w,y,x);
                            // Repinto el texto ya lleno
                            repinto_texto(w,texto); fflush(stdin);
                            wmove(w , y, x);
                            getyx( w, y, x);
                            mvwprintw(w, y, x, "%s", "");
                            break;
                            }







                            break;
                            }


                            }
                            //seteo las coordenadas del puntero
                            //x=3;y=2;
                            // BORRO LA VENTANA
                            refresh();
                            //REPINTO EL MENU
                            repintar(w);






























                     }



                            break;
                default:


                    break;



            }




            // ahora resalte el siguiente elemento en la lista (en el Menu principal)
            wattron( w, A_STANDOUT );

            sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );




    }

    delwin( w );
    endwin();
}
