//
//  main.cpp
//  Final
//
//  Created by Valeria Conde Naranjo A01281637 on 8/6/20.
//
//  Copyright © 2020 Invitado. All rights reserved.
//
/*

******************* A T E N C I O N ***********************************************************
******************* A T E N C I O N ***********************************************************
- Guarda TODOS tus celulares -
No debes usar tu celular - whatsapp, email, face, etc. durante la presentación de la evaluación.
Si necesitas enviarme algún mensaje este debe ser por medio del chat del zoom.
Debes siempre tener la cámara prendida y tu cara visible con tu nombre completo.


Antes de iniciar -  llena con tu nombre - si realmente te comprometes a lo siguiente -
Yo Valeria Conde Naranjo, me comprometo a que mi actuación durante esta
evaluación será siempre regida por  la honestidad académica y la responsabilidad

Yo Valeria Conde Naranjo, me comprometo a:
Realizar con toda honestidad mi examen de TC1030 -Programación orientada a objetos.

Yo Valeria Conde Naranjo, me comprometo a
NO compartir la información, contenido, desarrollo, solución de la evaluación de TC1030,
durante y después de terminar el examen.

Yo Valeria Conde Naranjo, me comprometo a
respetar la propiedad intelectual de los demás, evitando el plagio, copia, etc.

Yo Valeria Conde Naranjo, me comprometo a
llevar a cabo mi examen en forma individual.

*** Notas importantes ***
Podrás consultar los ejemplos vistos en clase, tus tareas - presentaciones
- El desarrollo de tu examen es completamente Individual, no debes pedir ayuda.
- Podrás llevar a cabo la programación en tu IDE que usualmente utilizas y al final subir
tu código a Vocareum.

***********************************************************************************************
***********************************************************************************************

Aplicación Sistema de Inventarios de FoodService Version1.0

Objetivo: Sistema de pedidos de los productos que maneja FoodService
Se te pide crear un mini sistema de pedidos para FoodService,
Por cuestiones de tiempo solo implementa los métodos set y get que se te solicitan –

La empresa tiene la siguiente lista de productos alimenticios:
•    CarnesFrias, Lacteos, Botanas, Comidas Preparadas, etc.

Para esta versión solo se implementarán las siguiente clases:
•    Producto
o     Clase Base -
•    Atributos:
o    + sNombreProd: string
o    + dPrecioXkg: double
+ iGramos: int
•    Métodos:
o    - Producto  ()
    Constructor por default, inicializa los atributos con tus valores default
o    - Producto  (string nombreProd, double precioXkg, int gramos)
    Constructor con parámetros, inicializa los atributos con los valores recibidos
o    - muestra( ):void
    Método virtual que despliega con cout la información separada por “, “ una coma seguida de un espacio, sin endl al final–
o    - getPrecio( ): double
    Método virtual
    Método que retorna el precio X Kg del producto
o    – getGramos( ): int
    Método que retorna el peso del producto en gramos
o    - operator  + (double dAcum): double  - método – virtual
    Sobrecarga de operador + para incrementar el dAcum con el valor de getPrecio( )  de la clase derivada
 
•    CarnesFrias
o    Clase derivada de la clase Producto
•    Atributos:
o    + sCategoria: string (las categorías que se maneja son : Pavo, Cerdo, Res)
•    Métodos:
o    - CarnesFrias  ()
    Constructor por default, inicializa los atributos con tus valores default
o    - CarnesFrias  (string nombreProd, double precioXKg, int gramos, string categoria)
    Constructor con parámetros, inicializa los atributos con los valores recibidos
o    - muestra( ):void
    Método que despliega con cout la información separada por “, “ una coma seguida
de un espacio – tanto la que heredo como la propia, le añade el string “Carnes Frias:”
al inicio y al final el precio de las Carnes Frias.
o    – getCategoria( ): string
    Retorna la categoria.
o    - getPrecio( ): double
    Método que retorna el precio del producto -  calcula el precio del producto
en base al precioXKg y a los gramos del producto, además -
    El precio se ve incrementado por las siguientes cantidades dependiendo
de la categoría a la que pertenece el producto–
    Pavo – 10 pesos
    Cerdo – 20 pesos
    Res – 30 pesos
    Verificar si el peso en gramos sea superior a 0 en caso de tener un valor de 0 el precio será 0.
o    double operator + (double dAcum);
    Función que incrementa el dAcum con el precio correspondiente a la carneFria (getPrecio( ) )
•    Botana
o    Clase derivada de la clase Producto
•    Atributos:
o    + iCarbohidratos:int
•    Métodos:
o    - Botana ( )
    Constructor por default, inicializa los atributos con tus valores default
o    - Botana (string nombreProd, double precioXKg, int gramos, double dCarbohidratos)
    Constructor con parámetros, inicializa los atributos con los valores recibidos
o    - muestra( ):void
    Método que despliega la información separada por “, “ , una coma seguida de un espacio
– tanto la que heredo como la propia, le añade el string “Botana:” al inicio
– debes desplegar el precio de la botana
o    – getCarbohidratos( ): double
    Retorna la cantidad de carbohidratos de la Botana.
o    - getPrecio( ): double
    Método que calcula y  retorna el precio de la botana -  calcula el precio del producto
en base al precio que se heredó, el cual indica el precio por Kilo del producto y considerando
el peso en gramos de la botana –  además dependiendo de la cantidad de carbohidratos se
incrementa el precio de la botana en la siguiente cantidad en pesos
– Verificar si el peso en gramos sea superior a 0 en caso de tener un valor de 0 el precio es 0
Carbohidratos    Incremento en pesos
Entre 0 y 30        10
entre 31 y 50        20
otro                30

    double operator + (double dAcum) – suma a dAcum el getPrecio( ) de la instancia de botana.

•    Observa que el atributo que lo diferencia de la clase Base se utiliza
para que al calcular el precio del producto sea diferente en las 2 clases,
de tal manera que el método getPrecio() sea único en cada clase derivada de Producto.

•    Pedido
Clase para almacenar los datos del pedido
•    Atributos:
o    + iIdPedido: int
o    + arrPtrProductos :  Producto *[ 100]
    Arreglo de apuntadores de tipo Producto que almacenará todos los productos
del pedido que pueden ser de cualquiera de las 2 clases derivadas.
o    +iCant:int
    Indica la cantidad de productos del pedido
•    Métodos:
o    - Pedido ( )
    Constructor por default, inicializa los atributos con idPedido y iCant con 0
y el arrPtrProductos con NULL;
o    -Pedido(int idPedido)
    Constructor con parámetro, inicializa el iIdPedido con el parámetro recibido e
inicializa el arrPtrProductos con NULL, además inicializa  iCant con 0;
o    - muestra( ):void
    Método que despliega con cout la información del pedido separada por “, “–
tanto la que heredo como la propia, le añade el string “Pedido: ” al inicio,
despliega todos los productos del pedido – y además calcula y
despliega el total a pagar por el pedido – Nota – después de los :
y de la , existe un espacio en blanco, Ejemplo -
Pedido: 2
Carnes Frias: Jamon York, 1000, 500, Cerdo, 520
Botana: Gloria de Linares, 300, 650, 90, 225
Total = 745
o    altaProducto (Producto * producto) –
    Añade un producto al pedido - apuntador de cualquier tipo de las clases derivadas de producto
-  al arreglo de apuntadores de productos e incrementa el contador iCant -

Programa principal

Te recomiendo poner como comentario lo que no tengas implementado, conforme
vayas avanzando puedes ir descomentando para ver que va funcionando tu programación.
Datos de entrada  usados para los diferentes casos de Prueba -
Carnes Frias
Datos usados  los casos de Prueba -
Nombre producto        PrecioXKg    iGramos        Categoria        Precio(lo calcula la clase)
Jamon York            1000        500                Cerdo               520
Chuletas Ahumada    500            580                Cerdo               310
Chorizo                100            200                Pavo                30
Kove                10000        5000            Res                 50030
Kove Extra Fino        20000        5000            Res                100030
Barbacoa Kove        700            10000            Res                  7030
Pechuga de Pavo        550            1000            Pavo               560
                    
Botanas
Nombre producto        PrecioXKg    iGramos        Carbohidratos        Precio(lo calcula la clase)
Gloria de Linares    300            650            51            30                225
Cacahuate            500            850            10            10                435
Nachos con queso    200            120            31            20                 44
Papitas Jalapeño    500            400            -1            30                230
Pizza Peperoni        200            450            500            30                120
Pizza de Trufa        10000        450            500            30               4530


Datos de salida de Caso de Prueba 1-
Pedido: 3
Botana: Gloria de Linares, 300, 650, 90, 225
Carnes Frias: Chuletas Ahumadas, 500, 580, Cerdo, 310
Carnes Frias: Chorizo, 100, 200, Pavo, 30
Carnes Frias: Kove, 10000, 5000, Res, 50030
Carnes Frias: Jamon York, 1000, 500, Cerdo, 520
Carnes Frias: Chuletas de Puerco, 500, 580, Cerdo, 310
Botana: Gloria de Linares, 300, 650, 51, 225
Botana: Cacahuates enchilados, 500, 850, 10, 435
Total = 52085
Pedido: 2
Carnes Frias: Jamon York, 1000, 500, Cerdo, 520
Botana: Gloria de Linares, 300, 650, 90, 225
Total = 745

Datos de salida de Caso de Prueba4  -
Pedido: 3
Botana: Gloria de Linares, 300, 650, 90, 225
Carnes Frias: Chuletas Ahumadas, 500, 580, Cerdo, 310
Carnes Frias: Chorizo, 100, 200, Pavo, 30
Carnes Frias: Kove, 10000, 5000, Res, 50030
Carnes Frias: Arrachera, 10000, 0, Res, 0
Carnes Frias: Molida, 20000, 0, Cerdo, 0
Botana: Trufas, 200, 0, 51, 0
Botana: Totopos, 500, 0, 31, 0
Total = 50595
Pedido: 2
Carnes Frias: Jamon York, 1000, 500, Cerdo, 520
Botana: Gloria de Linares, 300, 650, 90, 225
Total = 745


*/
#include <iostream>
using namespace std;

