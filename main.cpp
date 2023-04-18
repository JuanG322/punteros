#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

//Structs
//Ejercicio 13
struct Vocales {
    int A;
    int E;
    int I;
    int O;
    int U;
};
//Ejercicio 17
struct Persona{
    char nombre[30];
    int edad;
}persona, *puntero_persona = &persona;

//Ejercicio 18
struct Alumno{
    char nombre [30];
    int edad;
    float promedio;
}alumno[3], *puntero_alumno = alumno;

//Ejercicio 19
struct Etapas{
    int horas,minutos,segundos;
}tiempo[3], *puntero_ciclista = tiempo;

//Header
//Ejercicio 9
int hallarMax(int*,int);
//Ejercicio 12
int contador(char *);
//Ejercicio 13
Vocales contadorVocales(char *);
//Ejercicio 15
void sumarMatrices(int**, int**, int, int);
//Ejercicio 17
void pedirDatos();
void mostrarDatos(Persona *);
//Ejercicio 18
void pedirDatos2();
void calcularpromedio(Alumno *);
//Ejercicio 19
void datos_ciclista();
void tiempo_total(Etapas *);

int main()
{
    int opcion = 1;
    while(opcion != 0){
        cout<<"Ingrese una opcion"<<endl;
        cout<<"1. Basicos punteros"<<endl;
        cout<<"2. Numero par o impar"<<endl;
        cout<<"3. Numero es primo"<<endl;
        cout<<"4. Punteros y arreglos"<<endl;
        cout<<"5. Numeros pares de un arreglos"<<endl;
        cout<<"6. El elemento menor de un arreglo"<<endl;
        cout<<"7. Almacenar elementos en arreglos dinamicos"<<endl;
        cout<<"8. Intercambiar valores de 2 elementos con punteros"<<endl;
        cout<<"9. El numero mayor de un arreglo"<<endl;
        cout<<"10. Ordenamiento de un arreglo con punteros"<<endl;
        cout<<"11. Meotodo de busqueda con punteros"<<endl;
        cout<<"12. Numero de letras de una frase con punteros"<<endl;
        cout<<"13. Contar cada letra individualmente con punteros"<<endl;
        cout<<"14. Punteros y matrices"<<endl;
        cout<<"15. Duma de 2 matrices dinamicas"<<endl;
        cout<<"16. Transpuesta de una matriz"<<endl;
        cout<<"17. Punteros a structs"<<endl;
        cout<<"18. Notas de 3 alumnos y cual de los 3 tienen mejor promedio"<<endl;
        cout<<"19. Cuanto demora en reccorer un cliclista 3 etapas con punteros"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Escoje: ";cin>>opcion;

        switch (opcion) {
        case 1:{
            int num,*dir_num;

            num = 20;
            dir_num = &num;

            cout<<"Numero:"<<*dir_num<<endl;
            cout<<"Direcion dsadadde memoria: "<<dir_num<<endl;

            break;
        }

        case 2:{
            int numero, *dir_numero;

            cout<<"Digite un numero: ";cin>>numero;
            dir_numero = &numero;

            if(*dir_numero % 2 == 0){
                cout<<"El numero "<<*dir_numero<<" es par"<<endl;
                cout<<"Direccion: "<<dir_numero<<endl;
            }
            else{
                cout<<"El numero "<<*dir_numero<<" no es par"<<endl;
                cout<<"Direccion: "<<dir_numero<<endl;
            }
            break;
        }

        case 3:{
            int numero, *dir_numero;
            bool esPrimo = true;
            cout<<"Digite un numero: ";cin>>numero;
            dir_numero = &numero;

            for (int i = 2; i <= *dir_numero/2; i++) {
                if (*dir_numero % i == 0) {
                    esPrimo = false;
                    break;
                }
            }

            if (esPrimo) cout << *dir_numero << " es un numero primo" << endl;
            else cout << *dir_numero << " no es un numero primo" << endl;
            break;

        }

        case 4:{
            int numeros[] = {1,2,3,4,5};
            int *dir_numeros;

            dir_numeros = numeros;

            for(int i=0; i<5; i++){
                cout<<"Elemento del vector ["<<i<<"]: "<<*dir_numeros++<<endl;
                cout<<"Posicion de memoria "<<numeros[i]<<" es: "<<dir_numeros++<<endl;
            }
            break;
        }

        case 5:{
            int numeros[10], *dir_numeros;

            for(int i = 0; i<10; i++){
                cout<<"Digite un numero ["<<i<<"]: ";cin>>numeros[i];
            }

            dir_numeros = numeros;

            for(int i = 0; i<10; i++){
                if(*dir_numeros%2 == 0){
                    cout<<"El numero "<<*dir_numeros<<" es par"<<endl;
                    cout<<"Posicion: "<<dir_numeros<<endl;
                }
                dir_numeros++;
            }
            break;
        }

        case 6:{
            int tamano, mayor = 0,*dir_numeros;
            cout<<"Ingrese el tamano del arreglo: ";cin>>tamano;

            int numeros[tamano];
            for(int i = 0; i<tamano; i++){
                cout<<"Digite un numero ["<<i+1<<"]: ";cin>>numeros[i];
            }

            dir_numeros = numeros;

            for(int i = 0; i<tamano; i++){
                if(*dir_numeros>mayor) mayor = *dir_numeros;
                dir_numeros++;
            }

            cout<<"El numero mayor del arreglo es: "<<mayor<<endl;
            break;
        }

        case 7:{
            int numCalificaciones,*calificaciones;
            cout<<"Digite el numero de calificaciones: ";cin>>numCalificaciones;

            calificaciones = new int [numCalificaciones];

            for(int i = 0; i < numCalificaciones; i++){
                cout<<"Ingrese una nota: ";cin>>calificaciones[i];
            }
            cout<<"Notas"<<endl;
            for(int i = 0; i < numCalificaciones; i++){
                cout<<calificaciones[i]<<endl;
            }
            delete[] calificaciones;
            break;
        }

        case 8:{
            float num1 = 20.8, num2 = 6.78,aux = 0,*dirNm1, *dirNm2;
            dirNm1 = &num1; dirNm2 = &num2;
            cout<<"Primer numero: "<<*dirNm1<<" Posicion: "<<dirNm1<<endl;
            cout<<"Segundo numero: "<<*dirNm2<<" Posicion: "<<dirNm2<<endl;


            aux = *dirNm1;
            *dirNm1 = *dirNm2;
            dirNm2 = &aux;

            cout<<"Valores intercambiados"<<endl;
            cout<<"Primer numero: "<<*dirNm1<<" Posicion: "<<dirNm1<<endl;
            cout<<"Segundo numero: "<<*dirNm2<<" Posicion: "<<dirNm2<<endl;
            break;
        }

        case 9:{
            const int nElementos = 5;
            int numeros[nElementos] = {3,5,2,8,1,};

            cout<<"El mayor elemento es: "<<hallarMax(numeros,nElementos)<<endl<<endl;;
            break;
        }

        case 10:{

            int n_Numeros, aux, *arreglo;
            cout<<"Ingrese la cantidad de numeros que desea ingresar: ";cin>>n_Numeros;
            arreglo = new int [n_Numeros];

            for(int i = 0; i< n_Numeros; i++){
                cout<<"Ingrese un numero para la posicion ["<<i+1<<"]: ";cin>>*(arreglo+i);
            }

            for(int i = 0; i< n_Numeros; i++){
                for(int j = 0; j< n_Numeros - 1; j++){
                    if(*(arreglo) > *(arreglo+j+1)){
                        aux = *(arreglo+j);
                        *(arreglo+j) = *(arreglo+j+1);
                        *(arreglo+j+1) = aux;
                    }
                }
            }

            for(int i = 0; i < n_Numeros; i++){
                cout<<*(arreglo+i)<<endl;
            }

            delete[] arreglo;
            break;
        }

        case 11:{

            int n_Numeros, *arreglo, num = 0;
            bool bandera = false;
            cout<<"Ingrese la cantidad de numeros que desea ingresar: ";cin>>n_Numeros;
            arreglo = new int [n_Numeros];

            for(int i = 0; i< n_Numeros; i++){
                cout<<"Ingrese un numero para la posicion ["<<i+1<<"]: ";cin>>*(arreglo+i);
            }

            cout<<"Ingrese un numero a encontrar: ";cin>>num;

            for(int i = 0; i< n_Numeros; i++){
                if(*(arreglo+i) == num){
                    cout<<"El numero "<<num<<" se encuentra en la posicion "<<i<<endl;
                    bandera = true;
                    break;
                }
            }
            if(bandera == false) cout<<"El numero no se encuntra en el arreglo"<<endl;

            delete[] arreglo;
            break;
        }

        case 12:{
            char nombre[30];
            cin.ignore();
            cout<<"Digite su nombre: ";
            cin.getline(nombre,30,'\n');

            strupr(nombre);

            cout<<"El numero de vocales del nombre es: "<<contador(nombre)<<endl;
            break;
        }

        case 13:{
            char nombre[30];
            cin.ignore();
            cout<<"Digite su nombre: ";
            cin.getline(nombre,30,'\n');

            strupr(nombre);
            Vocales resultado = contadorVocales(nombre);
            cout<<"El número de vocales del nombre es: "<<endl;
            cout<<"A: "<<resultado.A<<endl;
            cout<<"E: "<<resultado.E<<endl;
            cout<<"I: "<<resultado.I<<endl;
            cout<<"O: "<<resultado.O<<endl;
            cout<<"U: "<<resultado.U<<endl;
            break;
        }

        case 14:{
            int **puntero_matriz, nFilas, nCol;

            cout<<"Digite el numero de filas: ";cin>>nFilas;
            cout<<"Digite el numero de columnas: ";cin>>nCol;

            puntero_matriz = new int*[nFilas];

            for(int i = 0; i<nFilas;i++){
                puntero_matriz[i] = new int[nCol];
            }

            for(int i = 0; i<nFilas ;i++){
                for(int j = 0;j<nCol; j++){
                    cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
                    cin>>*(*(puntero_matriz+i)+j);
                }
            }

            cout<<"Imprimiendo la matriz"<<endl;
            for(int i = 0; i<nFilas ;i++){
                for(int j = 0;j<nCol; j++){
                    cout<<*(*(puntero_matriz+i)+j)<<" ";
                }
                cout<<endl;
            }

            for(int i = 0; i<nFilas; i++){
                delete[] puntero_matriz[i];
            }
            delete[] puntero_matriz;
            break;
        }

        case 15:{
            int** puntero_matriz1, ** puntero_matriz2, nFilas, nCol;

                cout << "Digite el numero de filas: ";
                cin >> nFilas;
                cout << "Digite el numero de columnas: ";
                cin >> nCol;

                // Matriz1
                puntero_matriz1 = new int* [nFilas];
                for (int i = 0; i < nFilas; i++) {
                    puntero_matriz1[i] = new int[nCol];
                }

                cout << "Digite los elementos de la primera matriz: " << endl;

                for (int i = 0; i < nFilas; i++) {
                    for (int j = 0; j < nCol; j++) {
                        cout << "Digite el numero [" << i << "][" << j << "]: ";
                        cin >> *(*(puntero_matriz1 + i) + j);
                    }
                }

                // Matriz2
                puntero_matriz2 = new int* [nFilas];
                for (int i = 0; i < nFilas; i++) {
                    puntero_matriz2[i] = new int[nCol];
                }

                cout << "Digite los elementos de la segunda matriz: " << endl;

                for (int i = 0; i < nFilas; i++) {
                    for (int j = 0; j < nCol; j++) {
                        cout << "Digite el numero [" << i << "][" << j << "]: ";
                        cin >> *(*(puntero_matriz2 + i) + j);
                    }
                }

                sumarMatrices(puntero_matriz1, puntero_matriz2, nFilas, nCol);

                cout << "La matriz resultante es: " << endl;
                for (int i = 0; i < nFilas; i++) {
                    for (int j = 0; j < nCol; j++) {
                        cout << *(*(puntero_matriz1 + i) + j) << " ";
                    }
                    cout << endl;
                }

                // Liberar memoria
                for (int i = 0; i < nFilas; i++) {
                    delete[] puntero_matriz1[i];
                    delete[] puntero_matriz2[i];
                }
                delete[] puntero_matriz1;
                delete[] puntero_matriz2;

            break;
        }

        case 16:{

            int** puntero_matriz, nFilas, nCol;

            cout << "Digite el numero de filas: ";
            cin >> nFilas;
            cout << "Digite el numero de columnas: ";
            cin >> nCol;

            puntero_matriz = new int* [nFilas];
            for (int i = 0; i < nFilas; i++) {
                puntero_matriz[i] = new int[nCol];
            }

            cout << "Digite los elementos de la matriz: " << endl;

            for (int i = 0; i < nFilas; i++) {
                for (int j = 0; j < nCol; j++) {
                    cout << "Digite el numero [" << i << "][" << j << "]: ";
                    cin >> *(*(puntero_matriz + i) + j);
                }
            }

            cout<<"Matriz original"<<endl;
            for (int i = 0; i < nFilas; i++) {
                for (int j = 0; j < nCol; j++) {
                    cout << *(*(puntero_matriz + i) + j) << " ";
                }
                cout << endl;
            }

            cout<<"Matriz transpuesta"<<endl;
            for (int i = 0; i < nFilas; i++) {
                for (int j = 0; j < nCol; j++) {
                    cout << *(*(puntero_matriz + j) + i) << " ";
                }
                cout << endl;
            }

            for (int i = 0; i < nFilas; i++) {
                delete[] puntero_matriz[i];
            }
            delete[] puntero_matriz;
            break;
        }

        case 17:{
            pedirDatos();
            mostrarDatos(puntero_persona);
            break;
        }

        case 18:{
            pedirDatos2();
            calcularpromedio(puntero_alumno);
            break;
        }

        case 19:{
            datos_ciclista();
            tiempo_total(puntero_ciclista);
            break;
        }
        case 0:{
            opcion = 0;
            break;
        }

            //
        }
    }
    return 0;
}


