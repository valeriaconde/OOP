//
//  main.cpp
//  Archivos
//
//  Created by Ma. Guadalupe Roque on 5/24/20.
//  Copyright © 2020 . All rights reserved.
//  https://www.geeksforgeeks.org/csv-file-management-using-c/

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void alta()
{
    // file pointer
    fstream fout;
    
    // opens an existing csv file or creates a new file.
    fout.open("reportcard.csv", ios::out | ios::app);
    
    cout << "Ingresa la información de las peliculas:"
    << " id titulo duracion genero calificacion" << endl;
    
    int id, duracion, calificacion;
    string titulo, genero;
    
    // Read the input
    for (int iPeli = 0; iPeli < 2; iPeli++) {
        cout << "Id:";
        cin >> id;
        cin.ignore();
        cout << "Titulo:";
        getline(cin, titulo);
        cout << "Ingresa duracion, calificacion y genero:";
        cin >> duracion
        >> calificacion
        >> genero;
        
        // Insert the data to file
        fout << id << ", "
        << titulo << ", "
        << duracion << ", "
        << calificacion << ", "
        << genero
        << "\n";
    }
    
    fout.close();
}


void leer()
{
    // File pointer
    fstream fin;
    
    // Open an existing file
    fin.open("reportcard.csv", ios::in);
    
    
    // Read the Data from the file
    // as String array
    string row[6];
    string line, word;

    while ( getline(fin, line)) {
        // read an entire row and
        // store it in a string variable 'line'.
        
        cout << line << endl;
        // used for breaking words.
        stringstream s(line);
        
        // read every column data of a row and
        // store it in a string variable, 'word'
        int iR = 0;
        // extrae caracteres de s  y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row[iR++]=word;
        }
        
        
        cout << "iD " << row[0] << " : \n";
        cout << "Titulo: " << row[1] << "\n";
        cout << "Duracion: " << row[2] << "\n";
        cout << "Calificacion: " << row[3] << "\n";
        cout << "Genero: " << row[4] << "\n";
    
        
    }
    
    fin.close();
}

int menu(){
    int iOpcion;
    cout << "1. Alta peliculas\n2.Mostrar Peliculas\n0.Salir\nTeclea la opcion:";
    cin >> iOpcion;
    return iOpcion;
}


int main() {
    int iOpcion;

        iOpcion = menu();
        while (iOpcion != 0){
            if (iOpcion == 1)
                alta();
            else if (iOpcion == 2)
                leer();
            
            else cout << "Opcion incorrecta!\n" ;
            iOpcion = menu();
        }

    
    return 0;
}