// CLASE PRODUCTO //
class Producto {
protected:
    string sNombreProd;
    double dPrecioXKg;
    int iGramos;
public:
    Producto() {
        sNombreProd = "";
        dPrecioXKg = 0.0;
        iGramos = 0;
    }
    
    Producto(string nombreProd, double precioXKg, int gramos) {
        sNombreProd = nombreProd;
        dPrecioXKg = precioXKg;
        iGramos = gramos;
    }
    
    virtual void muestra() {
        cout << sNombreProd << ", " << dPrecioXKg << ", " << iGramos;
    }
    
    virtual double getPrecio() {
        return dPrecioXKg;
    }
    
    int getGramos() {
        return iGramos;
    }
    
    virtual double operator + (double dAcum) {
        return dAcum + getPrecio();
    }
};

// CLASE CARNES FRIAS //
class CarnesFrias : public Producto {
private:
    string sCategoria;
public:
    CarnesFrias() : Producto() {
        sCategoria = "";
    }
    
    CarnesFrias(string nombreProd, double precioXKg, int gramos, string categoria) : Producto(nombreProd, precioXKg, gramos) {
        sCategoria = categoria;
    }
    
    void muestra() {
        cout << "Carnes Frias: " << sNombreProd << ", " << dPrecioXKg << ", " << iGramos << ", " << sCategoria << ", " << getPrecio();
    }
    
