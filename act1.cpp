#include <iostream>
#include <cstring>

class Empleado
{
private:
    int ClaveEmpleado;
    char Nombre[50];
    char Domicilio[100];
    float Sueldo;
    char ReporteA[50];

public:
    bool operator==(Empleado& emp)
    {
        return ClaveEmpleado == emp.ClaveEmpleado;
    }

    bool operator!=(Empleado& emp)
    {
        return ClaveEmpleado != emp.ClaveEmpleado;
    }

    bool operator<(Empleado& emp)
    {
        return ClaveEmpleado < emp.ClaveEmpleado;
    }

    bool operator>(Empleado& emp)
    {
        return ClaveEmpleado > emp.ClaveEmpleado;
    }

    friend std::istream& operator>>(std::istream& in, Empleado& emp)
    {
        std::cout << "Ingrese la Clave del Empleado: ";
        in >> emp.ClaveEmpleado;

        std::cout << "Ingrese el Nombre: ";
        in.ignore();
        in.getline(emp.Nombre, sizeof(emp.Nombre));

        std::cout << "Ingrese el Domicilio: ";
        in.getline(emp.Domicilio, sizeof(emp.Domicilio));

        std::cout << "Ingrese el Sueldo: ";
        in >> emp.Sueldo;

        std::cout << "Ingrese el ReporteA: ";
        in.ignore();
        in.getline(emp.ReporteA, sizeof(emp.ReporteA));

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Empleado& emp)
    {
        out << "Clave del Empleado: " << emp.ClaveEmpleado << "\n";
        out << "Nombre: " << emp.Nombre << "\n";
        out << "Domicilio: " << emp.Domicilio << "\n";
        out << "Sueldo: " << emp.Sueldo << "\n";
        out << "ReporteA: " << emp.ReporteA << "\n";

        return out;
    }

    void Imprime() const
    {
        std::cout << *this;
    }

    void CambiarDomic(char nuevoDomicilio[])
    {
        std::strcpy(Domicilio, nuevoDomicilio);
    }

    void CambiarReporteA(char nuevoReporteA[])
    {
        std::strcpy(ReporteA, nuevoReporteA);
    }

    void ActualSueldo(float porcentajeIncremento)
    {
        Sueldo *= (1 + porcentajeIncremento / 100);
    }

    int ObtenerClave()
    {
        return ClaveEmpleado;
    }
};

int main()
{
    Empleado JefePlanta, JefePersonal;

    int opcion;
    do
    {
        std::cout << "\nMenú:\n 1. Cambiar domicilio de un empleado\n 2. Actualizar sueldo de un empleado\n 3. Imprimir datos de un empleado\n 4. Cambiar el nombre de la persona a quien reporta un empleado\n 5. Salir\nIngrese la opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
                int claveDomicilio;
                char nuevoDomicilio[100];

                std::cout << "Ingrese la clave del empleado para cambiar domicilio: ";
                std::cin >> claveDomicilio;

                std::cout << "Ingrese el nuevo domicilio: ";
                std::cin.ignore();
                std::cin.getline(nuevoDomicilio, sizeof(nuevoDomicilio));

                if (JefePlanta.ObtenerClave() == claveDomicilio)
                {
                    JefePlanta.CambiarDomic(nuevoDomicilio);
                }
                else if (JefePersonal.ObtenerClave() == claveDomicilio)
                {
                    JefePersonal.CambiarDomic(nuevoDomicilio);
                }
                else
                {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;

            case 2:
                int claveSueldo;
                float porcentajeIncremento;

                std::cout << "Ingrese la clave del empleado para actualizar sueldo: ";
                std::cin >> claveSueldo;

                std::cout << "Ingrese el porcentaje de incremento: ";
                std::cin >> porcentajeIncremento;

                if (JefePlanta.ObtenerClave() == claveSueldo)
                {
                    JefePlanta.ActualSueldo(porcentajeIncremento);
                }
                else if (JefePersonal.ObtenerClave() == claveSueldo)
                {
                    JefePersonal.ActualSueldo(porcentajeIncremento);
                }
                else
                {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;

            case 3:
                int claveImprimir;

                std::cout << "Ingrese la clave del empleado para imprimir datos: ";
                std::cin >> claveImprimir;

                if (JefePlanta.ObtenerClave() == claveImprimir)
                {
                    JefePlanta.Imprime();
                }
                else if (JefePersonal.ObtenerClave() == claveImprimir)
                {
                    JefePersonal.Imprime();
                }
                else
                {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;

            case 4:
                int claveReporteA;
                char nuevoReporteA[50];

                std::cout << "Ingrese la clave del empleado para cambiar el nombre de la persona a quien reporta: ";
                std::cin >> claveReporteA;

                std::cout << "Ingrese el nuevo nombre: ";
                std::cin.ignore();
                std::cin.getline(nuevoReporteA, sizeof(nuevoReporteA));

                if (JefePlanta.ObtenerClave() == claveReporteA)
                {
                    JefePlanta.CambiarReporteA(nuevoReporteA);
                }
                else if (JefePersonal.ObtenerClave() == claveReporteA)
                {
                    JefePersonal.CambiarReporteA(nuevoReporteA);
                }
                else
                {
                    std::cout << "Empleado no encontrado.\n";
                }
                break;

            case 5:
                std::cout << "Saliendo del programa.\n";
                break;

            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion);

    return 0;
}