//Funciones
//Ejercicio 9
int hallarMax(int *dirVec,int nElementos){
    int max = 0;

    for(int i = 0; i<nElementos; i++){
        if(*(dirVec+i)>max){
            max = *(dirVec+i);
        }
    }
    return max;
}

//Ejercicio 12
int contador(char *nombre){
    int cont = 0;
    while(*nombre){
        switch(*nombre){
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            cont++;
            break;
        }
        nombre++;
    }
    return cont;
}

//Ejercicio 13

Vocales contadorVocales(char *nombre){
    Vocales resultado = {0, 0, 0, 0, 0};
    while(*nombre){
        switch(*nombre){
        case 'A': resultado.A++; break;
        case 'E': resultado.E++; break;
        case 'I': resultado.I++; break;
        case 'O': resultado.O++; break;
        case 'U': resultado.U++; break;
        }
        nombre++;
    }
    return resultado;
}

//Ejercicio 15
void sumarMatrices(int** puntero_matriz1, int** puntero_matriz2, int nFilas, int nCol) {
    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nCol; j++) {
            *(*(puntero_matriz1 + i) + j) += *(*(puntero_matriz2 + i) + j);
        }
    }
}

//Ejercicio 17
void pedirDatos(){
    cin.ignore();
    cout<<"Digite su nombre: ";
    cin.getline(puntero_persona->nombre,30,'\n');
    cout<<"Digite su edad: ";
    cin>>puntero_persona->edad;
}

