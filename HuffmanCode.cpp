#include <iostream>

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

//Nodo
struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};

/**
 * @brief Crea un nodo
 * @param ch caracter
 * @param frec frecuencia del caracter
 * @param izq
 * @param der
 * @return
 */
Node* newNode(char ch, int frec, Node* izq, Node* der)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = frec;
    node->left = izq;
    node->right = der;

    return node;
}

//Comparacion para ordenar
struct comp
{
    bool operator()(Node* l, Node* r)
    {
        // El caracter con menor frecuencia tiene mayor prioridad.
        return l->freq > r->freq;
    }
};

/**
 * @brief Recorre el arbol y guarda el código de huffman en un mapa
 * @param root puntero al nodo root
 * @param str
 * @param huffmanCode mapa
 */
void comprimir(Node* root, string str,
               unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    comprimir(root->left, str + "0", huffmanCode);
    comprimir(root->right, str + "1", huffmanCode);
}


/**
 * @brief Recorre el arbol e imprime los caracteres
 * @param root Puntero al nodo root
 * @param index
 * @param str código comprimido
 */
void descomprimir(Node* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }

    //Se llegó al caracter
    if (!root->left && !root->right)
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] =='0')
        descomprimir(root->left, index, str);
    else
        descomprimir(root->right, index, str);
}

/**
 * @brief Construye el arbol de Huffman y ddescomprime el mensaje.
 * @param text
 */
void construirHuffmanTree(string text)
{
    // Cuenta la frecuencia de cada caracter.
    unordered_map<char, int> freq;
    for (char ch: text) {
        freq[ch]++;
    }

    // Crea un queue de prioridad que almacena los nodos del arbol
    priority_queue<Node*, vector<Node*>, comp> pq;

    //Agrega cada caracter en forma de nodo
    for (auto pair: freq) {
        pq.push(newNode(pair.first, pair.second, nullptr, nullptr));
    }

    while (pq.size() != 1)
    {
        //Remueve los dos nodos con menor frecuencia de la queue
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();	pq.pop();

        //anteriormente eliminados y lo agrega a la queue
        int sum = left->freq + right->freq;
        pq.push(newNode('\0', sum, left, right));
    }

    Node* root = pq.top();

    // Recorre el arbol y guarda el código de Huffman en un mapa
    unordered_map<char, string> huffmanCode;
    comprimir(root, "", huffmanCode);

    //Imprime cada caracter y su código.
    cout << "Código de Huffman:\n" << '\n';
    for (auto pair: huffmanCode) {
        cout << pair.first << " " << pair.second << '\n';
    }

    cout << "\nMensaje original :\n" << text << '\n';

    // printea al código comprimido
    string str = "";
    for (char ch: text) {
        str += huffmanCode[ch];
    }

    cout << "\nMensaje descomprimido :\n" << str << '\n';

    //Recorre el arbol y lo descomprime el código.
    int index = -1;
    cout << "\nDescompresión: \n";
    while (index < (int)str.size() - 2) {
        descomprimir(root, index, str);
    }
}

int main()
{
    string texto = "Prueba del algoritmo de compresion.";

    construirHuffmanTree(texto);

    return 0;
}