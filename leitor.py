import PyPDF2
import pandas as pd

path = "c:\\Nova pasta\\\Projetos Git\\PTradutor\\Computer Organization and Design.pdf"
nome_arquivo="Computer"

text = open(path,mode='rb')
reader = PyPDF2.PdfFileReader(text)

num = reader.numPages
lista = []

for i in range(5):
    page = reader.getPage(i)
    word = page.extractText().upper().replace(","," ").replace("."," ").replace("\n"," ")
    word = word.replace("(","").replace(")","").replace("“","").replace("”","").replace("ʽ","").replace("ʼ","")
    word = word.replace("?","").replace("!","").replace("[","").replace("]","").split(' ')

    print(word)

    for p in word:
        lista.append(p)
        #print("--",p)

print("A")
#my_list = list(dict.fromkeys(lista))
#print(my_list)

dicio = {}

for i in range(50):
    #print(i,lista[i])
    dicio[lista[i]] = lista.count(lista[i])

print(dicio)
print("Fim")

#print(dicio)
#PROXIMAS ETAPAS SAO:
    #AJUSTAR O DICIONARIO PARA QUE CONTENHA A PALAVRA E QTD
    #CRIAR UM DICIONARIO COM AS PALAVRAS COMO CHAVE, E AS TRADUÇÕES E PRONUNCIA COMO UMA TUPLA NOS VALORES
    #CRIAR UM TERCEIRO DICIONARIO/LISTA/TUPLA (DECIDIR A MELHOR ABORDAGEM) QUE CONTENHA | PALAVRA_INGLES | QTD | TRADUÇÕES |


tabela = [{ "PALAVRA":"None-1",
                "QTD_PALAVRA":0
              }
             ]
df = pd.DataFrame(tabela)
df = df[["PALAVRA","QTD_PALAVRA"]]
df.to_csv("Computer.csv",header=True,index=False)

for chave,valor in dicio.items():
    tabela = [{ "PALAVRA":chave,
                "QTD_PALAVRA":valor
              }
             ]
    df = pd.DataFrame(tabela)
    df = df[["PALAVRA","QTD_PALAVRA"]]
    df.to_csv("Computer.csv",header=False,mode='a',index=False)


