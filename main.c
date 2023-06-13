#include <stdio.h>
#include <string.h>

int ultimo_elemento=-1;
int id_incremental=0;

typedef struct{
    int id; //posição dos dados do animal no código
    
    char tipo[30]; //tipo de animal(gato, cachorro,etc)
    char nome_animal[50]; //nome do animal
    char raca_animal[50]; //raça do animal
    float peso_animal; //peso do animal
    int idade_animal;
    
    char hora_ent[10]; //horário de entrada
    char hora_sai[10]; //horário saída
    
    char nome_dono[50];
    char id_dono[30]; //identidade do dono
    char celular[30]; //número de celular do dono
    char sintomas[200]; //sintomas do animal
    char cirurgia[199];
} Dados; //Dados é o tipo da variável, e contém todas as outras variáveis 

Dados vetor[50]; //cada espaço do vetor vai ter

typedef struct{
    char nome_mat[50];//nome do material
    float total_mat;//total do preço de todos os materiais
} Material;
    
    Material vetor3[50];
    
void cadastrar() {
    ultimo_elemento++; //permite controlar a posição do próximo elemento a ser cadastrado no vetor
    id_incremental++; //garante que cada elemento tenha um ID único

    float total = 0,preco_mat=0; //igualar a 0 para quando o void cadastrar for chamado de novo, os valores estarão em 0
    int num_cirurgia, quant_mat;
    int quantidade=0; //igualar a 0 para quando o void cadastrar for chamado de novo, os valores estarão em 0
    char tipo_animal[30], nome[50], raca[50];
    char nome_r[50], num_id[30], num_celular[30];

    vetor[ultimo_elemento].id = id_incremental;

    printf("***DADOS DO ANIMAL***\n\n");
    printf("Qual o tipo de animal? (cachorro, gato, etc): ");
    scanf("%29s", tipo_animal);
    strcpy(vetor[ultimo_elemento].tipo, tipo_animal);

    printf("Nome do animal: ");
    scanf("%49s", nome);
    strcpy(vetor[ultimo_elemento].nome_animal, nome);

    printf("Raça do animal: ");
    scanf("%49s", raca);
    strcpy(vetor[ultimo_elemento].raca_animal, raca);

    printf("Peso do animal (só números): ");
    scanf("%f", &vetor[ultimo_elemento].peso_animal);

    printf("Anos de idade do animal (só números): ");
    scanf("%d", &vetor[ultimo_elemento].idade_animal);

    printf("\n***Dados do responsável***\n");
    printf("Nome do responsável: ");
    scanf("%49s", nome_r);
    strcpy(vetor[ultimo_elemento].nome_dono, nome_r);

    printf("Número de identidade do responsável: ");
    scanf("%29s", num_id);
    strcpy(vetor[ultimo_elemento].id_dono, num_id);

    printf("Número de celular do responsável (sem espaço entre os caracteres): ");
    scanf("%29s", num_celular);
    strcpy(vetor[ultimo_elemento].celular, num_celular);

    printf("\n***SINTOMAS***\n");
    printf("Sintomas do animal: ");
    scanf(" %[^\n]", vetor[ultimo_elemento].sintomas);

    printf("Será preciso cirurgia? Escolha 1-SIM; 2-NÃO: ");
    scanf("%d", &num_cirurgia);
    if (num_cirurgia==1) {
        printf("Descrição da cirurgia: ");
        scanf(" %[^\n]", vetor[ultimo_elemento].cirurgia);
    }else if(num_cirurgia==2){
        strcpy(vetor[ultimo_elemento].cirurgia, "Não precisa de cirurgia!");
    }else{
        strcpy(vetor[ultimo_elemento].cirurgia, "Inválido!");
    }

    printf("\nQuantos materiais foram usados (inclua os medicamentos)? ");
    scanf("%d",&quant_mat);
    for(int i=0;i<quant_mat; i++){
        
        printf("Preço do material %d: ",i+1); //i+1 porque ele começa do 0, assim o produto vai ter numero 1 e não 0
        scanf("%f",&preco_mat);
        
        printf("Quantidade do material %d: ",i+1);
        scanf("%d",&quantidade);
        
        total+=preco_mat*quantidade; //+= significa que o que está depois da operação será adicionado ao total
    }
    vetor3[ultimo_elemento].total_mat=total;
    

    printf("\nHorário de entrada à Clínica Animal: ");
    scanf(" %[^\n]", vetor[ultimo_elemento].hora_ent);

    printf("Horário de saída da Clínica Animal: ");
    scanf(" %[^\n]", vetor[ultimo_elemento].hora_sai);
}

