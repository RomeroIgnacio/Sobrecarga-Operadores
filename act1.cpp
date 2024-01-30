#include <iostream>
#include <string>

class Empleado
{
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReporteA;

public:
    Empleado(int clave, std::string nom, std::string dom, float sal, std::string repA) : ClaveEmpleado(clave), Nombre(nom), Domicilio(dom), Sueldo(sal), ReporteA(repA) {}
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
        std::getline(in, emp.Nombre);

        std::cout << "Ingrese el Domicilio: ";
        std::getline(in, emp.Domicilio);

        std::cout << "Ingrese el Sueldo: ";
        in >> emp.Sueldo;

        std::cout << "Ingrese el ReporteA: ";
        in.ignore();
        std::getline(in, emp.ReporteA);

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Empleado& emp)
    {
        out << "Clave del Empleado: " << emp.ClaveEmpleado << "\n";
        out << "Nombre: " << emp.Nombre << "\n";
        out << "Domicilio: " << emp.Domicilio << "\n";
        out << "Sueldo: " << emp.Sueldo << "\n";
        out << "ReporteA: " << emp.ReporteA << "\n";

        return out;
    }

    void Imprime()
    {
        std::cout << *this;
    }

    void CambiarDomic(std::string& nuevoDomicilio)
    {
        Domicilio = nuevoDomicilio;
    }

    void CambiarReporteA(std::string& nuevoReporteA)
    {
        ReporteA = nuevoReporteA;
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
    Empleado JefePlanta(1, "NombreJefePlanta", "DomicilioJefePlanta", 5000.0, "ReporteAJefePlanta");
    Empleado JefePersonal(2, "NombreJefePersonal", "DomicilioJefePersonal", 6000.0, "ReporteAJefePersonal");


    int opcion;
    do
    {
        std::cout << "\nMenú:\n 1. Cambiar domicilio de un empleado\n 2. Actualizar sueldo de un empleado\n 3. Imprimir datos de un empleado\n 4. Cambiar el nombre de la persona a quien reporta un empleado\n 5. Salir\nIngrese la opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                int claveDomicilio;
                std::string nuevoDomicilio;

                std::cout << "\nIngrese la clave del empleado para cambiar domicilio: ";
                std::cin >> claveDomicilio;

                std::cout << "Ingrese el nuevo domicilio: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoDomicilio);

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
                    std::cout << "\nEmpleado no encontrado.\n";
                }
                break;
            }

            case 2:
            {
                int claveSueldo;
                float porcentajeIncremento;

                std::cout << "\nIngrese la clave del empleado para actualizar sueldo: ";
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
                    std::cout << "\nEmpleado no encontrado.\n";
                }
                break;
            }

            case 3:
            {
                int claveImprimir;

                std::cout << "\nIngrese la clave del empleado para imprimir datos: ";
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
                    std::cout << "\nEmpleado no encontrado.\n";
                }
                break;
            }

            case 4:
            {
                int claveReporteA;
                std::string nuevoReporteA;

                std::cout << "\nIngrese la clave del empleado para cambiar el nombre de la persona a quien reporta: ";
                std::cin >> claveReporteA;

                std::cout << "Ingrese el nuevo nombre: ";
                std::cin.ignore();
                std::getline(std::cin, nuevoReporteA);

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
                    std::cout << "\nEmpleado no encontrado.\n";
                }
                break;
            }

            case 5:
            {
                std::cout << "\nSaliendo del programa.\n";
                break;
            }

            default:
            {
                std::cout << "\nOpción no válida.\n";
                break;
            }
        }
    } while (opcion != 5);

    return 0;
}