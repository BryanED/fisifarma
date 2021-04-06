#include<iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Inventario{
	int codigo;
	char nombre[20];
	float precioVenta;
	int stock;
};

struct Cliente{
	char nombreCl[30];
	int dni;
	int edad;
	char sexo;
};

struct Ventas{
	int dniCl;
	Inventario regProducto;
	int cantidad;
	float importe;
};

void crearArchivo(FILE *H,char nombre[]);

void llenarInventario(FILE *inv,Inventario regProducto,char nombreI[]);
void llenarRegCliente(FILE *cl, Cliente regCliente,char nombreC[]);
void llenarVenta(FILE *vent, Ventas venta,char nombreI[],char nombreV[]);

void mostrarInventario(FILE *inv, Inventario regProducto,char nombreI[]);
void mostrarRegCliente(FILE *cl, Cliente regCliente,char nombreC[]);
void mostrarVentas(FILE *vent, Ventas venta,char nombreV[]);
void mostrarComprobante(FILE *vent,Ventas venta,FILE *cl,Cliente regCliente,char nombreV[],char nombreC[]);

int menuAdministrador();
void menuAccionAdministrador(char nombreI[]);

int menuCliente();
void menuAccionCliente(char nombreC[]);

int menuVenta();
void menuAccionVentas(char nombreV[],char nombreC[],char nombreI[]);

void menuAccionPrincipal();

int main(){
	menuAccionPrincipal();
	system("cls");
	cout<<"\n\n\n.:\t\tGRACIAS POR USAR EL PROGRAMA DE BOTICA\t\t:.\n\n\n";
	return 0;
}

int menuPrincipal(){
	int opc;
	cout<<"========FISIFARMA=======\n";
	cout<<"[1]	Administrador.\n"; 
	cout<<"[2]	Cliente.\n";
	cout<<"[3]	Ventas.\n";
	cout<<"[4]	Salir.\n";
	cout<<"Digite una opcion: ";
	cin>>opc;
	return opc;
}

void menuAccionPrincipal(){
	int opc;
	char sVent[]="Venta.txt";
	char sInvent[]="Inventario.txt";
	char sClient[]="Cliente.txt";
	do{
		system("cls");
		opc=menuPrincipal();
		switch (opc){
		case 1: menuAccionAdministrador(sInvent); break;
		case 2: menuAccionCliente(sClient); break;
		case 3: menuAccionVentas(sVent,sClient,sInvent); break;
		}
	}while(opc!=4);
}

int menuAdministrador(){
	int opc;
	cout<<"========ADMINISTRADOR========\n";
	cout<<"[1]	Crear Inventario.\n";
	cout<<"[2]	Llenar Inventario.\n";
	cout<<"[3]	Mostrar Inventario.\n";
	cout<<"[4]	Atras.\n";
	cout<<"Digite una opcion: ";
	cin>>opc;
	return opc; 
}

void menuAccionAdministrador(char sInvent[]){
	int opc;
	FILE *inv ;
	Inventario regProducto;

	do{
		system("cls");
		opc=menuAdministrador();
		switch (opc){
		case 1: crearArchivo(inv,sInvent);system("pause"); break;
		case 2: llenarInventario(inv,regProducto,sInvent);system("pause"); break;
		case 3: mostrarInventario(inv,regProducto,sInvent); system("pause");break;
		}
	}while(opc!=4);
}

int menuCliente(){
	int opc;
	cout<<"========CLIENTE========\n";
	cout<<"[1]	Crear cliente.\n";
	cout<<"[2]	Llenar cliente.\n";
	cout<<"[3]	Mostrar cliente.\n";
	cout<<"[4]	Atras.\n";
	cout<<"Digite una opcion: ";
	cin>>opc;
	return opc; 
}
void menuAccionCliente(char sClient[]){
	int opc;
	FILE *cl;
	Cliente regCliente;

	do{
		system("cls");
		opc=menuCliente();
		switch (opc){
		case 1: crearArchivo(cl,sClient); system("pause"); break;
		case 2: llenarRegCliente(cl,regCliente,sClient); system("pause"); break;
		case 3: mostrarRegCliente(cl,regCliente,sClient); system("pause"); break;
		}
	}while(opc!=4);
}

