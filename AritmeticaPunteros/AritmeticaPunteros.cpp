#if 0
// VT 104 COD 001 

#include <iostream>

int main()
{
    int valor{ 7 };
    int* ptr{ &valor };

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';

    return 0;
}



// VT 104 COD 002

#include <iostream>

int main()
{
    short valor{ 7 };
    short* ptr{ &valor };

    std::cout << ptr << '\n';
    std::cout << ptr + 1 << '\n';
    std::cout << ptr + 2 << '\n';
    std::cout << ptr + 3 << '\n';

    return 0;
}



// VT 104 COD 003

#include <iostream>

int main()
{
    setlocale(LC_ALL, "es_ES.UTF-8");
    int array[]{ 9, 7, 5, 3, 1 };

    std::cout << "Elemento 0 está en la dirección: " << &array[0] << '\n';
    std::cout << "Elemento 1 está en la dirección: " << &array[1] << '\n';
    std::cout << "Elemento 2 está en la dirección: " << &array[2] << '\n';
    std::cout << "Elemento 3 está en la dirección: " << &array[3] << '\n';

    return 0;
}



// VT 104 COD 004

#include <iostream>

int main()
{
    int array[]{ 9, 7, 5, 3, 1 };

    std::cout << &array[1] << '\n'; // imprime dirección en memoria del elemento 1 del array
    std::cout << array + 1 << '\n'; // imprime dirección en memoria del array puntero + 1

    std::cout << array[1] << '\n'; // imprime 7
    std::cout << *(array + 1) << '\n'; // imprime 7 (observa los paréntesis necesarios aquí)
    //std::cout << *array + 1 << '\n'; // sin paréntesis las prioridades producen un resultado muy distinto


    return 0;
}







// VT 104 COD 005
#include <iostream>
#include <iterator> // para std::size

bool esVocal(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    char nombre[]{ "Francisco" };
    int arrayLength{ static_cast<int>(std::size(nombre)) };
    int numVocales{ 0 };

    for (char* ptr{ nombre }; ptr != (nombre + arrayLength); ++ptr)
    {
        if (esVocal(*ptr))
        {
            ++numVocales;
        }
    }

    std::cout << nombre << " tiene " << numVocales << " vocales.\n";

    return 0;
}

#endif



// VT 104 COD 006
#include <algorithm> // para std::count_if
#include <iostream>
#include <iterator> // para std::begin and std::end

bool esVocal(char ch)
{
    switch (ch)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    default:
        return false;
    }
}

int main()
{
    char nombre[]{ "Francisco" };

    // recorre todos los elementos de nombre y cuenta cuantas llamadas a esVocal devuelven true
    auto numVocales{ std::count_if(std::begin(nombre), std::end(nombre), esVocal) };

    std::cout << nombre << " tiene " << numVocales << " vocales.\n";

    return 0;
}




#if 0
// VT 104 COD 007
// nameLength is the number of elements in the array.
std::count_if(name, name + nameLength, isVowel)

// Don't do this. Accessing invalid indexes causes undefined behavior.
// std::count_if(name, &name[nameLength], isVowel)
#endif