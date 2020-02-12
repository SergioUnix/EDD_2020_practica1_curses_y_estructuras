#include <iostream>
#include<string.h>
#include<fstream>
#include <PDCurses-3.9/curses.h>

#include<stdio.h>
#include<windows.h>





using namespace std;


















void op1(){

        int ch, i = 0, width = 7;
      WINDOW *z;
      initscr();

       z = newwin( 20, 80, 1, 1); // create a new window yf , xf, yi, xi
       box( z, 0, 0 ); // establece bordes predeterminados para la ventana
       mvwprintw(z, 19, 2, "%s", "^W Buscar y Reemplazar");
       mvwprintw(z, 19, 28, "%s", "^C Reportes");
       mvwprintw(z, 19, 43, "%s", "^G Guardar");


   wrefresh( z ); // actualizar la pantalla del terminal


    noecho(); // deshabilitar el eco de caracteres en la pantalla
    keypad( z, TRUE ); // habilitar la entrada de teclado para la ventana.

       // obtener la entrada
    while(( ch = wgetch(z)) != 'q'){





;
              // use una variable para incrementar o disminuir el valor basado en la entrada.
            switch( ch ) {
                case KEY_UP:

                            break;
                case KEY_DOWN:

                            break;


                case 0xa:


                break;
            }



  }

    delwin( z );
    refresh();
    endwin();

}










int
main() {

    WINDOW *w;
    char list[13][26] = {"Universidad de San Carlos","Facultad de Ingenieria","Estructuras de Datos","Practica 1","Sergio Ariel Ramirez", "201020252"," "," " , "Menu", "1.Crear_Archivo", "2.Abrir_Archivo", "3.Archivos_Recientes", "4.Salir" };
    char item[12];
    int ch, i = 0, width = 7;

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




       // obtener la entrada
    while(( ch = wgetch(w)) != 'q'){

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
                case 0xa:

                     if( i == 9 ){ ////opcion 1 del menu


                            int ch, i = 0, width = 7;
                            WINDOW *z;
                            initscr();

                            z = newwin( 20, 80, 1, 1); // create a new window yf , xf, yi, xi
                            box( z, 0, 0 ); // establece bordes predeterminados para la ventana
                            mvwprintw(z, 19, 2, "%s", "^W Buscar y Reemplazar");
                            mvwprintw(z, 19, 28, "%s", "^C Reportes");
                            mvwprintw(z, 19, 43, "%s", "^G Guardar");


                            wrefresh( z ); // actualizar la pantalla del terminal


                            noecho(); // deshabilitar el eco de caracteres en la pantalla
                            keypad( z, TRUE ); // habilitar la entrada de teclado para la ventana.

                            // obtener la entrada
                            while(( ch = wgetch(z)) != 'q'){

                             // use una variable para incrementar o disminuir el valor basado en la entrada.
                            switch( ch ) {
                            case KEY_UP:

                            break;
                            case KEY_DOWN:

                            break;


                            case 0xa:


                            break;
                            }



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
