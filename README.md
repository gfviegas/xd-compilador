# Trabalho Prático 2 - Compiladores

## Linguagem XD - Cheese Development
Linguagem de programação **funcional** com background do "idioma" mineirês. O seu nome surgiu a partir do fato que culturalmente, em minas, temos as hamburguerias chamando os lanches de X-Burger ao invés Cheese Burger. Portanto homenageamos a culinária local com o X (Cheese) Development.

Extensão do código fonte: .uai

Paradigma de Programação: funcional.


Tipos de dados primitivos:
inteiro: Numero
float: NumeroQuebrado
caractere: Letra
string: Palavra
binario: ZeriUm
boolean: ÉOuNumÉ - assume valores verdadeiros (Vera) ou falsos (Bobagi)
atomos: Bolota


Outros tipos de dados:
Lista: Lista
Vetor: Vetorr
Hash (Mapa): Marpa
Tupla (Par, Valor): Parr
Pilha: Pia
Fila: Fila
Arquivo: Documento


Os tipos de dados sempre começam com letra maiúscula e a linguagem segue o padrão CamelCase.

A linguagem vai aceitar hexadecimais

A linguagem tem poder para criar tipos abstratos de dados (structs) que são chamados de Troço.

Palavras-chave:
Vera:  valor verdadeiro pra tipo booleano
Bobagi - valor falso pra tipo booleano
cêsabese - Comparador (equivalente a if)
intao - dar inicio a bloco de código (equivalente a then)
intaotabao - dar fim a bloco de código (equivalente a end)
sinão - Comparador equivalente a else
uai - ponto e virgula
negocio - declara o inicio de uma funcao
tendeu - dar fim a bloco de função
assim - dar inicio a bloco de modulo
cabô - dar fim a bloco de modulo
trem - declarar uma constante
desembucha - printar algo

Operadores lógicos:
ou - OR (|)
i - AND (&&)
ingual - Atribuição (=)
ingualzin - Comparação (==)
nadavê com - Comparação diferente (!=)
menó que - Comparação de menor (<)
maió que - Comparação de menor (>)

Operadores matemáticos:
mais - +
menus - \-
veiz - *
divididu - /
resto - %
elevado - **


Para declarar uma função: tem que usar a palavra chave “negocio" seguido do nome, parâmetros entre paranteses separados por virgulas, e “assim”, seguido do corpo da função e finalizado por “tendeu”


A linguagem adotará o casamento de padrão (pattern-matching) podendo receber vários corpos de uma mesma função dependendo do parâmetro

Declaração de constantes usando a palavra chave trem

Criação de modulos que agrupam funções. A linguagem já vai implementar um módulo padrão e alguns auxiliares (Tipo Matemática, etc)


negocio divididu(Numero x, 0) assim
    0
tendeu

negocio divididu(Numero x, Numero y) assim
    devorve x divididu y
tendeu


