import PyPDF2
import pandas as pd


path = input("Insira o path do arquivo: ")
tipo_arquivo = input("Insira o tipo do arquivo: ")
nome_arquivo = input("Insira o nome do arquivo final: ")

#path = "c:\\Nova pasta\\\Projetos Git\\PTradutor\\Computer Organization and Design.pdf"
#path = "c:\\Nova pasta\\\Projetos Git\\PTradutor\\leitura.txt"

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

    print("Fim da lista")

    dicio = {}

    for i in range(len(lista)):
        #print(i,lista[i])
        dicio[lista[i]] = lista.count(lista[i])

    print("Fim do Dicionario")

    tabela = [{ "PALAVRA":None,
                    "QTD_PALAVRA":0
                }
                ]

    df = pd.DataFrame(tabela)
    df = df[["PALAVRA","QTD_PALAVRA"]]
    df.to_csv(nome_arquivo+".csv",header=True,index=False)

    for chave,valor in dicio.items():
        tabela = [{ "PALAVRA":chave,
                    "QTD_PALAVRA":valor
                }
                ]
        df = pd.DataFrame(tabela)
        df = df[["PALAVRA","QTD_PALAVRA"]]
        df.to_csv(nome_arquivo+".csv",header=False,mode='a',index=False)

    print("Fim da tabela por CSV")

else:
    text = open(path,mode='r')
    reader = text.read()
    #print(reader)

    word = reader.upper().replace(","," ").replace("."," ").replace("\n"," ")
    word = word.replace("(","").replace(")","").replace("“","").replace("”","").replace("ʽ","").replace("ʼ","")
    word = word.replace("?","").replace("!","").replace("[","").replace("]","").split(' ')

    lista = []
    for p in word:
        lista.append(p)
        #print("--",p)

    print("Fim da lista por TXT")

    dicio = {}

    for i in range(len(lista)):
        #print(i,lista[i])
        dicio[lista[i]] = lista.count(lista[i])

    print("Fim do Dicionario por TXT")

    tabela = [{ "PALAVRA":None,
                    "QTD_PALAVRA":0
                }
                ]

    df = pd.DataFrame(tabela)
    df = df[["PALAVRA","QTD_PALAVRA"]]
    df.to_csv(nome_arquivo+".csv",header=True,index=False)

    for chave,valor in dicio.items():
        tabela = [{ "PALAVRA":chave,
                    "QTD_PALAVRA":valor
                }
                ]
        df = pd.DataFrame(tabela)
        df = df[["PALAVRA","QTD_PALAVRA"]]
        df.to_csv(nome_arquivo+".csv",header=False,mode='a',index=False)

    print("Fim da tabela por TXT")