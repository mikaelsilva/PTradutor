# PTradutor
O objetivo deste projeto é identificar de um texto (até o momento fazendo a leitura de um pdf) qual a quantidade de vezes que uma determinada palavra aparece no texto, e ordenar por essa quantidade, mostrando no final uma lista contendo a palavra estrangeira, a sua frequencia no texto (criterio de ordenação), e uma lista com as possiveis traduções para aquela palavra.

## Utilização

Primeiro é necessario executar o código *leitor.py*, passando os parametros abaixo.<br/>

![](img/Leitor.PNG)

O código *leitor.py* salva um arquivo *.csv*, com duas colunas 

![](img/Tabela_1.PNG)

Depois, é chamado a funçao *traduzindo*, que recebe o nome do arquivo final salvo e o nome do *Dicionario.csv* para a função *tradutozindo*<br/> 

![](img/Tradutor.PNG)

Salvando então um arquivo com um *nome_arquivo*+_traduzindo.csv, mostrando em ordem decrescente o número de aparações de cada palavra e suas possíveis traduções.

![](img/Tabela_2.PNG)
