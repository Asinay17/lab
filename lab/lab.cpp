// lab.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
class vehiculo
{
private:
	string marca;
	string modelo;
	double precio;
public:
	vehiculo(string m, string mod, double p) :	marca(m), modelo(mod), precio(p){}
		
	string getMarca() const { return marca; }
	void setMarca(string  m) { marca = m; }

	string getModelo() const { return modelo; }
	void setModelo(string  mod) { modelo = mod; }

	double getprecio() const { return precio; }
	void setprecio(double  p) { precio = p; }


	virtual void mostrarInfo()const {
		cout << "vehiculo:" << marca << " " << modelo << " ,precio:$" << precio << endl;
	}
};


class Automovil :public vehiculo {
private: 
	int numPuertas;
public:
	Automovil(string m, string mod, double p,int puertas) 
		: vehiculo(m, mod, p), numPuertas(puertas) {}

	void mostrarInfo() const override {
		vehiculo::mostrarInfo();
			cout << ",puertas" << numPuertas << endl;
	}


};
class motocicleta : public vehiculo{

private:
	int cilindraje;

public:
	motocicleta(string m, string mod, double p, int cil)
		: vehiculo(m, mod, p), cilindraje(cil) {}

	void mostrarInfo()const override {
		vehiculo::mostrarInfo();
		cout << ",cilindraje" << cilindraje << "cc" << endl;
}
	

};
class camioneta : public vehiculo {

private:
	int capacidadCarga;

public:
	camioneta(string m, string mod, double p, int cp)
		: vehiculo(m, mod, p), capacidadCarga(cp) {
	}

	void mostrarInfo()const override {
		vehiculo::mostrarInfo();
		cout << ",capaciad de carga" << capacidadCarga << "toneldas" << endl;
	}


};

class cliente {
private:
	string nombre;
	int edad;

public:
	cliente(string n,int e):nombre(n),edad(e){}
	void comprarvehiculo(vehiculo *v )const  {
		cout << "cliente:" << nombre << " ha comporaddo:" << v->getMarca() << " " << v->getModelo() << endl;
	}



};
int main() {
	// Crear instancias de vehículos
	Automovil auto1("Toyota","Corolla", 25000, 4);
	motocicleta moto1("Yamaha", "R1", 18000, 1000);
	camioneta camioneta1("Ford", "Ranger", 30000, 1.5);

	// Crear un cliente
	cliente cliente1("juan",28 );

	// Mostrar la información de los vehículos
	auto1.mostrarInfo();
	moto1.mostrarInfo();
	camioneta1.mostrarInfo();
		
	// Simular compra
	cliente1.comprarvehiculo(&auto1);  // Juan compra el Toyota Corolla

	return 0;
}