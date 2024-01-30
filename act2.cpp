#include <iostream>
#include <string>

class Materia
{
private:
    int Clave;
    std::string Nombre;
    std::string ProfesorTitular;
    std::string LibroTexto;

public:
    Materia(int clave, std::string nom, std::string profe, std::string libro) : Clave(clave), Nombre(nom), ProfesorTitular(profe), LibroTexto(libro) {}

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

    Materia operator+(const Materia& mat)
    {
        // Concatenar los nombres de las materias en el nuevo objeto Materia
        Materia nuevaMateria(0, Nombre + mat.Nombre, "", "");
        return nuevaMateria;
    }

    friend std::istream& operator>>(std::istream& in, Materia& mat)
    {
        std::cout << "Ingrese la Clave de la Materia: ";
        in >> mat.Clave;

        std::cout << "Ingrese el Nombre de la Materia: ";
        in.ignore();
        std::getline(in, mat.Nombre);

        std::cout << "Ingrese el Profesor Titular: ";
        std::getline(in, mat.ProfesorTitular);

        std::cout << "Ingrese el Libro de Texto: ";
        std::getline(in, mat.LibroTexto);

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, Materia& mat)
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

    void CambiaProfe(std::string nuevoProfesor)
    {
        ProfesorTitular = nuevoProfesor;
    }

    int ObtenerClave() const
    {
        return Clave;
    }
};

int main()
{
    Materia Programación(1, "Programacion", "ProfesorProgramacion", "LibroProgramacion");
    Materia BasesDatos(2, "BasesDatos", "ProfesorBasesDatos", "LibroBasesDatos");

    int opcion;
    do
    {
        std::cout << "\nMenú:\n 1. Imprime los datos de la materia\n 2. Cambiar clave de la materia\n 3. Cambiar profesor de la materia\n 4. Salir\nIngrese la opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
            case 1:
            {
                int claveMateria;
                std::cout << "\nIngrese la clave de la materia a imprimir: ";
                std::cin >> claveMateria;
                
                if (Programación.ObtenerClave() == claveMateria)
                {
                    Programación.Imprime();
                }
                else if (BasesDatos.ObtenerClave() == claveMateria)
                {
                    BasesDatos.Imprime();
                }
                else
                {
                    std::cout << "\nMateria no encontrada.\n";
                }
                break;
            }

            case 2:
            {
                int claveMateria, nuevaClave;
                std::cout << "\nIngrese la clave de la materia a cambiar: ";
                std::cin >> claveMateria;

                std::cout << "\nIngrese la nueva clave de la materia: ";
                std::cin >> nuevaClave;
                
                if (Programación.ObtenerClave() == claveMateria)
                {
                    Programación.CambiaClave(nuevaClave);
                }
                else if (BasesDatos.ObtenerClave() == claveMateria)
                {
                    BasesDatos.CambiaClave(nuevaClave);
                }
                else
                {
                    std::cout << "\nMateria no encontrada.\n";
                }
                break;
            }

            case 3:
            {
                int claveMateria;
                std::string nuevoProfesor;
                std::cout << "\nIngrese la clave de la materia a cambiar el nombre del profesor: ";
                std::cin >> claveMateria;

                std::cin.ignore();
                std::cout << "\nIngrese el nuevo nombre del profesor: ";
                std::getline(std::cin, nuevoProfesor);

                if (Programación.ObtenerClave() == claveMateria)
                {
                    Programación.CambiaProfe(nuevoProfesor);
                }
                else if (BasesDatos.ObtenerClave() == claveMateria)
                {
                    BasesDatos.CambiaProfe(nuevoProfesor);
                }
                else
                {
                    std::cout << "\nMateria no encontrada.\n";
                }
                break;
            }

            case 4:
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
    } while (opcion != 4);

    return 0;
}
