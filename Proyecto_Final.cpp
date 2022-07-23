#include <iostream>

using namespace std;

class Contacto{
    string Dni;
    string Nombres;
    string Apellidos;
    string Sexo;
    string F_nac;
    string Correo;
    string Telefono;
    string Direccion;

public:
    Contacto(){}

    void setDni(string valor)
	{
		Dni = valor;
	}
	void setNombres(string valor)
	{
		Nombres = valor;
	}
	void setApellidos(string valor)
	{
		Apellidos = valor;
	}
	void setSexo(string valor)
	{
		Sexo = valor;
	}
	void setF_nac(string valor)
	{
		F_nac = valor;
	}
	void setCorreo(string valor)
	{
		Correo = valor;
	}
	void setTelefono(string valor)
	{
		Telefono = valor;
	}
	void setDireccion(string valor)
	{
		Direccion = valor;
	}
	string getDni()
	{
		return Dni;
	}
	string getNombres()
	{
		return Nombres;
	}
	string getApellidos()
	{
		return Apellidos;
	}
	string getSexo()
	{
		return Sexo;
	}
	string getF_nac()
	{
		return F_nac;
	}
	string getCorreo()
	{
		return Correo;
	}
	string getTelefono()
	{
		return Telefono;
	}
	string getDireccion()
	{
		return Direccion;
	}
};

class Nodo {
	Contacto dato;
	Nodo* enlace;
public:

	Nodo(Contacto dato)
	{
		this->dato = dato;
		enlace = NULL;
	}
	Contacto getDato()
	{
		return dato;
	}
	void setDato(Contacto dato)
	{
		this->dato = dato;
	}
	Nodo* getEnlace()
	{
		return this->enlace;
	}
	void setEnlace(Nodo* enlace)
	{
		this->enlace = enlace;
	}
	void imprimir()
	{
		cout << "\n\nDNI: " << dato.getDni() << endl;
		cout << "Nombres: " << dato.getNombres() << endl;
		cout << "Apellidos: " << dato.getApellidos() << endl;
		cout << "Sexo: " << dato.getSexo() << endl;
		cout << "Fecha de Nacimiento: " << dato.getF_nac() << endl;
		cout << "Correo: " << dato.getCorreo() << endl;
		cout << "Telefono: " << dato.getTelefono() << endl;
		cout << "Direccion: " << dato.getDireccion() << endl;
	}
};

class Lista {
	Nodo* inicio;
public:
	Lista()
	{
		this->inicio = NULL;
	}
	void InsertarContacto(Contacto dato)
	{
		Nodo* temp = new Nodo(dato);
		if (EstaVacia())
		{
			inicio = temp;
		}
		else
		{
			Nodo* recorrido = this->inicio;
			while (recorrido->getEnlace() != NULL)
			{
				recorrido = recorrido->getEnlace();
			}
			recorrido->setEnlace(temp);
		}
	}

	void Imprimir()
	{
		int i = 1;
		Nodo* recorrido = inicio;
		cout << "\n\nContactos"<<endl;
		cout << "****************************" << endl;
		while (recorrido != NULL)
		{
			recorrido->imprimir();
			recorrido = recorrido->getEnlace();
		}
		cout << "****************************" << endl << endl;
	}

	void ImprimirOrdenado()
	{

	}

	void BuscarContacto01(string Dni)
	{
		bool encontrado = false;
		Nodo* recorrido = inicio;
		while (recorrido != NULL)
		{
			if (recorrido->getDato().getDni() == Dni)
			{
				recorrido->imprimir();
				encontrado = true;
				break;
			}
			else
			{
				recorrido = recorrido->getEnlace();
			}
		}
		if (encontrado == false)
		{
			cout << "El elemento buscado no fue encontrado." << endl;
		}
	}

	void BuscarContacto02(string Nombres)
	{
		bool encontrado = false;
		Nodo* recorrido = inicio;
		while (recorrido != NULL)
		{
			if (recorrido->getDato().getNombres() == Nombres)
			{
				recorrido->imprimir();
				encontrado = true;
				break;
			}
			else
			{
				recorrido = recorrido->getEnlace();
			}
		}
		if (encontrado == false)
		{
			cout << "El elemento buscado no fue encontrado." << endl;
		}
	}

	void BuscarContacto03(string Apellidos)
	{
		bool encontrado = false;
		Nodo* recorrido = inicio;
		while (recorrido != NULL)
		{
			if (recorrido->getDato().getApellidos() == Apellidos)
			{
				recorrido->imprimir();
				encontrado = true;
				break;
			}
			else
			{
				recorrido = recorrido->getEnlace();
			}
		}
		if (encontrado == false)
		{
			cout << "El elemento buscado no fue encontrado." << endl;
		}
	}

