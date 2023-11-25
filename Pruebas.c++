#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class class_abrir_cuenta {
public:
    class_abrir_cuenta();
    void met_abrir_cuenta();
    int obtener_numero_cuenta() const;
    const char* obtener_contrasena() const;

public:
    static int atr_contador_cuentas;
    int atr_numero_cuenta;
    char atr_nombre_completo[100];
    char atr_numero_identificacion[100];
    char atr_numero_celular[100];
    char atr_edad[100];
    string atr_motivo;
    char atr_contrasena[100];
};

int class_abrir_cuenta::atr_contador_cuentas = 1;

class_abrir_cuenta::class_abrir_cuenta() {
    atr_numero_cuenta = atr_contador_cuentas++;
}

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

int class_abrir_cuenta::obtener_numero_cuenta() const {
    return atr_numero_cuenta;
}

const char* class_abrir_cuenta::obtener_contrasena() const {
    return atr_contrasena;
}

class class_mostrar_cuenta {
public:
    class_mostrar_cuenta(const class_abrir_cuenta &var_cuenta);
    void mostrar_datos_cuenta() const;

private:
    const class_abrir_cuenta &var_cuenta;
};

class_mostrar_cuenta::class_mostrar_cuenta(const class_abrir_cuenta &var_cuenta) : var_cuenta(var_cuenta) {}

void class_mostrar_cuenta::mostrar_datos_cuenta() const {
    cout << "Nombre: " << var_cuenta.atr_nombre_completo << endl;
    cout << "Número de cuenta: " << var_cuenta.obtener_numero_cuenta() << endl;
}

class class_cerrar_cuenta {
public:
    class_cerrar_cuenta(const class_abrir_cuenta &cuenta);
    void cerrar_cuenta();

private:
    const class_abrir_cuenta &cuenta_a_cerrar;
};

class_cerrar_cuenta::class_cerrar_cuenta(const class_abrir_cuenta &cuenta) : cuenta_a_cerrar(cuenta) {}

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

    // Verificar si la información ingresada coincide con la cuenta a cerrar
    if (numeroCuenta == cuenta_a_cerrar.obtener_numero_cuenta() &&
        strcmp(contrasena, cuenta_a_cerrar.obtener_contrasena()) == 0 &&
        strcmp(numeroIdentificacion, cuenta_a_cerrar.atr_numero_identificacion) == 0 &&
        strcmp(nombre, cuenta_a_cerrar.atr_nombre_completo) == 0 &&
        motivo == cuenta_a_cerrar.atr_motivo) {
        cout << "Cuenta cerrada exitosamente.\n";
        // Aquí podrías realizar otras acciones, como eliminar la cuenta del vector.
    } else {
        cout << "Error al cerrar la cuenta. La información ingresada no coincide con la cuenta.\n";
    }
}

class GestorCuentas {
public:
    void ejecutarMenu();

private:
    vector<class_abrir_cuenta> cuentas;
};

void GestorCuentas::ejecutarMenu() {
    int ch;

    do {
        cout << "1) Crea una cuenta\n";
        cout << "2) Mostrar información de la cuenta\n";
        cout << "3) Cerrar una cuenta\n";
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

                // Buscar la cuenta por número de cuenta
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

                // Buscar la cuenta por número de cuenta
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
        }
    } while (ch != 0);
}

int main() {
    GestorCuentas gestor;
    gestor.ejecutarMenu();

    return 0;
}