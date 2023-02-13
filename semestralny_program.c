#include <stdio.h>
#include <stdlib.h>
#include <string.h> //pre pracu s retazcami
#include <conio.h> //pre prikaz getch()

int main()
{


    char c = 's';
    do{
        if(c == 's'){
            system("@cls||clear"); //vymazanie obrazovky, ktore nemusi vzdy fungovat
            printf("1)   Zasobniky\n");
            printf("2)   Rady\n");
            printf("3)   Jednosmerne spajane zoznamy\n");
            printf("4)   Obojsmerne spajane zoznamy\n");
            printf("5)   Stromy\n");
            printf("6)   Vyhladavanie(linearne, binarne, BST)\n");
            printf("7)   Vyhladavanie so spatnym navratom\n");
            printf("8)   Dynamicke programovanie\n");
            printf("9)   Hashovanie\n");
            printf("0)   Vyhladavanie podretazcov v retazcoch\n");
            printf("t)   Triedenie\n");
            printf("Esc) Koniec\n");
        };
        fflush(stdin);
        c = getch();
        switch(c){
            case '1':
                system("@cls||clear");
                printf("Zasobniky:\n");
                printf("1)   Zasobnik s naraznikom\n");
                printf("2)   Zasobnik bez naraznika\n");
                printf("3)   Zasobnik jednorozmernym polom\n");
                printf("4)   Reverz retazca\n");
                printf("5)   Ananlyza aritmetickeho vyrazu\n");
                printf("s)   Spat\n");
                printf("Esc) Koniec\n");
                do{
                    fflush(stdin);
                    c = getch();
                    switch(c){
                        case '1':
				system("@cls||clear");
                        	printf("Zasobnik/Zasobnik s naraznikom\n");
                                break;
			case '2':
                        	system("@cls||clear");
                        	printf("Zasobnik/Zasobnik bez naraznika\n");
                        	break;
                    	case '3':
                        	system("@cls||clear");
                        	printf("Zasobnik/Zasobnik jednorozmernym polom\n");
                        	break;
                    	case '4':
                        	system("@cls||clear");
                        	printf("Zasobnik/Reverz retazca\n");
                        	break;
                    	case '5':
                        	system("@cls||clear");
                        	printf("Zasobnik/Analyza aritmetickeho retazca\n");
                        	break;
                    }
                }while(c!= 27 && c !='s');
                break;
            case '2':
                system("@cls||clear");
                printf("Rady:\n"); break;
            case '3':
                system("@cls||clear");
                printf("Jednosmerne spajane zoznamy:\n"); break;
            case '4':
                system("@cls||clear");
                printf("Obojsmerne spajane zoznamy:\n"); break;
            case '5':
                system("@cls||clear");
                printf("Stromy:\n"); break;
            case '6':
                system("@cls||clear");
                printf("Vyhladavanie(linearne, binarne, BST):\n"); break;
            case '7':
                system("@cls||clear");
                printf("Vyhladavanie so spatnym navratom:\n"); break;
            case '8':
                system("@cls||clear");
                printf("Dynamicke programovanie:\n"); break;
            case '9':
                system("@cls||clear");
                printf("Hashovanie:\n"); break;
            case '0':
                system("@cls||clear");
                printf("Vyhladavanie podretazcov v retazcoch:\n"); break;
            case 't':
                system("@cls||clear");
                printf("Triedenie:\n"); break;
            case 27: break;
        }


    }while(c != 27);
    return 0;
}