    string getCategoria() {
        return sCategoria;
    }
    
    double getPrecio() {
        if(iGramos <= 0) return 0;
        double p = dPrecioXKg * iGramos / 1000.0;
        if (sCategoria == "Pavo") p += 10;
        else if (sCategoria == "Cerdo") p += 20;
        else if (sCategoria == "Res") p += 30;
        return p;
    }
    
    double operator + (double dAcum) {
        return dAcum + getPrecio();
    }
};

// CLASE BOTANA //
class Botana : public Producto {
private:
    int iCarbohidratos;
public:
    Botana() : Producto() {
        iCarbohidratos = 0;
    }
    
    Botana(string nombreProd, double precioXKg, int gramos, int dCarbohidratos) : Producto(nombreProd, precioXKg, gramos) {
        iCarbohidratos = dCarbohidratos;
    }
    
    void muestra() {
        cout << "Botana: " << sNombreProd << ", " << dPrecioXKg << ", " << iGramos << ", " << iCarbohidratos << ", " << getPrecio();
    }
    
    double getCarbohidratos() {
        return iCarbohidratos;
    }
    
    double getPrecio() {
        if(iGramos <= 0) return 0;
        double p = dPrecioXKg * iGramos / 1000.0;
        if (iCarbohidratos <= 30) p += 10;
        else if (iCarbohidratos <= 50) p += 20;
        else p += 30;
        return p;
    }
    
