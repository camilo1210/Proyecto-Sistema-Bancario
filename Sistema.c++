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
// Clase para abrir una cuenta bancaria

class ServicioCliente {
public:
    void mostrarInformacionBanco() const {
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
    class_abrir_cuenta();
    void met_abrir_cuenta();
    int obtener_numero_cuenta() const;
    const char* obtener_contrasena() const;
    float obtener_saldo() const;
    void cambiar_contrasena();

public:
    static int atr_contador_cuentas;
    int atr_numero_cuenta;
    char atr_nombre_completo[100];
    char atr_numero_identificacion[100];
    char atr_numero_celular[100];
    char atr_edad[100];
    string atr_motivo;
    char atr_contrasena[100];
    float saldo;
};

// Inicialización del contador de cuentas
int class_abrir_cuenta::atr_contador_cuentas = 1;

// Constructor de la clase abrir_cuenta
class_abrir_cuenta::class_abrir_cuenta() {
    atr_numero_cuenta = atr_contador_cuentas++;
    saldo = 0.0;
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

    cout << "Ingrese el motivo por el cual desea crear su cuenta: ";
    cin >> atr_motivo;

    cout << "Ingrese la contraseña que va a desear usar: ";
    cin.ignore();
    cin.getline(atr_contrasena, 100);

    cout << "Su cuenta ha sido creada con éxito." << endl;
}

// Método para obtener el número de cuenta
int class_abrir_cuenta::obtener_numero_cuenta() const {
    return atr_numero_cuenta;
}

// Método para obtener la contraseña
const char* class_abrir_cuenta::obtener_contrasena() const {
    return atr_contrasena;
}

// Método para obtener el saldo
float class_abrir_cuenta::obtener_saldo() const {
    return saldo;
}

// Método para cambiar la contraseña
void class_abrir_cuenta::cambiar_contrasena() {
    char nuevaContrasena[100];
    cout << "Ingrese la nueva contraseña: ";
    cin.ignore();
    cin.getline(nuevaContrasena, 100);
    strcpy(atr_contrasena, nuevaContrasena);
    cout << "Contraseña cambiada exitosamente.\n";
}

//======================================================================
// Clase para mostrar los datos de una cuenta
class class_mostrar_cuenta {
public:
    class_mostrar_cuenta(const class_abrir_cuenta &var_cuenta);
    void mostrar_datos_cuenta() const;

private:
    const class_abrir_cuenta &var_cuenta;
};

// Constructor de la clase mostrar_cuenta
class_mostrar_cuenta::class_mostrar_cuenta(const class_abrir_cuenta &var_cuenta) : var_cuenta(var_cuenta) {}

// Método para mostrar los datos de una cuenta
void class_mostrar_cuenta::mostrar_datos_cuenta() const {
    cout << "Nombre: " << var_cuenta.atr_nombre_completo << endl;
    cout << "Número de cuenta: " << var_cuenta.obtener_numero_cuenta() << endl;
    cout << "Saldo: $" << var_cuenta.obtener_saldo() << endl;
}

//======================================================================
// Clase para cerrar una cuenta
class class_cerrar_cuenta {
public:
    class_cerrar_cuenta(const class_abrir_cuenta &cuenta);
    void cerrar_cuenta();

private:
    const class_abrir_cuenta &cuenta_a_cerrar;
};

// Constructor de la clase cerrar_cuenta
class_cerrar_cuenta::class_cerrar_cuenta(const class_abrir_cuenta &cuenta) : cuenta_a_cerrar(cuenta) {}

// Método para cerrar una cuenta
void class_cerrar_cuenta::cerrar_cuenta() {
    int numeroCuenta;
    char contrasena[100];
    char numeroIdentificacion[100];
    char nombre[100];
    string motivo;

    cout << "Ingrese el número de cuenta: ";
    cin >> numeroCuenta;

    cout << "Ingrese la contraseña: ";
    cin.ignore();
    cin.getline(contrasena, 100);

    cout << "Ingrese el número de identificación: ";
    cin.getline(numeroIdentificacion, 100);

    cout << "Ingrese el nombre: ";
    cin.getline(nombre, 100);

    cout << "Ingrese el motivo por el cual quiere cerrar la cuenta: ";
    cin >> motivo;

    if (numeroCuenta == cuenta_a_cerrar.obtener_numero_cuenta() &&
        strcmp(contrasena, cuenta_a_cerrar.obtener_contrasena()) == 0 &&
        strcmp(numeroIdentificacion, cuenta_a_cerrar.atr_numero_identificacion) == 0 &&
        strcmp(nombre, cuenta_a_cerrar.atr_nombre_completo) == 0 &&
        motivo == cuenta_a_cerrar.atr_motivo) {
        cout << "Cuenta cerrada exitosamente.\n";
    } else {
        cout << "Error al cerrar la cuenta. La información ingresada no coincide con la cuenta.\n";
    }
}

//======================================================================
// Clase para realizar operaciones bancarias
class OperacionesBancarias {
public:
    static void depositarDinero(class_abrir_cuenta &cuenta, float monto);
    static void retirarDinero(class_abrir_cuenta &cuenta, float monto);
    static void transferirDinero(class_abrir_cuenta &cuentaOrigen, class_abrir_cuenta &cuentaDestino, float monto);
    static void consultarSaldo(const class_abrir_cuenta &cuenta);
};

// Método para depositar dinero en una cuenta
void OperacionesBancarias::depositarDinero(class_abrir_cuenta &cuenta, float monto) {
    cuenta.saldo += monto;
    cout << "Depósito exitoso. Nuevo saldo: $" << cuenta.obtener_saldo() << endl;
}

// Método para retirar dinero de una cuenta
void OperacionesBancarias::retirarDinero(class_abrir_cuenta &cuenta, float monto) {
    if (monto <= cuenta.saldo) {
        cuenta.saldo -= monto;
        cout << "Retiro exitoso. Nuevo saldo: $" << cuenta.obtener_saldo() << endl;
    } else {
        cout << "Saldo insuficiente para realizar el retiro.\n";
    }
}

// Método para transferir dinero entre dos cuentas
void OperacionesBancarias::transferirDinero(class_abrir_cuenta &cuentaOrigen, class_abrir_cuenta &cuentaDestino, float monto) {
    if (monto <= cuentaOrigen.saldo) {
        cuentaOrigen.saldo -= monto;
        cuentaDestino.saldo += monto;
        cout << "Transferencia exitosa. Nuevo saldo de la cuenta origen: $" << cuentaOrigen.obtener_saldo() << endl;
    } else {
        cout << "Saldo insuficiente para realizar la transferencia.\n";
    }
}

// Método para consultar el saldo de una cuenta
void OperacionesBancarias::consultarSaldo(const class_abrir_cuenta &cuenta) {
    cout << "Saldo actual de la cuenta: $" << cuenta.obtener_saldo() << endl;
}
//======================================================================
// Clase para gestionar cuentas y menús
class GestorCuentas {
public:
    void ejecutarMenu();

private:
    vector<class_abrir_cuenta> cuentas;
    ServicioCliente servicioCliente;
};

// Método para ejecutar el menú principal
void GestorCuentas::ejecutarMenu() {
    int ch;

    do {
        cout << "1) Crea una cuenta\n";
        cout << "2) Mostrar información de la cuenta\n";
        cout << "3) Cerrar una cuenta\n";
        cout << "4) Operaciones Bancarias\n";
        cout << "5) Servicio al Cliente\n";
        cout << "0) Salir\n";
        cin >> ch;

        switch (ch) {
        case 1:
            {
                class_abrir_cuenta obj_cuenta;
                obj_cuenta.met_abrir_cuenta();
                cuentas.push_back(obj_cuenta);
                break;
            }
        case 2:
            {
                int numeroCuenta;
                cout << "Ingrese el número de cuenta: ";
                cin >> numeroCuenta;

                bool cuentaEncontrada = false;
                for (const auto &cuenta : cuentas) {
                    if (cuenta.obtener_numero_cuenta() == numeroCuenta) {
                        class_mostrar_cuenta mostrar_cuenta(cuenta);
                        mostrar_cuenta.mostrar_datos_cuenta();
                        cuentaEncontrada = true;
                        break;
                    }
                }

                if (!cuentaEncontrada) {
                    cout << "Cuenta no encontrada.\n";
                }

                break;
            }
        case 3:
            {
                int numeroCuenta;
                cout << "Ingrese el número de cuenta a cerrar: ";
                cin >> numeroCuenta;

                bool cuentaEncontrada = false;
                for (const auto &cuenta : cuentas) {
                    if (cuenta.obtener_numero_cuenta() == numeroCuenta) {
                        class_cerrar_cuenta cerrar_cuenta(cuenta);
                        cerrar_cuenta.cerrar_cuenta();
                        cuentaEncontrada = true;
                        break;
                    }
                }

                if (!cuentaEncontrada) {
                    cout << "Cuenta no encontrada.\n";
                }

                break;
            }
        case 4:
            {
                int opcionOperacion;
                cout << "1) Depositar Dinero\n";
                cout << "2) Retirar Dinero\n";
                cout << "3) Transferir Dinero\n";
                cout << "4) Consultar Saldo\n";
                cout << "5) Cambiar Contraseña\n";
                cout << "0) Volver al Menú Principal\n";
                cin >> opcionOperacion;

                int numeroCuenta;
                cout << "Ingrese el número de cuenta: ";
                cin >> numeroCuenta;

                bool cuentaEncontrada = false;
                for (auto &cuenta : cuentas) {
                    if (cuenta.obtener_numero_cuenta() == numeroCuenta) {
                        cuentaEncontrada = true;

                        switch (opcionOperacion) {
                        case 1:
                            {
                                float monto;
                                cout << "Ingrese el monto a depositar: $";
                                cin >> monto;
                                OperacionesBancarias::depositarDinero(cuenta, monto);
                                break;
                            }
                        case 2:
                            {
                                float monto;
                                cout << "Ingrese el monto a retirar: $";
                                cin >> monto;
                                OperacionesBancarias::retirarDinero(cuenta, monto);
                                break;
                            }
                        case 3:
                            {
                                int numeroCuentaDestino;
                                cout << "Ingrese el número de cuenta destino: ";
                                cin >> numeroCuentaDestino;

                                bool cuentaDestinoEncontrada = false;
                                for (auto &cuentaDestino : cuentas) {
                                    if (cuentaDestino.obtener_numero_cuenta() == numeroCuentaDestino) {
                                        cuentaDestinoEncontrada = true;
                                        float monto;
                                        cout << "Ingrese el monto a transferir: $";
                                        cin >> monto;
                                        OperacionesBancarias::transferirDinero(cuenta, cuentaDestino, monto);
                                        break;
                                    }
                                }

                                if (!cuentaDestinoEncontrada) {
                                    cout << "Cuenta destino no encontrada.\n";
                                }

                                break;
                            }
                        case 4:
                            OperacionesBancarias::consultarSaldo(cuenta);
                            break;
                        case 5:
                            cuenta.cambiar_contrasena();
                            break;
                        case 0:
                            // No se realiza ninguna operación, simplemente se vuelve al menú principal
                            break;
                        default:
                            cout << "Opción no válida.\n";
                            break;
                        }

                        break;
                    }
                }

                if (!cuentaEncontrada) {
                    cout << "Cuenta no encontrada.\n";
                }

                break;
            }
        case 5:
            servicioCliente.mostrarInformacionBanco();
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida.\n";
            break;
        }
    } while (ch != 0);
}

//======================================================================
// Función principal que inicia el programa
int main() {
    GestorCuentas gestor;
    gestor.ejecutarMenu();

    return 0;
}
//======================================================================
