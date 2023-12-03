/******************************************************************************

                     Proyecto De Programación Orientada a Objetos
|Andrik Buitrago 
|Camilo Pavas 
|Samuel Ospina

*******************************************************************************/

//======================================================================
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
//======================================================================
// Clase para mostrar la información del servicio al cliente

class class_servicio_cliente {
public:
    void met_mostrar_informacion_banco() const {
        cout << "----- Información de Servicio al Cliente -----\n";
        cout << "Número telefónico del banco: 1502206\n";
        cout << "Número celular del banco: 3182260316\n";
        cout << "Correo del banco: apoyocliente@hotmail.com\n";
        cout << "Dirección del banco: Carrera 5 #12-17 Piso 5.\n";
        cout << "Horarios de atención: Lunes a Viernes de 9 AM a 5 PM\n";
        cout << "----------------------------------------------\n";
    }
};
//======================================================================
// Clase para abrir una cuenta bancaria

class class_abrir_cuenta {
public:
// Constructor y métodos de la clase abrir_cuenta
    class_abrir_cuenta();
    void met_abrir_cuenta();
    int met_obtener_numero_cuenta() const;
    const char* met_obtener_contrasena() const;
    float met_obtener_saldo() const;
    void met_cambiar_contrasena();

public:
 // Atributos de la clase abrir_cuenta
    static int atr_contador_cuentas;
    int atr_numero_cuenta;
    char atr_nombre_completo[100];
    char atr_numero_identificacion[100];
    char atr_numero_celular[100];
    char atr_edad[100];
    string atr_motivo;
    char atr_contrasena[100];
    float atr_saldo;
};

// Inicialización del contador de cuentas
int class_abrir_cuenta::atr_contador_cuentas = 1;

// Constructor de la clase abrir_cuenta
class_abrir_cuenta::class_abrir_cuenta() {
    atr_numero_cuenta = atr_contador_cuentas++;
    atr_saldo = 0.0;
}

// Método para abrir una cuenta
void class_abrir_cuenta::met_abrir_cuenta() {
    cout << "Ingresa tu nombre completo: ";
    cin.ignore();
    cin.getline(atr_nombre_completo, 100);

    cout << "Ingresa tu Número de identificación: ";
    cin.ignore();
    cin.getline(atr_numero_identificacion, 100);

    cout << "Ingresa tu Número de celular: ";
    cin.ignore();
    cin.getline(atr_numero_celular, 100);

    cout << "Ingrese su Edad: ";
    cin.ignore();
    cin.getline(atr_edad, 100);

    cout << "Ingrese la contraseña que va a desear usar: ";
    cin.ignore();
    cin.getline(atr_contrasena, 100);
    
    cout << "Infgrese el mótivo por el cual desea crear la cuenta: ";
    cin >> atr_motivo;
  
// Mostrar mensaje de éxito y número de cuenta
    cout << "Su cuenta ha sido creada con éxito." << endl;
    cout << " Su numero de cuenta es : " << atr_numero_cuenta << endl;
    
}

// Método para obtener el número de cuenta
int class_abrir_cuenta::met_obtener_numero_cuenta() const {
    return atr_numero_cuenta;
}

// Método para obtener la contraseña
const char* class_abrir_cuenta::met_obtener_contrasena() const {
    return atr_contrasena;
}

// Método para obtener el saldo
float class_abrir_cuenta::met_obtener_saldo() const {
    return atr_saldo;
}

// Método para cambiar la contraseña
void class_abrir_cuenta::met_cambiar_contrasena() {
    char atr_nueva_contrasena[100];
    cout << "Ingrese la nueva contraseña: ";
    cin.ignore();
    cin.getline(atr_nueva_contrasena, 100);
    strcpy(atr_contrasena, atr_nueva_contrasena);
    cout << "Contraseña cambiada exitosamente.\n";
}

