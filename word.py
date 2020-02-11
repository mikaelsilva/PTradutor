import pandas as pd 


palavras = open("palavras.txt","r",encoding="utf-8")

tabela = [{ "PALAVRA":None,
            "PRONUNCIA":None,
            "TRADUCAO":None
              }
             ]

df = pd.DataFrame(tabela)
df = df[["PALAVRA","PRONUNCIA","TRADUCAO"]]
df.to_csv("Dicionario.csv",header=True,index=False)

for i in range(1,1002):
    string = palavras.readline()
    string = string.replace("\n","").split("\t")
    print(string)

    try:
        tabela = [{ "PALAVRA":string[1],
                "PRONUNCIA":string[2],
                "TRADUCAO":string[3:]
              }
             ]

        df = pd.DataFrame(tabela)
        df = df[["PALAVRA","PRONUNCIA","TRADUCAO"]]
        df.to_csv("Dicionario.csv",header=False,mode='a',index=False)
    except:
        pass

palavras.close()



