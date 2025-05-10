#include <iostream>
#include <random>
#include <vector>
using namespace std;

int main()
{
    int limiteInferior;
    int limiteSuperior;

    cout << "Defini un numero inferior: ";
    cin >> limiteInferior;
    do
    {
        cout << "Defini un limite superior: ";
        cin >> limiteSuperior;
    } while (limiteSuperior <= limiteInferior);

    int intentos;
    do
    {
        cout << "Defini un numero de intentos: ";
        cin >> intentos;
    } while (intentos <= 0);

    int randomNum;
    randomNum =
        rand() % (limiteSuperior - limiteInferior + 1) + limiteInferior;

    int numeroadiv;
    vector<int> numerosIngresados;
    for (int i = 0; i < intentos; i++)
    {
        cout << "Adivina el numero generado: ";
        cin >> numeroadiv;

        bool repetido = false;
        for (int j = 0; j < numerosIngresados.size(); j++)
        {
            if (numeroadiv == numerosIngresados[j])
            {
                repetido = true;
                cout << "El numero ya fue ingresado, intento no válido." << endl;
                i--;
                break;
            }
        }
        if (repetido)
            continue;
        numerosIngresados.push_back(numeroadiv);
        int IntentosRestantes = intentos - i - 1;
        cout << "Intentos restantes:" << IntentosRestantes << endl;
        cout << "Intento " << i + 1 << " / " << intentos << endl;

        if (numeroadiv == randomNum)
        {
            cout << "¡Acertaste! El numero generado fue: " << randomNum << endl;
            cout << "Tu numero ingresado fue: " << numeroadiv;
            break;
        }
        else if (numeroadiv < randomNum)
        {
            cout << "¡Fallaste! El numero ingresado es menor que el numero generado." << endl;
        }
        else if (numeroadiv > randomNum)
        {
            cout << "¡Fallaste! El numero ingresado es mayor que el numero generado." << endl;
        }
    }
    return 0;
}