#include <iostream>
#include<string.h>
#include<fstream>
#include <PDCurses-3.9/curses.h>


#define ENTER ' /n'
#define INTRO '/r'

#include<stdio.h>
#include<windows.h>





using namespace std;

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
                case 0x41:
                            i++;
                            i = ( i>12 ) ? 8 : i;
                            break;
                case VK_RETURN:
                            i++;
                            i = ( i>12 ) ? 8 : i;
                            break;
                default:

                    initscr();			/* Start curses mode 		  */
	                printw("Hello World !!!");	/* Print Hello World		  */
	                printw("\nHas tecleado: %c\n", ch);

	                refresh();			/* Print it on to the real screen */
	                //getch();			/* Wait for user input */
	                endwin();			/* End curses mode		  */



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