    double operator + (double dAcum) {
        return dAcum + getPrecio();
    }
};

// CLASES PEDIDO //
class Pedido {
private:
    int iIdPedido;
    Producto *arrPtrProducto[100];
    int iCant;
public:
    Pedido() {
        iIdPedido = 0;
        iCant = 0;
    }
    
    Pedido(int idPedido) {
        iIdPedido = idPedido;
        iCant = 0;
    }
    
    void muestra() {
        cout << "Pedido: " << iIdPedido << endl;
        double dAcum = 0;
        for (int i = 0; i < iCant; i++) {
            arrPtrProducto[i] -> muestra();
            dAcum = *arrPtrProducto[i] + dAcum;
            cout << endl;
        }
        cout << "Total: " << dAcum << endl;
    }
    
    void altaProducto(Producto* producto) {
        arrPtrProducto[iCant] = producto;
        iCant++;
    }
};


// lee del teclado la información de un producto de carnes frias y retorna el apuntador
CarnesFrias * leerCarnesFrias(){
    
    string sNombreProducto, sCategoria;
    double dPrecio;
    int iGramos;
    
    getline(cin, sNombreProducto);
    cin >> dPrecio;
    cin >> iGramos;
    cin.ignore();
    cin >> sCategoria;
    cin.ignore();
    
    return new CarnesFrias(sNombreProducto,dPrecio,iGramos,sCategoria);
}

// Función que lee del teclado la información de un producto: Botana y retorna un apuntador
Botana * leerBotana(){
    
    string sNombreProducto;
    double dPrecio;
    int iGramos, iCarbohidratos;
    
    getline(cin, sNombreProducto);
    cin >> dPrecio;
    cin >> iGramos;
    cin >> iCarbohidratos;
    cin.ignore();
    
    return new Botana(sNombreProducto,dPrecio,iGramos,iCarbohidratos);
}


int main(int argc, const char * argv[]) {
  // Instancia de la clase Carnes Frias
    CarnesFrias jamon("Jamon York", 1000, 500, "Cerdo");
    
    // Instancia de Botana
    Botana gloria("Gloria de Linares", 300, 650, 90);
    
    // 2 instancias de la clase Pedido - cada pedido tiene a su vez un arrPtr de Productos
    Pedido pedidoGrupo2(2), pedidoGrupo3(3);
    
    // Arreglo de apuntadores de Pedidos - cada pedido tiene a su vez un arrPtr de Productos
    Pedido *arrPrtPedidos[3] = {&pedidoGrupo3, &pedidoGrupo2};
    
    // Dar de alta productos a los pedidos: pedidoGrupo2 y pedidoGrupo3
    pedidoGrupo2.altaProducto(&jamon);
    pedidoGrupo2.altaProducto(&gloria);
    pedidoGrupo3.altaProducto(&gloria);
    
    
    pedidoGrupo3.altaProducto(new CarnesFrias("Chuletas Ahumadas", 500, 580,"Cerdo"));
    pedidoGrupo3.altaProducto(new CarnesFrias("Chorizo", 100, 200,"Pavo"));
    pedidoGrupo3.altaProducto(new CarnesFrias("Kove", 10000, 5000,"Res"));
    
    // Dar de alta productos con datos ingresados del teclado
    pedidoGrupo3.altaProducto(leerCarnesFrias());
    pedidoGrupo3.altaProducto(leerCarnesFrias());
    pedidoGrupo3.altaProducto(leerBotana());
    pedidoGrupo3.altaProducto(leerBotana());

    // Desplegar todos los pedidos - polimorfismo -
    for (int iR = 0; iR < 2; iR ++){
        arrPrtPedidos[iR]->muestra();
    }

    return 0;
}