void listar(){
    for (int i=0;i<=ultimo_elemento;i++){
        printf("\n***RELATÓRIO COMPLETO ID %d ***\n", vetor[i].id);
        printf("\n***dados do animal***\n");
        printf("\n-Tipo: %s", vetor[i].tipo);
        printf("\n-Nome: %s", vetor[i].nome_animal);
        printf("\n-Raça: %s", vetor[i].raca_animal);
        printf("\n-Peso do animal: %.2f Kg", vetor[i].peso_animal);
        printf("\n-Idade do animal: %d anos\n", vetor[i].idade_animal);

        printf("\n***dados do responsável***\n");
        printf("\n-Nome do reponsável: %s", vetor[i].nome_dono);
        printf("\n-Id do responsável: %s\n", vetor[i].id_dono);
        printf("\n-Número de celular do responsável: %s\n", vetor[i].celular);

        printf("\n***sintomas do animal***\n");
        printf("\n-Sintomas do animal: %s", vetor[i].sintomas);
        printf("\n-Cirurgia: %s", vetor[i].cirurgia);
        if(vetor3[i].total_mat==0.00){
            printf("\n-Valor (só consulta): R$120,00");
        }else{
            printf("\n-Valor total dos materiais usados (+R$120,00 da consulta): R$%.2f\n", vetor3[i].total_mat+120);
        }
        

        printf("\n-Horário de entrada: %s\n", vetor[i].hora_ent);
        printf("-Horário de saída: %s\n", vetor[i].hora_sai);
    }
}

int buscar_posicao(int id){
    for(int i=0;i<=ultimo_elemento;i++){
        if(vetor[i].id==id){
            return i;
        }
    }
    return -1;
}

void buscar(){
    int id;
    printf("Digite o ID da posição: ");
    scanf("%d",&id);
    int posicao=buscar_posicao(id);
    if(posicao!=-1){ //-1 porque no int buscar_posicao, se não encontrar a posição, ele retorna -1;
        printf("\n***RELATÓRIO COMPLETO ID %d ***\n", vetor[posicao].id);
        printf("\n***dados do animal***\n");
        printf("\n-Tipo: %s", vetor[posicao].tipo);
        printf("\n-Nome: %s", vetor[posicao].nome_animal);
        printf("\n-Raça: %s", vetor[posicao].raca_animal);
        printf("\n-Peso do animal: %.2f Kg", vetor[posicao].peso_animal);
        printf("\n-Idade do animal: %d anos\n", vetor[posicao].idade_animal);

        printf("\n***dados do responsável***\n");
        printf("\n-Nome do reponsável: %s", vetor[posicao].nome_dono);
        printf("\n-Id do responsável: %s\n", vetor[posicao].id_dono);
        printf("\n-Número de celular do responsável: %s\n", vetor[posicao].celular);

        printf("\n***sintomas do animal***\n");
        printf("\n-Sintomas do animal: %s", vetor[posicao].sintomas);
        printf("\n-Cirurgia: %s", vetor[posicao].cirurgia);
        if(vetor3[posicao].total_mat==0.00){
            printf("\n-Valor (só consulta): R$120,00");
        }else{
            printf("\n-Valor total dos materiais usados (+R$120,00 da consulta): R$%.2f\n", vetor3[posicao].total_mat+120);
        }
        

        printf("\n-Horário de entrada: %s\n", vetor[posicao].hora_ent);
        printf("-Horário de saída: %s\n", vetor[posicao].hora_sai);
        
    }else{
        printf("Não encontrado!\n");
    }
    
}