//======================================================================
// Clase para mostrar los datos de una cuenta
class class_mostrar_cuenta {
public:
// Constructor y método de la clase mostrar_cuenta
    class_mostrar_cuenta(const class_abrir_cuenta &var_cuenta);
    void met_mostrar_datos_cuenta() const;

private:
// Atributo de la clase mostrar_cuenta
    const class_abrir_cuenta &var_cuenta;
};

// Constructor de la clase mostrar_cuenta
class_mostrar_cuenta::class_mostrar_cuenta(const class_abrir_cuenta &var_cuenta) : var_cuenta(var_cuenta) {}

// Método para mostrar los datos de una cuenta
void class_mostrar_cuenta::met_mostrar_datos_cuenta() const {
    cout << "Nombre: " << var_cuenta.atr_nombre_completo << endl;
    cout << "Número de cuenta: " << var_cuenta.met_obtener_numero_cuenta() << endl;
    cout << "Saldo: $" << var_cuenta.met_obtener_saldo() << endl;
}

//======================================================================
// Clase para cerrar una cuenta
class class_cerrar_cuenta {

public:
// Constructor y método de la clase cerrar_cuenta
    class_cerrar_cuenta(const class_abrir_cuenta &var_cuenta);
    void met_cerrar_cuenta();

private:
// Atributo de la clase cerrar_cuenta

    const class_abrir_cuenta &var_cuenta_a_cerrar;
};

// Constructor de la clase cerrar_cuenta
class_cerrar_cuenta::class_cerrar_cuenta(const class_abrir_cuenta &var_cuenta) : var_cuenta_a_cerrar(var_cuenta) {}

// Método para cerrar una cuenta
void class_cerrar_cuenta::met_cerrar_cuenta() {
    int atr_numero_cuenta;
    char atr_contrasena[100];
    char atr_numero_identificacion[100];
    char atr_nombre[100];
    string atr_motivo;

    cout << "Ingrese el número de cuenta: ";
    cin >> atr_numero_cuenta;

    cout << "Ingrese la contraseña: ";
    cin.ignore();
    cin.getline(atr_contrasena, 100);

    cout << "Ingrese el número de identificación: ";
    cin.getline(atr_numero_identificacion, 100);

    cout << "Ingrese el nombre: ";
    cin.getline(atr_nombre, 100);

    cout << "Ingrese el motivo por el cual quiere cerrar la cuenta: ";
    cin >> atr_motivo;
  
 // Verificar la información y cerrar la cuenta si es correcta
    if (atr_numero_cuenta == var_cuenta_a_cerrar.met_obtener_numero_cuenta() &&
        strcmp(atr_contrasena, var_cuenta_a_cerrar.met_obtener_contrasena()) == 0 &&
        strcmp(atr_numero_identificacion, var_cuenta_a_cerrar.atr_numero_identificacion) == 0 &&
        strcmp(atr_nombre, var_cuenta_a_cerrar.atr_nombre_completo) == 0 &&
        atr_motivo == var_cuenta_a_cerrar.atr_motivo) {
        cout << "Cuenta cerrada exitosamente.\n";
    } else {
        cout << "Error al cerrar la cuenta. La información ingresada no coincide con la cuenta.\n";
    }
}

//======================================================================
// Clase para realizar operaciones bancarias
class class_operaciones_bancarias {
public:
// Métodos estáticos para realizar operaciones bancarias
    static void met_depositar_dinero(class_abrir_cuenta &var_cuenta, float var_monto);
    static void met_retirar_dinero(class_abrir_cuenta &var_cuenta, float var_monto);
    static void met_transferir_dinero(class_abrir_cuenta &var_cuentaOrigen, class_abrir_cuenta &var_cuentaDestino, float var_monto);
    static void met_consultar_saldo(const class_abrir_cuenta &var_cuenta);
    static void met_mostrar_movimiento();
};

