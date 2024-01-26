#include <iostream>
#include <cstring>

class Materia {
private:
    int Clave;
    char Nombre[50];
    char ProfesorTitular[50];
    char LibroTexto[50];

public:
    bool operator==(Materia& mat)
    {
        return Clave == mat.Clave;
    }

    bool operator!=(Materia& mat)
    {
        return Clave != mat.Clave;
    }

    bool operator<(Materia& mat)
    {
        return Clave < mat.Clave;
    }

    bool operator>(Materia& mat)
    {
        return Clave > mat.Clave;
    }

    friend std::istream& operator>>(std::istream& in, Materia& mat)
    {
        std::cout << "Ingrese la Clave de la Materia: ";
        in >> mat.Clave;

        std::cout << "Ingrese el Nombre de la Materia: ";
        in.ignore();
        in.getline(mat.Nombre, sizeof(mat.Nombre));

        std::cout << "Ingrese el Profesor Titular: ";
        in.getline(mat.ProfesorTitular, sizeof(mat.ProfesorTitular));

        std::cout << "Ingrese el Libro de Texto: ";
        in.getline(mat.LibroTexto, sizeof(mat.LibroTexto));

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Materia& mat)
    {
        out << "Clave de la Materia: " << mat.Clave << "\n";
        out << "Nombre de la Materia: " << mat.Nombre << "\n";
        out << "Profesor Titular: " << mat.ProfesorTitular << "\n";
        out << "Libro de Texto: " << mat.LibroTexto << "\n";

        return out;
    }

    void Imprime()
    {
        std::cout << *this;
    }

    void CambiaClave(int nuevaClave)
    {
        Clave = nuevaClave;
    }

    void CambiaProfe(char nuevoProfesor[])
    {
        std::strcpy(ProfesorTitular, nuevoProfesor);
    }
};

int main()
{
    Materia Programacion, BasesDatos;

    int opcion;
    do
    {
        std::cout << "\nMenú:\n 1. Cambiar la clave de la materia Programación\n 2. Cambiar el nombre del maestro que imparte la materia Bases de Datos\n 3. Imprimir todos los datos de la materia Bases de Datos\n 4. Salir\nIngrese la opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
                int nuevaClaveProgramacion;

                std::cout << "Ingrese la nueva clave para Programación: ";
                std::cin >> nuevaClaveProgramacion;

                Programacion.CambiaClave(nuevaClaveProgramacion);
                break;

            case 2:
                char nuevoProfesorBasesDatos[50];

                std::cout << "Ingrese el nuevo nombre del maestro para Bases de Datos: ";
                std::cin.ignore();
                std::cin.getline(nuevoProfesorBasesDatos, sizeof(nuevoProfesorBasesDatos));

                BasesDatos.CambiaProfe(nuevoProfesorBasesDatos);
                break;

            case 3:
                BasesDatos.Imprime();
                break;

            case 4:
                std::cout << "Saliendo del programa.\n";
                break;

            default:
                std::cout << "Opción no válida.\n";
        }
    } while (opcion != 4);

    return 0;
}