int menuVentas(){
	int opc;
	cout<<"========CLIENTE========\n";
	cout<<"[1]	Crear Archivo Ventas.\n";
	cout<<"[2]	Llenar ventas.\n";
	cout<<"[3]	Boleta de venta.\n";
	cout<<"[4]	Mostrar ventas.\n";
	cout<<"[5]	Atras.\n";
	cout<<"Digite una opcion: ";
	cin>>opc;
	return opc; 
}
void menuAccionVentas(char sVent[],char sClient[],char sInvent[]){
	int opc;
	FILE *vent;
	FILE *cl;
	Ventas venta;
	Cliente regCliente;
	
	do{
		system("cls");
		opc=menuVentas();
		switch (opc){
		case 1: crearArchivo(vent,sVent); system("pause"); break;
		case 2: llenarVenta(vent,venta,sInvent,sVent); system("pause"); break;
		case 3: mostrarComprobante(vent,venta,cl,regCliente,sVent,sClient);system("pause"); break;
		case 4: mostrarVentas(vent,venta,sVent); system("pause"); break;
		}
	}while(opc!=5);
}

void crearArchivo(FILE *H,char nombre[]){
	system("cls");

	H=fopen(nombre,"w");
	if(H==NULL)
	  cout<<"No se puede abrir el archivo"<<endl;
	else{
		cout<<"Creacion exitosa"<<endl;
		fclose(H);
	}
}

void llenarInventario(FILE *inv,Inventario regProducto, char nombreI[]){
	char temp[2];
	char rpta;
	system("cls");	
	
	do{	
		system("cls");
		cout<<"\t\tINGRESO DE PRODUCTOS"<<endl;
	    cout<<"---------------------------------------------"<<endl;
		cout<<"";
		gets(temp);
		cout<<"Nombre          : "; gets(regProducto.nombre);
		cout<<"Codigo          : "; cin>>regProducto.codigo;
		cout<<"Precio en soles : "; cin>>regProducto.precioVenta; 
		cout<<"Stock           : "; cin>>regProducto.stock;
		
		inv=fopen(nombreI,"a");
		
		if (inv!=NULL){
			fwrite(&regProducto,sizeof(regProducto),1,inv);
			if (!ferror(inv))
				fclose(inv);
			else
				cout<<"Error de escritura en Archivo\n";
		}
		else
			cout<<"No se puede abrir Archivo\n";
		cout<<"---------------------------------------------"<<endl;
		cout<<"Desea continuar?(S/N): ";
		cin>>rpta; cout<<"\b\b\n";
	}while(rpta=='S'||rpta=='s');
}
void llenarRegCliente(FILE *cl, Cliente regCliente,char nombreC[]){
	char temp[2];
	system("cls");	
		
	cout<<"\t\tNUEVO CLIENTE"<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<"";
	gets(temp);
	cout<<"Nombre     : "; gets(regCliente.nombreCl);
	cout<<"DNI        : "; cin>>regCliente.dni;
	cout<<"Edad       : "; cin>>regCliente.edad; 
	cout<<"Sexo <M/F> : "; cin>>regCliente.sexo;
		
	cl=fopen(nombreC,"a");
		
	if (cl!=NULL){
		fwrite(&regCliente,sizeof(regCliente),1,cl);
		if (!ferror(cl))
			fclose(cl);
		else
			cout<<"Error de escritura en Archivo";
	}
	else
		cout<<"No se puede abrir Archivo\n";		
}
void llenarVenta(FILE *vent, Ventas venta, char nombreI[],char nombreV[]){
	char temp[2];
	char rpta;
	int dniCl;
	
	Inventario regProducto;
	int c=0;
	system("cls");	
	FILE *inv;
	cout<<"---------------------------------------------"<<endl;
	cout<<"\t\tGENERANDO VENTA...\n";
	cout<<"---------------------------------------------"<<endl;
	cout<<"DNI cliente: "; cin>>dniCl;
	do{	
		cout<<"---------------------------------------------"<<endl;
		gets(temp);
		
		system("cls");
		
		cout<<"Codigo del producto: "; cin>>venta.regProducto.codigo;
		
		inv=fopen(nombreI,"r+");
		if(inv==NULL){
		cout<<"No se puede realizar el proceso de venta"<<endl;
		}else{
			while(!feof(inv)){
				fread(&regProducto, sizeof(regProducto), 1, inv);
				if(venta.regProducto.codigo==regProducto.codigo){
					c=1;
					cout<<"Producto        : "<<regProducto.nombre<<endl;
					cout<<"Precio Unitario : "<<regProducto.precioVenta<<endl;
					cout<<"Cantidad        : "; cin>>venta.cantidad;
					regProducto.stock=regProducto.stock-venta.cantidad;
					strcpy(venta.regProducto.nombre,regProducto.nombre);
					venta.regProducto.precioVenta=regProducto.precioVenta;
					venta.dniCl=dniCl;	
					if(regProducto.stock>0){
						venta.importe=venta.cantidad*regProducto.precioVenta;
						
						cout<<"Importe         : "<<venta.importe<<endl;
						vent=fopen(nombreV,"a");
						if (vent!=NULL){
							fwrite(&venta,sizeof(venta),1,vent);
							if (!ferror(vent))
								fclose(vent);
							else
								cout<<"Error de escritura en Archivo";
						}
						else
							cout<<"No se puede abrir Archivo\n";
					}
					else
						cout<<"No hay stock de producto"<<endl;
					fread(&regProducto, sizeof(regProducto), 1, inv);
				}	
			} 	
		}		
		if(c==0)
			cout<<"No puede encontrar el elemento"<<endl;	
		fclose(inv);
		cout<<"\nDesea continuar con el mismo cliente?(S/N): ";
		cin>>rpta;
		cout<<endl;
	}while(rpta=='S'||rpta=='s');		
}