// Método para depositar dinero en una cuenta
void class_operaciones_bancarias::met_depositar_dinero(class_abrir_cuenta &var_cuenta, float var_monto) {
    var_cuenta.atr_saldo += var_monto;
    cout << "Depósito exitoso. Nuevo saldo: $" << var_cuenta.met_obtener_saldo() << endl;
}

// Método para retirar dinero de una cuenta
void class_operaciones_bancarias::met_retirar_dinero(class_abrir_cuenta &var_cuenta, float var_monto) {
  // Verificar si hay saldo suficiente y actualizar el saldo
  if (var_monto <= var_cuenta.atr_saldo) {
        var_cuenta.atr_saldo -= var_monto;
        cout << "Retiro exitoso. Nuevo saldo: $" << var_cuenta.met_obtener_saldo() << endl;
    } else {
        cout << "Saldo insuficiente para realizar el retiro.\n";
    }
}

// Método para transferir dinero entre dos cuentas
void class_operaciones_bancarias::met_transferir_dinero(class_abrir_cuenta &var_cuenta_origen, class_abrir_cuenta &var_cuenta_destino, float var_monto) {
   // Verificar si hay saldo suficiente en la cuenta de origen y actualizar saldos 
  if (var_monto <= var_cuenta_origen.atr_saldo) {
        var_cuenta_origen.atr_saldo -= var_monto;
        var_cuenta_destino.atr_saldo += var_monto;
        cout << "Transferencia exitosa. Nuevo saldo de la cuenta origen: $" << var_cuenta_origen.met_obtener_saldo() << endl;
    } else {
        cout << "Saldo insuficiente para realizar la transferencia.\n";
    }
}

// Método para consultar el saldo de una cuenta
void class_operaciones_bancarias::met_consultar_saldo(const class_abrir_cuenta &var_cuenta) {
    cout << "Saldo actual de la cuenta: $" << var_cuenta.met_obtener_saldo() << endl;
}
//======================================================================
// Clase para gestionar cuentas y menús
class class_gestor_cuentas {
public:
    void met_ejecutar_menu();

private:
    // Vector que almacena las cuentas creadas y objeto de servicio al cliente
    vector<class_abrir_cuenta> obj_cuentas;
    class_servicio_cliente obj_servicio_cliente;
};

