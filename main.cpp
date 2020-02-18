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

                            //noecho(); // deshabilitar el eco de caracteres en la pantalla
                            keypad( w, TRUE ); // habilitar la entrada de teclado para la ventana.
                            curs_set( 1 ); // Ocultar el cursor de pantalla predeterminado.



                            wattron( w, A_STANDOUT );

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

        sprintf(term, "%s", list[k] );
        mvwprintw( w, ys, xs, "%s", term );


        if(xs==76){ys++; xs=3;}else{
         xs++;}

        }

 }

 wrefresh( w ); // actualizar la pantalla del terminal



};






void pedir_palabra(WINDOW * w, int x, int y,ListaDoble* texto){
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
                            // REPINTO LA PANTALLA 2
                            repintar_p2(w,y,x);
                            // Repinto el texto ya lleno
                            repinto_texto(w,texto);
                            wmove(w , y, x);
                             // wrefresh( w ); // actualiza


mvwprintw(w, 15, 15, "%s", cadena_remplazo);

int chjeje;

chjeje = wgetch(w);




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
                     wclear(w);
                     if( i == 9 ){ ////opcion 1 del menu  /////////////////////////////////////////////////////////////

                             mvwprintw(w, y, x, "%s", "");
                            wrefresh(w);

                            // REPINTO LA PANTALLA 2
                            repintar_p2(w,y,x);
                            // Repinto el texto ya lleno
                            repinto_texto(w,texto);
                            wmove(w , y, x);


                            //noecho(); // deshabilitar el eco de caracteres en la pantalla
                            keypad( w, TRUE ); // habilitar la entrada de teclado para la ventana.

                            // obtener la entrada
                            while(( ch = wgetch(w)) != 27){                              // Presione la tecla ESC para Salir


                            // Capto las entradas en este switch
                            switch( ch ) {

                            case 03:      // control c para generar el reporte
                             texto->generar_txt();
                             wrefresh(w);

                            break;

                            case 23:   //control + w para recibir palabra a sustituir

                               wrefresh( w ); // actualiza

                            pedir_palabra(w, x , y, texto);
                            mvwprintw(w, y, x, "%s", "");


                            break;




                            default:

                            mvwprintw(w, 27, 65, "%#02x", "          ");
                            mvwprintw(w, 27, 65, "%#02x", ch);



                            if(ch==0xa){
                            texto->add_last(" ");
                            mvwprintw(w, y, x, "%s", " ");
                            x=3; y++;

                            break;
                            }else if(ch!=03){

                            char put = putchar(ch);
                            mvwprintw(w, y, x, "%c", ch); //Asi Obtento el Caracter de la tecla pulsada
                            //mvwprintw(z, y, x, "%#02x", ch); //Asi imprimo el codigo hex de la tecla pulsada
                            //mvwprintw(z, 12, 43, "%c", put); // Asi imprimo un texto
                            x++;
                            if(x==76){x=3; y++;  texto->add_last(" ");  }
                            // ingreso a texto cada caracter leido
                            std::string s(1,put);
                            texto->add_last(s);


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
