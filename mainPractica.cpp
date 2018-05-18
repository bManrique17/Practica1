#include <string>
#include <iostream>

using namespace std;

int*** crearArreglo();
void liberarArreglo(int***);
void imprimirContenido(int***);
int*** movimientos(int***);
int*** movimientoAFavor(int,int***);
int menu();

int main(){
    int x = 4,y = 4,z = 4;    

    cout<<"\n**Bocky's Sons International Championship**\n"<<endl;
    bool senuelo=true;
    int*** arreglo;    
    arreglo = crearArreglo();
    do{
        switch(menu()){                        
            case 1:
                imprimirContenido(arreglo);
                break;            
            case 2:
                arreglo = movimientos(arreglo);
                break;
            case 0:
                senuelo = false;
                break;
        }
    }while(senuelo);
    liberarArreglo(arreglo);

    //----------------
}

int menu(){
    int opcion;
    cout<<"     \n*MENU"<<endl        
    <<"(1)Imprimir arreglo"<<endl    
    <<"(2)Hacer movimientos"<<endl
    <<"(0)Salir"<<endl
    <<"->Ingrese su opcion: ";
    cin>>opcion;
    return opcion;
}

int*** crearArreglo(){
    int cont = 1;
    int*** arreglo = new int**[4];
    for(int i=0 ; i<4 ; i++){
        arreglo[i] = new int*[4];
        for(int j=0 ; j<4 ; j++){
            arreglo[i][j] = new int[4];
            for(int k=0 ; k<4 ; k++){
                arreglo[i][j][k] = cont;
                cont++;
            }
        }
    }
    return arreglo;
}

void liberarArreglo(int*** arreglo){
    for(int i=0 ; i<4 ; i++){        
        for(int j=0 ; j<4 ; j++){
            delete[] arreglo[i][j];
        }
        delete[] arreglo[i];
    }
    delete[] arreglo;
}

void imprimirContenido(int*** arreglo){
    cout<<"\nSu arreglo esta formado de la siguiente manera: "<<endl;
    for(int i=0 ; i<4 ; i++){
        cout<<"Zona ["<<i<<"]:"<<endl;        
        for(int j=0 ; j<4 ; j++){
            cout<<"     Region ["<<i<<"]["<<j<<"]:"<<endl;            
            for(int k=0 ; k<4 ; k++){                
                cout<<"             Elemento ["<<i<<"]["<<j<<"]["<<k<<"]: "<< arreglo[i][j][k]<<endl;
            }
        }
    }
    cout<<"\n->Efecto 3D :)"<<endl;
    cout<<"     | "<<arreglo[1][1][2]<<" | "<<arreglo[1][2][2]<<" |"<<endl
    <<"| "<<arreglo[1][1][1]<<" | "<<arreglo[1][2][1]<<" | "<<arreglo[2][2][2]<<" |"<<endl
    <<"| "<<arreglo[2][1][1]<<" | "<<arreglo[2][2][1]<<" |"<<endl;
}  

int*** movimientos(int*** arreglo){
    bool seguir = true;
    int zonaMover,direccion,temp;
    do{
        zonaMover=-1;
        cout<<"->Ingrese su zona a mover (9 para salir): ";
        cin>>zonaMover;
        if(zonaMover!=9){
            cout<<"->Ingrese su direccion (0 a favor, 1 en contra): ";
            cin>>direccion;
            
            if(direccion==0){
                arreglo = movimientoAFavor(zonaMover,arreglo);
            }else{
                arreglo = movimientoAFavor(zonaMover,arreglo);
                arreglo = movimientoAFavor(zonaMover,arreglo);
                arreglo = movimientoAFavor(zonaMover,arreglo);
            }
        }else{
            seguir = false;
        }
    }while(seguir);
    return arreglo;
}

int*** movimientoAFavor(int zonaMover, int*** arreglo){
    int temp = 0;

    temp=arreglo[zonaMover][0][0];
    arreglo[zonaMover][0][0] = arreglo[zonaMover][3][0];
    arreglo[zonaMover][3][0] = arreglo[zonaMover][3][3];
    arreglo[zonaMover][3][3] = arreglo[zonaMover][0][3];
    arreglo[zonaMover][0][3] = temp;

    temp=arreglo[zonaMover][0][1];
    arreglo[zonaMover][0][1] = arreglo[zonaMover][2][0];
    arreglo[zonaMover][2][0] = arreglo[zonaMover][3][2];
    arreglo[zonaMover][3][2] = arreglo[zonaMover][1][3];
    arreglo[zonaMover][1][3] = temp;

    temp=arreglo[zonaMover][0][2];
    arreglo[zonaMover][0][2] = arreglo[zonaMover][1][0];
    arreglo[zonaMover][1][0] = arreglo[zonaMover][3][1];
    arreglo[zonaMover][3][1] = arreglo[zonaMover][2][3];
    arreglo[zonaMover][2][3] = temp;

    //cubo del centro
    temp=arreglo[zonaMover][1][1];
    arreglo[zonaMover][1][1] = arreglo[zonaMover][2][1];
    arreglo[zonaMover][2][1] = arreglo[zonaMover][2][2];
    arreglo[zonaMover][2][2] = arreglo[zonaMover][1][2];
    arreglo[zonaMover][1][2] = temp;

    return arreglo;
}