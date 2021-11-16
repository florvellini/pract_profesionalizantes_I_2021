#include<iostream>
#include<string>
#include<cstdio>
#include<fstream>
#include<windows.h>
using namespace std;


void borrarinvitado(ifstream &borrar) //BORRAR UN INVITADO
    {

    system("cls");
    string nombre;
    string apellido;
    string nticket;
    string asistencia;
    string nombreaux, apellidoaux,nticketaux,asistaux;//variables aux para ingresar nuevos datos y reescribir los existentes

     borrar.open("Lista_de_invitados.txt", ios::in);
     ofstream aux("editinvitados.txt", ios::out);//creo un txt nuevo para ingresar datos temporales y asi guardar los cambios


     if(borrar.is_open()){
        cout<<"Ingrese el numero de ticket del invitado que quiere eliminar: ";
        cin>>nticketaux;
        cout<<" ";
        cout<<"\n\n";
        cout<<"________________________________________________________________________"<<endl;
        cout<<"                  ATENCION! ESTE USUARIO SERA ELIMINADO                 "<<endl;
        cout<<"________________________________________________________________________"<<endl;
        cout<<"\n";

        borrar>>nombre;

            while(!borrar.eof()){
                  borrar>>apellido;
                  borrar>>nticket;
                  borrar>>asistencia;

                    if(nticket == nticketaux){ //si el numero que busco coincide con el guardado elimina toda la informacion de esa linea
                       cout<<"Nombre: "<<nombre<<endl;
                       cout<<"Apellido: "<<apellido<<endl;
                       cout<<"Numero ticket: "<<nticket<<endl;
                       cout<<"Asistencia: "<<asistencia<<endl;
                       cout<<"\n\n";

                       cout<<"El invitado fue borrado correctamente";
                       cout<<"\n";

                       }

                       else

                       {

                       aux<<nombre<<" "<<apellido<<" "<<nticket<<" "<<asistencia<<"\n";//guardo en el nuevo txt los datos sin modificar

                       }

                       borrar>>nombre;

            }

            borrar.close();//cierro el archivo original
            aux.close();//cierro el archivo auxiliar
            remove("Lista_de_invitados.txt");//elimino el archivo original
            rename("editinvitados.txt","Lista_de_invitados.txt");//renombro el archivo auxiliar con el nombre del original

            exit(1);

     }
     else
     {

     cout<<"error"<<endl;

     }

}



void editardatos (ifstream &editar){

    system("cls");
    string nombre;
    string apellido;
    string asistencia;
    string nticket;
    string nombreaux,apellidoaux,asistaux,nticketaux;

     editar.open("Lista_de_invitados.txt", ios::in);
     ofstream aux("editinvitados.txt", ios::out);//creo un txt nuevo para ingresar datos temporales y asi guardar los cambios

     if(editar.is_open()){
        cout<<"Ingrese numero de ticket que desea buscar: ";
        cout<<" ";
        cin>>nticketaux;
        cout<<" ";


cout<<"\n\n";
cout<<"________________________________________________________________________"<<endl;
cout<<"                      EDITAR DATOS DE INVITADO/S                        "<<endl;
cout<<"________________________________________________________________________"<<endl;

        cout<<"\n";
        editar>>nombre;

            while(!editar.eof()){
                    editar>>apellido;
                    editar>>nticket;
                    editar>>asistencia;
                    if(nticket == nticketaux){

                            cout<<"Nombre: "<<nombre<<endl;
                            cout<<"Apellido: "<<apellido<<endl;
                            cout<<"Numero ticket: "<<nticket<<endl;
                            cout<<"Asistencia: "<<asistencia<<endl;
                            cout<<"\n\n";
                        cout<<"_______________________REINGRESE LOS DATOS A EDITAR_______________________\n"<<endl;
                            cout<<"Reingrese nombre: ";
                            cin>>nombreaux;
                            cout<<"Reingrese apellido: ";
                            cin>>apellidoaux;
                            cout<<"Edite asistencia: ";
                            cin>>asistaux;
                            aux<<nombreaux<<" "<<apellidoaux<<" "<<asistaux<<" "<<nticket<<"\n";//guardo en el nuevo txt la correccion de datos

                        }
                        else{

                            aux<<nombre<<" "<<apellido<<" "<<asistencia<<" "<<nticket<<"\n";//mantengo el el mismo txt los datos que ya existian
                        }

                    editar>>nombre;
            }
            editar.close();//cierro archivo original
            aux.close();//cierro archivo auxliar
            remove("Lista_de_invitados.txt");//elimino el txt original
            rename("editinvitados.txt","Lista_de_invitados.txt");//cambio nombre del txt auxiliar y le dejo el nombre del original

            cout<<"\n";
            cout<<"Presione 1 para terminar";
            cout<<"\n";

            exit(1);

     }
     else
     {

        cout<<"error"<<endl;

     }

}


