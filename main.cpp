#include <iostream>
#include<string.h>
#include<fstream>
#include <PDCurses-3.9/curses.h>

#include<stdio.h>
#include<windows.h>


#include "listadoble.h"

using namespace std;

























int
main() {
    ListaDoble *texto= new ListaDoble();




    WINDOW *w;
    char list[13][26] = {"Universidad de San Carlos","Facultad de Ingenieria","Estructuras de Datos","Practica 1","Sergio Ariel Ramirez", "201020252"," "," " , "Menu", "1.Crear_Archivo", "2.Abrir_Archivo", "3.Archivos_Recientes", "4.Salir  Ctl+X" };
    char item[12];
    int ch, i = 0;

    initscr(); // initialize Ncurses
    w = newwin( 20, 80, 1, 1); // create a new window yf , xf, yi, xi
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

                     if( i == 9 ){ ////opcion 1 del menu


                            int ch;
                            WINDOW *z;

                            initscr();

                            z = newwin( 28, 80, 1, 1); // create a new window yf , xf, yi, xi
                            box( z, 0, 0 ); // establece bordes predeterminados para la ventana

                            mvwprintw(z, 27, 2, "%s", " ^W Buscar y Reemplazar ");
                            mvwprintw(z, 27, 28, "%s", " ^C Reportes ");
                            mvwprintw(z, 27, 43, "%s", " ^G Guardar ");
                            mvwprintw(z, 27, 43, "%s", " ESC Salir ");

                                      wattron( w, A_STANDOUT );

          sprintf(item, "%-7s",  list[i]);
            mvwprintw( z, y, x, "%s", "|");
            wattroff( z, A_STANDOUT );

                            wrefresh( z ); // actualizar la pantalla del terminal


                            noecho(); // deshabilitar el eco de caracteres en la pantalla
                            keypad( z, TRUE ); // habilitar la entrada de teclado para la ventana.

                            // obtener la entrada
                            while(( ch = wgetch(z)) != 27){                              // Presione la tecla ESC para Salir
                            mvwprintw(z, y, x, "%s", "|");

                            // Capto las entradas en este switch
                            switch( ch ) {

                            case 03:
                             texto->generar_txt();

                            break;

                            case KEY_DOWN:
                            break;



                            default:



                            if(ch==0xa){
                            char put = putchar(ch);
                            std::string s(1,'\n');
                            texto->add_last(s);
                            mvwprintw(z, y, x, "%s", " ");
                            x=3; y++;

                            break;
                            }else if(ch!=03){

                            char
                            put = putchar(ch);
                            mvwprintw(z, y, x, "%c", ch); //Asi Obtento el Caracter de la tecla pulsada
                            //mvwprintw(z, y, x, "%#02x", ch); //Asi imprimo el codigo hex de la tecla pulsada
                            //mvwprintw(z, 12, 43, "%c", put); // Asi imprimo un texto
                            x++;
                            if(x==76){x=3; y++;}
                            // ingreso a texto cada caracter leido
                            std::string s(1,put);
                            texto->add_last(s);


                            break;
                            }

                            break;
                            }

                            mvwprintw(z, y, x, "%s", "|");

                            }

                            delwin( z );
                            endwin();

                            box( w, 0, 0 ); // establece bordes predeterminados para la ventana
                             wrefresh( w ); // actualizar la pantalla del terminal




























                     }



                            break;
                default:


                    break;



            }




            // ahora resalte el siguiente elemento en la lista.
           wattron( w, A_STANDOUT );

          sprintf(item, "%-7s",  list[i]);
            mvwprintw( w, i+1, 2, "%s", item);
            wattroff( w, A_STANDOUT );




    }

    delwin( w );
    endwin();
}
