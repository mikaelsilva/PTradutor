import PyPDF2
import pandas as pd


path = input("Insira o path do arquivo: ")
tipo_arquivo = input("Insira o tipo do arquivo: ")

#path = "c:\\Nova pasta\\\Projetos Git\\PTradutor\\Computer Organization and Design.pdf"

nome_arquivo = 

if(tipo_arquivo == 'pdf'):
    text = open(path,mode='rb')
    reader = PyPDF2.PdfFileReader(text)

    num = reader.numPages
    lista = []

    for i in range(num):
        page = reader.getPage(i)
        word = page.extractText().upper().replace(","," ").replace("."," ").replace("\n"," ")
        word = word.replace("(","").replace(")","").replace("“","").replace("”","").replace("ʽ","").replace("ʼ","")
        word = word.replace("?","").replace("!","").replace("[","").replace("]","").split(' ')

        for p in word:
            lista.append(p)
            #print("--",p)

        print(i)

    print("Fim da lista")


    #print("A")
    #my_list = list(dict.fromkeys(lista))
    #print(my_list)

    dicio = {}

    for i in range(len(lista)):
        #print(i,lista[i])
        dicio[lista[i]] = lista.count(lista[i])

    #print(dicio)
    print("Fim do Dicionario")

    tabela = [{ "PALAVRA":None,
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

    print("Fim da tabela")

else:
    text = open(path,mode='r')
    reader = text.read