// Método para ejecutar el menú principal
void class_gestor_cuentas::met_ejecutar_menu() {
    int var_ch;

    do {
      // Menú principal
        cout << "1) Crea una cuenta\n";
        cout << "2) Mostrar información de la cuenta\n";
        cout << "3) Cerrar una cuenta\n";
        cout << "4) Operaciones Bancarias\n";
        cout << "5) Servicio al Cliente\n";
        cout << "0) Salir\n";
        cin >> var_ch;

        switch (var_ch) {
        case 1:// Crear una nueva cuenta y agregarla al vector de cuentas
            {
                class_abrir_cuenta obj_cuenta;
                obj_cuenta.met_abrir_cuenta();
                obj_cuentas.push_back(obj_cuenta);
                break;
            }
        case 2:// Mostrar información de una cuenta específica
            {
                int atr_numero_cuenta;
                cout << "Ingrese el número de cuenta: ";
                cin >> atr_numero_cuenta;

                bool var_cuenta_encontrada = false;
                for (const auto &obj_cuenta : obj_cuentas) {
                    if (obj_cuenta.met_obtener_numero_cuenta() == atr_numero_cuenta) {
                        class_mostrar_cuenta obj_mostrar_cuenta(obj_cuenta);
                        obj_mostrar_cuenta.met_mostrar_datos_cuenta();
                        var_cuenta_encontrada = true;
                        break;
                    }
                }

                if (!var_cuenta_encontrada) {
                    cout << "Cuenta no encontrada.\n";
                }

                break;
            }
        case 3: // Cerrar una cuenta existente
            {
                int atr_numero_cuenta;
                cout << "Ingrese el número de cuenta a cerrar: ";
                cin >> atr_numero_cuenta;

                bool var_cuenta_encontrada = false;
                for (const auto &obj_cuenta : obj_cuentas) {
                    if (obj_cuenta.met_obtener_numero_cuenta() == atr_numero_cuenta) {
                        class_cerrar_cuenta obj_cerrar_cuenta(obj_cuenta);
                        obj_cerrar_cuenta.met_cerrar_cuenta();
                        var_cuenta_encontrada = true;
                        break;
                    }
                }

                if (!var_cuenta_encontrada) {
                    cout << "Cuenta no encontrada.\n";
                }

                break;
            }
        case 4:// Menú de operaciones bancarias
            {
                int var_opcion_operacion;
                cout << "1) Depositar Dinero\n";
                cout << "2) Retirar Dinero\n";
                cout << "3) Transferir Dinero\n";
                cout << "4) Consultar Saldo\n";
                cout << "5) Cambiar Contraseña\n";
                cout << "0) Volver al Menú Principal\n";
                cin >> var_opcion_operacion;

                int atr_numero_cuenta;
                cout << "Ingrese el número de cuenta: ";
                cin >> atr_numero_cuenta;

                bool var_cuenta_encontrada = false;
                for (auto &obj_cuenta : obj_cuentas) {
                    if (obj_cuenta.met_obtener_numero_cuenta() == atr_numero_cuenta) {
                        var_cuenta_encontrada = true;

                        switch (var_opcion_operacion) {
                        case 1:// Depositar dinero
                            {
                                float var_monto;
                                cout << "Ingrese el monto a depositar: $";
                                cin >> var_monto;
                                class_operaciones_bancarias::met_depositar_dinero(obj_cuenta, var_monto);
                                break;
                            }
                        case 2:// Retirar dinero
                            {
                                float var_monto;
                                cout << "Ingrese el monto a retirar: $";
                                cin >> var_monto;
                                class_operaciones_bancarias::met_retirar_dinero(obj_cuenta, var_monto);
                                break;
                            }
                        case 3:// Transferir a una cuenta
                            {
                                int var_numero_cuenta_destino;
                                cout << "Ingrese el número de cuenta destino: ";
                                cin >> var_numero_cuenta_destino;

                                bool var_cuenta_destino_encontrada = false;
                                for (auto &var_cuenta_destino : obj_cuentas) {
                                    if (var_cuenta_destino.met_obtener_numero_cuenta() == var_numero_cuenta_destino) {
                                        var_cuenta_destino_encontrada = true;
                                        float var_monto;
                                        cout << "Ingrese el monto a transferir: $";
                                        cin >> var_monto;
                                        class_operaciones_bancarias::met_transferir_dinero(obj_cuenta, var_cuenta_destino, var_monto);
                                        break;
                                    }
                                }

                                if (!var_cuenta_destino_encontrada) {
                                    cout << "Cuenta destino no encontrada.\n";
                                }

                                break;
                            }
                        case 4:// consultar saldo de la cuenta
                            class_operaciones_bancarias::met_consultar_saldo(obj_cuenta);
                            break;
                        case 5://cambiar contraseña
                            obj_cuenta.met_cambiar_contrasena();
                            break;
                        case 0: // No se realiza ninguna operación,se vuelve al menú principal
                            break;
                        default:
                            cout << "Opción no válida.\n";
                            break;
                        }

                        break;
                    }
                }

                if (!var_cuenta_encontrada) {
                    cout << "Cuenta no encontrada.\n";
                }

                break;
            }
        case 5://Mostrar informacion del servicio al cliente
            obj_servicio_cliente.met_mostrar_informacion_banco();
            break;
        case 0://salir del sistema
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida.\n";
            break;
        }
    } while (var_ch != 0);
}

//======================================================================
// Función principal que inicia el programa
int main() {
    class_gestor_cuentas obj_gestor;
    obj_gestor.met_ejecutar_menu();

    return 0;
}
//======================================================================