void alterar(){
    int id;
    printf("Digite o ID da posição: ");
    scanf("%d",&id);
    int posicao=buscar_posicao(id);
    if(posicao!=-1){
    float total=0,preco_mat=0; //igualar a 0 para quando o void cadastrar for chamado de novo, os valores estarão em 0
    int num_cirurgia, quant_mat;
    int quantidade=0; //igualar a 0 para quando o void cadastrar for chamado de novo, os valores estarão em 0
    char tipo_animal[30], nome[50], raca[50];
    char nome_r[50], num_id[30], num_celular[30];

    vetor[ultimo_elemento].id = id_incremental;

    printf("***DADOS DO ANIMAL***\n\n");
    printf("Qual o tipo de animal? (cachorro, gato, etc): ");
    scanf("%29s", tipo_animal);
    strcpy(vetor[ultimo_elemento].tipo, tipo_animal);

    printf("Nome do animal: ");
    scanf("%49s", nome);
    strcpy(vetor[ultimo_elemento].nome_animal, nome);

    printf("Raça do animal: ");
    scanf("%49s", raca);
    strcpy(vetor[ultimo_elemento].raca_animal, raca);

    printf("Peso do animal (só números): ");
    scanf("%f", &vetor[ultimo_elemento].peso_animal);

    printf("Anos de idade do animal (só números): ");
    scanf("%d", &vetor[ultimo_elemento].idade_animal);

    printf("\n***Dados do responsável***\n");
    printf("Nome do responsável: ");
    scanf("%49s", nome_r);
    strcpy(vetor[ultimo_elemento].nome_dono, nome_r);

    printf("Número de identidade do responsável: ");
    scanf("%29s", num_id);
    strcpy(vetor[ultimo_elemento].id_dono, num_id);

    printf("Número de celular do responsável (sem espaço entre os caracteres): ");
    scanf("%29s", num_celular);
    strcpy(vetor[ultimo_elemento].celular, num_celular);

    printf("\n***SINTOMAS***\n");
    printf("Sintomas do animal: ");
    scanf(" %[^\n]", vetor[ultimo_elemento].sintomas);

    printf("Será preciso cirurgia? Escolha 1-SIM; 2-NÃO: ");
    scanf("%d", &num_cirurgia);
    if (num_cirurgia==1) {
        printf("Descrição da cirurgia: ");
        scanf(" %[^\n]", vetor[ultimo_elemento].cirurgia);
    }else if(num_cirurgia==2){
        strcpy(vetor[ultimo_elemento].cirurgia, "Não precisa de cirurgia!");
    }else{
        strcpy(vetor[ultimo_elemento].cirurgia, "Inválido!");
    }

    printf("\nQuantos materiais foram usados (inclua os medicamentos)? ");
    scanf("%d",&quant_mat);
    for (int i=0;i<quant_mat; i++) {
        
        printf("Preço do material %d: ",i+1); //i+1 porque ele começa do 0, assim o produto vai ter numero 1 e não 0
        scanf("%f",&preco_mat);
        
        printf("Quantidade do material %d: ",i+1);
        scanf("%d",&quantidade);
        
        total+=preco_mat*quantidade; //+= significa que o que está depois da operação será adicionado ao total
    }
    vetor3[ultimo_elemento].total_mat=total;
    

    printf("\nHorário de entrada à Clínica Animal: ");
    scanf(" %[^\n]", vetor[ultimo_elemento].hora_ent);

    printf("Horário de saída da Clínica Animal: ");
    scanf(" %[^\n]", vetor[ultimo_elemento].hora_sai);
        
    }else{
        printf("Não encontrado!\n");
    }
}

void excluir(){
    int id;
    printf("Digite o ID a ser excluído: ");
    scanf("%d",&id);
    int posicao=buscar_posicao(id);
    if (posicao!=-1){
        Dados d=vetor[ultimo_elemento];
        vetor[ultimo_elemento]=vetor[posicao];
        vetor[posicao]=d;
        ultimo_elemento--;
        printf("Espaço no ID excluído com sucesso!");
    }else{
        printf("ID não encontrado!");
    }
}

int main(){
    int op;
    do{
        printf("\n=====ESCOLHA UM NÚMERO=====");
        printf("\n==   1-Cadastrar         ==");
        printf("\n==   2- Listar           ==");
        printf("\n==   3- Alterar          ==");
        printf("\n==   4- Buscar           ==");
        printf("\n==   5- Excluir          ==");
        printf("\n==   0- Sair             ==\n");
        printf("Resposta: ");
        scanf("%d",&op);
        switch(op){
            case 1:
                cadastrar();
            break;
            
            case 2:
                listar(vetor);
            break;
            
            case 3:
                alterar();
            break;
            
            case 4:
                buscar();
            break;
            
            case 5:
                excluir();
            break;
        }
    }while(op!=0);
    
    
    return 0;
}
