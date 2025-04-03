
#define MAXSALAS 3

struct salas {
    int identificacao;
    int capacidadeMaxima;
    int capacidadeAtual;
    char tipoSala[20];
    char bloco;
};

typedef struct lista Lista;
typedef struct salas Salas;

// Funções principais
Lista* criaSala();
int insereOrdenada(Lista* list, Salas room);

void tela();
void imprimeLista(Lista* list);
void addSala(Lista* sala, Salas vetSalas[]);
void taxaOcupacao(Lista* sala, Salas vetSalas[]);
void ocupacaoComputadores(Lista* sala, Salas vetSalas[]);
void imprimeListaOrdenada(Lista* list);
void OrdenaSalas(Lista* list);
void imprimeListaTipo(Lista* Salas);
void insereAutomatico(Lista* salas);