void mostrar_invitados(ifstream &archivo_leer){

system("cls"); //Limpio lo que hay en pantalla.
string nombre;
string apellido;
string ticket;
string asistencia;


               cout <<"Muestra el listado de asistentes por pantalla:  ";
               cout<<"\n";
               cout<<"\n";

               cout<<"___________________________________________"<<endl;
               cout<<"NOMBRE Y APELLIDO / N-TICKET  / ASISTENCIA  "<<endl;
               cout<<"____________________________________________"<<endl;


               archivo_leer.open("Lista_de_invitados.txt", ios::in); //Abrir el archivo en modo lectura.

               if(archivo_leer.fail()){
               cout <<"No se pudo abrir el archivo";

               }

               while(!archivo_leer.eof()){

               getline(archivo_leer, nombre);
               getline(archivo_leer, apellido);
               getline(archivo_leer, ticket);
               getline(archivo_leer, asistencia);

               cout<<"\n";
               cout <<nombre;
               cout<<"\n";
               cout <<apellido;
               cout<<"\n";
               cout <<ticket;
               cout<<"\n";
               cout <<asistencia;
               cout<<"\n";
               archivo_leer>>nombre>>apellido>>ticket>>asistencia;

               cout<<"\n";
               cout <<"Presione 1 para terminar. ";
               cout<<"\n";

               exit(1);
                  }

	archivo_leer.close(); //Cierre
}

void buscarinvitado(ifstream &archivo_buscar){

system("cls");

string nombre2;
string apellido2;
string asistencia2;
string ticket2, nticketaux;

archivo_buscar.open("Lista_de_invitados.txt", ios::in );

cout<<"________________________________________________"<<endl;
cout<<"           BUSCADOR DE INVITADOS                "<<endl;
cout<<"________________________________________________"<<endl;

bool ticketencontrado = FALSE;

cout<<"Ingrese numero de ticket que desea buscar: ";
cin>>nticketaux;
archivo_buscar>>nombre2;
cout<<"\n";

            while(!archivo_buscar.eof()&& !ticketencontrado){

            archivo_buscar>>apellido2;
            archivo_buscar>>ticket2;
            archivo_buscar>>asistencia2;

            if(ticket2 == nticketaux){
            cout<<"Nombre: "<<nombre2<<endl;
            cout<<"Apellido: "<<apellido2<<endl;
            cout<<"Asistencia: "<<asistencia2<<endl;
            cout<<"Numero ticket: "<<ticket2<<endl;
            cout<<"\n\n";
            ticketencontrado = true;

            cout<<"\n";

                 }

                    archivo_buscar>>nombre2;

            }
             archivo_buscar.close();

         if(!ticketencontrado){
             cout<<"Ticket no encontrado "<<endl;
             cout<<"\n";
         }
         system("Pause");
}
int main(){

string nombre, apellido, texto, asistencia;
int opcion, ticket;
ofstream archivo("Lista_de_invitados.txt",ios::app);
ifstream archivo_leer,mostrar,buscar,editar,borrar;
void lectura(); //Mostrar invitados por pantalla
string nombre1;
string apellido1;
string ticket1;
string asistencia1;


    cout<<"\t\t**********************************************"<<endl;
    cout<<"\t\t*              MENU PRINCIPAL                *"<<endl;
    cout<<"\t\t**********************************************"<<endl;
    cout<<"\t\tBIENVENIDO al Sistema de Invitaciones para la"<<endl;
    cout<<"\t\tFiesta Aniversario de Studio 54 en New York!"<<endl;
    cout<<"\n";
    cout<<"\t\tQue accion desea realizar?"<<endl;
    cout<<
    "\n\t\t1- Registrar invitado"
    "\n\t\t2- Mostrar listado de asistentes por pantalla"
    "\n\t\t3- Buscar por numero de ticket"
    "\n\t\t4- Modificar dato de invitado"
    "\n\t\t5- Eliminar invitado"
    "\n\t\t6- Salir" <<endl;
    cout<<"\n";
    cout<<"\t\tDigite la opcion y luego presione enter: ";
    cin>>opcion;
    cout<<"\n";


    while (texto !="6"){
    switch(opcion) {
      case 1:
              system("cls"); //Limpio lo que hay en pantalla.

              cout <<"Ingrese su primer nombre y su apellido: ";
              cin>>nombre;
              archivo<<nombre<<" ";
              getline(cin, apellido);
              archivo<<apellido<<" ";

              cout <<"Ingrese los 5 digitos del numero de ticket: ";
              cin>>ticket;
              archivo<<ticket<<" ";

              cout <<"Asistencia si/no: ";
              cin>>asistencia;
              archivo<<asistencia<<" ";
              cout<<"\n";

              cout <<"Presione 1 para agregar otro/a invitado/a o 6 para salir: ";
              cin>>opcion;
              cout<<"\n";

              break;

            case 2:
                cout<<"\n";
                mostrar_invitados(mostrar);

              break;

              case 3:
                  buscarinvitado(buscar);
              break;

              case 4:
                  editardatos(editar);
                  break;

              case 5:
                  borrarinvitado(borrar);
                  break;

              case 6:
                  cout <<"El sistema se cerro correctamente, hasta luego.";
                  archivo.close(); //Cierre
                  cout<<"\n";
                  return 0;
                  break;

              default:
                cout <<"La opcion ingresada es invalida";
                cout<<"\n";
                exit(1);
                break;
    }


if (texto != "6"){
archivo << texto << endl;
}

    }
	archivo.close(); //Cierre

    return 0;
}