	void BuscarContacto04(string F_nac)
	{
		bool encontrado = false;
		Nodo* recorrido = inicio;
		while (recorrido != NULL)
		{
			if (recorrido->getDato().getF_nac() == F_nac)
			{
				recorrido->imprimir();
				encontrado = true;
				break;
			}
			else
			{
				recorrido = recorrido->getEnlace();
			}
		}
		if (encontrado == false)
		{
			cout << "El elemento buscado no fue encontrado." << endl;
		}
	}

	void EliminarContacto(int posicion)
	{
		int contador = 0;
		if (EstaVacia())
		{
			cout << "No hay elemento a eliminar" << endl;
		}
		else
		{
            Nodo* recorrido = inicio;

            while (recorrido->getEnlace() != NULL)
            {
                if (contador == posicion - 1)
                {
                    recorrido->setEnlace(recorrido->getEnlace()->getEnlace());
                    break;
                }
                else
                {
                    contador++;
                    recorrido = recorrido->getEnlace();
                }

            }
		}
	}

	bool EstaVacia()
	{
		if (inicio == NULL)
			return true;
		else
			return false;
	}
};

void MostrarMenu()
{
	cout << "\n\n1.- Ver el contenido de los Contactos" << endl;
	cout << "2.- Añadir Contacto" << endl;
	cout << "3.- Buscar Contacto" << endl;
	cout << "4.- Eliminar Contacto en la posición" << endl;
	cout << "0.- Salir" << endl;
}

void MostrarMenu2()
{
	cout << "\n\n6.- Buscar Contacto por DNI" << endl;
	cout << "7.- Buscar Contacto por Nombre" << endl;
	cout << "8.- Buscar Contacto por Apellido" << endl;
	cout << "9.- Buscar Contacto por Fecha de Nacimiento" << endl;
	cout << "0.- Salir" << endl;
}

Contacto LeerDatosContacto()
{
	Contacto contacto = Contacto();
	string temporal;

	cout << "\n\nIngrese DNI: ";
	cin >> temporal;
	contacto.setDni(temporal);

	cout << "\nIngrese Nombres: ";
	cin >> temporal;
	contacto.setNombres(temporal);

	cout << "\nIngrese Apellidos: ";
	cin >> temporal;
	contacto.setApellidos(temporal);

	cout << "\nIngrese Sexo: ";
	cin >> temporal;
	contacto.setSexo(temporal);

	cout << "\nIngrese Fecha de Nacimiento: ";
	cin >> temporal;
	contacto.setF_nac(temporal);

	cout << "\nIngrese Correo: ";
	cin >> temporal;
	contacto.setCorreo(temporal);

	cout << "\nIngrese Telefono: ";
	cin >> temporal;
	contacto.setTelefono(temporal);

	cout << "\nIngrese Direccion: ";
	cin >> temporal;
	contacto.setDireccion(temporal);

	return contacto;
}

int main()
{
    Lista agenda = Lista();
	int posicion;
	string Dni;
	string Nombres;
	string Apellidos;
	string F_nac;
	Contacto elemento = Contacto();
	int opcion, opcion2;
	do
	{
		MostrarMenu();
		cin >> opcion;
		switch (opcion)
		{
		case 0:
			cout << "Ingeniería de Sistemas, hasta luego." << endl;
			break;
		case 1:
			agenda.Imprimir();
			break;
		case 2:
			agenda.InsertarContacto(LeerDatosContacto());
			break;
		case 3:
		    MostrarMenu2();
            cin >> opcion2;
            switch (opcion2)
            {
                case 6:
                cout << "\n\nDigite el numero de dni: " << endl;
                cin >> Dni;
                agenda.BuscarContacto01(Dni);
                break;

                case 7:
                cout << "Digite el nombre: " << endl;
                cin >> Nombres;
                agenda.BuscarContacto02(Nombres);
                break;

                case 8:
                cout << "Digite el apellido: " << endl;
                cin >> Apellidos;
                agenda.BuscarContacto03(Apellidos);
                break;

                case 9:
                cout << "Digite la fecha de Nacimineto: " << endl;
                cin >> F_nac;
                agenda.BuscarContacto04(F_nac);
                break;
            } while (opcion != 0);

			break;
		case 4:
			cout << "\n\nDigite posición del contacto: " << endl;
			cin >> posicion;
			agenda.EliminarContacto(posicion);
			break;
		default:
			cout << "Opción no valida." << endl;
			break;
		}
	} while (opcion != 0);
}