void mostrarDatos(Persona *puntero_persona){
    cout<<"Su nombre: "<<puntero_persona->nombre <<endl;
    cout<<"Su edad es: "<<puntero_persona->edad<<endl;
}
//Ejercicio 18
void pedirDatos2(){
    for(int i = 0; i < 3; i++){
        cin.ignore();
        cout<<"Digite su nombre: ";
        cin.getline((puntero_alumno+i)->nombre,30,'\n');
        cout<<"Digite su edad: ";
        cin>>(puntero_alumno+i)->edad;
        cout<<"Digite el promedio: ";
        cin>>(puntero_alumno+i)->promedio;
        cout<<endl;
    }
}

void calcularpromedio(Alumno *puntero_alumno){
    float mayor = 0.0;
    int pos = 0;

    for(int i = 0; i<3;i++){
        if((puntero_alumno+i)->promedio> mayor){
            mayor = (puntero_alumno+i)->promedio;
            pos = i;
        }
    }

    cout<<"El alumno con mejor promedio es: "<<endl;
    cout<<"Nombre: "<<(puntero_alumno+pos)->nombre<<endl;
    cout<<"Edad: "<<(puntero_alumno+pos)->edad<<endl;
    cout<<"Promedio"<<(puntero_alumno+pos)->promedio<<endl;
}

void datos_ciclista(){
    for(int i = 0; i < 3; i++){
        cin.ignore();
        cout<<"Etapa "<<i+1<<endl;
        cout<<"Horas: ";
        cin>>(puntero_ciclista+i)->horas;
        cout<<"Minutos: ";
        cin>>(puntero_ciclista+i)->minutos;
        cout<<"Segundos: ";
        cin>>(puntero_ciclista+i)->segundos;
        cout<<endl;
    }
}

void tiempo_total(Etapas *puntero_ciclista){
    int h = 0, m = 0, s = 0;
    for (int i = 0; i < 3; i++) {
        h += (puntero_ciclista+i)->horas;
        m += (puntero_ciclista+i)->minutos;
        s += (puntero_ciclista+i)->segundos;
    }
    if(s>60){
        s -= 60;
        m++;
    }

    if(m>60){
        m -= 60;
        h++;
    }
    cout<<"El ciclista demoro un total de "<<h<<" horas "<<m<<" minutos "<<s<<" segundos en recorrer las 3 etapas."<<endl;
}
