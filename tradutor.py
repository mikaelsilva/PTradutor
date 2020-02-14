import pandas as pd

aux_1 = input("CSV do arquivo: ")
aux_2 = input("CSV do tradutor: ")

arq_1 = "c:\\Nova pasta\\Projetos Git\\PTradutor\\"+aux_1
arq_2 = "c:\\Nova pasta\\Projetos Git\\PTradutor\\"+aux_2

dataframe_1 = pd.read_csv(arq_1)
dataframe_2 = pd.read_csv(arq_2)

dataframe_join = pd.merge(dataframe_1, dataframe_2, on='PALAVRA', how='inner')

dataframe_join = dataframe_join.sort_values(by=['QTD_PALAVRA'],ascending=False)
print(dataframe_join.head(10))

dataframe_join.to_csv("C:\\Nova pasta\\Projetos Git\\PTradutor\\"+aux_1.split(".csv")[0]+"_Traduzido.csv")