void mostrarInventario(FILE *inv, Inventario regProducto,char nombre[]){	
	system("cls");
	
	inv=fopen(nombre,"r");
	
	if(inv==NULL)
		cout<<"No se puede abrir el archivo"<<endl;
	else{
		cout<<"\t\tLista de medicamentos"<<endl;
		cout<<"---------------------------------------------"<<endl;
		while(!feof(inv)){
			fread(&regProducto,sizeof(regProducto),1,inv);
			if(ferror(inv))
				cout<<"Error de lectura del archivo"<<endl;
			if(!feof(inv)){
				cout<<"Nombre          : "; cout<<regProducto.nombre<<endl;
				cout<<"Codigo          : "; cout<<regProducto.codigo<<endl;
				cout<<"Precio en soles : "; cout<<regProducto.precioVenta<<endl; 
				cout<<"Stock           : "; cout<<regProducto.stock<<endl;
				cout<<"---------------------------------------------"<<endl;
			}
		}
		fclose(inv);
	}
}
void mostrarRegCliente(FILE *cl, Cliente regCliente,char nombreC[]){
	system("cls");
	
	cl=fopen(nombreC,"r");
	
	if(cl==NULL)
		cout<<"No se puede abrir el archivo"<<endl;
	else{
		cout<<"\t\tLista de clientes"<<endl;
		cout<<"---------------------------------------------"<<endl;
		while(!feof(cl)){
			fread(&regCliente,sizeof(regCliente),1,cl);
			if(ferror(cl))
				cout<<"Error de lectura del archivo"<<endl;
			if(!feof(cl)){
				cout<<"Nombre  : "; cout<<regCliente.nombreCl<<endl;
				cout<<"DNI     : "; cout<<regCliente.dni<<endl;
				cout<<"Edad    : "; cout<<regCliente.edad<<endl; 
				cout<<"Sexo    : "; cout<<regCliente.sexo<<endl;
				cout<<"---------------------------------------------"<<endl;
			}
		}
		fclose(cl);
	}
}
void mostrarVentas(FILE *vent, Ventas venta,char nombreV[]){
	system("cls");
	Inventario regProducto;
	int g=0;
	
	vent=fopen(nombreV,"r");
	if(vent==NULL)
		cout<<"No se puede abrir el archivo"<<endl;
	else{
		cout<<"\t\tVENTAS REALIZADAS"<<endl;
		cout<<"---------------------------------------------"<<endl;
		while(!feof(vent)){
			fread(&venta,sizeof(venta),1,vent);
			if(ferror(vent))
				cout<<"Error de lectura del archivo"<<endl;
			if(!feof(vent)){
				cout<<"Producto        : "<<venta.regProducto.nombre<<endl;
				cout<<"Codigo          : "<<venta.regProducto.codigo<<endl;
				cout<<"Precio unitario : "<<venta.regProducto.precioVenta<<endl; 
				cout<<"Cantidad        : "<<venta.cantidad<<endl;
				cout<<"Importe Neto    : "<<venta.importe<<endl;
				cout<<"---------------------------------------------"<<endl;
				g=g+venta.importe;
			}
		}
		fclose(vent);
		cout<<"Ganancia del dia: "<<g<<endl;
		cout<<"---------------------------------------------"<<endl;
	}
}

void mostrarComprobante(FILE *vent,Ventas venta,FILE *cl,Cliente regCliente,char nombreV[],char nombreC[]){
	char temp[2];
	int c=0;
	float subTotal=0,igv=0,total=0; 
	int docIdentidad;
	
	system("cls");
	cout<<"---------------------------------------------"<<endl;
	cout<<"\t\tBOLETA DE VENTA\n";
	cout<<"---------------------------------------------"<<endl;
	gets(temp);
	cout<<"BOTICA FISIFARMA              RUC:20399497257\n";
	cout<<"---------------------------------------------"<<endl;
	cout<<"DNI del cliente: ";
	cin>>docIdentidad;
	cl=fopen(nombreC,"r+");
	if(cl==NULL)
		cout<<"No se puede realizar el proceso"<<endl;
	else{
		while(!feof(cl)){
			fread(&regCliente, sizeof(regCliente), 1, cl);
			if(docIdentidad==regCliente.dni){
				c=1;
				cout<<"Nombre         : "<<regCliente.nombreCl<<endl;
				cout<<"Edad           : "<<regCliente.edad<<endl; 
				cout<<"Sexo           : "<<regCliente.sexo<<endl;
				cout<<"---------------------------------------------"<<endl;
				fread(&regCliente,sizeof(regCliente),1,cl);	
			}			
		}
		if(c==0)
			cout<<"No puede encontrar el elemento"<<endl;	
		fclose(cl);	
	}
	c=0;
	vent=fopen(nombreV,"r+");
	if(vent==NULL)
		cout<<"No se puede realizar el proceso"<<endl;
	else{
		while(!feof(vent)){
			fread(&venta,sizeof(venta),1,vent);
			if(ferror(vent))
				cout<<"Error de lectura del archivo"<<endl;
			if(!feof(vent)){
				if(docIdentidad==venta.dniCl){
					c=1;
					cout<<"\tCodigo de producto: "<<venta.regProducto.codigo<<endl;
					cout<<"\tNombre de producto: "<<venta.regProducto.nombre<<endl;
					cout<<"\tPrecio unitario   : "<<venta.regProducto.precioVenta<<endl;
					cout<<"\tCantidad          : "<<venta.cantidad<<endl;
					cout<<"\tImporte           : "<<venta.importe<<endl;
					
					subTotal=subTotal+venta.importe;
					igv=igv+0.18*venta.importe;
					total=total+1.18*venta.importe;	
					cout<<"\n\n";	
				}
			}
			
		}fclose(vent);
		if(c==1){
			cout<<"---------------------------------------------"<<endl;
			cout<<"Subtotal  : "<<subTotal<<endl;
			cout<<"IGV (18%) : "<<igv<<endl;
			cout<<"Total     : "<<total<<endl;
			cout<<"---------------------------------------------"<<endl;
		}
	}		
}
